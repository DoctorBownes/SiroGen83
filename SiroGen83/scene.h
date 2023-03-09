#ifndef SCENE_H_
#define SCENE_H_

#include <SiroGen83/camera.h>
#include <SiroGen83/renderer.h>
#include <SiroGen83/entity.h>
#include <forward_list>


class Scene : public Entity {
public:

	std::forward_list<Entity*> entities;

	Camera* GetCamera() { return _camera; };

	unsigned char renderpos = 0;

	TileScreen* TileScreens[256];

	Renderer* SiroGen = SiroGen->GetInstance();

private:
	Camera* _camera = new Camera();
};

#define AddtoScene(entity){ \
entity->SetScene(this); \
entities.push_front(entity); \
}

#define RemovefromScene(entity){ \
entity->SetScene(nullptr); \
entities.remove(entity); \
}

#endif
