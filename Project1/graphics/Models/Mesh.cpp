#include"Mesh.h"

vector<Vertex> genvertices(GLfloat vertices[], int j) {
	vector<Vertex> verts;
	for (int i = 0; i < j; i++) {
		Vertex v;
		v.pos = vec3(
			vertices[3 * i],
			vertices[3 * i + 1],
			vertices[3 * i + 2]
		);
		verts.push_back(v);
	} 
	return verts;
}

Mesh::Mesh() {};
Mesh::Mesh(vector<Vertex>& vertices, vector<GLuint>& indices, int vertattribp, int coloattribp) {
	this->vertices = vertices;
	this->indices = indices;
	this->vertattribp = vertattribp;
	this->normattribp = coloattribp;
	init();
}



void Mesh::init( ) {
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size()*sizeof(GLuint), &indices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &posVBO);
	glBindBuffer(GL_ARRAY_BUFFER, posVBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &normVBO);
	glBindBuffer(GL_COLOR_ARRAY, normVBO);
	glBufferData(GL_COLOR_ARRAY, vertices.size() * sizeof(Vertex), &vertices[0], GL_COLOR);

	glEnableVertexAttribArray(vertattribp);
	glVertexAttribPointer(vertattribp, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

	glEnableVertexAttribArray(normattribp);
	glVertexAttribPointer(normattribp, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
}

void Mesh::cleanup() {
	glDeleteBuffers(1, &posVBO);
	glDeleteBuffers(1, &normVBO);
	glDeleteVertexArrays(1, &VAO);
}

void Mesh::render(GLenum type,Shader shader) {
	shader.activate();
	glBindVertexArray(VAO);
	glDrawElements(type, indices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}