#include "world1.h"

//void World1::ApplyGravity(Character* chr) {
	//if (gravity / 4) {
	//	gravity = 0;
	//}
	//chr->position.y += chr->velocity.y;
	//chr->velocity.y += gravity / 4;
//}

World1::World1() {
	SiroGen->BackgroundColor = {
		27,0,119,
	};
	SiroGen->BackgroundPalette[0] = {
		10, 10, 10,	105, 0, 0,		213, 12, 24
	};
	SiroGen->BackgroundPalette[1] = {
		91, 91, 91,	158, 158, 158,		255, 213, 0
	};
	SiroGen->ForgroundPalette[0] = {
		119, 74, 31,	253, 169, 100,		254, 252, 221
	};
	SiroGen->ForgroundPalette[1] = {
		255, 0, 20,		110, 191, 62,		42, 159, 71
	};
	SiroGen->ForgroundPalette[2] = {
		255, 255, 255,	222, 16, 20,		241, 235, 35
	};

	TileScreen* GUIScreen = new TileScreen{
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
	};
	SiroGen->SetGUIScreen(GUIScreen);


	TileScreens[255] = new TileScreen {
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		12,12,12,12,12,11,10,10,10,10,10,10,10,10,10,10,
		13,13,13,13,13,15,10,10,10,10,10,10,10,10,10,10,
		13,14,13,14,13,15,10,10,10,10,10,10,10,10,10,10,
		13,14,13,14,13,15,10,10,10,10,10,10,10,10,10,10,
		13,13,13,13,13,15,10,10,10,10,10,10,10,10,10,10,
		13,14,13,14,13,15,10,10,10,10,10,10,10,10,10,10,
		13,14,13,14,13,15,10,10,10,10,10,10,10,10,10,10,

		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		1,1,1,1,1,5,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,
		0,1,0,1,0,4,0,0,0,0,0,0,0,0,0,0,
		0,1,0,1,0,4,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,
		0,1,0,1,0,4,0,0,0,0,0,0,0,0,0,0,
		0,1,0,1,0,4,0,0,0,0,0,0,0,0,0,0,
	};

	TileScreens[0] = new TileScreen{
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,11,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,15,
		10,10,11,12,12,12,12,12,12,12,12,12,11,10,10,15,
		10,10,15,13,13,13,13,13,13,13,13,13,15,10,10,15,
		10,10,15,13,14,13,13,14,13,13,14,13,15,10,10,15,
		10,10,15,13,14,13,13,14,13,13,14,13,15,10,10,15,
		10,10,15,13,13,13,13,13,13,13,13,13,15,10,10,15,

		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,1,1,1,1,1,1,1,1,1,1,5,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,
		0,0,0,0,1,0,0,1,0,0,1,0,4,0,0,0,
		0,0,0,0,1,0,0,1,0,0,1,0,4,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,
	};

	TileScreens[1] = new TileScreen{
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		12,12,12,12,12,11,10,10,10,10,10,10,10,10,10,10,
		13,13,13,13,13,15,10,10,10,10,10,10,10,10,10,10,
		13,14,13,14,13,15,10,10,10,10,10,10,10,10,10,10,
		13,14,13,14,13,15,10,10,10,10,10,10,10,10,10,10,
		13,13,13,13,13,15,10,10,10,10,10,10,10,10,10,10,
		13,14,13,14,13,15,10,10,10,10,10,10,10,10,10,10,
		13,14,13,14,13,15,10,10,10,10,10,10,10,10,10,10,

		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		1,1,1,1,1,5,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,
		0,1,0,1,0,4,0,0,0,0,0,0,0,0,0,0,
		0,1,0,1,0,4,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,
		0,1,0,1,0,4,0,0,0,0,0,0,0,0,0,0,
		0,1,0,1,0,4,0,0,0,0,0,0,0,0,0,0,
	};
	TileScreens[2] = new TileScreen{
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,13,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,13,13,13,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,13,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,13,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,11,
		10,10,11,12,12,12,12,12,12,12,12,12,11,10,10,15,
		13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
		10,10,15,13,13,13,13,13,13,13,13,13,15,10,10,15,
		10,10,15,13,14,13,13,14,13,13,14,13,15,10,10,15,
		10,10,15,13,14,13,13,14,13,13,14,13,15,10,10,15,
		10,10,15,13,13,13,13,13,13,13,13,13,15,10,10,15,

		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,1,1,1,1,1,1,1,1,1,1,5,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,
		0,0,0,0,1,0,0,1,0,0,1,0,4,0,0,0,
		0,0,0,0,1,0,0,1,0,0,1,0,4,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,
	};

	TileScreens[3] = new TileScreen{
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		12,12,12,12,12,11,10,10,10,10,10,10,10,10,10,10,
		13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
		13,14,13,14,13,15,10,10,10,10,10,10,10,10,10,10,
		13,14,13,14,13,15,10,10,10,10,10,10,10,10,10,10,
		13,13,13,13,13,15,10,10,10,10,10,10,10,10,10,10,
		13,14,13,14,13,15,10,10,10,10,10,10,10,10,10,10,
		13,14,13,14,13,15,10,10,10,10,10,10,10,10,10,10,

		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		1,1,1,1,1,5,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,
		0,1,0,1,0,4,0,0,0,0,0,0,0,0,0,0,
		0,1,0,1,0,4,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,
		0,1,0,1,0,4,0,0,0,0,0,0,0,0,0,0,
		0,1,0,1,0,4,0,0,0,0,0,0,0,0,0,0,
	};

	player = new Player();
	player->hitbox.x = 6;
	player->hitbox.y = 0;
	player->hitbox.width = 4;
	player->hitbox.height = 16;
	player->position = { 7 * 16, 7 * 16 };
	SiroGen->SetSpritetoEntity(player, 0);
	AddtoScene(player);

	pickle = new Character();
	pickle->hitbox.x = 0;
	pickle->hitbox.y = 0;
	pickle->hitbox.width = 16;
	pickle->hitbox.height = 24;
	pickle->position = { 8 * 16, 10 * 16 };
	SiroGen->SetAttributetoEntity(pickle, 1);
	SiroGen->SetSpritetoEntity(pickle, 4);
	AddtoScene(pickle);

	enemywalk = Animation{0.2f, 7,6};
	gravity = 1;
	player->velocity = {2,0};
	player->gravity_damper = 4;
	pickle->gravity_damper = 4;

}

