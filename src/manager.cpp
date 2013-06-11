#include "manager.h"
#include "visual.h"
#include "Controls/Base.h"
#include "Renderers/Base.h"

using namespace NGUI;

Manager::Manager(Renderers::Base* renderer):
	renderer_(renderer)
{}

Manager::~Manager(void){
	for(auto control: controls_) delete control;
}

void Manager::addControl(Controls::Base* control){
	controls_.push_back(control);
}

void Manager::render(void)const{
	for(auto control: controls_){
		std::vector<VisualPacket> packets = control->getVisualPackets();
		renderer_->drawVisualPackets(packets);
	}
}

void Manager::mouseMotionEvent(int x, int y){
	for(auto control: controls_){
		control->onMouseMove(x, y);
	}
}

bool Manager::mouseLeftClickEvent(bool isPressed, int x, int y){
	bool controlClicked = false;
	for(auto control: controls_){
		controlClicked = control->onMouseMove(x, y);
	}
	return controlClicked;
}

bool Manager::mouseRightClickEvent(bool isPressed, int x, int y){
	bool controlClicked = false;
	for(auto control: controls_){
		controlClicked = control->onMouseMove(x, y);
	}
	return controlClicked;
}