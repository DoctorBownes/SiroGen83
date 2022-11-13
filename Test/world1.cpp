#include "world1.h"
#include <SiroGen83/tile.h>
#include <SiroGen83/renderer.h>

World1::World1() {
	_instance = _instance->GetInstance();
	Tile air = {
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
		1
	};
	Tile dirt = {
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
		1
	};
	Screen tl = {
		&dirt,&air,&dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt, 
		&dirt,&dirt,&dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,
		&dirt,&dirt,&dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,
		&dirt,&dirt,&dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,
		&dirt,&dirt,&dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,
		&dirt,&dirt,&dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,
		&dirt,&dirt,&dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,
		&dirt,&dirt,&dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,
		&dirt,&dirt,&dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,
		&dirt,&dirt,&dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,
		&dirt,&dirt,&dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,
		&dirt,&dirt,&dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,
		&dirt,&dirt,&dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,
		&dirt,&dirt,&dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,
		&dirt,&dirt,&dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,
		&dirt,&dirt,&dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,& dirt,
	};
	Screen td = {
		&dirt,&air,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,
		&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,
		&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,
		&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,
		&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,
		&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,
		&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,
		&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,
		&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,
		&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,
		&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,
		&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,
		&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,
		&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,
		&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,
		&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,&dirt,
	};
	LevelMap tw = {
		&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,
		&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,
		&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,
		&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,
		&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,
		&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,
		&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,
		&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,
		&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,
		&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,
		&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,
		&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,
		&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,
		&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,
		&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,
		&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,&tl,&td,&tl,
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
	entity->position.x = 10;
	entities[0] = entity;



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
