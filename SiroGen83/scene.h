#pragma once

#include <SiroGen83/entity.h>
#include <SiroGen83/camera.h>
#include <SiroGen83/tile.h>
#include <forward_list>

class Scene : public Entity {
public:
	std::forward_list<Entity*> entities;

	Camera* GetCamera() { return _camera; };

	Vector2 renderpos = {0,0};

	Nametable** Nametables;

private:
	Camera* _camera = new Camera();
};
