#pragma once

#include <glad/glad.h>

class GLFWwindow;
class Scene;

class Core {

public:
	Core();

	void Run(Scene* scene);

private:
	Scene* CurrentScene = nullptr;
	GLFWwindow* _window = nullptr;

	GLuint shaderProgram = 0;

	GLfloat VertexBuffer[24];
	GLuint VertexVBO = 0;
};

