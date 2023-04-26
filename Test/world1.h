#ifndef WORLD1_H_
#define WORLD1_H_

#include <SiroGen83/scene.h>

class World1 : public Scene {

public:
	World1();

	virtual void update() override;

	TileScreen* ScoreScreen = nullptr;

	int downscore = 100;
	int upscore = 566;

};

#endif
