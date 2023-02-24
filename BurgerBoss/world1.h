#ifndef WORLD1_H_
#define WORLD1_H_

#include <SiroGen83/scene.h>

class World1 : public Scene {

public:
	World1();

	virtual void update() override;

	Entity* player = nullptr;

	Entity* player2 = nullptr;

	Animation playerwalk;

	bool TileCol(Entity* entity);

	unsigned char gravity = 0;
	Vector2 velocity = {0,0};
	Vector2 oldpos = {0,0};
	bool onground = false;
	bool onoff = false;

};

#endif
