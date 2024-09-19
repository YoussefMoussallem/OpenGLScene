#include"Scene.h"

unsigned int Scene::scr_width;
unsigned int Scene::scr_heigth;

Scene::Scene(int x, int y) {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_ANY_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	this->x = x;
	this->y = y;
	window = nullptr;
}

void Scene::update(float red, float green, float bleue) {
	glClearColor(red / 255.0, green / 255.0, bleue / 255.0, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

bool Scene::initialize(const char* name, int w, int h) {
	window = glfwCreateWindow(w, h, name, NULL, NULL);
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		glfwTerminate();
		glad = false;
	}
	glfwGetWindowPos(window, &x,&y);
	glEnable(GL_DEPTH_TEST);
	if (!glad) {
		return false;
	}
	return true;
}

void Scene::newframe() {
	glfwSwapBuffers(window);
	glfwPollEvents();
}

void framebuffersizecallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
	Scene::scr_width = width;
	Scene::scr_heigth=height;
}

bool Scene::shouldclose() {
	return glfwWindowShouldClose(window);
}
void Scene::setshouldclose(bool shouldclose) {
	glfwSetWindowShouldClose(window, shouldclose);
}



void Scene::setparameters() {
	glViewport(0, 0, width, heigth);
	glEnable(GL_DEPTH_TEST);
	glfwSetFramebufferSizeCallback(window, framebuffersizecallback);/*
	glfwSetKeyCallback(window,keyCallback);*/
}

