#include "world1.h"
#include <SiroGen83/tile.h>

World1::World1() {
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
