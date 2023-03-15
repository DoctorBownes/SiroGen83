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

	colstat = 0;
	if (TileCol(this, 12) | TileCol(this, 11) & 3) {
		this->position.y -= (this->position.y - (((this->position.y) / 16) * 16) - 8);
		this->velocity.y = 0;
		onground = true;
	}
	else {
		onground = false;
	}
}

unsigned char Character::TileCol(Entity* entity, unsigned char tiletype) {
	unsigned char posx = ((position.x + hitbox.x) & 255) * 0.0625f;
	unsigned char posy = ((position.y - hitbox.y) & 255) * 0.0625f;
	posy *= 16;
	if (GetScene()->TileScreens[(position.x + hitbox.x) >> 8]->tiles[posx + posy] == tiletype) {
		colstat |= 0b0001;
	}
	posx = ((position.x + hitbox.x + (hitbox.width - 1)) & 255) * 0.0625f;
	posy = ((position.y - hitbox.y) & 255) * 0.0625f;
	posy *= 16;
	if (GetScene()->TileScreens[(position.x + hitbox.x + (hitbox.width - 1)) >> 8]->tiles[posx + posy] == tiletype) {
		colstat |= 0b0010;
	}
	posx = ((position.x + hitbox.x) & 255) * 0.0625f;
	posy = ((position.y - hitbox.y - (hitbox.height - 1)) & 255) * 0.0625f;
	posy *= 16;
	if (GetScene()->TileScreens[(position.x + hitbox.x) >> 8]->tiles[posx + posy] == tiletype) {
		colstat |= 0b0100;
	}
	posx = ((position.x + hitbox.x + (hitbox.width - 1)) & 255) * 0.0625f;
	posy = ((position.y - hitbox.y - (hitbox.height - 1)) & 255) * 0.0625f;
	posy *= 16;
	if (GetScene()->TileScreens[(position.x + hitbox.x + (hitbox.width - 1)) >> 8]->tiles[posx + posy] == tiletype) {
		colstat |= 0b1000;
	}
	return colstat;
}
