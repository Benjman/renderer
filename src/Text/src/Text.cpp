#include <Text/Text.h>
#include <Text/Font.h>

#include <utility>

namespace internal {
	void set_alignment(Text* text, uint32_t flags);
	void set_line_gap(Text* text, uint32_t flags);
	void set_size(Text* text, uint32_t flags);
}

Text::Text(std::string value, Font& font, glm::vec2 pos, uint32_t flags)
	: value(std::move(value)),
	  pos(pos) {
	set_flags(flags);
}

void Text::set_flags(uint32_t flags) noexcept {
	alignment = get_alignment_flags(flags);
	line_gap = get_line_gap_flags(flags);
	text_size = get_text_size_flags(flags);
}

u_char Text::get_alignment_flags(uint32_t flags) noexcept {
	return (u_char)((flags >> TEXT_ALIGN_SHIFT) & TEXT_ALIGN_MASK);
}

float_t Text::get_line_gap_flags(uint32_t flags) noexcept {
	auto line_gap = (flags >> LINE_GAP_SHIFT) & LINE_GAP_MASK;
	if (line_gap) {
		if (line_gap == ((LINE_GAP_1_0 >> LINE_GAP_SHIFT) & LINE_GAP_MASK)) {
			return 1.0;
		}
		if (line_gap == ((LINE_GAP_1_15 >> LINE_GAP_SHIFT) & LINE_GAP_MASK)) {
			return 1.15;
		}
		if (line_gap == ((LINE_GAP_1_5 >> LINE_GAP_SHIFT) & LINE_GAP_MASK)) {
			return 1.5;
		}
		if (line_gap == ((LINE_GAP_2_0 >> LINE_GAP_SHIFT) & LINE_GAP_MASK)) {
			return 2.0;
		}
	}
	return line_gap;
}

float_t Text::get_text_size_flags(uint32_t flags) noexcept {
	return (float_t)((flags >> TEXT_SIZE_SHIFT) & TEXT_SIZE_MASK);
}
