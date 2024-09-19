#ifndef LIGTH_H
#define LIGTH_H

#include<glm/glm.hpp>

using namespace glm;

struct Ligth {
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	vec3 position;
};
#endif // !LIGTH_H
