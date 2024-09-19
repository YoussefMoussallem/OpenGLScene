#ifndef  MESH_H
#define MESH_H

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<vector>
#include<glm/glm.hpp>
#include<iostream>
#include<map>
#include"Vertex.h"
#include"../inquiries/Shader.h"
using namespace std;
using namespace glm;

vector<Vertex> genvertices(GLfloat* vertices,int j);
class Mesh {
private:
	GLuint normVBO, posVBO, VAO, EBO;
	int vertattribp,normattribp;
public:
	vector<Vertex> vertices;
	vector<GLuint> indices;
	void init();
	Mesh();
	Mesh(vector<Vertex>& vertices, vector<GLuint>& indices, int vertattribp, int normattribp);
	void cleanup();
	void render(GLenum type, Shader shader);
};

#endif // ! MESH_H


