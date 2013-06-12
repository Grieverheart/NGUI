#ifndef __NGUI_MANAGER_H
#define __NGUI_MANAGER_H

#include <vector>

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