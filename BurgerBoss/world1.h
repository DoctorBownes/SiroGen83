#ifndef WORLD1_H_
#define WORLD1_H_

#include <SiroGen83/scene.h>
#include <BurgerBoss/checkpoint.h>
#include <BurgerBoss/player.h>

class World1 : public Scene {

public:
	World1();

	virtual void update() override;

	Player* player = nullptr;

	Character* pickle = nullptr;
	Character* pickletoo = nullptr;

	std::forward_list<Entitiy_CheckPoint*> enemy_chkp[256];
	std::forward_list<CheckPoint*> array_chkp[256];

	const char* barney[12];

	Animation enemywalk;

	//std::vector<Character*> enemies[5];

	unsigned char TileCol(Character* chr, unsigned char tiletype);

	//void ApplyGravity(Character* chr);

	unsigned char gravity = 0;
	char onoff = true;

};

#endif
