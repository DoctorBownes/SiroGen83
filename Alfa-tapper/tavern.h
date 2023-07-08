#ifndef TAVERN_H_
#define TAVERN_H_

#include <SiroGen83/scene.h>
#include <Alfa-tapper/tavern.h>

struct Beer : public Entity {
	bool full = true;
	unsigned char barpos = 0;
};

struct Barfly : public Entity {
	unsigned char id = 0;
	unsigned char yellmeter = 0;
};

class Tavern : public Scene {

public:
	Tavern();

	virtual void update() override;
	//virtual void BeginPlay() override;
	Entity* player = nullptr;
	Entity* glass = nullptr;
	Animation* glassshattering = nullptr;
	Animation* playerwalking = nullptr;
	Animation* playertapping = nullptr;
	Barfly* gameoverman = nullptr;
	Beer* shatterglass = nullptr;
	Entity* SpawnBeer(unsigned char bar, Entity* near, bool full = true);
	Entity* SpawnPeople();

	Entity* Taps[4];

	Barfly* People[7];
	Animation* drinkanim[7];
	Animation* walkanim[7];
	Barfly* mc = nullptr;
	Barfly* jk = nullptr;
	Barfly* st = nullptr;
	Barfly* dp = nullptr;
	Barfly* gw = nullptr;
	Barfly* ep = nullptr;
	Barfly* rt = nullptr;

	std::vector<Beer*> Bar[4];
	std::vector<Barfly*> WaitLine[4];
	unsigned char barspeeds[4];
	unsigned short spawncounter = 0;
	unsigned short spawntimer = 0;
	unsigned char randomnumber = 0;
	std::vector<Barfly*> DrinkLine[4];
	Animation* BeerFilling = nullptr;

	bool done = 0;
	bool idle = 1;
	unsigned char moving = 0;
	unsigned char dir = 0;
	unsigned char status = 0;
	unsigned char barpos = 0;
	int score = 0;
	int hiscore = 0;
};

#endif
