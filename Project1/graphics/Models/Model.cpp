#include"Model.h"
 
Model::Model(){}

void Model:: render(GLenum type,Shader shader) {
	for (Mesh mesh : meshes){
		mesh.render(type,shader);
	}
}

void Model::cleanup() {
	for (Mesh mesh : meshes) {
		mesh.cleanup();
	}
}