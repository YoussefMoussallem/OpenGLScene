#include"Pipe.h"

Pipe::Pipe(float r,float h, vec3 size, vec3 pos, vec3 color, int res) {
	this->pos = pos;
	this->size = size;
	Circle circle(res, r);
	float delta = (float)(2 * M_PI / res);
	float dz = h / circle.meshes[0].vertices.size();
	float z = 0;
	for (int i = 0; i < circle.meshes[0].vertices.size(); i++) {
		float theta = 0;
		for (int j = 0; j < res; j++) {
			Vertex v;
			v.pos.x = (float)(r * cos(theta));
			v.pos.y = (float)(r * sin(theta));
			v.pos.z = z;
			v.color = color;
			vertices.push_back(v);
			theta += delta;
		}
		z += dz;
	}
	int A, B, C, D;
	for (int i = 0; i < circle.vertices.size() - 1; i++) {
		for (int j = 0; j < res; j++) {
			A = i * res + j;
			B = i * res+ (j + 1) % res;
			C = (i + 1) * res + j;
			D = (i + 1) * res+ (j + 1) % res;
			indices.push_back(A);
			indices.push_back(D);
			indices.push_back(B);

			indices.push_back(A);
			indices.push_back(C);
			indices.push_back(D);
		}
	}
	Mesh mesh(vertices, indices, 0, 1);
	meshes.push_back(mesh);
}

void Pipe::render(Shader shader, float angle, vec3 axis) {
	mat4 model = mat4(1.0);
	model = translate(model, pos);
	model = rotate(model, (float)(glfwGetTime() * radians(angle)), axis);
	model = scale(model, size);
	shader.setMatrix4("model", model);
	Model::render(GL_TRIANGLES, shader);
}
