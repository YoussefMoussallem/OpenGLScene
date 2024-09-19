#ifndef SWEPT
#define SWEPT

#include"Model.h"
#include<vector>
#include"Circle.h"
#include"../inquiries/Material.h"
#include"Heart.h"

#define M_PI 3.14159265358979323846
using namespace glm;
class Swept :public Model {
	vector<Vertex> vertices;
	vector<GLuint> faces;
	vector<GLuint> indices;
	Material material;
public:
	Swept(Model model, float cr, int outerres, Material material,bool closed);
	void init(Model model, float cr, int outerres, Material material, bool closed);
	void render(GLenum type, Shader shader, vec3 size, vec3 pos, float angle, vec3 axis);
};

#endif // !Circular_Pipe_H

