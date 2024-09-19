#ifndef CAMERA_H
#define CAMERA_H

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
using namespace glm;

enum moves{left,rigth,upwards,downwards,forward,backwards};
class Camera {
	vec3 worldup=vec3(0,1,0);
	vec3 front = vec3(0, 0, 1);
	vec3 right ;
	float zoom = 120;
	float speed = 40;
	vec3 up = vec3(0, 1, 0);
	
public:
	float pitch = 0;
	float yaw = -90;
	vec3 position = vec3(0, 0, 5);
	Camera();
	Camera(vec3 pos, vec3 front, vec3 up, float yaw, float pitch);
	mat4  getViewmatrix();
	void updateCameraPosition(moves mode,float dt);
	void updateCameraVector();
	float getzoom();
};

#endif // DEBUG
