#include "Controls/Anchor.h"
#include "Manager.h"
#include "math.h"

using namespace NGUI;
using namespace NGUI::Controls;

Anchor::Anchor(void):
	isDragged_(false),
	isMouseOver_(false)
{
	hide();
}

void Anchor::onMouseMove(int mx, int my){
	isMouseOver_ = isPointInside(mx, my);
	if(isMouseOver_){
		show();
		start_mx_ = mx;
		start_my_ = my;
	}
	else if(!isDragged_) hide();
	else{
		int dx = mx - start_mx_;
		int dy = my - start_my_;
		if(fabs(dx) > 3 || fabs(dy) > 3){
			parent_->translate(dx, dy);
			start_mx_ = mx;
			start_my_ = my;
		}
	}
}

bool Anchor::onMouseClick(unsigned char btn, bool isDown){
	if(btn != NGUI_LBUTTON) return isMouseOver_;
	
	if(isMouseOver_ && isDown) isDragged_ = true;
	else if(!isDown && isDragged_) isDragged_ = false;
	
	return isMouseOver_;
}