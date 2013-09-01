#include "Controls/Base.h"

using namespace NGUI;
using namespace NGUI::Controls;

Base::Base(void):
	posX_(0), posY_(0),
	width_(1), height_(1),
	tex_(0),
	isHidden_(false),
	parent_(nullptr)
{}
	
void Base::setSize(Dim sx, Dim sy){
	width_  = sx;
	height_ = sy;
}

void Base::setPosition(Dim x, Dim y){
	posX_ = x;
	posY_ = y;
}

void Base::translate(int x, int y){
	posX_.px += x;
	posY_.px += y;
}

void Base::resize(int x, int y){
	width_.px  += x;
	height_.px += y;
}

void Base::setTexture(const Texture& tex){
	tex_ = tex;
}

void Base::setText(std::string text){
	text_ = text;
}

void Base::setTextProperties(const NGUI::TextProperties& textProperties){
	textProperties_ = textProperties;
}

void Base::setParent(Base* parent){
	parent_ = parent;
}

void Base::show(void){
	isHidden_ = false;
}

void Base::hide(void){
	isHidden_ = true;
}

bool Base::isHidden(void){
	return isHidden_;
}

void Base::onMouseMove(int mx, int my){
}

bool Base::onMouseClick(unsigned char btn, bool isDown){
	return false;
}

//TODO: Cache Position and Size and refresh when parent is resized

int Base::getPosX(void)const{
	if(parent_) return posX_.getAbsolute(parent_->getWidth());
	else return posX_.px;
}

int Base::getPosY(void)const{
	if(parent_) return posY_.getAbsolute(parent_->getHeight());
	else return posY_.px;
}

int Base::getAbsolutePosX(void)const{
	if(parent_) return posX_.getAbsolute(parent_->getWidth(), parent_->getAbsolutePosX());
	else return posX_.px;
}

int Base::getAbsolutePosY(void)const{
	if(parent_) return posY_.getAbsolute(parent_->getHeight(), parent_->getAbsolutePosY());
	else return posY_.px;
}

int Base::getWidth(void)const{
	if(parent_) return width_.getAbsolute(parent_->getWidth());
	else return width_.px;
}

int Base::getHeight(void)const{
	if(parent_) return height_.getAbsolute(parent_->getHeight());
	else return height_.px;
}

const Texture& Base::getActiveTexture(void)const{
	return tex_;
}

VisualPacket Base::getVisualPacket(void)const{
	int x = getAbsolutePosX(), y = getAbsolutePosY();
	int w = getWidth(), h = getHeight();
	Rect rect(getWidth(), getHeight(), x, y);
	
	x = textProperties_.x_.getAbsolute(w, x);
	y = textProperties_.y_.getAbsolute(h, y);
	Text text(text_, textProperties_.font_, textProperties_.width_, x, y);
	
	return VisualPacket(rect, tex_, text);
}

std::vector<VisualPacket> Base::getVisualPackets(void)const{
	return std::vector<VisualPacket>(1, getVisualPacket());
}

bool Base::isPointInside(int x, int y)const{
	int posX = getAbsolutePosX();
	int posY = getAbsolutePosY();
	int width = getWidth();
	int height = getHeight();
	return (x > posX && x < (posX + width) &&
			y > posY && y < (posY + height));
}