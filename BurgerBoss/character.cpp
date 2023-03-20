#include "character.h"
#include <BurgerBoss/world1.h>

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

	if (GetScene<World1>()->TileCol(this, 12) | GetScene<World1>()->TileCol(this, 11) & 3) {
		while (this->position.y - (((this->position.y) / 16) * 16) & 8) {
			//printf("coldif: %d\n", 16 - (this->position.y - (((this->position.y) / 16) * 16)) & 4);
			this->position.y--;
			this->velocity.y = 0;
			onground = true;
		}
		//this->position.y -= (this->position.y - (((this->position.y) / 16) * 16) - 8);
	}
	else {
		onground = false;
	}
	//printf("colstat: %d\n", colstat);
}

//unsigned char Character::TileCol(Character* chr, unsigned char tiletype) {
//	unsigned char posx = ((chr->position.x + chr->hitbox.x) & 255) * 0.0625f;
//	unsigned char posy = ((chr->position.y - chr->hitbox.y) & 255) * 0.0625f;
//	posy *= 16;
//	if (GetScene<World1>()->TileScreens[(chr->position.x + chr->hitbox.x) >> 8]->tiles[posx + posy] == tiletype) {
//		colstat |= 0b0001;
//	}
//	posx = ((chr->position.x + chr->hitbox.x + (chr->hitbox.width - 1)) & 255) * 0.0625f;
//	if (GetScene<World1>()->TileScreens[(chr->position.x + chr->hitbox.x + (chr->hitbox.width - 1)) >> 8]->tiles[posx + posy] == tiletype) {
//		colstat |= 0b0010;
//	}
//	posy = ((chr->position.y - chr->hitbox.y - (chr->hitbox.height - 1)) & 255) * 0.0625f;
//	posy *= 16;
//	if (GetScene<World1>()->TileScreens[(chr->position.x + chr->hitbox.x + (chr->hitbox.width - 1)) >> 8]->tiles[posx + posy] == tiletype) {
//		colstat |= 0b0100;
//	}
//	posx = ((chr->position.x + chr->hitbox.x) & 255) * 0.0625f;
//	if (GetScene<World1>()->TileScreens[(chr->position.x + chr->hitbox.x) >> 8]->tiles[posx + posy] == tiletype) {
//		colstat |= 0b1000;
//	}
//	return colstat;
//}
