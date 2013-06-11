#include "Renderers/OpenGL.h"
#include "Renderers/shader.h"
#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_access.hpp>

using namespace NGUI;
using namespace NGUI::Renderers;

OpenGL::~OpenGL(void){
	if(shader_) delete shader_;
}

void OpenGL::init(void){
	
	shader_ = new Shader(
		"#version 330 core\n\
		\n\
		uniform mat4 projectionMatrix;\n\
		uniform mat4 modelMatrix;\n\
		\n\
		layout(location = 0) in vec2 in_Position;\n\
		layout(location = 1) in vec2 in_TexCoord;\n\
		\n\
		smooth out vec2 TexCoord;\n\
		\n\
		void main(void){\n\
			TexCoord = in_TexCoord;\n\
			gl_Position = projectionMatrix * modelMatrix * vec4(in_Position, 0.0, 1.0);\n\
		}",
		"#version 330 core\n\
		\n\
		uniform sampler2D inSampler;\n\
		smooth in vec2 TexCoord;\n\
		\n\
		layout(location = 0) out vec4 out_Color;\n\
		\n\
		void main(void){\n\
			out_Color = texture(inSampler, TexCoord);\n\
		}"
	);
	shader_->bind();
	{
		glm::mat4 projectionMatrix = glm::ortho(0.0f, 600.0f, 0.0f, 600.0f);
		shader_->setUniform("projectionMatrix", 1, projectionMatrix);
		shader_->setUniform("inSampler", 0);
	}
	shader_->unbind();
	
	float vertices[4*6] = {
		-0.5f, -0.5f, 0.0f, 0.0f,
		-0.5f,  0.5f, 0.0f, 1.0f,
		 0.5f, -0.5f, 1.0f, 0.0f,
		 0.5f, -0.5f, 1.0f, 0.0f,
		-0.5f,  0.5f, 0.0f, 1.0f,
		 0.5f,  0.5f, 1.0f, 1.0f
	};
	
	glGenVertexArrays(1,&vao_);
	glBindVertexArray(vao_);
	
	glGenBuffers(1,&vbo_);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_);
	glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(float) * 6, &vertices[0], GL_STATIC_DRAW);
	
	glEnableVertexAttribArray((GLuint)0);
	glVertexAttribPointer((GLuint)0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (GLvoid*)0);
	
	glEnableVertexAttribArray((GLuint)1);
	glVertexAttribPointer((GLuint)1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (GLvoid*)(2 * sizeof(float)));
	
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void OpenGL::drawVisualPackets(const std::vector<VisualPacket>& vipackets){
	
	// glActiveTexture(GL_TEXTURE0);
	shader_->bind();
	for(auto packet: vipackets){
		const Rect& rect = packet.rect_;
		const Texture& tex = packet.tex_;
		glm::mat4 modelMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(rect.w_, rect.h_, 1.0f));
		modelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.5f*rect.w_ + rect.x_, 600.0f - 0.5f*rect.h_ - rect.y_, 0.0f)) * modelMatrix;
		shader_->setUniform("modelMatrix", 1, modelMatrix);
		glBindTexture(GL_TEXTURE_2D, *(GLuint*)tex.data_);
		
		glBindVertexArray(vao_); 
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);
	}
	shader_->unbind();
}