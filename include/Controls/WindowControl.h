#ifndef __NGUI_WINDOW_CONTROL_H
#define __NGUI_WINDOW_CONTROL_H

#include <vector>
#include "Controls/Base.h"

namespace NGUI{
	namespace Controls{
	
		class Window: public Controls::Base{
		public:
			Window(void);
			~Window(void);
			void addControl(Controls::Base* control);
			void onMouseMove(int mx, int my);
			bool onMouseClick(unsigned char btn, bool isDown);
			std::vector<VisualPacket> getVisualPackets(void)const;
		private:
			bool isMouseOver_;
			std::vector<Controls::Base*> controls_;
		};
		
	}
}

#endif