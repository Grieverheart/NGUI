#include "Controls/WindowControl.h"
#include <iostream>

using namespace NGUI;
using namespace NGUI::Controls;

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
		for(auto packet: control->getVisualPackets()) packets.push_back(packet);
	}
	return packets;
}

void Window::onMouseMove(int mx, int my){
	static bool isMouseInside = false;
	if(isPointInside(mx, my)){
		if(!isMouseInside) std::cout << "Mouse entered " << mx << ", " << my << std::endl;
		isMouseInside = true;
	}
	else if(isMouseInside){
		std::cout << "Mouse left " << mx << ", " << my << std::endl;
		isMouseInside = false;
	}
}