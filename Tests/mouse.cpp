#include "mouse.h"
#include <GL/freeglut.h>


CMouse::CMouse(void):
	gui_manager_(nullptr)
{}

CMouse::~CMouse(void){
}

void CMouse::init(NGUI::Manager* gui_manager){
	gui_manager_ = gui_manager;
}

void CMouse::onMouse(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON){
		if(state == GLUT_DOWN) gui_manager_->mouseClickEvent(0, true);
		else gui_manager_->mouseClickEvent(0, false);
	}
}

void CMouse::onMotion(int x, int y){
	gui_manager_->mouseMotionEvent(x, y);
}

void CMouse::onPassiveMotion(int x, int y){
	gui_manager_->mouseMotionEvent(x, y);
}