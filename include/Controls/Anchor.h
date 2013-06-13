#ifndef __NGUI_ANCHOR_H
#define __NGUI_ANCHOR_H

#include "Controls/Base.h"

namespace NGUI{
	namespace Controls{
	
		class Anchor: public Controls::Base{
		public:
			Anchor(void);
			void onMouseMove(int mx, int my);
			bool onMouseClick(unsigned char btn, bool isPressed, int mx, int my);
		private:
			bool isDragged;
			int start_mx_, start_my_;
		};
		
	}
}

#endif