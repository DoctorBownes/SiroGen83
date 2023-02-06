#pragma once

#include <SiroGen83/scene.h>

class World1 : public Scene {

public:
	World1();

	virtual void update() override;

	double starttime = 0.0;
};

