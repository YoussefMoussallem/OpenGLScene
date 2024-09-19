#ifndef TWO_D_SHAPE
#define TWO_D_SHAPE

#include"Model.h"
#include"../inquiries/Shader.h"

class shapes {
public:
	shapes();
	vector<Vertex> vertices;
	virtual void render(Shader shader, float angle, vec3 axis)=0;
};
#endif // !1
