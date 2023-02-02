#pragma once

#include <SiroGen83/camera.h>
#include <SiroGen83/renderer.h>
#include <SiroGen83/entity.h>
#include <forward_list>

class Scene : public Entity {
public:
	std::forward_list<Entity*> entities;

	Camera* GetCamera() { return _camera; };

	unsigned char renderpos = 0;

	//unsigned char rendermode = 1;

	Nametable* Nametables[256];

protected:
	Renderer* SiroGen = SiroGen->GetInstance();

private:
	Camera* _camera = new Camera();
};
