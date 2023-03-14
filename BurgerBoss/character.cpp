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
		this->position.y -= (this->position.y - (((this->position.y) / 16) * 16) - 8);
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
			unsigned char posx = ((position.x + hitbox.x + i * (hitbox.width - 1) & 255)) * 0.0625f;
			unsigned char posy = ((position.y - hitbox.y - j * (hitbox.height - 1) & 255)) * 0.0625f;
			posy *= 16;
			switch (GetScene()->TileScreens[(position.x + hitbox.x + i * (hitbox.width - 1)) >> 8]->tiles[posx + posy]) {
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
