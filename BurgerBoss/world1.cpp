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
		127,0,219,
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
		10,10,10,10,10,10,10,12,10,10,10,10,10,10,10,10,
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
	player->position = { 10 * 16, 7 * 16 };
	SiroGen->SetSpritetoEntity(player, 0);
	AddtoScene(player);

	pickle = new Character();
	pickle->hitbox.x = 0;
	pickle->hitbox.y = 8;//fix this
	pickle->hitbox.width = 16;
	pickle->hitbox.height = 24;
	pickle->position = { 5 * 16, 9 * 16 };
	SiroGen->SetAttributetoEntity(pickle, 1);
	SiroGen->SetSpritetoEntity(pickle, 4);
	AddtoScene(pickle);

	enemywalk = Animation{0.2f, 5,4};
	gravity = 1;
	player->velocity = {1,0};
	player->gravity_damper = 4;
	pickle->gravity_damper = 4;

}

void World1::update() {

	SiroGen->PlayAnimation(pickle, &enemywalk, 1);
	//if (TileCol(player)) {
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

bool World1::TileCol(Character* chr)
{
	for (char i = 0; i < 2; i++) {
		for (char j = 0; j < 2; j++) {
			unsigned char posx = ((chr->position.x + chr->hitbox.x + i * (chr->hitbox.width - 1) & 255)) * 0.0625f;
			unsigned char posy = ((chr->position.y - chr->hitbox.y + j * (chr->hitbox.height - 1) & 255)) * 0.0625f;
			posy *= 16;
			switch (TileScreens[(chr->position.x + chr->hitbox.x + i * (chr->hitbox.width - 1)) >> 8]->tiles[posx + posy]) {
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
