#ifndef __NGUI_MANAGER_H
#define __NGUI_MANAGER_H

#include <vector>

#define NGUI_LBUTTON	0
#define NGUI_MBUTTON	1
#define NGUI_RBUTTON	2
#define NGUI_XBUTTON1	3
#define NGUI_XBUTTON2	4

namespace NGUI{
	namespace Controls{
		class Base;
	}

	namespace Renderers{
		class Base;
	}
	
	class Manager{
	public:
		explicit Manager(Renderers::Base* renderer);
		~Manager(void);
		void setSize(int w, int h);
		void addControl(Controls::Base* control);
		void render(void)const;
		void mouseMotionEvent(int x, int y);
		bool mouseClickEvent(unsigned char btn, bool isPressed);
	private:
		Renderers::Base* renderer_;
		std::vector<Controls::Base*> controls_;
		int mx_, my_;
		int width_, height_;
	};

}

#endif