#ifndef HEART_H
#define HEART_H

#include"Model.h"
#include<glm/glm.hpp>
#include<vector>
#include"Vertex.h"
#include"../inquiries/Shader.h"
#include<glm/gtc/matrix_transform.hpp>

using namespace glm;
class Heart:public Model {
	
	vector<GLuint> ind;
	vec3 size, pos;
public:
	vector<Vertex> vertices;
	Heart(vec3 pos, vec3 size, vec3 color, int res);
	void render(Shader shader, float angle, vec3 axis);
	
};
#endif // !HEART_H
