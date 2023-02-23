#ifndef WORLD1_H_
#define WORLD1_H_

#include <SiroGen83/scene.h>

class World1 : public Scene {

public:
	World1();

	virtual void update() override;

	Entity* player = nullptr;

	Entity* player2 = nullptr;

	Animation playerwalk;

	bool TileCol(Entity* entity);

};

#endif
