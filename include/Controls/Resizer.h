#ifndef __NGUI_RESIZER_H
#define __NGUI_RESIZER_H

#include "Controls/Base.h"

namespace NGUI{
	namespace Controls{
	
		class Resizer: public Controls::Base{
		public:
			Resizer(void);
			void onMouseMove(int mx, int my);
			bool onMouseClick(unsigned char btn, bool isDown);
		private:
			bool isDragged_;
			bool isMouseOver_;
			int start_mx_, start_my_;
		};
		
	}
}

#endif