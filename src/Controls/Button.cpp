#include "Controls/Button.h"
#include "Manager.h"
#include "math.h"

using namespace NGUI;
using namespace NGUI::Controls;

Button::Button(void):
	isPressed_(false),
	pressedTex_(0),
	defaultTex_(0)
{}

void Button::setPressedTexture(const Texture& tex){
	pressedTex_ = tex;
}

void Button::onMouseMove(int mx, int my){
	isMouseOver_ = isPointInside(mx, my);
	if(isPressed_){
		if(!isMouseOver_) setTexture(defaultTex_);
		else setTexture(pressedTex_);
	}
}

bool Button::onMouseClick(unsigned char btn, bool isDown){
	if(!defaultTex_.index_) defaultTex_ = getActiveTexture();
	
	if(btn != NGUI_LBUTTON) return isMouseOver_;
	
	if(isMouseOver_ && isDown){
		isPressed_ = true;
		setTexture(pressedTex_);
	}
	else if(!isDown && isPressed_){
		isPressed_ = false;
		setTexture(defaultTex_);
	}
	
	return isMouseOver_;
}