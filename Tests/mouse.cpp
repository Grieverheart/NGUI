#include "mouse.h"
#include <GL/freeglut.h>


CMouse::CMouse(OpenGLContext *context){
	this->context = context;
	last_mx=last_my=cur_mx=cur_my=0;
	dragging=false;
}

CMouse::~CMouse(void){
}

void CMouse::onMouse(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON){
		if(state == GLUT_DOWN){
			dragging = true;
			cur_mx   = x;
			last_mx  = cur_mx;
			cur_my   = y;
			last_my  = cur_my;
		}
		else if(dragging){
			dragging = false;
			if(last_mx == x && last_my == y){
			//Regular Clicking goes here//
			}
			last_mx = cur_mx;
			last_my = cur_my;
		}
	}
}

void CMouse::onMotion(int x, int y){
	context->gui_manager_->mouseMotionEvent(x, y);
	if(dragging){
		cur_mx=x;
		cur_my=y;
	}
}

void CMouse::onPassiveMotion(int x, int y){
	context->gui_manager_->mouseMotionEvent(x, y);
}