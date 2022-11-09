#pragma once

#include <SiroGen83/entity.h>
#include <SiroGen83/camera.h>

class Scene : public Entity {
public:
	Entity entities[5];

	Camera* GetCamera() { return _camera; };

private:
	Camera* _camera = new Camera();
};
