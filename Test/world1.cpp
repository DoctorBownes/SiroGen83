#include "world1.h"
#include <SiroGen83/tile.h>
#include <SiroGen83/renderer.h>

World1::World1() {
	_instance = _instance->GetInstance();
	static char air[256] = {
		1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	};
	static char drt[256] = {
		0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	};

	Tile ar = {
		air,0,0
	};

	Tile dr = {
		drt,1,0
	};

	Screen tl = {
		&dr,&ar,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr, 
		&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,
		&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,
		&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,
		&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,
		&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,
		&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,
		&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,
		&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,
		&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,
		&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,
		&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,
		&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,
		&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,
		&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,
		&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,
	};

	Screen td = {
		&dr,&ar,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,
		&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,
		&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,
		&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,
		&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,
		&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,
		&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,
		&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,
		&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,
		&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,
		&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,
		&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,
		&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,
		&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,
		&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,
		&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,
	};

	static char canvas[25] = {
		1,0,1,0,1,
		1,1,1,1,1,
		0,0,1,0,0,
		0,1,1,1,0,
		1,1,0,1,1,
	};
	Entity* entity = new Entity();
	_instance->GenerateSprite(entity, canvas, 5, 5);
	entity->position.x = 0;
	entities[0] = entity;
	printf("%d\n", sizeof(*entity));

	Screens[0] = &tl;
	Screens[1] = &tl;
	Screens[2] = &td;
	Screens[3] = &td;
	Screens[4] = &tl;

	GetCamera()->SetZoom(30.0f);
	//printf("%d\n", (int)(tl[0]).sprite[0]);
	//printf("%d\n", (int)(tl[1]).sprite[0]);
	//printf("%d\n", (int)(*tw[1]));
	//printf("%d\n", (int)(*tw[2]));
	//printf("%d\n", (int)(*tl[1]).sprite[0]);
	//Tile gro;
	//gro.spriteTL = drt.spriteTL;
}

void World1::update() {
}
