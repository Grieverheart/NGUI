#ifndef __NGUI_OGLRENDERER_H
#define __NGUI_OGLRENDERER_H

#include "Renderers/Base.h"
#include "Renderers/OpenGLText.h"

class Shader;

namespace NGUI{
	namespace Renderers{

		class OpenGL: public Renderers::Base{
		public:
			~OpenGL(void);
			void init(void);
			void resize(int w, int h);
			void drawVisualPackets(const std::vector<VisualPacket>& vipackets);
		private:
			unsigned int vao_;
			unsigned int vbo_;
			
			int width_, height_;
			
			Shader *shader_;
			
			OpenGLText textRenderer_;
		};
		
	}
}

#endif