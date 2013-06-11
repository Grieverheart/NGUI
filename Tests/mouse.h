#ifndef __CMOUSE_H
#define __CMOUSE_H
#include "opengl_3.h"

class CMouse{
public:
	CMouse(OpenGLContext *context);
	~CMouse(void);
	
	void onMouse(int button, int state, int x, int y);
	void onMotion(int x, int y);
	void onPassiveMotion(int x, int y);
private:
	OpenGLContext *context;
	int last_mx,last_my,cur_mx,cur_my;
	bool dragging;
	int windowWidth;
	int windowHeight;
};
#endif