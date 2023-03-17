#include "player.h"
#include <SiroGen83/scene.h>

Player::Player() {
	playerwalk = Animation{ 0.075f, 1,0,2,0 };
	hitspatula = Animation{ 0.1f, 0,5,4};
}

void Player::BeginPlay() {
	spatula = new Entity();
	GetScene<Scene>()->entities.push_front(spatula);
	spatula->SetScene(GetScene<Scene>());
	spatula->GetScene<Scene>()->SiroGen->SetAttributetoEntity(spatula, 3);
	spatula->GetScene<Scene>()->SiroGen->SetSpritetoEntity(spatula, 4);
	spatula->position.x = position.x + 11;
	spatula->position.y = position.y - 5;
}

void Player::update() {
	Character::update();
	if (GetInput()->KeyDown(KeyCode::Left)) {
		this->position.x -= this->velocity.x;
		GetScene<Scene>()->SiroGen->SetAttributetoEntity(this, 4);
		GetScene<Scene>()->SiroGen->PlayAnimation(this, &playerwalk, 3);
		GetScene<Scene>()->GetCamera()->scrolldir.x = 0;
		spatula->position.x = position.x -7;
		spatula->GetScene<Scene>()->SiroGen->SetAttributetoEntity(spatula, 7);
	}
	else if (GetInput()->KeyDown(KeyCode::Right)) {
		this->position.x += this->velocity.x;
		GetScene<Scene>()->SiroGen->SetAttributetoEntity(this, 0);
		GetScene<Scene>()->SiroGen->PlayAnimation(this, &playerwalk, 3);
		GetScene<Scene>()->GetCamera()->scrolldir.x = 1;
		spatula->position.x = position.x + 11;
		spatula->GetScene<Scene>()->SiroGen->SetAttributetoEntity(spatula,3);
	}
	else {
		GetScene<Scene>()->SiroGen->SetSpritetoEntity(this, 0);
	}
	if (!onground) {
		GetScene<Scene>()->SiroGen->SetSpritetoEntity(this, 3);
	}
	if (GetInput()->KeyPressed(KeyCode::Up) && onground) {
		//player->position.y -= 10;
		this->position.y -= 4;
		this->gravity = 0;
		this->velocity.y = -5;
	}

	if (GetInput()->KeyPressed(KeyCode::Space)) {
		spatula->frame = 1;
	}
	else if (spatula->frame > 0) {
		spatula->GetScene<Scene>()->SiroGen->PlayAnimation(spatula, &hitspatula, 2);
	}

	if (GetInput()->KeyPressed(KeyCode::R)) {
		this->position.x = 128;
		this->position.y = 128;
	}
	spatula->position.y = position.y - 5;
	GetScene<Scene>()->GetCamera()->X = this->position.x - 112;
}
