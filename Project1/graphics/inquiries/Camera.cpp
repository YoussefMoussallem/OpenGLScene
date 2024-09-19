#include"Camera.h"

Camera::Camera() {
	updateCameraVector();
}
Camera::Camera(vec3 pos, vec3 front, vec3 up, float yaw, float pitch) {
	this->position = pos;
	this->front = front;
	this->up = up;
	this ->yaw = yaw;
	this->pitch = pitch;
	this->right = vec3(1, 0, 0);
}

mat4 Camera::getViewmatrix() {
	return lookAt(position, position + front, up);
}

void Camera::updateCameraPosition(moves move, float dt) {
	float velocity =4.5* dt*speed;
	switch (move) {
		case(moves::forward):
			position += front*velocity;
			break;
		case(moves::backwards):
			position -= front* velocity;
			break;
		case(moves::left):
			position -=right* velocity;
			break;
		case(moves::rigth):
			position += right* velocity;
			break;
		case(moves::upwards):
			position +=up* velocity;
			break;
		case(moves::downwards):
			position -=up* velocity;
			break;
	}
}
void Camera::updateCameraVector() {
	vec3 direction;
	direction.x = cos(radians(yaw)) * cos(radians(pitch));
	direction.y = sin(radians(pitch));
	direction.z = sin(radians(yaw)) * cos(radians(pitch));
	front = normalize(direction);
	right = normalize(cross(front, worldup));
    up = normalize(cross(right, front));

}

float Camera::getzoom() {
	return radians(zoom);
}