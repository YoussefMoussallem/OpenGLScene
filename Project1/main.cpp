#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include"graphics/inquiries/Scene.h"
#include"graphics/inquiries/Shader.h"
#include"graphics/models/Cube.h"
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include"graphics/Models/Sphere.h"
#include"graphics/Models/Heart.h"
#include"graphics/Models/Pipe.h"
#include"graphics/Models/Square.h"
#include"graphics/inquiries/Camera.h"
#include"graphics/inquiries/callbackfunc/Keyboard.h"
#include"graphics/inquiries/Ligth.h"
#include"graphics/inquiries/Material.h"
#include"graphics/Models/Swept.h"
#include"graphics/Models/Sin.h"
#include"graphics/Models/Func.h"
#include"Mouse.h"

using namespace std;
float dt=0;
Camera cam;
Ligth ligth = { vec3(1),vec3(1),vec3(1),vec3(0,0,350)};
Sphere sph;
bool isline = false;
double res=70;
double spin,lspin=10;
static void cursorPositionCallBack(GLFWwindow* window, double x, double y) {
	float dx = x - Mouse::x;
	float dy = Mouse::y-y;
	Mouse::x = x;
	Mouse::y = y;
	cam.yaw += dx*1.1;
	cam.pitch += dy*1.1;
	if (cam.pitch > 89) {
		cam.pitch = 89;
	}
	else if (cam.pitch < -89) {
		cam.pitch = -89;
	}
	cam.updateCameraVector();
}

bool keys[GLFW_KEY_LAST] = { 0 };

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_SPACE) {
		switch (action)
		{
		case GLFW_PRESS:
			cam.updateCameraPosition(moves::upwards,dt);
			break;
		case GLFW_REPEAT:
			cam.updateCameraPosition(moves::upwards,dt);
			break;
		}
	}

	if (key == GLFW_KEY_LEFT_SHIFT || key == GLFW_KEY_RIGHT_SHIFT) {
		switch (action)
		{
		case GLFW_PRESS:
			cam.updateCameraPosition(moves::downwards, dt);
			break;
		case GLFW_REPEAT:
			cam.updateCameraPosition(moves::downwards, dt);
			break;
		}
	}

	if (key == GLFW_KEY_W) {
		switch (action)
		{
		case GLFW_PRESS:
			cam.updateCameraPosition(moves::forward, dt);
			break;
		case GLFW_REPEAT:
			cam.updateCameraPosition(moves::forward, dt);
			break;
		}
	}

	if (key == GLFW_KEY_S) {
		switch (action)
		{
		case GLFW_PRESS:
			cam.updateCameraPosition(moves::backwards, dt);
			break;
		case GLFW_REPEAT:
			cam.updateCameraPosition(moves::backwards, dt);
			break;
		}
	}

	if (key == GLFW_KEY_D) {
		switch (action)
		{
		case GLFW_PRESS:
			cam.updateCameraPosition(moves::rigth, dt);
			break;
		case GLFW_REPEAT:
			cam.updateCameraPosition(moves::rigth, dt);
			break;
		}
	}

	if (key == GLFW_KEY_A) {
		switch (action)
		{
		case GLFW_PRESS:
			cam.updateCameraPosition(moves::left, dt);
			break;
		case GLFW_REPEAT:
			cam.updateCameraPosition(moves::left, dt);
			break;
		}
	}

	if (key == GLFW_KEY_C) {
		switch (action)
		{
		case GLFW_PRESS:
			ligth.position += vec3(0,0,2);
			break;
		case GLFW_REPEAT:
			ligth.position += vec3(0, 0, 2);
			break;
		}
	}

	if (key == GLFW_KEY_X) {
		switch (action)
		{
		case GLFW_PRESS:
			ligth.position-= vec3(0, 0, 2);
			break;
		case GLFW_REPEAT:
			ligth.position -= vec3(0, 0, 2);
			break;
		}
	}
	if (key == GLFW_KEY_UP) {
		switch (action)
		{
		case GLFW_PRESS:
			ligth.position += vec3(0, 2, 0);
			break;
		case GLFW_REPEAT:
			ligth.position += vec3(0, 2, 0);
			break;
		}
	}
	if (key == GLFW_KEY_DOWN) {
		switch (action)
		{
		case GLFW_PRESS:
			ligth.position -= vec3(0, 2, 0);
			break;
		case GLFW_REPEAT:
			ligth.position -= vec3(0, 2, 0);
			break;
		}
	}
	if (key == GLFW_KEY_RIGHT) {
		switch (action)
		{
		case GLFW_PRESS:
			ligth.position += vec3(2, 0, 0);
			break;
		case GLFW_REPEAT:
			ligth.position += vec3(2, 0, 0);
			break;
		}
	}
	if (key == GLFW_KEY_LEFT) {
		switch (action)
		{
		case GLFW_PRESS:
			ligth.position -= vec3(2, 0, 0);
			break;
		case GLFW_REPEAT:
			ligth.position -= vec3(2, 0, 0);
			break;
		}
	}

	if (key == GLFW_KEY_TAB) {
		switch (action)
		{
		case GLFW_PRESS:
			isline = !isline;
			break;
		}
	}
	
	if (key == GLFW_KEY_LEFT_ALT) {
		switch (action)
		{
		case GLFW_PRESS:
			spin++;
			break;
		case GLFW_REPEAT:
			spin++;
			break;
		}
	
	}
	if (key == GLFW_KEY_RIGHT_ALT) {
		switch (action)
		{
		case GLFW_PRESS:
			spin --;
			break;
		case GLFW_REPEAT:
			spin--;
			break;
		}
	}

	if (key == GLFW_KEY_L) {
		switch (action)
		{
		case GLFW_PRESS:
			lspin++;
			break;
		case GLFW_REPEAT:
			lspin++;
			break;
		}

	}
	if (key == GLFW_KEY_K) {
		switch (action)
		{
		case GLFW_PRESS:
			 lspin--;
			break;
		case GLFW_REPEAT:
			lspin--;
			break;
		}
	}

}





