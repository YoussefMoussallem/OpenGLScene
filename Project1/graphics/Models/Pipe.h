#ifndef PIPE_H
#define PIPE_H
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include"Model.h"
#include"Circle.h"
using namespace glm;
class Pipe:public Model {
	vec3 size, pos;
	vector<Vertex> vertices;
	vector<GLuint> indices;
public:
	Pipe(float r,float h, vec3 size, vec3 pos, vec3 color, int res);

	void render(Shader shader, float angle, vec3 axis);
};
#endif // !PIPE_H