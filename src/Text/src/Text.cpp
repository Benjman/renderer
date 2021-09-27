#include <Text/Text.h>
#include <Text/Font.h>
#include <Text/internal/TextMeshGenerator.h>

#include <utility>
#include <limits>
#include <iostream>

namespace internal {
	void set_alignment(Text* text, uint32_t flags);
	void set_line_gap(Text* text, uint32_t flags);
	void set_size(Text* text, uint32_t flags);
}

Text::Text(std::string value, Font* font, glm::vec2 pos, uint32_t flags) :
	Text(value, font, pos, std::numeric_limits<float_t>::max(), flags) {
}

Text::Text(std::string value, Font* font, glm::vec2 pos, float_t max_width, uint32_t flags) :
	value(std::move(value)),
	pos(pos),
	font(font),
	max_width(max_width),
	flags(flags)
{
}

void Text::set_value(std::string value) noexcept {
	this->value = std::move(value);
	internal::generate_text_mesh(this);
}

void Text::set_flag(uint32_t value, uint32_t mask) noexcept {
	// clear old value
	flags = ~(flags & mask) & flags;

	// add new value
	flags |= value;
}

void Text::set_flags(uint32_t flags) noexcept {
	this->flags = flags;
}

uint32_t Text::get_alignment() const noexcept {
	return (uint32_t)(flags & TEXT_ALIGN_MASK);
}

float_t Text::get_aspect_ratio() const noexcept {
	auto display_profile = flags & DISPLAY_PROFILE_MASK;
	if (display_profile == DISPLAY_PROFILE_1280_720
		|| display_profile == DISPLAY_PROFILE_1920_1080
		|| display_profile == DISPLAY_PROFILE_2560_1440
		|| display_profile == DISPLAY_PROFILE_7680_4320) {
		return 1.777777778;
	} else if (display_profile == DISPLAY_PROFILE_640_480) {
		return 1.333333333;
	} else if (display_profile == DISPLAY_PROFILE_2048_1080) {
		return 0.564971751;
	} else if (display_profile == DISPLAY_PROFILE_3840_2160) {
		return 0.526315789;
	} else {
		return 1.0;
	}
}

float_t Text::get_line_gap() const noexcept {
	auto line_gap = flags & LINE_GAP_MASK;
	if (line_gap == LINE_GAP_1_0) {
		return 1.0;
	} else if (line_gap == LINE_GAP_1_15) {
		return 1.15;
	} else if (line_gap == LINE_GAP_1_5) {
		return 1.5;
	} else if (line_gap == LINE_GAP_2_0) {
		return 2.0;
	} else {
		return 0.0;
	}
}

uint32_t Text::get_text_size() const noexcept {
	return (size_t)(flags & TEXT_SIZE_MASK) >> TEXT_SIZE_SHIFT;
}

uint32_t Text::get_display_width() const noexcept {
	auto display_profile = flags & DISPLAY_PROFILE_MASK;
	if (display_profile == DISPLAY_PROFILE_640_480) {
		return 640;
	}
	if (display_profile == DISPLAY_PROFILE_1280_720) {
		return 1280;
	}
	if (display_profile == DISPLAY_PROFILE_1920_1080) {
		return 1920;
	}
	if (display_profile == DISPLAY_PROFILE_2560_1440) {
		return 2560;
	}
	if (display_profile == DISPLAY_PROFILE_2048_1080) {
		return 2048;
	}
	if (display_profile == DISPLAY_PROFILE_3840_2160) {
		return 3840;
	}
	if (display_profile == DISPLAY_PROFILE_7680_4320) {
		return 7680;
	}
	return 0;
}

uint32_t Text::get_display_height() const noexcept {
	auto display_profile = flags & DISPLAY_PROFILE_MASK;
	if (display_profile == DISPLAY_PROFILE_640_480) {
		return 480;
	}
	if (display_profile == DISPLAY_PROFILE_1280_720) {
		return 720;
	}
	if (display_profile == DISPLAY_PROFILE_1920_1080) {
		return 1080;
	}
	if (display_profile == DISPLAY_PROFILE_2560_1440) {
		return 1440;
	}
	if (display_profile == DISPLAY_PROFILE_2048_1080) {
		return 1080;
	}
	if (display_profile == DISPLAY_PROFILE_3840_2160) {
		return 2160;
	}
	if (display_profile == DISPLAY_PROFILE_7680_4320) {
		return 4320;
	}
	return 0;
}

void Text::generate_mesh() {
	internal::generate_text_mesh(this);
}
