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

	void SetUpMaintable(Nametable** nametables, unsigned char RenderPos);

	void UpdateMainTile(Nametable* nametable, unsigned short tile);

private:
	bool updatetiles = false;

	void EditTile(unsigned short tile, int test);

	std::vector<unsigned char> pixelcanvas;

	GLuint shaderProgram = 0;

	GLfloat VertexBuffer[12];

	GLfloat UVBuffer[12];

	Nametable* Maintables[4];

	//char MainTiles[960];
	//char MainFlip[960];

	void RenderMaintables(Scene* scene);

	void RenderEntity(Entity* entity);

	//void ProcessTileQueue();


	char TileMap[96 * 16];

	std::vector<GLfloat>MT_UVBuffer;

	std::vector<GLfloat>MT_VertexBuffer;

	Renderer();

	static Renderer* _instance;

	unsigned int tilemap_texture_buffer;

	unsigned int vertex_buffer;

	unsigned int uv_buffer;

	unsigned char N = 0;

	Vector2 overwrite_pos{0,0};

	unsigned short overwrite_posz = 0;
};

