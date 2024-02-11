#include "world1.h"
#include <cmath>

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
	SiroGen->BackgroundPalette[2] = {
		91, 91, 91,	158, 158, 158,		200, 200, 200
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
	SiroGen->ForgroundPalette[3] = {
		163, 163, 163,	218, 255, 165,		253, 169, 100
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
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,14,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,14,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,14,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,14,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
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
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,14,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,14,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,14,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,14,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
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
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,14,
		10,10,10,10,14,10,14,10,10,10,10,10,10,10,10,14,
		10,10,10,10,14,10,14,10,10,10,10,10,10,10,10,14,
		10,10,10,14,10,10,10,14,10,10,10,10,10,10,10,14,
		10,10,10,14,10,10,10,14,10,10,10,10,10,10,10,10,
		10,10,10,10,14,14,14,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
		13,14,13,14,13,15,10,13,13,13,13,13,13,13,13,10,
		13,13,13,13,13,15,10,13,13,13,13,13,13,13,13,10,
		13,14,13,14,13,15,10,13,13,13,13,13,13,13,13,10,
		13,14,13,14,13,15,10,13,13,13,13,13,13,13,13,10,

		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,
		1,1,1,1,1,5,0,2,2,2,2,2,2,2,2,0,
		0,0,0,0,0,4,0,2,2,2,2,2,2,2,2,0,
		0,1,0,1,0,4,0,2,2,2,2,2,2,2,2,0,
		0,1,0,1,0,4,0,2,2,2,2,2,2,2,2,0,
		0,0,0,0,0,4,0,2,2,2,2,2,2,2,2,0,
		0,1,0,1,0,4,0,2,2,2,2,2,2,2,2,0,
		0,1,0,1,0,4,0,2,2,2,2,2,2,2,2,0,
	};
	TileScreens[16] = new TileScreen{
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

	TileScreens[17] = new TileScreen{
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

//	player = new Player();
//	player->hitbox.x = 6;
//	player->hitbox.y = 0;
//	player->hitbox.width = 4;
//	player->hitbox.height = 16;
//	player->position = { 7 * 16, 7 * 16 };
//	SiroGen->SetSpritetoEntity(player, 0);
//	//AddtoScene(player);
//
//	pickle = new Character();
//	pickle->hitbox.x = 0;
//	pickle->hitbox.y = 0;
//	pickle->hitbox.width = 16;
//	pickle->hitbox.height = 24;
//	pickle->position = { 0, 5 * 16 };
//	SiroGen->SetAttributetoEntity(pickle, 1);
//	SiroGen->SetSpritetoEntity(pickle, 7);
//	//AddtoScene(pickle);
//
//	pickletoo = new Character();
//	pickletoo->hitbox.x = 0;
//	pickletoo->hitbox.y = 0;
//	pickletoo->hitbox.width = 16;
//	pickletoo->hitbox.height = 24;
//	pickletoo->position = { 400, 8 * 16 };
//	SiroGen->SetAttributetoEntity(pickletoo, 1);
//	SiroGen->SetSpritetoEntity(pickletoo, 7);
//
//	enemywalk = Animation{30, 7,6};
//	gravity = 1;
//	player->velocity = {2,0};
//	player->gravity_damper = 4;
//	pickle->gravity_damper = 4;
//	pickletoo->gravity_damper = 4;
//	pickle->velocity = { 1,0 };
//	pickletoo->velocity = { 1,0 };
//
//	//checkpoints[pickle->position.x >> 8].push_front(pickle);
//	//checkpoints[pickletoo->position.x >> 8].push_front(pickletoo);
//	Entitiy_CheckPoint* chkp1 = new Entitiy_CheckPoint();
//	chkp1->posx = 400;
//	chkp1->heldentity = pickle;
//	enemy_chkp[chkp1->posx >> 8].push_front(chkp1);
//	CheckPoint* chkp2 = new CheckPoint{300,0};
//	CheckPoint* chkp3 = new CheckPoint{100,0};
//	array_chkp[chkp2->posx >> 8].push_front(chkp2);
//	array_chkp[chkp3->posx >> 8].push_front(chkp3);
//	barney[0] = "Mario\n";
//	barney[1] = "Luigi\n";
//	onoff = 0;
	//enemies[pickle->position.x >> 8].push_back(pickle);
	//enemies[pickletoo->position.x >> 8].push_back(pickletoo);
}

void World1::update() {
	//unsigned char playpage = player->position.x >> 8;
	//for (unsigned char i = 0; i < 2; i++) {
	//	for (Entitiy_CheckPoint* echkp : enemy_chkp[playpage + i]) {
	//		if (!echkp->flag) {
	//			if (player->position.x - echkp->posx >= -128) {
	//				echkp->heldentity->position.x = echkp->posx;
	//				AddtoScene(echkp->heldentity);
	//				echkp->flag = 1;
	//			}
	//		}
	//	}
	//}
	//for (Entitiy_CheckPoint* echkp : enemy_chkp[(unsigned char)(playpage -1)]) {
	//	echkp->flag = 0;
	//}
	//printf("%s", barney[onoff]);
	
	//unsigned char playpage = player->position.x >> 8;
	//for (unsigned char i = 0; i < 2; i++) {
	//	for (Entity* enemy : checkpoints[playpage + i]) {
	//		if (!enemy->flag) {
	//			if (player->position.x - enemy->position.x >= -128) {
	//				printf("Spawned!\n");
	//				AddtoScene(enemy);
	//				enemy->flag = 1;
	//			}
	//		}
	//	}
	//}
	//entities.remove_if([&](Entity* entity) {
	//	return GetCamera()->X - 128 >= entity->position.x;
	//});
	//for (Entity* enemi : checkpoints[unsigned char(playpage - 1)]) {
	//	enemi->flag = 0;
	//}
	//enemies[pagepos][i]->position.x += enemies[pagepos][i]->velocity.x;
	//unsigned char test = (TileCol(enemies[pagepos][i], 11) | TileCol(enemies[pagepos][i], 12));
	//if (test != 3) {
	//	enemies[pagepos][i]->velocity.x *= -1;
	//	SiroGen->SetAttributetoEntity(enemies[pagepos][i], 1 + 4 * (test - 1));
	//}
	//SiroGen->PlayAnimation(enemies[pagepos][i], &enemywalk, 1);
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
