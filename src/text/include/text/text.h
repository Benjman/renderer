#ifndef TEXT_TEXT_H
#define TEXT_TEXT_H

#include <cmath>
#include <string>
#include <glm/vec2.hpp>

class Font;

class Text {
	public:
		size_t char_count = 0; // non-whitespace chars only
		uint32_t flags;
		Font* font;
		uint32_t max_width;
		glm::vec2 pos;
		std::string value;

		uint32_t* i_buffer{};
		size_t i_buffer_size = 0;
		float_t* v_buffer{};
		size_t v_buffer_size = 0;

		Text(std::string value, Font* font, glm::vec2 pos, uint32_t flags);

		uint32_t get_alignment() const noexcept;
		float_t get_aspect_ratio() const noexcept;
		uint32_t get_display_height() const noexcept;
		uint32_t get_display_width() const noexcept;
		float_t get_line_gap() const noexcept;
		uint32_t get_text_size() const noexcept;

		void set_flag(uint32_t value, uint32_t mask) noexcept;
		void set_flags(uint32_t flags) noexcept;
		void set_value(std::string value) noexcept;

		void generate_mesh();
};

#endif // TEXT_TEXT_H
