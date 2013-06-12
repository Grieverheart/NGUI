#ifndef __NGUI_BASE_RENDERER_H
#define __NGUI_BASE_RENDERER_H

#include "visual.h"
#include <vector>

namespace NGUI{
	namespace Renderers{
	
		class Base{
		public:
			virtual ~Base(void){};
			virtual void init(void) = 0;
			virtual void resize(int w, int h) = 0;
			virtual void drawVisualPackets(const std::vector<VisualPacket>& vipackets) = 0;
			// void setResolution(int w, int h);
			// glm::vec2 getResolution(void)const;
		};
		
	}
}

#endif