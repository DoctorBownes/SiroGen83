#include "world1.h"
#include <SiroGen83/renderer.h>
#include <stdio.h>

Entity* entity = new Entity();

World1::World1() {
	_instance = _instance->GetInstance();
	static char yin[256] = {
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
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		//1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		//1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		//1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,
		//1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,
		//1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,
		//1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,
		//1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,
		//1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,
		//1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,
		//1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,
		//1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,
		//1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,
		//1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,
		//1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,
		//1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		//1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	};
	static char yang[256] = {
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
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		//0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		//0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
		//0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
		//0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,0,
		//0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,0,
		//0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,0,
		//0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,0,
		//0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,0,
		//0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,0,
		//0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,0,
		//0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,0,
		//0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,0,
		//0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,0,
		//0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
		//0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
		//0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	};

	ar = {
		yin,0
	};

	dr = {
		yang,1
	};

	Nametable tl = {
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
		&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,&dr,
	};

	Nametables[0] = {
		&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,
		&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,
		&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,
		&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,
		&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,
		&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,
		&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,
		&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,
		&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,
		&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,
		&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,
		&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,
		&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,
		&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,
		&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,
		&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,&ar,
	};

	static char canvas[25] = {
		1,0,1,0,1,
		1,1,1,1,1,
		0,0,1,0,0,
		0,1,1,1,0,
		1,1,0,1,1,
	};

	static char canvas2[256] = {
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
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
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	};

	_instance->GenerateSprite(entity, canvas, 5, 5);
	//entities.push_front(entity);

	Entity* entity2 = new Entity();
	_instance->GenerateSprite(entity2, canvas2, 16, 16);
	entity2->position.x = -248.0f;
	entity2->position.y = 232.0f;
	//entities.push_front(entity2);

	printf("%d\n", (int)Nametables[0].tiles[0]->pixels[0]);

	GetCamera()->SetZoom(4.5f); //4.5f = Pixel Perfect Zoom
	GetCamera()->X = -120;
	GetCamera()->Y = 120;
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
