#include "character.h"

Character::Character() {
	//_currentscene->
}

void Character::update() {
	if (gravity / gravity_damper) {
		gravity = 0;
	}
	gravity += 1;
	this->position.y += velocity.y;
	this->velocity.y += gravity / gravity_damper;
}
