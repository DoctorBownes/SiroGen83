#ifndef WORLD1_H_
#define WORLD1_H_

#include <SiroGen83/scene.h>
#include <BurgerBoss/player.h>

class World1 : public Scene {

public:
	World1();

	virtual void update() override;

	Player* player = nullptr;

	Character* pickle = nullptr;

	Animation enemywalk;

	unsigned char TileCol(Character* chr, unsigned char tiletype);

	//void ApplyGravity(Character* chr);

	unsigned char gravity = 0;
	bool onoff = false;

};

#endif
