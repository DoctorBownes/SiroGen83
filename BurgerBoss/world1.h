#ifndef WORLD1_H_
#define WORLD1_H_

#include <list>
#include <SiroGen83/scene.h>
#include <BurgerBoss/player.h>

class World1 : public Scene {

public:
	World1();

	virtual void update() override;

	Player* player = nullptr;

	Character* pickle = nullptr;
	Character* pickletoo = nullptr;

	Animation enemywalk;

	std::list<Character*>::iterator it;
	std::list<Character*> enemies;

	unsigned char TileCol(Character* chr, unsigned char tiletype);

	//void ApplyGravity(Character* chr);

	unsigned char gravity = 0;
	bool onoff = true;

};

#define AddEnemytoScene(entity){ \
AddtoScene(entity); \
enemies.push_back(entity); \
}

#define RemoveEnemyFromScene(entity){ \
RemovefromScene(entity); \
enemies.remove(entity); \
}

#endif
