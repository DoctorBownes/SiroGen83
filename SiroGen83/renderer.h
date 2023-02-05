#pragma once

#include <glad/glad.h>
#include <SiroGen83/tile.h>
#include <SiroGen83/vector2.h>
#include <SiroGen83/sprite.h>
#include <list>
#include <vector>

class Scene;
class Entity;

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

	void AddSpritetoMemory(Sprite* sprite, GLuint position);

	void SetSpritetoEntity(Entity* entity, GLuint position);

	void AddtoTileMap(Tile* tile, char position);

	void UpdateMainTile(Nametable* nametable, unsigned short tile);

	void UpdatePalettes();

	void SetRenderMode(Scene* scene, unsigned char mode);

	GLubyte rendermode = 1;

	Color BackgroundColor;

	Palette BackgroundPalette[4];
	Palette ForgroundPalette[4];


private:
	GLubyte bg_PaletteColors[4 * 4 * 4];
	GLubyte fg_PaletteColors[4 * 4 * 4];

	void EditTile(unsigned short tile, int test);

	std::vector<unsigned char> pixelcanvas;

	GLuint shaderProgram = 0;

	GLuint bg_PaletteSampler = 0;

	GLuint fg_PaletteSampler = 0;

	GLfloat VertexBuffer[12];

	GLfloat UVBuffer[12];

	GLfloat PaletteBuffer[6];

	Nametable* Maintables[2];

	void RenderMaintables(Scene* scene);

	void RenderEntity(Entity* entity);

	std::vector<GLubyte>TileMap;

	std::vector<GLfloat>MT_UVBuffer;

	std::vector<GLfloat>MT_VertexBuffer;

	std::vector<GLfloat>MT_PaletteBuffer;

	Renderer();

	static Renderer* _instance;

	GLuint tilemap_texture_buffer;

	GLuint vertex_buffer;

	GLuint uv_buffer;

	GLuint spr_uv_buffer;

	GLuint palette_buffer;

	GLubyte N = 0;

	Vector2 overwrite_pos{0,0};
};

