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
			
			void setSize(Dim x, Dim y);
			void setPosition(Dim x, Dim y);
			void translate(int x, int y);
			void resize(int x, int y);
			void setTexture(const Texture& tex);
			void setParent(Controls::Base* parent);
			void show(void);
			void hide(void);
			bool isHidden(void);
			
			virtual std::vector<VisualPacket> getVisualPackets(void)const;
			virtual void onMouseMove(int mx, int my);
			virtual bool onMouseClick(unsigned char btn, bool isDown);
		
		protected:
			bool isPointInside(int x, int y)const;
			const Rect& getRect(void)const;
			int getPosX(void)const;
			int getAbsolutePosX(void)const;
			int getPosY(void)const;
			int getAbsolutePosY(void)const;
			int getWidth(void)const;
			int getHeight(void)const;
			const Texture& getActiveTexture(void)const;
			VisualPacket getVisualPacket(void)const;
		
		private:
			Dim     posX_, posY_;
			Dim     width_, height_;
			Texture tex_;
			bool    isHidden_;
		
		protected:
			Controls::Base* parent_;
		};
		
	}
}

#endif