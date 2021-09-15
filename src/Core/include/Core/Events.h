#ifndef CORE_EVENTS_H
#define CORE_EVENTS_H

struct KeyDown final {
	inline KeyDown(int key_code) : keycode(key_code) {}
	int keycode = -1;
};

struct KeyUp final {
	inline KeyUp(int key_code) : keycode(key_code) {}
	int keycode = -1;
};

struct ViewportSizeChange final {
	inline ViewportSizeChange(int width, int height) : width(width), height(height) {}
	int width;
	int height;
};


#endif // CORE_EVENTS_H
