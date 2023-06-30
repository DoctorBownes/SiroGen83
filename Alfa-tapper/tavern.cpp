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
	glassshattering = new Animation{10, 4,4,16,17,16,17,1,1,16,17,16,17 };

	mc = new Barfly();
	mc->position.x = 16;
	mc->position.y = 60;
	mc->id = 0;
	SiroGen->SetSpritetoEntity(mc, 5);
	drinkanim[mc->id] = new Animation{ 20, 6,7,8,9,10,11,11,11 };
	walkanim[mc->id] = new Animation{ 8, 12,13,12,13,14,15 };
	People[mc->id] = mc;

	entities.push_front(player);
	entities.push_front(glass);
	BeerFilling = new Animation{ 5, 1,2,3,4 };
	barspeeds[0] = 100;
	barspeeds[1] = 100;
	barspeeds[2] = 100;
	barspeeds[3] = 100;
}

Entity* Tavern::SpawnPeople()
{
	std::srand(randomnumber);
	unsigned char randbar = std::rand() & 3;
	Barfly* ghost = new Barfly();
	ghost->id = People[0]->id;
	ghost->position.x = 16;
	ghost->position.y = 60 + randbar * 48;


	WaitLine[randbar].push_back(ghost);
	entities.push_front(ghost);
	return ghost;
}

Entity* Tavern::SpawnBeer(unsigned char bar, Entity* near, bool full) {
	Beer* beer = new Beer();
	beer->position.x = near->position.x + 16;
	beer->position.y = 60 + bar * 48;
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

void Tavern::update() {
	switch (status) {
	case 0://GameRunning
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
			done = false;
			glass->frame = 0;
			glass->starttime = 0;
			SiroGen->SetSpritetoEntity(glass, 5);
		}
		else if (GetInput()->KeyPressed(KeyCode::Down) && player->position.y < 224) {
			player->position.y += 48;
			player->position.x = 176;
			done = false;
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
		if (GetInput()->KeyPressed(KeyCode::LeftControl)) {
			SpawnPeople();
		}
		//WaitingLine
		for (unsigned char j = 0; j < 4; j++) {
			std::vector<Barfly*>::iterator bit = WaitLine[j].begin();
			while (bit != WaitLine[j].end()) {
				bool caught = false;
				if (!(*bit)->yellmeter) {
					if (SiroGen->PlayAnimation((*bit), walkanim[(*bit)->id], 3, 0)) {
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
					if ((*bit)->position.x > 176) {
						gameoverman = (*bit);
						SiroGen->SetAttributetoEntity(gameoverman, 4);
						status = 2;
					}
				}
				std::vector<Beer*>::iterator it = Bar[j].begin();
				while (it != Bar[j].end()) {
					signed char difx = (*bit)->position.x - (*it)->position.x;
					if (difx < 10 && difx > -10 && (*it)->full) {
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
					SiroGen->PlayAnimation(*bit, drinkanim[(*bit)->id], 0, 0);
					DrinkLine[j].push_back(*bit);
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
					if ((*it)->frame == 5) {
						SpawnBeer(((*it)->position.y - 60) / 48, *it, false);
						(*it)->frame++;
					}
					if (SiroGen->PlayAnimation(*it, drinkanim[(*it)->id], 6)) {

						WaitLine[j].push_back(*it);
						it = DrinkLine[j].erase(it);
					}
					else {
						it++;
					}
				}
				else if ((*it)->position.x < 16) {
					entities.remove(*it);
					delete (*it);
					it = DrinkLine[j].erase(it);
				}
				else {
					(*it)->yellmeter--;
					(*it)->position.x -= 2;
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
						//entities.remove(*it);
						//delete* it;
						//it = Bar[x].erase(it);
						shatterglass = (*it);
						status = 1;
					}
					it++;
				}
				else {
					(*it)->position.x += 1;
					signed char difx = player->position.x - (*it)->position.x;
					if (difx < 10 && difx > -10) {
						entities.remove(*it);
						delete* it;
						it = Bar[x].erase(it);
					}
					else if ((*it)->position.x > 176) {
						shatterglass = (*it);
						status = 1;
					}
					else {
						it++;
					}
				}
			}
		}
		randomnumber++;
		break;
	case 1://GlassOver
		if (shatterglass->frame < 2) {
			shatterglass->position.y++;
		}
		if (SiroGen->PlayAnimation(shatterglass, glassshattering, 4)) {
			//Insert Game Reset here
			status = 3;
		}
		
		break;
	case 2://PeopleOver
		player->position.x = gameoverman->position.x - 16;
		player->position.y = gameoverman->position.y;
		gameoverman->position.x-=4;
		if (player->position.x < 4) {
			status = 3;
		}
		break;
	case 3://GameReset

		for (unsigned char j = 0; j < 4; j++) {
			std::vector<Barfly*>::iterator bit = DrinkLine[j].begin();
			while (bit != DrinkLine[j].end()) {
				entities.remove(*bit);
				delete* bit;
				bit = DrinkLine[j].erase(bit);
			}
			std::vector<Barfly*>::iterator it = WaitLine[j].begin();
			while (it != WaitLine[j].end()) {
				entities.remove(*it);
				delete* it;
				it = WaitLine[j].erase(it);
			}
			std::vector<Beer*>::iterator sit = Bar[j].begin();
			while (sit != Bar[j].end()) {
				entities.remove(*sit);
				delete* sit;
				sit = Bar[j].erase(sit);
			}
		}
		player->position.y = 80;
		player->position.x = 176;
		SiroGen->SetSpritetoEntity(glass, 5);
		status = 0;
		break;
	}
}
