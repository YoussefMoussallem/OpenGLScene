#include"Shader.h"

Shader::Shader(const char* vshader_path, const char* fshader_path) {
	readstring(vshader_path, vshader_str);
	readstring(fshader_path, fshader_str);
	compile_shader(GL_VERTEX_SHADER, vshader, vshader_str);
	compile_shader(GL_FRAGMENT_SHADER, fshader, fshader_str);
	generate();
}

void Shader::generate() {
	int success;
	char* infolog = new char[512];
	id = glCreateProgram();
	glAttachShader(id, vshader);
	glAttachShader(id, fshader);
	glLinkProgram(id);
	glGetProgramiv(id, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(id, 512, NULL, infolog);
		cout << "Program link error: " << infolog << endl;
	}
	glDeleteShader(vshader);
	glDeleteShader(fshader);
}
bool Shader::readstring(const char* pathname, string &shader_str) {
	fstream path(pathname);
	if (path) {
		ostringstream st;
		st << path.rdbuf();
		shader_str = st.str();
		cout << "shader found at: " + (string)pathname + "." << endl;
		path.close();
		return true;
	}
	else {
		cout << "shader not found at: " + (string)pathname + "." << endl;
		return false;
	}
	
}

void Shader::compile_shader(GLenum type, GLuint& shader, string shader_str) {
	int success;
	char* infolog = new char[512];
	shader = glCreateShader(type);
	const GLchar* Shad;
	Shad = shader_str.c_str();
	glShaderSource(shader, 1, &Shad, NULL);
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(shader, 512, NULL, infolog);
			if (type == GL_VERTEX_SHADER) {
				cout << "error with vertex shader compilation: " << infolog << endl;
			}
			else {
				cout << "error with fragment shader compilation: " << infolog << endl;
			}
	}
	
}

void Shader::activate() {
	glUseProgram(id);
}

void Shader::setMatrix4(const char* name,mat4 val) {
	int location=glGetUniformLocation(id, name);
	glUniformMatrix4fv(location, 1, GL_FALSE, value_ptr(val));
}

void Shader::setfloat3(const char* name, vec3 val) {
	setfloat3(name, val.x, val.y, val.z);
}
void Shader::setfloat3(const char* name, float x, float y, float z) {
	unsigned int loc = glGetUniformLocation(id, name);
	glUniform3f(loc, x, y, z);
}

void Shader::setfloat(const char* name, float val) {
	unsigned int loc = glGetUniformLocation(id, name);
	glUniform1f(loc, val);
}