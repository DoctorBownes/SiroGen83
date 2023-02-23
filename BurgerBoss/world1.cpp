#include "world1.h"

World1::World1() {
	SiroGen->BackgroundColor = {
		97,153,255,
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


	TileScreens[0] = new TileScreen {
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,13,10,10,10,10,10,
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

	player = new Entity();
	player->position = { 10 * 16, 7 * 16 };
	SiroGen->SetSpritetoEntity(player, 0);
	entities.push_front(player);

	player2 = new Entity();
	player2->position = { 5 * 16, 9 * 16 };
	SiroGen->SetAttributetoEntity(player2, 1);
	SiroGen->SetSpritetoEntity(player2, 0);
	entities.push_front(player2);

	playerwalk = Animation{0.15f, 1,0};

}

bool World1::TileCol(Entity* entity) {
	for (char i = 0; i < 2; i++) {
		for (char j = 0; j < 2; j++) {
			unsigned char posx = (entity->position.x + 3 + i * 8) * 0.0625f;
			unsigned char posy = (entity->position.y + 3 + j * 12) * 0.0625f;
			posy *= 16;
			if (TileScreens[renderpos]->tiles[posx + posy] == 13) {
				return true;
			}
		}
	}
	return false;
}

void World1::update() {
	if (GetInput()->KeyDown(KeyCode::Left)) {
		player->position.x -= 1;
		SiroGen->SetAttributetoEntity(player, 4);
		SiroGen->PlayAnimation(player, &playerwalk, 1);
	}
	else if (GetInput()->KeyDown(KeyCode::Right)) {
		player->position.x += 1;
		SiroGen->SetAttributetoEntity(player, 0);
		SiroGen->PlayAnimation(player, &playerwalk, 1);
	}
	else if (GetInput()->KeyDown(KeyCode::Up)) {
		player->position.y -= 1;
		SiroGen->PlayAnimation(player, &playerwalk, 1);
	}
	else if (GetInput()->KeyDown(KeyCode::Down)) {
		player->position.y += 1;
		SiroGen->PlayAnimation(player, &playerwalk, 1);
	}
	else {
		SiroGen->SetSpritetoEntity(player, 0);
	}
	if (GetInput()->KeyDown(KeyCode::A)) {
		player2->position.x -= 2;
		SiroGen->SetAttributetoEntity(player2, 5);
		SiroGen->PlayAnimation(player2, &playerwalk, 1);
	}
	else if (GetInput()->KeyDown(KeyCode::D)) {
		player2->position.x += 2;
		SiroGen->SetAttributetoEntity(player2, 1);
		SiroGen->PlayAnimation(player2, &playerwalk, 1);
	}
	else {
		SiroGen->SetSpritetoEntity(player2, 0);
	}
	//GetCamera()->X = player->position.x - 112;

	signed char difx = player2->position.x - player->position.x;
	signed char dify = player2->position.y - player->position.y;
	if (difx < 16 && difx > -16 && dify < 16 && dify > -16) {
		printf("Hit!\n");
	}
	if (TileCol(player)) {
		printf("Hit!\n");
	}

	//printf("player->position.x: %d\n", player->position.x / 16);
	//printf("player->position.y: %d\n", player->position.y / 16);
}
