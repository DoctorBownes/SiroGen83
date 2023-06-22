#ifndef TAVERN_H_
#define TAVERN_H_

#include <SiroGen83/scene.h>
#include <Alfa-tapper/tavern.h>

class Tavern : public Scene {

public:
	Tavern();

	virtual void update() override;
	//virtual void BeginPlay() override;
	Entity* player = nullptr;
	Entity* barfly = nullptr;
	Entity* glass = nullptr;
	Entity* SpawnBeer();
	std::vector<Entity*> Tap;
	Animation* BeerFilling = nullptr;
};

#endif
