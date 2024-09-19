#include"Square.h"

Square::Square(vec3 size, vec3 pos, vec3 color) {
	this->pos = pos;
	this->size = size;
	GLfloat verts[] = {
		1,1,0,
		-1,1,0,
		-1,-1,0,
		1,-1,0
	};

	indices = { 0,1,2,3,0 };
	
	vertices = genvertices(verts, 4);
	Mesh mesh(vertices, indices, 0, 1);
	meshes.push_back(mesh);
}

void Square:: render(Shader shader, float angle, vec3 axis) {
	mat4 model = mat4(1.0);
	model = scale(model, size);
	model = translate(model, pos);
	model = rotate(model, (float)(glfwGetTime() * radians(angle)), axis);
	shader.setMatrix4("model", model);
	Model::render(GL_LINE_STRIP, shader);
}


