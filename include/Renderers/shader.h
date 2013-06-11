#ifndef __NGUI_SHADER_H
#define __NGUI_SHADER_H

#include <map>
#include <string>
#include <glm/glm.hpp>
#include <GL/glew.h>

class Shader{
public:
	Shader(void);
	Shader(const char *vertexText, const char *fragmentText);
	~Shader(void);
	
	void bind(void)const;
	void unbind(void)const;
	unsigned int id(void)const;
	
	void setUniform(const char * name, int count, glm::vec2 const &value)const;
	void setUniform(const char * name, int count, glm::vec3 const &value)const;
	void setUniform(const char * name, int count, glm::vec4 const &value)const;
	void setUniform(const char * name, int count, glm::ivec2 const &value)const;
	void setUniform(const char * name, int count, glm::ivec3 const &value)const;
	void setUniform(const char * name, int count, glm::ivec4 const &value)const;
	void setUniform(const char * name, int count, glm::mat3 const &value)const;
	void setUniform(const char * name, int count, glm::mat4 const &value)const;
	void setUniform(const char * name, int value)const;
	void setUniform(const char * name, float value)const;
	void setUniform(const char * name, float value1, float value2, float value3)const;
	
private:
	void init(void);
	
	unsigned int shader_id;
	unsigned int shader_vp;
	unsigned int shader_fp;
	
	std::map<std::string, GLint> mUniformLocations;
};

#endif