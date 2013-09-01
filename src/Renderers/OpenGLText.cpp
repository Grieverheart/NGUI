#include "Renderers/OpenGLText.h"

using namespace NGUI;
using namespace NGUI::Renderers;

OpenGLText::OpenGLText(void){
	FT_Init_FreeType(&ftLibrary_);
}

OpenGLText::~OpenGLText(void){
}

GLuint OpenGLText::loadGlyphTexture(FT_Face face, uint32_t character){
	FT_Load_Char(face, character, FT_LOAD_RENDER);
	const FT_Bitmap &bitmap = face->glyph->bitmap; 
	
	GLuint texobj;
	glGenTextures(1, &texobj);
	glBindTexture(GL_TEXTURE_2D, texobj);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, bitmap.width, bitmap.rows, 0, GL_ALPHA, GL_UNSIGNED_BYTE, bitmap.buffer);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	return texobj;
}

void OpenGLText::renderChar(void){
}

void OpenGLText::renderText(const Text &text){
	Font& font = FontMap_[text.font_];
	//Face doesn't exist yet. We have to create it
	if(!font.face_){
		FT_New_Face(ftLibrary_, text.font_.c_str(), 0, &font.face_);
		FT_Set_Pixel_Sizes(font.face_, 0, 48); //Pre-set width
	}
	
	for(auto character: text.text_){
		Glyph& glyph = font.charMap_[character];
		//Glyph was not previously loaded. We need to do this now
		if(!glyph.tex_) glyph.tex_ = loadGlyphTexture(font.face_, character);
		
		renderChar();
	}
}