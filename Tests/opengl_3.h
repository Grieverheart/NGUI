#ifndef __OPENGL_3_H
#define __OPENGL_3_H

#include "texture.h"
#include "../include/manager.h"
#include <glm/glm.hpp>

namespace NGUI{namespace Renderers{class OpenGL;}}

class OpenGLContext{
public:
	OpenGLContext(void); 				// Default constructor  
	~OpenGLContext(void); 				// Destructor for cleaning up our application  
	bool create30Context(void); 	// Creation of our OpenGL 3.x context  
	void setupScene(int argc, char *argv[]); 				// All scene information can be setup here  
	void reshapeWindow(int w, int h); 	// Method to get our window width and height on resize  
	void renderScene(void); 			// Render scene (display method from previous OpenGL tutorials)
	void processScene(void);
	
	bool redisplay;
	
	NGUI::Manager           *gui_manager_;
	
private:
	NGUI::Renderers::OpenGL *gui_renderer_;
	TextureManager          *tex_manager_;
	GLuint                  *texData_;
	
	int windowWidth;	//Store the width of the window
	int windowHeight;	//Store the height of the window
	
	void drawPass(void)const;
};


#endif