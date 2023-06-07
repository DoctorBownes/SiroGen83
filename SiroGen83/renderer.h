#ifndef RENDERER_H_
#define RENDERER_H_

#include <glad/glad.h>
#include <SiroGen83/tile.h>
#include <SiroGen83/vector2.h>
#include <SiroGen83/sprite.h>
#include <list>
#include <vector>

#define PALETTE_ZERO 0
#define PALETTE_ONE 1
#define PALETTE_TWO 2
#define PALETTE_THREE 3

#define FLIP_NONE 0
#define FLIP_HORT 4
#define FLIP_VERT 8
#define FLIP_DIAG 12

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

	void SetAttributetoEntity(Entity* entity, GLuint attribute);

	void AddtoTileMap(Tile tile, char position);

	void UpdateMainTile(TileScreen* tilescreen, unsigned short tile);

	void UpdateGUITile(unsigned short tile);

	void UpdatePalettes();

	void SetRenderMode(Scene* scene);

	void SetGUIScreen(TileScreen* tilescreen);

	void DeactivateGUIScreen() { GUIScreen = nullptr; };

	void SetTileDigits(int score, unsigned char posR2L, unsigned char blankdigit = 0);

	void PlayAnimation(Entity* entity, Animation* animation, unsigned char endframe, unsigned char beginframe = 0);

	Color BackgroundColor;

	Palette BackgroundPalette[4];
	Palette ForgroundPalette[4];

private:

	TileScreen* GUIScreen = nullptr;

	GLubyte bg_PaletteColors[4 * 4 * 4];
	GLubyte fg_PaletteColors[4 * 4 * 4];

	void EditTile(unsigned short tile);

	GLuint shaderProgram = 0;

	GLuint bg_PaletteSampler = 0;

	GLuint fg_PaletteSampler = 0;

	GLfloat VertexBuffer[12];

	GLfloat UVBuffer[12];

	GLfloat PaletteBuffer[6];

	TileScreen* MainScreen[4];

	void RenderMainScreens(Scene* scene, unsigned char num, Vector2 pos);

	void RenderGUIScreen(Scene* scene);

	void RenderEntity(Entity* entity);

	std::vector<GLubyte>TileMap;
	float MapSize = 0.0f;

	GLfloat MT_UVBuffer[4][2880 * 4];
	GLfloat MT_VertexBuffer[4][2880 * 4];
	GLfloat MT_PaletteBuffer[4][1440 * 4];

	GLfloat GUI_UVBuffer[2880 * 4];
	GLfloat GUI_PaletteBuffer[1440 * 4];

	Renderer();

	static Renderer* _instance;

	GLuint tilemap_texture_buffer;

	GLuint uv_buffer;
	GLuint vertex_buffer;
	GLuint palette_buffer;

	GLuint fuv_buffer;
	GLuint fpalette_buffer;

	GLubyte N = 0;

	Vector2 overwrite_pos{0,0};
	unsigned short overwrite_posz = 0;

	unsigned short lo_CamX = 0;
	unsigned short lo_CamY = 0;

	unsigned short lo_EntX = 0;
	unsigned short lo_EntY = 0;
};

#endif
