#include"Sin.h"

Sin::Sin(int n, float r,float range) {

	float theta = 0, delta = (float)(range * M_PI / n);
	for (int i = 0; i < n; i++) {
		Vertex v;
		v.pos.x = theta;
		v.pos.y = r * sin(theta);
		v.pos.z = 0;
		vertices.push_back(v);
		theta += delta;
	}
	for (int i = 0; i < vertices.size() ; i++) {
		indices.push_back(i );
	}

	Mesh mesh(vertices, indices, 0, 1);
	meshes.push_back(mesh);
}

Sin::Sin() {}

void Sin::render(Shader shader,vec3 size,vec3 position, float angle, vec3 axis) {
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