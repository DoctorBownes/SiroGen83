#pragma once
#include <SiroGen83/vector2.h>
#include <SiroGen83/input.h>

class Entity { //friend class Renderer
public:
	Entity();

	unsigned int texture_buffer;

	unsigned int palette_buffer;

	unsigned int vertex_buffer;

	unsigned int uv_buffer;

	Vector2 position{0,0};

	unsigned char attributes = 0;

	virtual void update();

	Input* GetInput() { return _instance; };

private:
	Input* _instance = _instance->GetInstance();
};
