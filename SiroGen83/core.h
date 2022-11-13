#pragma once

//#include <SiroGen83/renderer.h>

class Renderer;
class GLFWwindow;
class Scene;

class Core {

public:
	Core();

	void Run(Scene* scene);

private:
	GLFWwindow* _window = nullptr;

	Renderer* _instance = nullptr;
};

