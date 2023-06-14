#include "playground.h"

PlayGround::PlayGround() {
	SiroGen->BackgroundColor = {
		0,0,0
	};
	SiroGen->BackgroundPalette[0] = {
		135, 103, 62,	214, 182, 141,		221, 217, 212,
	};
	SiroGen->BackgroundPalette[1] = {
		94, 71, 44,	190, 205, 232,		255, 255, 244
	};
	SiroGen->BackgroundPalette[2] = {
		135, 59, 58,		127, 140, 122,		211, 194, 173,
	};
	SiroGen->BackgroundPalette[3] = {
		96, 96, 96,	153, 153, 153,	255, 255, 255,
	};

	SiroGen->ForgroundPalette[0] = {
		0, 0, 0,	211, 176, 116,		255, 249, 249,
	};
	SiroGen->ForgroundPalette[1] = {
		0, 0, 0,	61, 125, 255,		255, 198, 198,
	};
	SiroGen->ForgroundPalette[2] = {
		0, 0, 0,	229, 52, 82,		255, 198, 198,
	};
	SiroGen->ForgroundPalette[3] = {
		0, 0, 0,	153, 134, 120,		255, 198, 198,
	};

	TileScreens[0] = new TileScreen{
10,10,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,10,10,
10,10,14,14,10,10,10,10,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,10,10,
10,10,11,11,17,17,17,17,11,12,13,12,13,12,13,12,13,12,13,12,13,12,13,12,13,11,11,11,11,11,10,10,
10,10,11,11,17,17,17,17,11,12,13,12,13,12,13,12,13,12,13,12,13,12,13,12,13,11,11,11,11,11,10,10,
10,10,11,11,11,11,11,11,11,12,13,12,13,12,13,12,26,27,13,12,13,12,13,12,13,11,11,11,11,11,10,10,
10,10,11,11,11,11,11,11,11,12,13,12,13,12,13,12,28,29,13,12,13,12,13,12,13,11,11,11,11,11,10,10,
18,19,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,16,16,
20,21,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,16,16,
10,10,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,16,16,
10,10,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,16,16,
10,10,11,11,11,11,22,23,11,11,11,11,22,23,11,11,11,11,22,23,11,11,11,11,22,23,11,11,11,11,10,10,
10,10,11,11,11,11,24,25,11,11,11,11,24,25,11,11,11,11,24,25,11,11,11,11,24,25,11,11,11,11,10,10,
10,10,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,10,10,
10,10,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,10,10,
10,10,11,11,11,11,22,23,11,11,11,11,22,23,11,11,11,11,22,23,11,11,11,11,22,23,11,11,11,11,16,16,
10,10,11,11,11,11,24,25,11,11,11,11,24,25,11,11,11,11,24,25,11,11,11,11,24,25,11,11,11,11,16,16,
10,10,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,16,16,
10,10,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,16,16,
10,10,11,11,11,11,22,23,11,11,11,11,22,23,11,11,11,11,22,23,11,11,11,11,22,23,11,11,11,11,10,10,
10,10,11,11,11,11,24,25,11,11,11,11,24,25,11,11,11,11,24,25,11,11,11,11,24,25,11,11,11,11,10,10,
10,10,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,10,10,
10,10,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,10,10,
18,19,11,11,11,11,22,23,11,11,11,11,22,23,11,11,11,11,22,23,11,11,11,11,22,23,11,11,11,11,16,16,
20,21,11,11,11,11,24,25,11,11,11,11,24,25,11,11,11,11,24,25,11,11,11,11,24,25,11,11,11,11,16,16,
10,10,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,16,16,
10,10,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,16,16,
10,10,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,10,10,
10,10,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,10,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
15,15,15,15,15,15,16,16,16,16,15,15,15,15,16,16,16,16,15,15,15,15,16,16,16,16,15,15,15,15,15,15,

1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	};

	player = new Entity();
	player->position.x = 64;
	player->position.y = 64;
	SiroGen->SetSpritetoEntity(player, 0);
	AddtoScene(player);

	playerWalkingdown = new Animation{ 10, 1,0, 3,2, 5,4 };

	printf("%d\n", sizeof(Entity));
}

unsigned char test = 4;

void PlayGround::update() {
	if (GetInput()->KeyDown(KeyCode::Down)) {
		player->position.y++;
		if (SiroGen->PlayAnimation(player, playerWalkingdown, 1, 0)) {
			SiroGen->SetAttributetoEntity(player, test);
			test = (~test & 4);
		}
	}else if (GetInput()->KeyDown(KeyCode::Up)) {
		player->position.y--;
		if (SiroGen->PlayAnimation(player, playerWalkingdown, 3, 2)) {
			SiroGen->SetAttributetoEntity(player, test);
			test = (~test & 4);
		}
	}
	else if (GetInput()->KeyDown(KeyCode::Right)) {
		player->position.x++;
		SiroGen->PlayAnimation(player, playerWalkingdown, 5, 4);
		SiroGen->SetAttributetoEntity(player, 0);
	}
	else if (GetInput()->KeyDown(KeyCode::Left)) {
		player->position.x--;
		SiroGen->PlayAnimation(player, playerWalkingdown, 5, 4);
		SiroGen->SetAttributetoEntity(player, 4);
	}
	else {
		SiroGen->PlayAnimation(player, playerWalkingdown, 1, 1);
	}
	printf("%d\n", player->frame);
}
