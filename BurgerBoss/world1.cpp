#include "world1.h"

bool World1::TileCol(Entity* entity) {
	for (char i = 0; i < 2; i++) {
		for (char j = 0; j < 2; j++) {
			unsigned char posx = ((entity->position.x + 6 + i * 3 & 255)) * 0.0625f;
			unsigned char posy = ((entity->position.y) - 5 + j * 12) * 0.0625f;//TODO MAKE BETTER
			posy *= 16;
			if (TileScreens[(entity->position.x + 6 + i * 3) >> 8]->tiles[posx + posy] == 12 || TileScreens[(entity->position.x + 6 + i * 3) >> 8]->tiles[posx + posy] == 11) {
				return true;
			}
		}
	}
	return false;
}

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

	player = new Entity();
	player->position = { 10 * 16, 7 * 16 };
	SiroGen->SetSpritetoEntity(player, 0);
	entities.push_front(player);

	//player2 = new Entity();
	//player2->position = { 5 * 16, 9 * 16 };
	//SiroGen->SetAttributetoEntity(player2, 1);
	//SiroGen->SetSpritetoEntity(player2, 0);
	//entities.push_front(player2);

	playerwalk = Animation{0.075f, 1,0,2,0};

	gravity = 1;
	velocity = {2,0};

}

void World1::update() {
	if (gravity / 4) {
		gravity = 0;
	}
	gravity += 1;
	player->position.y += velocity.y;
	velocity.y += gravity / 4;
	if (GetInput()->KeyDown(KeyCode::Left)) {
		player->position.x -= velocity.x;
		SiroGen->SetAttributetoEntity(player, 4);
		SiroGen->PlayAnimation(player, &playerwalk, 3);
		GetCamera()->scrolldir.x = 0;
	}
	else if (GetInput()->KeyDown(KeyCode::Right)) {
		player->position.x += velocity.x;
		SiroGen->SetAttributetoEntity(player, 0);
		SiroGen->PlayAnimation(player, &playerwalk, 3);
		GetCamera()->scrolldir.x = 1;
	}
	else {
		SiroGen->SetSpritetoEntity(player, 0);
	}
	if (GetInput()->KeyPressed(KeyCode::Space) && onground) {
		//player->position.y -= 10;
		player->position.y -= 1;
		gravity = 0;
		velocity.y = -5;
	}

	if (GetInput()->KeyPressed(KeyCode::A)) {
		player->position.x -= 1;
		SiroGen->SetAttributetoEntity(player, 4);
		SiroGen->PlayAnimation(player, &playerwalk, 3);
	}
	else if (GetInput()->KeyPressed(KeyCode::D)) {
		player->position.x += 1;
		SiroGen->SetAttributetoEntity(player, 0);
		SiroGen->PlayAnimation(player, &playerwalk, 3);
	}
	GetCamera()->X = player->position.x - 112;

	//signed char difx = player2->position.x - player->position.x;
	//signed char dify = player2->position.y - player->position.y;
	//if (difx < 16 && difx > -16 && dify < 16 && dify > -16) {
	//	//printf("Hit!\n");
	//}
	if (TileCol(player)) {
		velocity.y = 0;
		player->position.y = oldpos.y + 1;//TODO FIX
		onground = true;
	}
	else {
		onground = false;
		oldpos.y = player->position.y;
	}
	//printf("gravity: %d\n", gravity);
}
