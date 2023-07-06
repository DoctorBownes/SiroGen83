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
	player->position.y = 80 + barpos * 48;
	player->position.x = 165;
	SiroGen->SetSpritetoEntity(player, 0);
	playerwalking = new Animation{20, 0,78,79,79,80,81,82, 85,86,87,88};
	playertapping = new Animation{20, 91,91,91};

	glass = new Entity();
	glass->position.x = player->position.x + 16;
	glass->position.y = player->position.y - 24;
	glassshattering = new Animation{8, 16,17,16,17,16,17,16,17,16,17,16,17, };

	mc = new Barfly();
	mc->position.x = 16;
	mc->position.y = 60;
	mc->id = 0;
	drinkanim[mc->id] = new Animation{ 20, 6,7,8,9,10,11,11,11 };
	walkanim[mc->id] = new Animation{ 10, 12,13,12,13,14,15 };
	People[mc->id] = mc;

	jk = new Barfly();
	jk->position.x = 16;
	jk->position.y = 60;
	jk->id = 1;
	drinkanim[jk->id] = new Animation{ 20, {22,23,24,25,26,27,27,27},{1,1,1,1,1,1,1,1} };
	walkanim[jk->id] = new Animation{ 10, {18,19,18,19,20,21},{1,1,1,1,1,1} };
	People[jk->id] = jk;

	st = new Barfly();
	st->position.x = 16;
	st->position.y = 60;
	st->id = 2;
	drinkanim[st->id] = new Animation{ 20, {32,33,34,35,36,37,37,37},{1,1,1,1,1,1,1,1} };
	walkanim[st->id] = new Animation{ 10, {28,29,28,29,30,31},{1,1,1,1,1,1} };
	People[st->id] = st;

	dp = new Barfly();
	dp->position.x = 16;
	dp->position.y = 60;
	dp->id = 3;
	drinkanim[dp->id] = new Animation{ 20, {42,43,44,45,46,47,47,47},{1,1,1,1,1,1,1,1} };
	walkanim[dp->id] = new Animation{ 10, {38,39,38,39,40,41},{1,1,1,1,1,1} };
	People[dp->id] = dp;

	gw = new Barfly();
	gw->position.x = 16;
	gw->position.y = 60;
	gw->id = 4;
	drinkanim[gw->id] = new Animation{ 20, {52,53,54,55,56,57,57,57},{1,1,1,1,1,1,1,1} };
	walkanim[gw->id] = new Animation{ 10, {48,49,48,49,50,51},{1,1,1,1,1,1} };
	People[gw->id] = gw;

	ep = new Barfly();
	ep->position.x = 16;
	ep->position.y = 60;
	ep->id = 5;
	drinkanim[ep->id] = new Animation{ 20, {62,63,64,65,66,67,67,67},{1,1,1,1,1,1,1,1} };
	walkanim[ep->id] = new Animation{ 10, {58,59,58,59,60,61},{1,1,1,1,1,1} };
	People[ep->id] = ep;

	rt = new Barfly();
	rt->position.x = 16;
	rt->position.y = 60;
	rt->id = 6;
	drinkanim[rt->id] = new Animation{ 20, {72,73,74,75,76,77,77,77},{1,1,1,1,1,1,1,1} };
	walkanim[rt->id] = new Animation{ 10, {68,69,68,69,70,71},{1,1,1,1,1,1} };
	People[rt->id] = rt;

	for (int i = 0; i < 4; i++) {
		Taps[i] = new Entity();
		Taps[i]->position.x = 189;
		Taps[i]->position.y = 58 + i * 48;
		SiroGen->SetSpritetoEntity(Taps[i], 92);
	}


	entities.push_front(player);
	entities.push_front(glass);
	entities.push_front(Taps[0]);
	entities.push_front(Taps[1]);
	entities.push_front(Taps[2]);
	entities.push_front(Taps[3]);
	BeerFilling = new Animation{ 5, 1,2,3,4 };
	barspeeds[0] = 150;
	barspeeds[1] = 100;
	barspeeds[2] = 70;
	barspeeds[3] = 50;
	spawntimer = 121;
}

