#include "character.h"
#include <SiroGen83/scene.h>

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

	if (TileCol(this)) {
		//if (!onground) {
		//}
		this->position.y -= (this->position.y - (((this->position.y) / 16) * 16) - 9);
		this->velocity.y = 0;
		onground = true;
	}
	else {
		onground = false;
	}
}

bool Character::TileCol(Entity* entity) {
	for (char i = 0; i < 2; i++) {
		for (char j = 0; j < 2; j++) {
			unsigned char posx = ((entity->position.x + i * (width - 1) & 255)) * 0.0625f;
			unsigned char posy = ((entity->position.y - 8 + j * (height -1))) * 0.0625f;
			posy *= 16;
			switch (GetScene()->TileScreens[(entity->position.x + i * (width - 1)) >> 8]->tiles[posx + posy]) {
			case	12:
				return true;
				break;
			case	11:
				return true;
				break;
			}
		}
	}
	return false;
}
