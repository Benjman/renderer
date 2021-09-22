#ifndef TEXT_TEXT_H
#define TEXT_TEXT_H

#include "Flags.h"

#include <cmath>
#include <string>
#include <glm/vec2.hpp>

class Font;

class Text {
	public:
		Text(std::string value, Font& font, glm::vec2 pos, uint32_t flags);

		void set_value(std::string value, bool update_mesh = true);

		float* get_mesh() const noexcept;

		void set_flags(uint32_t flags) noexcept;

		void set_alignment(u_char alignment) noexcept { this->alignment = alignment; }
		void set_line_gap(float_t line_gap) noexcept { this->line_gap = line_gap; }
		void set_text_size(float_t text_size) noexcept { this->text_size = text_size; }

	private:
		std::string value;
		float_t* mesh{};
		float_t text_size = get_text_size_flags(TEXT_SIZE_12);
		float_t line_gap = get_line_gap_flags(LINE_GAP_1_0);
		u_char alignment = get_alignment_flags(TEXT_ALIGN_LEFT);
		glm::vec2 pos;

		u_char get_alignment_flags(uint32_t flags) noexcept;
		float_t get_line_gap_flags(uint32_t flags) noexcept;
		float_t get_text_size_flags(uint32_t flags) noexcept;
};

#endif // TEXT_TEXT_H
