#ifndef TAVERN_H_
#define TAVERN_H_

#include <SiroGen83/scene.h>
#include <Alfa-tapper/tavern.h>

struct Beer : public Entity {
	unsigned char full = true;
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
	Entity* SpawnBeer(unsigned char bar, Entity* near, bool full = true);
	Entity* SpawnPeople();

	Barfly* People[7];
	Animation* drinkanim[7];
	Animation* walkanim[7];
	Barfly* mc = nullptr;

	std::vector<Beer*> Bar[4];
	std::vector<Barfly*> WaitLine[4];
	unsigned char barspeeds[4];
	std::vector<Barfly*> DrinkLine[4];
	Animation* BeerFilling = nullptr;
};

#endif
