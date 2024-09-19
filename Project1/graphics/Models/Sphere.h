#ifndef  SPHERE_H
#define SPHERE_H
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include"Model.h"
#include"Circle.h"
#include"../inquiries/Material.h"
class Sphere:public Model {
	vector<Vertex> vertices;
	vector<GLuint> indices;
	vector<Vertex> faces;
	Material material;
	double resolution;
	float radius;
public:
	vec3 position;
	vec3 size;
	Sphere();
	void init(float radius, int point_on_circle);
	Sphere(float radius,int point_on_circle);
	void render(Shader shader, Material material, vec3 size, vec3 position, float angle, vec3 axis);
	
};
#endif // ! SPHERE_H
