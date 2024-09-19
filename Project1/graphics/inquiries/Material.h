#ifndef MATERIAL_H
#define MATERIAL_H

#include<glm/glm.hpp>

using namespace glm;

struct Material {
public:
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float shininess;
};
#endif // !MATERIAL_H
