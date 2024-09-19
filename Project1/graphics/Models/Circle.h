#ifndef CIRCLE_H
#define CIRCLE_H

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include<vector>
#include"../inquiries/Shader.h"
#include<cmath>
#include<glm/glm.hpp>
#include"Model.h"

using namespace std;


class Circle:public Model {
public:
	vector<Vertex> vertices;
	vector<GLuint>indices;
	vec3 position, size;
	Circle(int n, float r);
	Circle();
	void render(Shader shader,vec3 size, vec3 position,float angle,vec3 axis);
};


#endif // !CIRCLE_H