Scene scene(200, 200);

int main() {
	keys[0] = 1;
	keys[1] = 1;
	scene.initialize("Test", 800, 800);
	glfwSetInputMode(scene.window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetKeyCallback(scene.window, keyCallback);
	glfwSetCursorPosCallback(scene.window, cursorPositionCallBack);
	Shader shader("assets/vshader.glsl", "assets/fshader.glsl");
	Shader shader1("assets/vshader.glsl", "assets/simplefshader.glsl");
	Material material = { vec3(1, 0.45 ,0.0215), vec3(0.07568, 0.61424, 0.07568), vec3(0.633 ,0.727811, 0.633 ),1};
	Material material1 = { vec3(128/255.,128/255.0,118/255.0), vec3(128 / 255.,128 / 255.0,118 / 255.0), vec3(128 / 255.,128 / 255.0,118 / 255.0),100 };
	Material emerald = { vec3(0.02,0.17,0.02),vec3(0.07,0.61,0.07),vec3(0.63,0.72,0.63),15 };
	Material gold = { vec3(0.24,0.19,0.07),vec3(0.75,0.60,0.22),vec3(0.62,0.55,0.36),0.4 };
	Cube cube(material1);


	mat4 view = mat4(1.0);
	mat4 projection = mat4(1.0);

	sph.init(3, res);
	
	Model heart=Heart(vec3(1), vec3(0.5), vec3(1), res);

	Model circle=Circle(res, 3);
	Model circle1 = Circle(res, 5);

	Model s=Sin(res, 2, 4);
	Model s1 = Sin(res, 2, 2);
	Model s2 = Sin(res, 2, 8);

	Swept sw2(circle, 1, res, gold, 1);
	Swept sw21(circle, 3, res, gold, 1);

	Swept sw1(heart, 5, res, material, 1);
	Swept sw11(heart, 8, res, material, 1);

	Swept sw3(s, 2.5, res, emerald, 0);	
	Swept sw31(s1, 0.5, res, emerald, 0);
	Swept sw32(s2, 2.5, res, emerald, 0);

	
	float lastframe = 0;
	float currentframe = 0;
	float delta = 0;


	while (!scene.shouldclose()) {
		if (isline) {
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		}
		else {
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		}
		
		scene.update(15, 15, 15);
		currentframe = glfwGetTime();
		delta = currentframe - lastframe;
		lastframe = currentframe;
		dt = delta;
		mat4 model = mat4(1);
		model = rotate(model, (float)(delta*(radians(lspin))), vec3(1, 0, 0));

		shader.activate();
		shader.setMatrix4("view", view);
		shader.setMatrix4("projection", projection);


		shader.setfloat3("ligth.ambient", ligth.ambient);
		shader.setfloat3("ligth.diffuse", ligth.diffuse);
		shader.setfloat3("ligth.specular", ligth.specular);
		shader.setfloat3("ligth.position", ligth.position);
		shader.setfloat3("viewPos", cam.position);

		view = cam.getViewmatrix();
		projection = perspective((double)cam.getzoom(), 1.0, 0.1, 2000.0);

		ligth.position = model * vec4(ligth.position, 1);
		cube.render(shader, vec3(500, 0.5,500), vec3(0, -3, 0), 0, vec3(1));

		sw2.render(GL_TRIANGLES, shader, vec3(2), vec3(-10, 15, -10), 0, vec3(1, 0, 0));
		sw21.render(GL_TRIANGLES, shader, vec3(2), vec3(10, 15, -10), 0, vec3(1, 0, 0));
		sw2.render(GL_TRIANGLES, shader, vec3(6), vec3(45, 25, -10), spin, vec3(1, 1, 0));
		sw2.render(GL_TRIANGLES, shader, vec3(3), vec3(45, 25, -10), -spin, vec3(1, 1, 0));
		sw2.render(GL_TRIANGLES, shader, vec3(1), vec3(45, 25, -10), spin, vec3(1, 0, 1));

		sw1.render(GL_TRIANGLES, shader, vec3(1), vec3(-90, 15, 45), 0, vec3(1, 0, 1));
		sw11.render(GL_TRIANGLES, shader, vec3(1), vec3(-45 - 90, 15, 45), spin, vec3(0, 1, 0));
		sw1.render(GL_TRIANGLES, shader, vec3(2), vec3(60 - 90, 30, 45), spin, vec3(-1, 1, 0));
		sw1.render(GL_TRIANGLES, shader, vec3(1), vec3(60 - 90, 30, 45), -spin, vec3(-1, 1, 0));

		sw3.render(GL_TRIANGLES, shader, vec3(2), vec3(40, 10, 80), -spin, vec3(1, 0, 0));
		sw31.render(GL_TRIANGLES, shader, vec3(2), vec3(-25 + 40, 10, 80), -spin, vec3(1, 0, 0));
		sw32.render(GL_TRIANGLES, shader, vec3(2), vec3(50 + 40, 10, 80), -spin, vec3(1, 0, 0));

		shader1.activate();
		shader1.setMatrix4("view", view);
		shader1.setMatrix4("projection", projection);
		sph.render(shader1, { vec3(1), vec3(1), vec3(1), 1 }, vec3(10), ligth.position, 0, vec3(0, 0, 1));

		scene.newframe();
	}

	glfwTerminate();
	return 0;

}