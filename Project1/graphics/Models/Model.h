#ifndef MODEL_H
#define MODEL_H

#include"Mesh.h"

class Model {
public:
	vector<Mesh> meshes;
	Model();
	void render(GLenum type, Shader shader);
	void cleanup();
};

#endif // !Model_H


