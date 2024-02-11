#ifndef PLAYER_H_
#define PLAYER_H_

#include <BurgerBoss/character.h>

class Player : public Character {

public:
	Player();

	virtual void BeginPlay() override;

	virtual void update() override;

	Animation playerwalk;
	Animation hitspatula;

	Entity* spatula = nullptr;

};

#endif
