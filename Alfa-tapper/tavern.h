#ifndef TAVERN_H_
#define TAVERN_H_

#include <SiroGen83/scene.h>
#include <Alfa-tapper/tavern.h>

struct Beer : public Entity {};

class Tavern : public Scene {

public:
	Tavern();

	virtual void update() override;
	//virtual void BeginPlay() override;
	Entity* player = nullptr;
	Entity* barfly = nullptr;
	Entity* glass = nullptr;
	Entity* SpawnBeer(unsigned char bar);
	std::vector<Beer*> Bar[4];
	std::vector<Entity*> Line[4];
	Animation* BeerFilling = nullptr;
};

#endif
