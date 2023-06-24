#ifndef TAVERN_H_
#define TAVERN_H_

#include <SiroGen83/scene.h>
#include <Alfa-tapper/tavern.h>

struct Beer : public Entity {};

struct Barfly : public Entity {
	unsigned char id = 0;
};

class Tavern : public Scene {

public:
	Tavern();

	virtual void update() override;
	//virtual void BeginPlay() override;
	Entity* player = nullptr;
	Entity* glass = nullptr;
	Entity* SpawnBeer(unsigned char bar);

	Barfly* People[7];
	Barfly* mc = nullptr;

	std::vector<Beer*> Bar[4];
	std::vector<Entity*> WaitLine[4];
	std::vector<Entity*> DrinkLine[4];
	Animation* BeerFilling = nullptr;
};

#endif
