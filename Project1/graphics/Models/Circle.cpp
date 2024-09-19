#include"Circle.h"

Circle::Circle(int n, float r) {
	float theta = 0, delta = (float)(2 * M_PI/n);
	for (int i = 0; i < n; i++) {
			Vertex v;
			v.pos.x =r * cos(theta);
			v.pos.y = r * sin(theta);
			v.pos.z = 0;
			vertices.push_back(v);
			theta += delta;
	}
	for (int i = 0; i < vertices.size()/2+1; i++) {
		indices.push_back(i%vertices.size());
	}

	Mesh mesh(vertices, indices, 0, 1);
	meshes.push_back(mesh);
}

Circle::Circle(){}
void Circle::render(Shader shader,vec3 size, vec3 position,float angle,vec3 axis) {
	this->size = size;
	this->position = position;
	mat4 model = mat4(1.0);
	model = scale(model, size);
	model = translate(model, position);
	model = rotate(model, (float)(glfwGetTime()*radians(angle)), axis);
	shader.setMatrix4("model", model);
	/*Model::render(GL_LINE_STRIP, shader);*/

	for (Mesh mesh : meshes) {
		mesh.render(GL_LINE_STRIP,shader);
	}
}