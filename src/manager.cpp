#include "manager.h"
#include "visual.h"
#include "Controls/Base.h"
#include "Renderers/Base.h"

using namespace NGUI;

Manager::Manager(Renderers::Base* renderer):
	renderer_(renderer),
	width_(1), height_(1)
{
	renderer_->init();
}

Manager::~Manager(void){
	for(auto control: controls_) delete control;
	delete renderer_;
}

void Manager::setSize(int w, int h){
	width_  = w;
	height_ = h;
	renderer_->resize(w, h);
}

void Manager::addControl(Controls::Base* control){
	controls_.push_back(control);
}

void Manager::render(void)const{
	for(auto control: controls_){
		if(control->isHidden()) continue;
		std::vector<VisualPacket> packets = control->getVisualPackets();
		renderer_->drawVisualPackets(packets);
	}
}

void Manager::mouseMotionEvent(int x, int y){
	for(auto control: controls_) control->onMouseMove(x, y);
}

bool Manager::mouseClickEvent(unsigned char btn, bool isPressed){
	for(auto ctrl_itr = controls_.begin(); ctrl_itr < controls_.end(); ctrl_itr++){
		if((*ctrl_itr)->onMouseClick(btn, isPressed)){
			Controls::Base* temp = *ctrl_itr;
			controls_.erase(ctrl_itr);
			controls_.push_back(temp);
			return true;
		}
	}
	return false;
}
