#ifndef CORE_INPUTEVENTS_H
#define CORE_INPUTEVENTS_H

struct KeyDown final {
	inline KeyDown(int key_code) : keycode(key_code) {}
	int keycode = -1;
};

struct KeyUp final {
	inline KeyUp(int key_code) : keycode(key_code) {}
	int keycode = -1;
};


#endif // CORE_INPUTEVENTS_H
