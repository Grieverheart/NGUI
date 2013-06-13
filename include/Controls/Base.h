#ifndef __NGUI_BASE_CONTROL_H
#define __NGUI_BASE_CONTROL_H

#include "visual.h"
#include "Dim.h"
#include <vector>

namespace NGUI{
	namespace Controls{

		class Base{
		public:
			Base(void);
			virtual ~Base(void){};
			virtual void setSize(Dim x, Dim y);
			virtual void setPosition(Dim x, Dim y);
			virtual void translate(int x, int y);
			virtual void setTexture(const Texture& tex);
			void setParent(Controls::Base* parent);
			virtual std::vector<VisualPacket> getVisualPackets(void)const;
			virtual void onMouseMove(int mx, int my) = 0;
			virtual bool onMouseClick(unsigned char btn, bool isPressed, int mx, int my);
		protected:
			bool isPointInside(int x, int y)const;
			const Rect& getRect(void)const;
			int getPosX(void)const;
			int getAbsolutePosX(void)const;
			int getPosY(void)const;
			int getAbsolutePosY(void)const;
			int getWidth(void)const;
			int getHeight(void)const;
			VisualPacket getVisualPacket(void)const;
		private:
			Dim             posX_, posY_;
			Dim             width_, height_;
			Texture         tex_;
		protected:
			Controls::Base* parent_;
		};
		
	}
}

#endif