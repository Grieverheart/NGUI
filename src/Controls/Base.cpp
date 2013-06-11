#include "Controls/Base.h"

using namespace NGUI;
using namespace NGUI::Controls;

Base::Base(void):
	posX_(0), posY_(0),
	width_(1), height_(1),
	tex_(nullptr),
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

void Base::setTexture(const Texture& tex){
	tex_ = tex;
}

void Base::setParent(Base* parent){
	parent_ = parent;
}

//TODO: Cache Position and Size and refresh when parent is resized

int Base::getPosX(void)const{
	if(parent_) return (int)(posX_.pct * parent_->getWidth()) + posX_.px;
	else return posX_.px;
}

int Base::getPosY(void)const{
	if(parent_) return (int)(posY_.pct * parent_->getHeight()) + posY_.px;
	else return posY_.px;
}

int Base::getAbsolutePosX(void)const{
	if(parent_) return (int)(posX_.pct * parent_->getWidth()) + posX_.px + parent_->getAbsolutePosX();
	else return posX_.px;
}

int Base::getAbsolutePosY(void)const{
	if(parent_) return (int)(posY_.pct * parent_->getHeight()) + posY_.px + parent_->getAbsolutePosY();
	else return posY_.px;
}

int Base::getWidth(void)const{
	if(parent_) return (int)(width_.pct * parent_->getWidth()) + width_.px;
	else return width_.px;
}

int Base::getHeight(void)const{
	if(parent_) return (int)(height_.pct * parent_->getHeight()) + height_.px;
	else return height_.px;
}

VisualPacket Base::getVisualPacket(void)const{
	Rect rect(getWidth(), getHeight(), getAbsolutePosX(), getAbsolutePosY());
	return VisualPacket(rect, tex_);
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