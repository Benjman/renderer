#ifndef PONG_KEYUP_H
#define PONG_KEYUP_H

struct KeyUp final {
	inline KeyUp(int key_code) : keycode(key_code) {}
	int keycode = -1;
};

#endif // PONG_KEYUP_H
