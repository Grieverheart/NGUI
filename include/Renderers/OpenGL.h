#ifndef __NGUI_OGLRENDERER_H
#define __NGUI_OGLRENDERER_H

#include "Renderers/Base.h"

class Shader;

namespace NGUI{
	namespace Renderers{

		class OpenGL: public Renderers::Base{
		public:
			~OpenGL(void);
			void init(void);
			void drawVisualPackets(const std::vector<VisualPacket>& vipackets);
		private:
			unsigned int vao_;
			unsigned int vbo_;
			Shader *shader_;
		};
		
	}
}

#endif