#include"func.h"

Func::Func(int n, float range) {

	float x = 0, delta = (float)(range  / n);
	for (int i = 0; i < n; i++) {
		Vertex v;
		v.pos.x = x*3;
		float denum = pow((pow(x, x) - M_PI / 2) / M_PI,2);
		v.pos.y = abs(sin(pow(x,x)/denum))*2;
		v.pos.z = 0;
		vertices.push_back(v);
		x += delta;
	}
	for (int i = 0; i < vertices.size(); i++) {
		indices.push_back(i);
	}

	Mesh mesh(vertices, indices, 0, 1);
	meshes.push_back(mesh);
}

Func::Func() {}

void Func::render(Shader shader, vec3 size, vec3 position, float angle, vec3 axis) {
	mat4 model = mat4(1.0);
	model = scale(model, size);
	model = translate(model, position);
	model = rotate(model, (float)(glfwGetTime() * radians(angle)), axis);
	shader.setMatrix4("model", model);
	/*Model::render(GL_LINE_STRIP, shader);*/

	for (Mesh mesh : meshes) {
		mesh.render(GL_LINE_STRIP, shader);
	}
}