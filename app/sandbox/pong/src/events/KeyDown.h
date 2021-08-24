#ifndef PONG_KEYDOWN_H
#define PONG_KEYDOWN_H

struct KeyDown final {
	inline KeyDown(int key_code) : keycode(key_code) {}
	int keycode = -1;
};

#endif // PONG_KEYDOWN_H
