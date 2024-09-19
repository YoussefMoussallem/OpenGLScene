#include""
Heart(vec3 pos, vec3 size, vec3 color, int res) {
	this->pos = pos;
	this->size = size;
	float dt = 20 / (float)res;
	float t = -10;
	for (int i = 0; i < res; i++) {
		Vertex v;
		v.pos.x = 16 * pow(sin(t), 3);
		v.pos.y = 13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t);
		v.pos.z = 0;
		v.color = color;
		vertices.push_back(v);
		t += dt;
	}
	vector<GLuint> indices;
	for (int i = 0; i < vertices.size(); i++) {
		indices.push_back(i);
	}
	Mesh mesh = Mesh(vertices, indices, 0, 1);
	meshes.push_back(mesh);
}


void render(Shader shader, float angle, vec3 axis) {
	mat4 model = mat4(1.0);
	model = translate(model, pos);
	model = rotate(model, (float)(glfwGetTime() * radians(angle)), axis);
	model = scale(model, size);
	shader.setMatrix4("model", model);
	Model::render(GL_LINE_STRIP, shader);
}