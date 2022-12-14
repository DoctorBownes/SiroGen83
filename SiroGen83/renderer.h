#pragma once

#include <glad/glad.h>
#include <SiroGen83/scene.h>
#include <list>
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

	void AddtoTileMap(Tile* tile, char position);

	void SetUpMaintable(Nametable* nametable);

	void UpdateTile(unsigned char tile);

	void EditTile(unsigned char tile, unsigned char sprite, unsigned char flip);

	void ProcessTileQueue();

private:
	std::forward_list<unsigned char>::iterator it;
	std::forward_list<unsigned char> TileQueue;

	std::vector<unsigned char> pixelcanvas;

	GLuint shaderProgram = 0;

	GLfloat VertexBuffer[12];

	GLfloat UVBuffer[12];

	Nametable* Maintables[4];

	void SetMaintables(Scene* scene);

	void RenderEntity(Entity* entity);

	char TileMap[96 * 16];//1536

	std::vector<GLfloat>MT_UVBuffer;

	std::vector<GLfloat>MT_VertexBuffer;

	Renderer();

	static Renderer* _instance;

	unsigned int tilemap_texture_buffer;

	unsigned int vertex_buffer;

	unsigned int uv_buffer;
};

