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
		void addControl(Controls::Base* control);
		void render(void)const;
		void mouseMotionEvent(int x, int y);
		bool mouseLeftClickEvent(bool isPressed, int x, int y);
		bool mouseRightClickEvent(bool isPressed, int x, int y);
	private:
		Renderers::Base* renderer_;
		std::vector<Controls::Base*> controls_;
	};

}

#endif