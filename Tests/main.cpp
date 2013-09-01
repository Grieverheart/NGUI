#include <iostream>
#include <glm/glm.hpp>
#include "texture.h"
#include <GL/freeglut.h>
#include "keyboard.h"
#include "mouse.h"
#include "../include/manager.h"
#include "../include/Controls/WindowControl.h"
#include "../include/Controls/Anchor.h"
#include "../include/Controls/Resizer.h"
#include "../include/Controls/Button.h"
#include "../include/Renderers/OpenGL.h"

bool exitLoop = false;

namespace{

	NGUI::Manager* gui_manager_;
	TextureManager* tex_manager_;
	CKeyboard keyboard;
	CMouse mouse;
	std::vector<GLuint*> texData_;

	////////////GLUT Keyboard Function Wrappers/////////////
	void keyDown(unsigned char key, int x, int y){
		keyboard.keyIsDown(key);
		keyboard.keyOps();
	}

	void keyUp(unsigned char key, int x, int y){
		keyboard.keyIsUp(key);
	}

	void specialDown(int key, int x, int y){
		keyboard.keySpIsDown(key);
		keyboard.keySpOps();
	}

	void specialUp(int key, int x, int y){
		keyboard.keySpIsUp(key);
	}

	//////////////GLUT Mouse Function Wrappers////////////////

	void onMouse(int button, int state, int x, int y){
		mouse.onMouse(button,state,x,y);
	}

	void onMotion(int x, int y){
		mouse.onMotion(x,y);
	}

	void onPassiveMotion(int x, int y){
		mouse.onPassiveMotion(x, y);
	}
	//////////////////////////////////////////////////////////

	void display(void){
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		gui_manager_->render();
		glutSwapBuffers();
	}

	void idle(void){
		if(exitLoop){
			delete gui_manager_;
			delete tex_manager_;
			for(auto tex_data: texData_) if(tex_data) delete tex_data;
			glutLeaveMainLoop();
		}
		float last_time = 0.0;
		float this_time = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
		if(this_time-last_time > 1.0f / 61.0f){
			last_time = this_time;
			glutPostRedisplay();
		}
	}

	void reshape(int width, int height){
		glViewport(0, 0, width, height);
		gui_manager_->setSize(width, height);
	}

	void createContext(void){
		////////////////////////////////////////////////////
		// Create an OpenGL 3.2 context. Fall back to a   //
		// OpenGL 2.1 Context if it fails.				  //
		////////////////////////////////////////////////////
		
		glutInitContextVersion(3, 3);
		glutInitContextProfile(GLUT_CORE_PROFILE);
		
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_ALPHA);
		glutInitWindowSize(600, 600);
		glutCreateWindow("SimpleGUI Test");
		
		glewExperimental = GL_TRUE;
		/*GLenum error = */glewInit(); //Enable GLEW
		
		int glVersion[2] = {-1,1};
		glGetIntegerv(GL_MAJOR_VERSION, &glVersion[0]);
		glGetIntegerv(GL_MINOR_VERSION, &glVersion[1]);
		
		std::cout << "Using OpenGL: " << glVersion[0] << "." << glVersion[1] << std::endl;
		std::cout << "Renderer used: " << glGetString(GL_RENDERER) << std::endl;
		std::cout << "Shading Language: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
	}

	void setupScene(void){
		tex_manager_ = new TextureManager();
		NGUI::Renderers::OpenGL *gui_renderer_ = new NGUI::Renderers::OpenGL();
		gui_manager_ = new NGUI::Manager(gui_renderer_);
		mouse.init(gui_manager_);
		
		NGUI::Controls::Window  *window  = new NGUI::Controls::Window();
		NGUI::Controls::Anchor  *anchor  = new NGUI::Controls::Anchor();
		NGUI::Controls::Base    *panel   = new NGUI::Controls::Base();
		NGUI::Controls::Base    *panel2  = new NGUI::Controls::Base();
		NGUI::Controls::Resizer *resizer = new NGUI::Controls::Resizer();
		NGUI::Controls::Button  *button  = new NGUI::Controls::Button();
		
		window->setSize(250, 150);
		window->setPosition(20, 20);
		GLuint texData = tex_manager_->load("window.png");
		window->setTexture(NGUI::Texture(texData));
		
		window->addControl(anchor);
		anchor->setSize(25, 25);
		anchor->setPosition(-20, -20);
		texData = tex_manager_->load("anchor.png");
		anchor->setTexture(NGUI::Texture(texData));
		
		window->addControl(resizer);
		resizer->setSize(25, 25);
		resizer->setPosition(NGUI::Dim(-28, 1.0f), NGUI::Dim(-28, 1.0f));
		texData = tex_manager_->load("resizer.png");
		resizer->setTexture(NGUI::Texture(texData));
		
		window->addControl(panel);
		panel->setSize(NGUI::Dim(0, 1.0f), 5);
		panel->setPosition(0, NGUI::Dim(25, 0.0f));
		texData = tex_manager_->load("shadow.png");
		panel->setTexture(NGUI::Texture(texData));
		
		window->addControl(panel2);
		panel2->setSize(NGUI::Dim(0, 1.0f), 25);
		texData = tex_manager_->load("linen_solarized.png");
		panel2->setTexture(NGUI::Texture(texData));
		panel2->setText("Hello World");
		NGUI::TextProperties textProp;
		textProp.font_  = "C:/Windows/Fonts/consola.ttf";
		textProp.width_ = 24;
		textProp.x_ = NGUI::Dim(10, 0.0f);
		textProp.y_ = NGUI::Dim(-5, 1.0f);
		panel2->setTextProperties(textProp);
		
		window->addControl(button);
		button->setSize(100, 50);
		button->setPosition(NGUI::Dim(-50, 0.5f), NGUI::Dim(-25, 0.5f));
		texData = tex_manager_->load("button.png");
		button->setTexture(NGUI::Texture(texData));
		texData = tex_manager_->load("button-down.png");
		button->setPressedTexture(NGUI::Texture(texData));
		
		gui_manager_->addControl(window);
		glClearColor(0.3f, 0.2f, 0.8f, 0.0f);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	void init(void){
		createContext();
		setupScene();
	}
}

int main(int argc,char *argv[]){

	glutInit(&argc,argv);
	
	init();
	
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutReshapeFunc(reshape);
	
	
	glutKeyboardFunc(keyDown);
	glutKeyboardUpFunc(keyUp);
	glutSpecialFunc(specialDown);
	glutSpecialUpFunc(specialUp);
	glutMouseFunc(onMouse);
	glutMotionFunc(onMotion);
	glutPassiveMotionFunc(onPassiveMotion);
	
	glutMainLoop();
	
	return 0;
}