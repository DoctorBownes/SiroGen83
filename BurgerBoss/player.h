#ifndef PLAYER_H_
#define PLAYER_H_

#include <BurgerBoss/character.h>
#include <SiroGen83/sprite.h>

class Player : public Character {

public:
	Player();

	virtual void update() override;

	Animation playerwalk;

};

#endif
