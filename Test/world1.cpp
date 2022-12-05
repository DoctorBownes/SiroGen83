#include "world1.h"
#include <SiroGen83/renderer.h>
#include <stdio.h>

Entity* entity = new Entity();

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
		air,0
	};

	Tile dr = {
		drt,1
	};

	Nametable tl = {
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

	Nametable td = {
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

	static char canvas2[256] = {
		0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,
		1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,
		1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,
		1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,
		1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,
		1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,
		1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,
		1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,
		1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,
		1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,
		1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,
		1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
	};
	_instance->GenerateSprite(entity, canvas, 5, 5);
	entities.push_front(entity);

	Entity* entity2 = new Entity();
	_instance->GenerateSprite(entity2, canvas2, 16, 16);
	entity2->position.x = -120.0f;
	entity2->position.y = 112.0f;
	entities.push_front(entity2);




	Screens[0] = &tl;
	Screens[1] = &tl;
	Screens[2] = &td;
	Screens[3] = &td;
	Screens[4] = &tl;

	GetCamera()->SetZoom(4.5f);
	//printf("%d\n", (int)(tl[0]).sprite[0]);
	//printf("%d\n", (int)(tl[1]).sprite[0]);
	//printf("%d\n", (int)(*tw[1]));
	//printf("%d\n", (int)(*tw[2]));
	//printf("%d\n", (int)(*tl[1]).sprite[0]);
	//Tile gro;
	//gro.spriteTL = drt.spriteTL;
}

void World1::update() {
	//entity->position.x += 0.5f;
	//GetCamera()->X = entity->position.x;
}