Entity* Tavern::SpawnPeople()
{
	std::srand(randomnumber);
	unsigned char randbar = std::rand() & 3;
	unsigned char randpeep = std::rand() % 7;
	Barfly* ghost = new Barfly();
	ghost->id = People[randpeep]->id;
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
	beer->barpos = bar;
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
		if (!moving) {
			//PlayerMovement
			if (GetInput()->KeyDown(KeyCode::Space)) {
				idle = false;
				SiroGen->SetAttributetoEntity(player, 0);
				dir = 0;
				player->position.x = 165;
				glass->position.x = player->position.x + 27;
				glass->position.y = player->position.y - 15;
				if (!done) {
					SiroGen->SetSpritetoEntity(player, 90);
					SiroGen->SetSpritetoEntity(Taps[barpos], 93);
					if (SiroGen->PlayAnimation(glass, BeerFilling, 3) || glass->frame == 3) {
						done = true;
					}
				}
			}
			if (GetInput()->KeyReleased(KeyCode::Space)) {
				SiroGen->SetSpritetoEntity(player, 89);
				SiroGen->SetSpritetoEntity(Taps[barpos], 92);
				if (done) {
					SiroGen->SetSpritetoEntity(player, 91);
					glass->frame = 0;
					glass->starttime = 0;
					SiroGen->SetSpritetoEntity(glass, 5);
					SpawnBeer((player->position.y - 80) / 48, player);
					done = false;
				}
			}
			if (GetInput()->KeyPressed(KeyCode::Up)) {
				idle = true;
				glass->frame = 0;
				glass->starttime = 0;
				SiroGen->SetSpritetoEntity(Taps[barpos], 92);
				SiroGen->SetSpritetoEntity(glass, 5);
				done = false;
				moving = 1;
				dir = 0;
				player->starttime = 0;
			}
			else if (GetInput()->KeyPressed(KeyCode::Down)) {
				idle = true;
				glass->frame = 0;
				glass->starttime = 0;
				SiroGen->SetSpritetoEntity(Taps[barpos], 92);
				SiroGen->SetSpritetoEntity(glass, 5);
				done = false;
				moving = 2;
				dir = 0;
				player->starttime = 0;
			}
			else if (GetInput()->KeyDown(KeyCode::Left)) {
				idle = true;
				if (player->position.x > 16) {
					player->position.x--;
				}
				dir = 4;
				playerwalking->framerate = 8;
				SiroGen->SetSpritetoEntity(Taps[barpos], 92);
				SiroGen->SetSpritetoEntity(glass, 5);
				SiroGen->PlayAnimation(player, playerwalking, 10, 7);
				SiroGen->SetAttributetoEntity(player, 4);
			}
			else if (GetInput()->KeyDown(KeyCode::Right)) {
				idle = true;
				if (player->position.x < 176) {
					player->position.x++;
				}
				dir = 0;
				playerwalking->framerate = 8;
				SiroGen->SetSpritetoEntity(Taps[barpos], 92);
				SiroGen->SetSpritetoEntity(glass, 5);
				SiroGen->PlayAnimation(player, playerwalking, 10, 7);
				SiroGen->SetAttributetoEntity(player, 0);
			}
			else if (idle) {
				playerwalking->framerate = 20;
				SiroGen->PlayAnimation(player, playerwalking, 1);
				SiroGen->SetAttributetoEntity(player, dir);
			}
		}


		if (moving) {
			playerwalking->framerate = 3;
			if (SiroGen->PlayAnimation(player, playerwalking, 6, 2)) {
				if (moving > 1) {
					barpos++;
				}
				else {
					barpos--;
				}
				barpos &= 3;
				player->position.y = 80 + barpos * 48;
				player->position.x = 165;
				moving = false;
				playerwalking->framerate = 20;
			}
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
						status = 2;
					}
				}
				std::vector<Beer*>::iterator it = Bar[j].begin();
				while (it != Bar[j].end()) {
					signed char difx = (*bit)->position.x - (*it)->position.x;
					if (difx < 14 && difx > -10 && (*it)->full) {
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
					if (difx < 10 && difx > -10 && barpos == (*it)->barpos) {
						entities.remove(*it);
						delete* it;
						it = Bar[x].erase(it);
					}
					else if ((*it)->position.x > 176) {
						shatterglass = (*it);
						status = 1;
						it++;
					}
					else {
						it++;
					}
				}
			}
		}
		randomnumber++;
		spawncounter++;
		if (spawncounter / spawntimer) {
			spawncounter = 0;
			SpawnPeople();
		}
		break;
	case 1://GlassOver
		SiroGen->SetSpritetoEntity(player, 83);
		if (shatterglass->position.y < 80 + shatterglass->barpos * 48) {
			shatterglass->position.y++;
		}
		else {
			if (SiroGen->PlayAnimation(shatterglass, glassshattering, 11)) {
				status = 3;
			}
		}
		
		break;
	case 2://PeopleOver
		SiroGen->PlayAnimation(gameoverman, walkanim[gameoverman->id], 3, 0);
		if (gameoverman->id) {
			SiroGen->SetAttributetoEntity(gameoverman, 5);
		}
		else {
			SiroGen->SetAttributetoEntity(gameoverman, 4);
		}
		SiroGen->SetSpritetoEntity(player, 84);
		SiroGen->SetAttributetoEntity(player, 4);
		if (gameoverman->position.x > 32) {
			player->position.x = gameoverman->position.x - 16;
			player->position.y = gameoverman->position.y + 8;
			gameoverman->position.x -= 2;
		}
		else {
			player->position.x-=2;
		}
		if ((player->position.x & 511) > 256 && (player->position.x & 511) <= 300) {
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
		barpos = 0;
		player->position.y = 80;
		player->position.x = 165;
		idle = true;
		done = false;
		SiroGen->SetSpritetoEntity(glass, 5);
		status = 0;
		break;
	}
}
