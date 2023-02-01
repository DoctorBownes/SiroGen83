#pragma once

#include <glad/glad.h>
#include <SiroGen83/scene.h>
#include <list>
#include <vector>

struct Palette {
	Color colors[3];
};

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

	void UpdateMainTile(Nametable* nametable, unsigned short tile);

	void UpdatePalettes();

	void SetRenderMode(Scene* scene, unsigned char mode);

	unsigned char rendermode = 1;

	Color BackgroundColor;

	Palette BackgroundPalette[4];
	Palette ForgroundPalette[4];

private:
	unsigned char bg_PaletteColors[4 * 4 * 4];
	unsigned char fg_PaletteColors[4 * 4 * 4];

	void EditTile(unsigned short tile, int test);

	std::vector<unsigned char> pixelcanvas;

	GLuint shaderProgram = 0;

	GLuint PaletteSampler = 0;

	GLfloat VertexBuffer[12];

	GLfloat UVBuffer[12];

	Nametable* Maintables[2];

	void RenderMaintables(Scene* scene);

	void RenderEntity(Entity* entity);

	std::vector<unsigned char>TileMap;

	std::vector<GLfloat>MT_UVBuffer;

	std::vector<GLfloat>MT_VertexBuffer;

	std::vector<GLfloat>MT_PaletteBuffer;

	Renderer();

	static Renderer* _instance;

	GLuint tilemap_texture_buffer;

	GLuint vertex_buffer;

	GLuint uv_buffer;

	GLuint palette_buffer;

	unsigned char N = 0;

	Vector2 overwrite_pos{0,0};
};

