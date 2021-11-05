// TODO kerning
// TODO calculated widths and max-widths not correct (try wrapping a line with 128 size text)
#include <text/internal/generator.h>
#include <text.h>

#include <cstring>

#define VERT_COUNT 16

void internal::TextMeshGenerator::generate_structure() {
	scale = root.m_line_height / root.m_font->line_height;

	Word* word = new Word;
	Line* line = new Line(root.m_max_width);

	lines.push_back(line);

	for (size_t i = 0, len = root.m_value.size(); i < len; i++) {
		char c = root.m_value.at(i);
		if (c == ' ') {
			if (!line->try_add_word(word)) {
				line = new Line(root.m_max_width);
				lines.push_back(line);
				line->try_add_word(word);
			}
			word = new Word;
			float_t tmp_x = 0, tmp_y = 0;
			root.m_font->get_char(' ', &tmp_x, &tmp_y);
			line->width += tmp_x;
			continue;
		}

		float_t kern = 0;
		if (i + 1 != len) {
			// kern = (float_t) stbtt_GetCodepointKernAdvance(&root.m_font->fontinfo, c, root.m_value.at(i + 1)) * context.scale;
		}

		word->add_char(*this, c, kern);
		root.m_char_count++;
	}

	if (!line->try_add_word(word)) {
		line = new Line(root.m_max_width);
		lines.push_back(line);
		line->try_add_word(word);
	}
}

void internal::TextMeshGenerator::generate_mesh() {
	generate_structure();

	size_t buffer_pointer = 0;
	float_t cursor_x = root.m_pos_x,
			cursor_y = root.m_pos_y + root.m_font->ascent;

	size_t i_len = root.m_char_count * 6;
	size_t v_len = root.m_char_count * VERT_COUNT;

	// TODO should we be worrying about buffer allocations? Perhaps the owner could ensure their buffers are ready for mesh generation
	delete[] root.m_idx_buf;
	root.m_idx_buf = new uint32_t[i_len]{0};

	delete[] root.m_vert_buf;
	root.m_vert_buf = new float_t[v_len]{0};

	if (!root.m_char_count)
		return;

	for (auto line : lines) {
		process_line(line, &cursor_x, &cursor_y, &buffer_pointer);
		cursor_y += root.m_font->line_height;
		cursor_x = root.m_pos_x;
	}
}

void internal::TextMeshGenerator::process_line(Line* line, float_t* cursor_x, float_t* cursor_y, size_t* buffer_pointer) {
	for (auto word : line->words) {
		for (size_t i = 0, len = word->value.size(); i < len; i++) {

			stbtt_aligned_quad quad = root.m_font->get_char(word->value.at(i), cursor_x, cursor_y);
			process_quad(quad, buffer_pointer);

			// adjust for kerning
			if (i + 1 != len) {
				// *cursor_x += (float_t) stbtt_GetCodepointKernAdvance(&context.text->font->fontinfo, context.text->m_value.at(i), context.text->m_value.at(i + 1)) * context.scale;
			}

		}
        root.m_font->get_char(' ', cursor_x, cursor_y);
	}
}

void internal::TextMeshGenerator::process_quad(stbtt_aligned_quad quad, size_t* buffer_pointer) {
	// scale from font line height to text size
	quad.x0 *= scale;
	quad.x1 *= scale;
	quad.y0 *= scale;
	quad.y1 *= scale;

	// normalize value to screen space
	quad.x0 /= root.m_display_height;
	quad.x1 /= root.m_display_height;
	quad.y0 /= root.m_display_height;
	quad.y1 /= root.m_display_height;

	// scale for aspect ratio
	if (root.m_aspect_ratio > 1) {
		quad.y0 *= root.m_aspect_ratio;
		quad.y1 *= root.m_aspect_ratio;
	} else {
		quad.x0 *= root.m_aspect_ratio;
		quad.x1 *= root.m_aspect_ratio;
	}

	// map from [0,1] to [-1,1]
	quad.x0 = 2 * quad.x0 - 1;
	quad.x1 = 2 * quad.x1 - 1;
	quad.y0 = -2 * quad.y0 + 1;
	quad.y1 = -2 * quad.y1 + 1;

	const float_t vertices[VERT_COUNT] {
		quad.x0, quad.y0,
		quad.s0, -quad.t0,

		quad.x0, quad.y1,
		quad.s0, -quad.t1,

		quad.x1, quad.y1,
		quad.s1, -quad.t1,

		quad.x1, quad.y0,
		quad.s1, -quad.t0
	};

	uint32_t indices[] {
			0, 1, 3,
			1, 2, 3,
	};

	for (uint32_t &index : indices) {
		index += *buffer_pointer * 4;
	}

	size_t i_size = sizeof(indices);
	std::memcpy(&root.m_idx_buf[*buffer_pointer * 6], indices, i_size);
	root.m_idx_buf_size += i_size;

	size_t v_size = sizeof(vertices);
	std::memcpy(&root.m_vert_buf[*buffer_pointer * VERT_COUNT], vertices, v_size);
	root.m_vert_buf_size += v_size;

	(*buffer_pointer)++;
}

bool internal::TextMeshGenerator::Line::try_add_word(Word* word) {
	if (max_width < width + word->width)
		return false;
	words.emplace_back(word);
	width += word->width;
	return true;
}

void internal::TextMeshGenerator::Word::add_char(TextMeshGenerator& generator, char c, float_t kern) {
	float_t tmp_x = 0, tmp_y = 0;
    generator.root.m_font->get_char(c, &tmp_x, &tmp_y);
	width += tmp_x * generator.scale + kern;
	value += c;
}
