#ifndef SQUARE_H
#define SQUARE_H

#include"Model.h"

class Square :public Model {
private:
	vec3 size, pos;
	vector<GLuint> indices;

public:
	vector<Vertex> vertices;
	Square(vec3 size, vec3 pos, vec3 color);
	void  render(Shader shader, float angle, vec3 axis);
};
#endif // !1


