#include"Cube.h"

Cube::Cube(Material material) {
	this -> material = material;
	GLfloat vertices[] = {
		-0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		-0.5f,  0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,

		-0.5f, -0.5f,  0.5f,
		 0.5f, -0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,
		-0.5f, -0.5f,  0.5f,

		-0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,

		 0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,

		-0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f,  0.5f,
		 0.5f, -0.5f,  0.5f,
		-0.5f, -0.5f,  0.5f,
		-0.5f, -0.5f, -0.5f,

		-0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f, -0.5f,
	};

	vector<GLuint> indices;
	int i = 0;
	for (; i < sizeof(vertices) / sizeof(GLfloat); i += 3) {
		indices.push_back(i / 3);
	}
	vector<Vertex>verts = genvertices(vertices,i);

	for (int i = 0; i < verts.size() / 3; i++) {
		int A = 3 * i;
		int B = 3 * i + 1;
		int C = 3 * i + 2;
		vec3 normal = cross(verts[C].pos - verts[B].pos,verts[A].pos- verts[B].pos);
		verts[3 * i].normal =-normalize(normal);
		verts[3 * i+1].normal =-normalize(normal);
		verts[3 * i+2].normal =-normalize(normal);
	}
	
	meshes.push_back(Mesh(verts, indices, 0, 1));
}

void Cube::render(Shader shader, vec3 size, vec3 position, float angle, vec3 axis) {
	shader.setfloat3("material.ambient", material.ambient);
	shader.setfloat3("material.diffuse", material.diffuse);
	shader.setfloat3("material.specular", material.specular);
	shader.setfloat("material.shininess", material.shininess);
	mat4 model = mat4(1.0);
	model = translate(model, position);
	model = rotate(model, (float)(glfwGetTime() * radians(angle)), axis);
	model = scale(model, size);
	shader.setMatrix4("model", model);
	Model::render(GL_TRIANGLES, shader);
}