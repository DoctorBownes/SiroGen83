#pragma once

#include <glad/glad.h>
#include <vector>

class Scene;
class Entity;

class Renderer {

public:
	Renderer(const Renderer&) = delete;

	static Renderer* GetInstance()
	{
		if (!_instance)
		{
			_instance = new Renderer();
		}
		return _instance;
	}

	void RenderScene(Scene* scene);

	void GenerateSprite(Entity* entity, char* canvas, char width, char height);

private:

	std::vector<unsigned char> pixelcanvas;

	GLuint shaderProgram = 0;

	GLfloat VertexBuffer[24];

	void RenderEntity(Entity* entity);

	Renderer();

	static Renderer* _instance;
};

