// TODO kerning
// TODO calculated widths and max-widths not correct (try wrapping a line with 128 size text)
#include <Text/internal/TextMeshGenerator.h>
#include <Text.h>

#include <cstdint>
#include <cstring>
#include <stb_truetype.h>
#include <string>

#define VERT_COUNT 16

void internal::generate_text_mesh(Text* text) {
	TextMeshGenerationContext context;
	generate_text_structure(text, context);

	size_t buffer_pointer = 0;
	float_t cursor_x = text->pos.x,
			cursor_y = text->pos.y + text->font->ascent;

	size_t i_len = text->char_count * 6;
	size_t v_len = text->char_count * VERT_COUNT;

	// TODO should we be worrying about buffer allocations? Perhaps the owner could ensure their buffers are ready for mesh generation
	delete[] text->i_buffer;
	text->i_buffer = new uint32_t[i_len]{0};

	delete[] text->v_buffer;
	text->v_buffer = new float_t[v_len]{0};

	if (!text->char_count)
		return;

	for (auto line : context.lines) {
		process_line(line, context, &cursor_x, &cursor_y, &buffer_pointer);
		cursor_y += text->font->line_height;
		cursor_x = text->pos.x;
	}
}

void internal::process_line(Line* line, TextMeshGenerationContext& context, float_t* cursor_x, float_t* cursor_y, size_t* buffer_pointer) {
	for (auto word : line->words) {
		for (size_t i = 0, len = word->value.size(); i < len; i++) {
			stbtt_aligned_quad quad = context.text->font->get_char(word->value.at(i), cursor_x, cursor_y);
			process_quad(quad, buffer_pointer, context);

			// adjust for kerning
			if (i + 1 != len) {
				// *cursor_x += (float_t) stbtt_GetCodepointKernAdvance(&context.text->font->fontinfo, context.text->value.at(i), context.text->value.at(i + 1)) * context.scale;
			}
		}

		context.text->font->get_char(' ', cursor_x, cursor_y);
	}
}

void internal::process_quad(stbtt_aligned_quad quad, size_t* buffer_pointer, TextMeshGenerationContext& context) {
	// scale from font line height to text size
	quad.x0 *= context.scale;
	quad.x1 *= context.scale;
	quad.y0 *= context.scale;
	quad.y1 *= context.scale;

	// normalize value to screen space
	quad.x0 /= context.display_height;
	quad.x1 /= context.display_height;
	quad.y0 /= context.display_height;
	quad.y1 /= context.display_height;

	// scale for aspect ratio
	if (context.aspect_ratio > 1) {
		quad.y0 *= context.aspect_ratio;
		quad.y1 *= context.aspect_ratio;
	} else {
		quad.x0 *= context.aspect_ratio;
		quad.x1 *= context.aspect_ratio;
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

	for (GLuint &index : indices) {
		index += *buffer_pointer * 4;
	}

	size_t i_size = sizeof(indices);
	std::memcpy(&context.text->i_buffer[*buffer_pointer * 6], indices, i_size);
	context.text->i_buffer_size += i_size;

	size_t v_size = sizeof(vertices);
	std::memcpy(&context.text->v_buffer[*buffer_pointer * VERT_COUNT], vertices, v_size);
	context.text->v_buffer_size += v_size;

	(*buffer_pointer)++;
}

void internal::generate_text_structure(Text* text, TextMeshGenerationContext& context) {
	context.aspect_ratio = text->get_aspect_ratio();
	context.display_height = text->get_display_height();
	context.text_size = text->get_text_size();
	context.text = text;
	context.scale = context.text_size / text->font->line_height;

	Word* word = new Word;
	Line* line = new Line(text->max_width);
	context.lines.push_back(line);
	for (size_t i = 0, len = text->value.size(); i < len; i++) {
		char c = text->value.at(i);
		if (c == ' ') {
			if (!line->try_add_word(word)) {
				line = new Line(text->max_width);
				context.lines.push_back(line);
				line->try_add_word(word);
			}
			word = new Word;
			float_t tmp_x = 0, tmp_y = 0;
			text->font->get_char(' ', &tmp_x, &tmp_y);
			line->width += tmp_x;
			continue;
		}

		float_t kern = 0;
		if (i + 1 != len) {
			// kern = (float_t) stbtt_GetCodepointKernAdvance(&text->font->fontinfo, c, text->value.at(i + 1)) * context.scale;
		}

		word->add_char(c, context, kern);
		text->char_count++;
	}

	if (!line->try_add_word(word)) {
		line = new Line(text->max_width);
		context.lines.push_back(line);
		line->try_add_word(word);
	}
}

bool internal::Line::try_add_word(Word* word) {
	if (max_width < width + word->width)
		return false;
	words.emplace_back(word);
	width += word->width;
	return true;
}

void internal::Word::add_char(char c, TextMeshGenerationContext& context, float_t kern) {
	float_t tmp_x = 0, tmp_y = 0;
	context.text->font->get_char(c, &tmp_x, &tmp_y);
	width += tmp_x * context.scale + kern;
	value += c;
}
