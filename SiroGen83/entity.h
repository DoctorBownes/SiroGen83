#pragma once
#include <SiroGen83/vector2.h>

class Entity {
public:
	Entity();

	unsigned int texture_buffer;

	unsigned int vertex_buffer;

	Vector2 position{0,0};

	virtual void update();
};
