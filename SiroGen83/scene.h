#pragma once

#include <SiroGen83/entity.h>
#include <SiroGen83/camera.h>
#include <SiroGen83/tile.h>

class Scene : public Entity {
public:
	Entity* entities[1];

	Camera* GetCamera() { return _camera; };

	Screen* Screens[16];

private:
	Camera* _camera = new Camera();
};
