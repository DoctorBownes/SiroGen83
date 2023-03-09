#ifndef WORLD1_H_
#define WORLD1_H_

#include <SiroGen83/scene.h>
#include <BurgerBoss/character.h>

class World1 : public Scene {

public:
	World1();

	virtual void update() override;

	Character* player = nullptr;

	Character* pickle = nullptr;

	Animation playerwalk;
	Animation enemywalk;

	bool TileCol(Entity* entity);

	//void ApplyGravity(Character* chr);

	unsigned char gravity = 0;
	bool onground = false;
	bool onoff = false;

};

#endif
