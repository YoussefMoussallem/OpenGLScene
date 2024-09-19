#ifndef CUBE_HPP
#define CUBE_HPP

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include"Vertex.h"
#include"Model.h"
#include<glm/gtc/matrix_transform.hpp>
#include"../inquiries/Material.h"

class Cube:public Model {
	Material material;
public:

	Cube(Material material);
	void render(Shader shader, vec3 size, vec3 position ,float angle, vec3 axis);
};
#endif // !CUBE_HPP
