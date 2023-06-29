#include "tavern.h"

Tavern::Tavern() {
	SiroGen->BackgroundColor = {
		0,0,200
	};
	//SiroGen->BackgroundPalette = {
	//	0,0,0, 255,255,255,	255, 146, 73,
	//	255, 30, 39,  0, 73, 146, 36,146,255,
	//	146, 36,0, 255,0,73, 255, 146, 0,
	//	181,214,255, 232, 242, 255, 128,128,128,
	//	124, 108, 88, 196,23,32, 145,17,25,
	//};
	SiroGen->ForgroundPalette[0] = {
		0,0,0,	255, 146, 73, 255,0,73, 
		255, 30, 39,  0, 73, 146, 36,146,255,
		146, 36,0,	124, 108, 88,	196,23,32,
		 145, 17, 25, 56,56,56,	255,255,255,
		 181, 214, 255, 255,146,0, 219,73,36,
	};
	SiroGen->ForgroundPalette[1] = {
		0,0,0,	255, 146, 73, 255,0,73,
		255, 30, 39,  229, 214, 172, 232,242,255,
		146, 36,0,	124, 108, 88,	22,22,22,
		 128, 128, 128, 56,56,56,	255,255,255,
		 181, 214, 255, 255,146,0, 219,73,36,
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
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};

	player = new Entity();
	player->position.y = 80;
	player->position.x = 176;
	SiroGen->SetSpritetoEntity(player, 0);

	glass = new Entity();
	glass->position.x = player->position.x + 16;
	glass->position.y = player->position.y - 24;

	mc = new Barfly();
	mc->position.x = 16;
	mc->position.y = 60;
	mc->id = 0;
	SiroGen->SetSpritetoEntity(mc, 5);
	People[mc->id] = mc;
	drinkanim[mc->id] = new Animation{ 20, 6,7,8,9,10,11 };
	walkanim[mc->id] = new Animation{ 8, 12,13,12,13,14,15 };
	WaitLine[0].push_back(mc);

	entities.push_front(player);
	entities.push_front(glass);
	entities.push_front(mc);
	BeerFilling = new Animation{ 5, 1,2,3,4 };
	barspeeds[0] = 100;
}

Entity* Tavern::SpawnBeer(unsigned char bar, Entity* near, bool full) {
	Beer* beer = new Beer();
	beer->position.x = near->position.x + 16;
	beer->position.y = 60 + bar * 60;
	if (full) {
		SiroGen->SetSpritetoEntity(beer, 4);
		beer->full = true;
	}
	else {
		SiroGen->SetSpritetoEntity(beer, 1);
		beer->full = false;
	}
	Bar[bar].push_back(beer);
	entities.push_front(beer);
	return beer;
}

bool done = 0;

void Tavern::update() {
	//PlayerMovement
	if (GetInput()->KeyDown(KeyCode::Space)) {
		player->position.x = 176;
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
		SiroGen->SetSpritetoEntity(glass, 5);
		SpawnBeer((player->position.y - 80) / 48, player);
	}
	if (GetInput()->KeyPressed(KeyCode::Up) && player->position.y > 80) {
		player->position.y -= 48;
		player->position.x = 176;
		glass->frame = 0;
		glass->starttime = 0;
		SiroGen->SetSpritetoEntity(glass, 5);
	}
	else if (GetInput()->KeyPressed(KeyCode::Down) && player->position.y < 224) {
		player->position.y += 48;
		player->position.x = 176;
		glass->frame = 0;
		glass->starttime = 0;
		SiroGen->SetSpritetoEntity(glass, 5);
	}
	else if (GetInput()->KeyDown(KeyCode::Left)) {
		player->position.x--;
	}
	else if (GetInput()->KeyDown(KeyCode::Right)) {
		player->position.x++;
	}

	//WaitingLine
	for (unsigned char j = 0; j < 4; j++) {
		std::vector<Barfly*>::iterator bit = WaitLine[j].begin();
		while (bit != WaitLine[j].end()) {
			bool caught = false;
			if (!(*bit)->yellmeter) {
				if (SiroGen->PlayAnimation((*bit), walkanim[(*bit)->id], 3,0)) {
					(*bit)->yellmeter = true;
				}
			}
			if ((*bit)->yellmeter > 0) {
				SiroGen->PlayAnimation((*bit), walkanim[(*bit)->id], 5, 4);
				(*bit)->yellmeter++;
				if ((*bit)->yellmeter >= barspeeds[j]) {
					(*bit)->yellmeter = false;
				}
			}
			if ((*bit)->frame < 4) {
				(*bit)->position.x++;
			}
			std::vector<Beer*>::iterator it = Bar[j].begin();
			while (it != Bar[j].end()) {
				signed char difx = (*bit)->position.x - (*it)->position.x;
				if (difx < 10 && difx > -10) {
					//caught
					entities.remove(*it);
					delete* it;
					it = Bar[j].erase(it);
					it = Bar[j].end();

					caught = true;
				}
				else {
					it++;
				}
			}
			if (caught) {
				(*bit)->yellmeter = 40;
				SiroGen->PlayAnimation(*bit, drinkanim[(*bit)->id], 0,0);
				DrinkLine->push_back(*bit);
				bit = WaitLine[j].erase(bit);
			}
			else {
				bit++;
			}
		}
	}

	//DrinkingLine
	for (unsigned char j = 0; j < 4; j++) {
		std::vector<Barfly*>::iterator it = DrinkLine[j].begin();
		while (it != DrinkLine[j].end()) {
			
			if ((*it)->yellmeter < 1) {
				if (SiroGen->PlayAnimation(*it, drinkanim[(*it)->id], 5)) {
					SpawnBeer(((*it)->position.y - 60) / 48, *it, false);

					WaitLine->push_back(*it);
					it = DrinkLine[j].erase(it);
				}
				else {
					it++;
				}
			}
			else if ((*it)->position.x < 16) {
				entities.remove(*it);
				it = DrinkLine[j].erase(it);
			}
			else {
				(*it)->yellmeter--;
				(*it)->position.x-=2;
				it++;
			}

		}
	}


	//BeerMovement
	for (unsigned char x = 0; x < 4; x++) {
		std::vector<Beer*>::iterator it = Bar[x].begin();
		while (it != Bar[x].end()) {


			if ((*it)->full) {
				(*it)->position.x -= 4;
				if ((*it)->position.x < 8) {
					//Create Game Over here
					entities.remove(*it);
					delete* it;
					it = Bar[x].erase(it);
				}
				else {
					it++;
				}
			}
			else {
				(*it)->position.x += 1;
				signed char difx = player->position.x - (*it)->position.x;
				if (difx < 10 && difx > -10) {
					entities.remove(*it);
					delete* it;
					it = Bar[x].erase(it);
				}
				else {
					it++;
				}
			}
		}
	}

}
