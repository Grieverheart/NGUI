#ifndef __NGUI_WINDOW_CONTROL_H
#define __NGUI_WINDOW_CONTROL_H

#include <vector>
#include "Controls/Base.h"

namespace NGUI{
	namespace Controls{
	
		class Window: public Controls::Base{
		public:
			~Window(void);
			void addControl(Controls::Base* control);
			bool onMouseMove(int mx, int my);
			std::vector<VisualPacket> getVisualPackets(void)const;
		private:
			std::vector<Controls::Base*> controls_;
		};
		
	}
}

#endif