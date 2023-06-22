#include "tavern.h"

Tavern::Tavern() {
	SiroGen->BackgroundColor = {
		0,0,200
	};
	SiroGen->MainPalette = {
		0,0,0, 255,255,255,	255, 146, 73,	
		255, 30, 39,  0, 73, 146, 36,146,255, 
		146, 36,0, 255,0,73, 255, 146, 0, 
		181,214,255, 232, 242, 255, 128,128,128,
		124, 108, 88, 196,23,32, 145,17,25, 229, 214, 172,
		219, 73, 36
	};
	
	TileScreens[0] = new TileScreen{
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,10,10,15,15,15,15,16,16,16,16,16,16,15,15,15,15,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,10,10,15,15,15,15,16,16,16,16,16,16,15,15,15,15,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,10,10,14,14,14,14,16,16,16,16,16,16,14,14,14,14,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,10,10,12,13,12,13,12,13,12,13,12,13,12,13,12,13,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,10,10,12,13,12,13,12,13,12,13,12,13,12,13,12,13,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,10,10,12,13,12,13,12,13,12,13,12,13,12,13,12,13,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,16,16,12,13,12,13,12,13,12,13,12,13,12,13,12,13,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,16,16,12,13,12,13,12,13,12,13,12,13,12,13,12,13,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,16,16,12,13,12,13,12,13,12,13,12,13,12,13,12,13,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,16,16,12,13,12,13,12,13,12,13,12,13,12,13,12,13,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,16,16,12,13,12,13,12,13,12,13,12,13,12,13,12,13,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,16,16,12,13,12,13,12,13,12,13,12,13,12,13,12,13,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,10,10,12,13,12,13,12,13,12,13,12,13,12,13,12,13,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,10,10,12,13,12,13,12,13,12,13,12,13,12,13,12,13,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,16,16,12,13,12,13,12,13,12,13,12,13,12,13,12,13,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,16,16,12,13,12,13,12,13,12,13,12,13,12,13,12,13,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,16,16,12,13,12,13,12,13,12,13,12,13,12,13,12,13,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,16,16,12,13,12,13,12,13,12,13,12,13,12,13,12,13,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,16,16,12,13,12,13,12,13,12,13,12,13,12,13,12,13,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,16,16,12,13,12,13,12,13,12,13,12,13,12,13,12,13,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,10,10,12,13,12,13,12,13,12,13,12,13,12,13,12,13,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,10,10,12,13,12,13,12,13,12,13,12,13,12,13,12,13,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,10,10,12,13,12,13,12,13,12,13,12,13,12,13,12,13,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,10,10,12,13,12,13,12,13,12,13,12,13,12,13,12,13,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,10,10,12,13,12,13,12,13,12,13,12,13,12,13,12,13,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,10,10,12,13,12,13,12,13,12,13,12,13,12,13,12,13,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,10,10,12,13,12,13,12,13,12,13,12,13,12,13,12,13,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,10,10,12,13,12,13,12,13,12,13,12,13,12,13,12,13,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,10,10,12,13,12,13,12,13,12,13,12,13,12,13,12,13,

0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	};

	player = new Entity();
	player->position.y = 80;
	player->position.x = 176;
	SiroGen->SetSpritetoEntity(player, 0);

	glass = new Entity();
	glass->position.x = player->position.x + 16;
	glass->position.y = player->position.y - 24;

	barfly = new Entity();
	barfly->position.x = 16;
	barfly->position.y = 112;
	SiroGen->SetSpritetoEntity(barfly, 5);

	entities.push_front(player);
	entities.push_front(glass);
	entities.push_front(barfly);
	BeerFilling = new Animation{ 5, 1,2,3,4 };
}

Entity* Tavern::SpawnBeer(void) {
	Entity* beer = new Entity();
	beer->position.x = player->position.x + 16;
	beer->position.y = player->position.y - 24;
	SiroGen->SetSpritetoEntity(beer, 4);
	Tap.push_back(beer);
	entities.push_front(beer);
	return beer;
}

bool done = 0;

void Tavern::update() {
	if (GetInput()->KeyDown(KeyCode::Space)) {
		glass->position.x = player->position.x + 16;
		glass->position.y = player->position.y - 24;
		if (!done) {
			if (SiroGen->PlayAnimation(glass, BeerFilling, 3) || glass->frame == 3) {
				done = true;
			}
		}
	}
	if (GetInput()->KeyReleased(KeyCode::Space) && done) {
		done = false;
		glass->frame = 0;
		glass->starttime = 0;
		SiroGen->SetSpritetoEntity(glass, 6);
		SpawnBeer();
	}
	if (GetInput()->KeyPressed(KeyCode::Up) && player->position.y > 80) {
		player->position.y -= 48;
		player->position.x = 176;
		glass->frame = 0;
		glass->starttime = 0;
		SiroGen->SetSpritetoEntity(glass, 6);
	}
	else if (GetInput()->KeyPressed(KeyCode::Down) && player->position.y < 224) {
		player->position.y += 48;
		player->position.x = 176;
		glass->frame = 0;
		glass->starttime = 0;
		SiroGen->SetSpritetoEntity(glass, 6);
	}
	else if (GetInput()->KeyDown(KeyCode::Left)) {
		player->position.x--;
	}
	else if (GetInput()->KeyDown(KeyCode::Right)) {
		player->position.x++;
	}
	for (int i = 0; i < Tap.size(); i++) {
		Tap[i]->position.x -= 4;
	}
}
