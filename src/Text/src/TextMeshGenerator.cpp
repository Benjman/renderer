// TODO fix starting y-position not being at the top of the line
// TODO kerning not rendering accurately

#include <Text/internal/TextMeshGenerator.h>
#include <Text.h>
#include <cmath>
#include <cstring>
#include <iostream>
#include <stb_truetype.h>

void internal::generate_text_mesh(Text* text) {
	float_t cursor_x = text->pos.x,
			cursor_y = text->pos.y;

	size_t buffer_pointer = 0;

	delete[] text->i_buffer;
	delete[] text->v_buffer;

	TextStructure structure;
	generate_text_structure(text, structure);

	size_t i_len = text->char_count * 6;
	size_t v_len = text->char_count * VERTICES_PER_CHAR * ELEMENTS_PER_VERT;

	text->i_buffer = new uint32_t[i_len]{0};
	text->v_buffer = new float_t[v_len]{0};

	if (!text->char_count)
		return;

	for (auto line : structure.lines) {
		process_line(line, text, &cursor_x, &cursor_y, &buffer_pointer);
	}
}

void internal::process_line(Line* line, Text* text, float_t* cursor_x, float_t* cursor_y, size_t* buffer_pointer) {
	for (auto word : line->words) {
		for (size_t i = 0, len = word->value.size(); i < len; i++) {
			stbtt_aligned_quad quad = text->font->get_char(word->value[i], cursor_x, cursor_y);
			process_quad(quad, text, buffer_pointer);
		}

		text->font->get_char(' ', cursor_x, cursor_y);
	}
}

void internal::process_quad(stbtt_aligned_quad quad, Text *text, size_t* buffer_pointer) {
	float_t display_height = (float_t) text->get_display_height();
	float_t aspect_ratio = text->get_aspect_ratio();
	float_t text_size = (float_t) text->get_text_size();

	float_t x0 = quad.x0;
	float_t x1 = quad.x1;
	float_t y0 = text->font->line_height + quad.y0;
	float_t y1 = text->font->line_height + quad.y1;

	x0 *= text_size / text->font->line_height;
	x1 *= text_size / text->font->line_height;
	y0 *= text_size / text->font->line_height;
	y1 *= text_size / text->font->line_height;

	x0 /= display_height;
	x1 /= display_height;
	y0 /= display_height;
	y1 /= display_height;

	 if (aspect_ratio > 1) {
		 y0 *= aspect_ratio;
		 y1 *= aspect_ratio;
	 } else {
		 x0 *= aspect_ratio;
		 x1 *= aspect_ratio;
	 }

	// convert from [0,1] to [-1,1]
	x0 = 2 * x0 - 1;
	x1 = 2 * x1 - 1;
	y0 = -2 * y0 + 1;
	y1 = -2 * y1 + 1;

	const float_t vertices[VERTICES_PER_CHAR * ELEMENTS_PER_VERT] {
			x0, y0,
			quad.s0, -quad.t0,

			x0, y1,
			quad.s0, -quad.t1,

			x1, y1,
			quad.s1, -quad.t1,

			x1, y0,
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
	std::memcpy(&text->i_buffer[*buffer_pointer * 6], indices, i_size);
	text->i_buffer_size += i_size;

	size_t v_size = sizeof(vertices);
	std::memcpy(&text->v_buffer[*buffer_pointer * 16], vertices, v_size);
	text->v_buffer_size += v_size;

	(*buffer_pointer)++;
}

void internal::generate_text_structure(Text* text, TextStructure& structure) {
	Word* word = new Word;
	Line* line = new Line(text->max_width);
	structure.lines.push_back(line);
	for (size_t i = 0, len = text->value.size(); i < len; i++) {
		char c = text->value.at(i);
		if (c == ' ') {
			if (!line->try_add_word(word)) {
				line = new Line(text->max_width);
				structure.lines.push_back(line);
				line->try_add_word(word);
			}
			word = new Word;
			float_t tmp_x = 0, tmp_y = 0;
			text->font->get_char(' ', &tmp_x, &tmp_y);
			line->width += tmp_x;
			continue;
		}
		float_t kern = 0;
		if (i + 1 != len)
			kern = (float_t) stbtt_GetCodepointKernAdvance(&text->font->fontinfo, c, text->value.at(i + 1));
		word->add_char(c, text->font, line, kern);
		text->char_count++;
	}
	if (!line->try_add_word(word)) {
		line = new Line(text->max_width);
		structure.lines.push_back(line);
		line->try_add_word(word);
	}
}

bool internal::Line::try_add_word(Word* word) {
	if (max_width < width + word->width)
		return false;
	words.emplace_back(word);
	return true;
}

void internal::Word::add_char(u_char c, Font* font, Line* line, float_t kern) {
	float_t tmp_x = 0, tmp_y = 0;
	font->get_char(c, &tmp_x, &tmp_y);
	width += tmp_x + kern;
	value += c;
}

