#include"Sphere.h"
Sphere::Sphere(){}
Sphere::Sphere(float radius,int point_on_circle) {
		this->resolution = point_on_circle;
		this->radius = radius;
		float deltat = (float)( M_PI / point_on_circle);
		float deltap = (float)(2*M_PI / point_on_circle);
		float theta = 0;
		theta = M_PI / 2;
		for (int i = 0; i < point_on_circle;i++) {
			float phie =0;
			float xy = radius * cos(theta);
			float z = radius * sin(theta);
			for (int j = 0; j < point_on_circle;j++) {
				Vertex v;
				v.pos.x =(float)(xy*cos(phie));
				v.pos.y = (float)(xy* sin(phie));
				v.pos.z = z;
				vertices.push_back(v);
				phie += deltap;
			}
			theta -= deltat;
		}
		int A, B, C, D;

		for (int i =0; i < point_on_circle-1 ;i++) {
			for (int j = 0; j < point_on_circle; j++) {
				A = i * point_on_circle + j;
				B = i * point_on_circle + (j + 1) % point_on_circle;
				C = (i + 1) * point_on_circle + j;
				D = (i + 1) * point_on_circle + (j + 1) % point_on_circle;


				indices.push_back(A);
				indices.push_back(D);
				indices.push_back(B);

				indices.push_back(A);
				indices.push_back(C);
				indices.push_back(D);
			}
		}

		for (int i = 0; i < indices.size() / 3; i++) {
			int A, B, C;
			A = indices[3 * i];
			B = indices[3 * i + 1];
			C = indices[3 * i + 2];
			vec3 normal = cross(vertices[B].pos - vertices[A].pos, vertices[C].pos - vertices[B].pos);
			vertices[A].normal = normalize(normal);
			vertices[B].normal = normalize(normal);
			vertices[C].normal = normalize(normal);
		}
		Mesh mesh(vertices, indices, 0, 1);
		meshes.push_back(mesh);
	}

void Sphere::init(float radius, int point_on_circle) {
	float deltat = (float)(M_PI / point_on_circle);
	float deltap = (float)(2 * M_PI / point_on_circle);
	float theta = 0;

	theta = M_PI / 2;
	for (int i = 0; i < point_on_circle; i++) {
		float phie = 0;
		float xy = radius * cos(theta);
		float z = radius * sin(theta);
		for (int j = 0; j < point_on_circle; j++) {
			Vertex v;
			v.pos.x = (float)(xy * cos(phie));
			v.pos.y = (float)(xy * sin(phie));
			v.pos.z = z;
			vertices.push_back(v);
			phie += deltap;
		}
		theta -= deltat;
	}
	int A, B, C, D;

	for (int i = 0; i < point_on_circle - 1; i++) {
		for (int j = 0; j < point_on_circle; j++) {
			A = i * point_on_circle + j;
			B = i * point_on_circle + (j + 1) % point_on_circle;
			C = (i + 1) * point_on_circle + j;
			D = (i + 1) * point_on_circle + (j + 1) % point_on_circle;


			indices.push_back(A);
			indices.push_back(D);
			indices.push_back(B);

			indices.push_back(A);
			indices.push_back(C);
			indices.push_back(D);
		}
	}

	for (int i = 0; i < indices.size() / 3; i++) {
		int A, B, C;
		A = indices[3 * i];
		B = indices[3 * i + 1];
		C = indices[3 * i + 2];
		vec3 normal = cross(vertices[B].pos - vertices[A].pos, vertices[C].pos - vertices[B].pos);
		vertices[A].normal =- normalize(normal);
		vertices[B].normal = -normalize(normal);
		vertices[C].normal = -normalize(normal);
	}
	Mesh mesh(vertices, indices, 0, 1);
	meshes.push_back(mesh);
}
void Sphere::render(Shader shader, Material material, vec3 size, vec3 position, float angle, vec3 axis) {
		this->size = size;
		this->position = position;
		this->material = material;
		mat4 model = mat4(1.0);
		model = translate(model, position);
		//model = rotate(model, (float)(glfwGetTime() * radians(angle)), axis);
		model = scale(model, size);
	/*	shader.setfloat3("material.ambient", material.ambient);
		shader.setfloat3("material.diffuse", material.diffuse);
		shader.setfloat3("material.specular", material.specular);
		shader.setfloat("material.shininess", material.shininess);*/
		shader.setMatrix4("model", model);
		Model::render(GL_TRIANGLES, shader);
		//Model::render(GL_LINE_STRIP, shader);
	}