void World1::update() {

	SiroGen->PlayAnimation(pickle, &enemywalk, 1);
	//if (TileCol(pickle)) {
	//	printf("Hit!\n");
	//}
	if (GetInput()->KeyDown(KeyCode::A)) {
		pickle->position.x -= 1;
		SiroGen->SetAttributetoEntity(pickle, 5);
	}
	else if (GetInput()->KeyDown(KeyCode::D)) {
		pickle->position.x += 1;
		SiroGen->SetAttributetoEntity(pickle, 1);
	}
	//else if (GetInput()->KeyDown(KeyCode::W)) {
	//	pickle->position.y -= 1;
	//	SiroGen->SetAttributetoEntity(pickle, 1);
	//}
	//else if (GetInput()->KeyDown(KeyCode::S)) {
	//	pickle->position.y += 1;
	//	SiroGen->SetAttributetoEntity(pickle, 1);
	//}
	//if (GetInput()->KeyPressed(KeyCode::F)) {
	//	pickle->position.x -= 1;
	//	SiroGen->SetAttributetoEntity(pickle, 5);
	//}
	//else if (GetInput()->KeyPressed(KeyCode::H)) {
	//	pickle->position.x += 1;
	//	SiroGen->SetAttributetoEntity(pickle, 1);
	//}
	//else if (GetInput()->KeyPressed(KeyCode::T)) {
	//	pickle->position.y -= 1;
	//	SiroGen->SetAttributetoEntity(pickle, 1);
	//}
	//else if (GetInput()->KeyPressed(KeyCode::G)) {
	//	pickle->position.y += 1;
	//	SiroGen->SetAttributetoEntity(pickle, 1);
	//}
	if (GetInput()->KeyPressed(KeyCode::W) && pickle->onground) {
		//player->position.y -= 10;
		pickle->position.y -= 4;
		pickle->gravity = 0;
		pickle->velocity.y = -5;
	}
	//signed char difx = player2->position.x - player->position.x;
	//signed char dify = player2->position.y - player->position.y;
	//if (difx < 16 && difx > -16 && dify < 16 && dify > -16) {
	//	//printf("Hit!\n");
	//}
}

unsigned char World1::TileCol(Character* chr, unsigned char tiletype)
{
	unsigned char status = 0;
	unsigned char posx = ((chr->position.x + chr->hitbox.x) & 255) * 0.0625f;
	unsigned char posy = ((chr->position.y - chr->hitbox.y) & 255) * 0.0625f;
	posy *= 16;
	if (TileScreens[(chr->position.x + chr->hitbox.x) >> 8]->tiles[posx + posy] == tiletype) {
		status |= 0b0001;
	}
	posx = ((chr->position.x + chr->hitbox.x + (chr->hitbox.width - 1)) & 255) * 0.0625f;
	if (TileScreens[(chr->position.x + chr->hitbox.x + (chr->hitbox.width - 1)) >> 8]->tiles[posx + posy] == tiletype) {
		status |= 0b0010;
	}
	posy = ((chr->position.y - chr->hitbox.y - (chr->hitbox.height - 1)) & 255) * 0.0625f;
	posy *= 16;
	if (TileScreens[(chr->position.x + chr->hitbox.x + (chr->hitbox.width - 1)) >> 8]->tiles[posx + posy] == tiletype) {
		status |= 0b0100;
	}
	posx = ((chr->position.x + chr->hitbox.x) & 255) * 0.0625f;
	if (TileScreens[(chr->position.x + chr->hitbox.x) >> 8]->tiles[posx + posy] == tiletype) {
		status |= 0b1000;
	}
	return status;
}
