#include "Controls/WindowControl.h"
#include <iostream>

using namespace NGUI;
using namespace NGUI::Controls;


Window::Window(void):
	isMouseOver_(false)
{}

Window::~Window(void){
	for(auto control: controls_) delete control;
}

void Window::addControl(Controls::Base* control){
	control->setParent(this);
	controls_.push_back(control);
}

std::vector<VisualPacket> Window::getVisualPackets(void)const{
	std::vector<VisualPacket> packets;
	packets.push_back(getVisualPacket());
	for(auto control: controls_){
		if(control->isHidden()) continue;
		for(auto packet: control->getVisualPackets()) packets.push_back(packet);
	}
	return packets;
}

void Window::onMouseMove(int mx, int my){
	isMouseOver_ = isPointInside(mx, my);
	for(auto control: controls_) control->onMouseMove(mx, my);
}

bool Window::onMouseClick(unsigned char btn, bool isDown){
	bool retVal = isMouseOver_;
	for(auto control: controls_){
		if(control->onMouseClick(btn, isDown)){
			retVal = true;
			break;
		}
	}
	return retVal;
}