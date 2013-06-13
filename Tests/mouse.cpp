#include "mouse.h"
#include <GL/freeglut.h>


CMouse::CMouse(OpenGLContext *context){
	this->context = context;
}

CMouse::~CMouse(void){
}

void CMouse::onMouse(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON){
		if(state == GLUT_DOWN) context->gui_manager_->mouseClickEvent(0, true);
		else context->gui_manager_->mouseClickEvent(0, false);
	}
}

void CMouse::onMotion(int x, int y){
	context->gui_manager_->mouseMotionEvent(x, y);
}

void CMouse::onPassiveMotion(int x, int y){
	context->gui_manager_->mouseMotionEvent(x, y);
}