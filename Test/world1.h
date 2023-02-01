#pragma once

#include <SiroGen83/scene.h>

class Renderer;

class World1 : public Scene {

public:
	World1();

	virtual void update() override;

	bool once = 1;


private:
	Renderer* _instance = nullptr;
};

