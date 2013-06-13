#include "Controls/Anchor.h"
#include "Manager.h"
#include "math.h"

using namespace NGUI;
using namespace NGUI::Controls;

Anchor::Anchor(void):
	isDragged(false)
{}

void Anchor::onMouseMove(int mx, int my){
	if(isDragged){
		int dx = mx - start_mx_;
		int dy = my - start_my_;
		if(fabs(dx) > 3 || fabs(dy) > 3){
			parent_->translate(dx, dy);
			start_mx_ = mx;
			start_my_ = my;
		}
	}
}

bool Anchor::onMouseClick(unsigned char btn, bool isPressed, int mx, int my){
	bool retVal = isPointInside(mx, my);
	if(btn != NGUI_LBUTTON) return retVal;
	
	if(retVal && isPressed){
		isDragged = true;
		start_mx_ = mx;
		start_my_ = my;
	}
	else if(!isPressed && isDragged) isDragged = false;
	
	return retVal;
}