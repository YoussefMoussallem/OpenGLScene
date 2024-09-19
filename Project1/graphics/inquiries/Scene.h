#ifndef SCENE_H
#define SCENE_H

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include"callbackfunc/Keyboard.h"

using namespace std;

static void framebuffersizecallback(GLFWwindow* window, int width, int height);

class Scene {
public:
	bool glad;
	GLFWwindow* window;
	int x, y;
//public:
	int width, heigth;
	unsigned static int scr_width;
	unsigned static int scr_heigth;
	Scene(int x, int y);

	void update(float red, float green, float bleue);

	bool initialize(const char* name, int w, int h);
	void newframe();

	bool shouldclose();
	void setshouldclose(bool shouldclose);

	void setparameters();
};

#endif // !SCENE_H