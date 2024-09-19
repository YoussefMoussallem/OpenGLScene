#include"Swept.h"

Swept::Swept(Model model, float cr, int outerres, Material material,bool closed) {
	this->material = material;
	Circle c(outerres, cr);
	vector<Vertex> path = model.meshes[0].vertices;
	int innerres = path.size();
	for (int i = 0; i < path.size();i++) {
		vec3 norm = path[(i+1)% path.size()].pos - path[i].pos;
		vec3 ortho = cross(norm, vec3(0, 0, 1));
		mat4 model = mat4(1.0);
		model = translate(model, vec3(path[i].pos.x, path[i].pos.y, path[i].pos.z));
		model = rotate(model,(float)radians(90.0), ortho);
		for (Vertex vert : c.vertices) {
			vert.pos = model * vec4(vert.pos, 1);
			vertices.push_back(vert);
		}
	}
	int endCondition;
	int A, B, C, D;
	if (closed) {
		endCondition = innerres;
	}
	else {
		endCondition = innerres - 1;
	}
	for (int i = 0; i < endCondition; i++) {
		for (int j = 0; j < outerres; j++) {
			A = i * outerres + j;
			B = i * outerres + (j + 1) % outerres;
			C = ((i + 1) * outerres) % (outerres * innerres) + j;
			D = ((i + 1) * outerres) % (outerres * innerres) + (j + 1) % outerres;


			indices.push_back(A);
			indices.push_back(C);
			indices.push_back(D);

			indices.push_back(A);
			indices.push_back(D);
			indices.push_back(B);

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

	//vector<GLuint> ind;
	//ind.push_back(indices[0]);
	//ind.push_back(indices[1]);
	//ind.push_back(indices[2]);
	//for (int i = 0; i < endCondition*outerres*6-3; i+=3) {
	//	if (i % outerres == 0 && i!=0) {
	//		Mesh mesh(vertices, ind, 0, 1);
	//		meshes.push_back(mesh);
	//		ind.clear();
	//	}
	//	else {
	//		ind.push_back(indices[i]);
	//		ind.push_back(indices[i+1]);
	//		ind.push_back(indices[i+2]);

	//		ind.push_back(indices[i+3]);
	//		ind.push_back(indices[i+4]);
	//		ind.push_back(indices[i+5]);
	//	}
	//}
	//for (int i = 8; i >= 1; i--) {
	//	vector<GLuint>::const_iterator first = indices.begin();
	//	vector<GLuint>::const_iterator last = indices.begin() + indices.size()/i;
	//	vector<GLuint> newVec(first, last);
	//	//indices = newVec;
	//	Mesh mesh(vertices, newVec, 0, 1);
	//	meshes.push_back(mesh);
	//}
	//vector<GLuint>::const_iterator first = indices.begin() ;
	//vector<GLuint>::const_iterator last = indices.begin() + indices.size();
	//vector<GLuint> newVec(first, last);
	//indices = newVec;
	Mesh mesh(vertices, indices, 0, 1);
	meshes.push_back(mesh);
}


void Swept::render(GLenum type, Shader shader, vec3 size, vec3 pos, float angle, vec3 axis) {


	mat4 model = mat4(1.0);
	model = translate(model, pos);
	model = rotate(model, (float)(glfwGetTime() * radians(angle)), axis);
	model = scale(model, size);

	shader.setfloat3("material.ambient", material.ambient);
	shader.setfloat3("material.diffuse", material.diffuse);
	shader.setfloat3("material.specular", material.specular);
	shader.setfloat("material.shininess", material.shininess);
	shader.setMatrix4("model", model);
	Model::render(GL_TRIANGLES, shader);
	
}












