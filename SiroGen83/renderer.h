#pragma once

#include <glad/glad.h>
#include <SiroGen83/scene.h>
#include <vector>

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

	Nametable Maintables[4];

	void SetMaintables(Scene* scene);

	void RenderEntity(Entity* entity);

	Renderer();

	static Renderer* _instance;

	unsigned int texture_buffer;

	unsigned int vertex_buffer;

	bool once = true;
};

