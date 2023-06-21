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
	Animation* playerWalking = nullptr;
	Animation* playerFighting = nullptr;
};

#endif
