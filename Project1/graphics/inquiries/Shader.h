#ifndef  Shader_H
#define Shader_H
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include<string>
#include<fstream>
#include<streambuf>
#include<sstream>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
using namespace std;
using namespace glm;
class Shader {
public:
	string vshader_str, fshader_str;
	GLuint vshader, fshader, id;
public:
	Shader(const char* vshader_path, const char* fshader_path);

	void generate();
	bool readstring(const char* pathname, string &shader_str);

	void compile_shader(GLenum type,GLuint &shader, string shader_str);

	void activate();

	void setMatrix4(const char* name,mat4 val);

	void setfloat3(const char* name, vec3 val);
	void setfloat3(const char* name, float x, float y, float z);

	void setfloat(const char* name, float val);
};

#endif // ! Shader_H
