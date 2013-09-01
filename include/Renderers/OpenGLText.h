#ifndef __TEXT_MANAGER_H
#define __TEXT_MANAGER_H

#include <map>
#include <cstdint>
#include <ft2build.h>
#include "visual.h"
#include "Renderers/shader.h"
#include FT_FREETYPE_H

namespace NGUI{
	namespace Renderers{
		class OpenGLText{
		public:
			OpenGLText(void);
			~OpenGLText(void);
			void renderText(const Text &text);
		private:
			GLuint loadGlyphTexture(FT_Face face, uint32_t character);
			void renderChar(void);
			
		private:
			struct Glyph{
				Glyph(void):
					tex_(0)
				{}
				FT_Glyph_Metrics metrics_;
				unsigned int tex_;
			};
			typedef std::map<uint32_t, Glyph> CharacterGlyphMap;
			struct Font{
				Font(void):
					face_(nullptr)
				{}
				FT_Face face_;
				CharacterGlyphMap charMap_;
			};
			std::map<std::string, Font> FontMap_;
			FT_Library ftLibrary_;
			Shader shader_;
		};
	}
}

#endif