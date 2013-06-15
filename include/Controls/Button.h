#ifndef __NGUI_BUTTON_H
#define __NGUI_BUTTON_H

#include "Controls/Base.h"

namespace NGUI{
	namespace Controls{
	
		class Button: public Controls::Base{
		public:
			Button(void);
			void onMouseMove(int mx, int my);
			bool onMouseClick(unsigned char btn, bool isDown);
			void setPressedTexture(const Texture& tex);
		private:
			bool isPressed_;
			bool isMouseOver_;
			Texture pressedTex_;
			Texture defaultTex_;
		};
		
	}
}

#endif