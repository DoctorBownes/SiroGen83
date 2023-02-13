#ifndef ENTITY_H_
#define ENTITY_H_
#include <SiroGen83/vector2.h>
#include <SiroGen83/input.h>

class Entity { //friend class Renderer
public:
	Entity();

	Vector2 position{0,0};

	virtual void update();

	Input* GetInput() { return _instance; };

	friend class Renderer;

private:
	float starttime = 0.0;

	unsigned char frame = 0;

	unsigned short texture_buffer;

	unsigned short palette_buffer = 1;

	unsigned short vertex_buffer;

	unsigned short uv_buffer = 5;

	Input* _instance = _instance->GetInstance();
};

#endif
