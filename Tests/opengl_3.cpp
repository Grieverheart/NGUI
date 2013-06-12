#include "opengl_3.h"
#include "../include/Controls/WindowControl.h"
#include "../include/Renderers/OpenGL.h"
#include <GL/freeglut.h>
#include <iostream>

OpenGLContext::OpenGLContext(void){
	/////////////////////////////////////////////////
	// Default Constructor for OpenGLContext class //
	/////////////////////////////////////////////////
	redisplay = false;
}

OpenGLContext::~OpenGLContext(void){
	delete gui_manager_;
	delete tex_manager_;
	if(texData_) delete texData_;
}  

bool OpenGLContext::create30Context(void){
	////////////////////////////////////////////////////
	// Create an OpenGL 3.2 context. Fall back to a   //
	// OpenGL 2.1 Context if it fails.				  //
	////////////////////////////////////////////////////
	
	glutInitContextVersion(3, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_ALPHA);
	glutInitWindowSize(600,600);
	windowWidth=windowHeight = 600;
	// glutInitWindowPosition(100,100);
	glutCreateWindow("SimpleGUI Test");
	
	glewExperimental = GL_TRUE;
	/*GLenum error = */glewInit(); //Enable GLEW
	
	int glVersion[2] = {-1,1};
	glGetIntegerv(GL_MAJOR_VERSION, &glVersion[0]);
	glGetIntegerv(GL_MINOR_VERSION, &glVersion[1]);
	
	std::cout << "Using OpenGL: " << glVersion[0] << "." << glVersion[1] << std::endl;
	std::cout << "Renderer used: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "Shading Language: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
	
	return true; // Success, return true
}

void OpenGLContext::setupScene(int argc, char *argv[]){
	tex_manager_ = new TextureManager();
	NGUI::Renderers::OpenGL *gui_renderer_ = new NGUI::Renderers::OpenGL();
	gui_manager_ = new NGUI::Manager(gui_renderer_);
	NGUI::Controls::Window *window = new NGUI::Controls::Window();
	NGUI::Controls::Window *window2 = new NGUI::Controls::Window();
	window->setSize(250, 150);
	window->setPosition(20, 20);
	texData_ = new GLuint(tex_manager_->load("bg.png"));
	NGUI::Texture tex(texData_);
	window->setTexture(tex);
	
	window2->setSize(60, 60);
	window2->setPosition(0, 0);
	window2->setTexture(tex);
	
	window->addControl(window2);
	
	gui_manager_->addControl(window);
	glClearColor(0.1f, 0.6f, 0.8f, 0.0f);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void OpenGLContext::reshapeWindow(int w, int h){
	windowWidth = w;
	windowHeight = h;
	glViewport(0, 0, windowWidth, windowHeight);
	gui_manager_->setSize(w, h);
}

void OpenGLContext::processScene(void){
	static float last_time = 0.0;
	float this_time = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
	if(this_time-last_time > 1.0f / 61.0f){
		last_time = this_time;
	}
}

void OpenGLContext::drawPass(void)const{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gui_manager_->render();
}

void OpenGLContext::renderScene(void){	
	drawPass();
	glutSwapBuffers();
}