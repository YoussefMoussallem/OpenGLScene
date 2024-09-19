#ifndef VERTEX_H
#define VERTEX_H

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>

using namespace glm;
using namespace std;
struct Vertex {
	vec3 pos;
	vec3 normal=vec3(0);
	vec3 color;
	vec2 texture;
};

#endif // !Vert_H

