#ifndef KEYBOARD_H
#define KEYBOARD_H

class CKeyboard{
public:
	CKeyboard(void);
	~CKeyboard(void);
	void keyOps(void);
	void keySpOps(void);
	void keyIsDown(int key);
	void keyIsUp(int key);
	void keySpIsDown(int key);
	void keySpIsUp(int key);
private:
	bool keyMap[256];
	bool keySpMap[256];
	bool keyRepeat;
	bool fullscreen;
};

extern bool exitLoop;
#endif