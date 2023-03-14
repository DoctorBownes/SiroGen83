#include "player.h"
#include <SiroGen83/scene.h>

Player::Player() {
	playerwalk = Animation{ 0.075f, 1,0,2,0 };
}

void Player::update() {
	Character::update();
	if (GetInput()->KeyDown(KeyCode::Left)) {
		this->position.x -= this->velocity.x;
		GetScene()->SiroGen->SetAttributetoEntity(this, 4);
		GetScene()->SiroGen->PlayAnimation(this, &playerwalk, 3);
		GetScene()->GetCamera()->scrolldir.x = 0;
	}
	else if (GetInput()->KeyDown(KeyCode::Right)) {
		this->position.x += this->velocity.x;
		GetScene()->SiroGen->SetAttributetoEntity(this, 0);
		GetScene()->SiroGen->PlayAnimation(this, &playerwalk, 3);
		GetScene()->GetCamera()->scrolldir.x = 1;
	}
	else {
		GetScene()->SiroGen->SetSpritetoEntity(this, 0);
	}
	if (!onground) {
		GetScene()->SiroGen->SetSpritetoEntity(this, 3);
	}
	if (GetInput()->KeyPressed(KeyCode::Up) && onground) {
		//player->position.y -= 10;
		this->position.y -= 4;
		this->gravity = 0;
		this->velocity.y = -5;
	}

	if (GetInput()->KeyPressed(KeyCode::R)) {
		this->position.x = 128;
		this->position.y = 128;
	}
	GetScene()->GetCamera()->X = this->position.x - 112;
}
