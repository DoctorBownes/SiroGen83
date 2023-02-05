#include "world1.h"
#include <stdio.h>

Entity* entity = new Entity();

World1::World1() {

	SiroGen->BackgroundColor = {
		0,0,0
	};
	SiroGen->BackgroundPalette[0] = {
		185, 188, 185,	123, 80, 0,		106, 109, 106,
	};
	SiroGen->BackgroundPalette[1] = {
		185, 188, 185,	150, 56, 0,		242, 121, 199
	};
	SiroGen->BackgroundPalette[2] = {
		0, 18, 125,		38, 122, 0,		0, 61, 0
	};
	SiroGen->BackgroundPalette[3] = {
		255, 255, 255,	245, 143, 111,	150, 56, 0,
	};

	SiroGen->ForgroundPalette[0] = {
		250, 232, 182,	84, 62, 2,		41, 20, 226,
	};
	SiroGen->ForgroundPalette[1] = {
		247, 216, 165,	86, 29, 0,		234, 158, 34
	};
	SiroGen->ForgroundPalette[2] = {
		0, 18, 125,		38, 122, 0,		0, 61, 0
	};
	SiroGen->ForgroundPalette[3] = {
		255, 255, 255,	245, 143, 111,	150, 56, 0,
	};

	Tile t0 = {
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,1,1,1,1,1,1,1,1,1,1,1,1,1,3,0,
1,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,
1,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,
1,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,
1,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,
1,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,
1,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,
1,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,
1,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,
1,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,
1,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,
1,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,
1,2,2,2,2,3,3,3,3,3,3,3,3,3,3,0,
0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	};

	Tile t1 = {
1,3,1,3,3,3,3,3,1,1,1,1,3,3,3,3,
3,3,1,3,1,1,1,1,1,1,1,1,3,1,1,1,
3,3,3,3,3,3,1,1,1,1,1,1,1,3,1,1,
1,1,3,3,3,3,3,1,1,3,3,3,3,3,1,1,
3,3,1,1,1,1,3,3,3,3,3,3,3,1,1,1,
1,1,1,1,3,3,3,3,1,1,1,3,3,1,1,1,
1,1,1,1,1,1,1,3,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,3,1,1,3,1,1,1,1,1,
1,3,1,3,3,3,3,3,3,3,3,3,1,1,1,1,
3,3,1,3,1,1,1,1,1,1,1,1,1,1,1,1,
3,3,3,3,3,3,1,1,1,1,1,1,1,1,1,1,
1,1,3,3,3,3,3,1,1,1,1,1,1,1,1,1,
3,3,1,1,1,1,3,3,3,1,1,1,1,1,1,1,
1,1,1,1,3,3,3,3,3,1,1,1,1,1,1,3,
1,1,1,1,1,1,1,3,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,3,1,1,1,1,3,1,1,3,


	};

	Tile t2 = {
1,1,1,1,3,3,3,3,1,3,1,3,3,3,3,3,
1,1,1,1,3,1,1,1,3,3,1,3,1,1,1,1,
1,1,1,1,1,3,1,1,3,3,3,3,3,3,1,1,
1,3,3,3,3,3,1,1,1,1,3,3,3,3,3,1,
3,3,3,3,3,1,1,1,3,3,1,1,1,1,3,3,
1,1,1,3,3,1,1,1,1,1,1,1,3,3,3,3,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,
1,1,3,1,1,1,1,1,1,1,1,1,1,1,1,3,
1,1,1,1,1,1,1,1,1,1,1,1,3,3,3,3,
1,1,1,1,1,1,1,1,1,1,1,1,3,1,1,1,
1,3,1,1,1,1,1,1,1,1,1,1,1,3,1,1,
1,3,1,1,1,1,1,1,1,3,3,3,3,3,1,1,
3,3,1,1,3,1,1,1,3,3,3,3,3,1,1,1,
3,1,3,3,3,1,1,1,1,1,1,3,3,1,1,1,
3,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,
3,3,1,1,1,1,1,1,1,1,3,1,1,1,1,1,

	};

	Tile t3 = {
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
3,1,1,1,1,3,1,1,1,1,1,1,1,1,1,1,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
3,0,0,0,0,0,0,0,0,0,3,3,3,3,1,1,
3,0,0,0,0,0,3,1,3,1,3,3,3,1,1,1,
3,0,0,0,3,3,3,1,1,1,3,3,3,3,1,1,
3,0,0,3,3,3,3,1,1,3,3,3,3,1,1,1,
3,0,3,0,3,3,3,3,1,3,3,1,3,1,1,1,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
3,1,1,1,1,3,1,1,1,1,1,1,1,1,1,1,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
3,0,0,0,0,0,0,0,0,0,3,3,3,3,1,1,
3,0,0,0,0,0,3,1,3,1,3,3,3,1,1,1,
3,0,0,0,3,3,3,1,1,1,3,3,3,3,1,1,
3,0,0,3,3,3,3,1,1,3,3,3,3,1,1,1,
3,0,3,0,3,3,3,3,1,3,3,1,3,1,1,1,
	};

	Tile t4 = {
3,0,3,3,3,3,1,1,1,1,1,1,1,1,1,1,
3,0,0,3,3,3,1,1,3,1,1,1,1,1,1,1,
3,0,3,0,3,3,1,1,3,1,1,1,1,1,1,1,
3,0,0,3,3,3,3,1,3,1,1,3,1,1,1,1,
3,0,3,0,3,3,3,1,3,1,1,3,1,1,1,1,
3,0,0,3,3,3,3,1,3,1,1,1,1,1,1,1,
3,0,3,3,3,3,3,1,3,1,1,1,1,1,1,1,
3,0,0,3,3,3,3,1,1,1,1,1,1,1,1,1,
3,0,3,3,3,3,1,1,1,1,1,1,1,1,1,1,
3,0,0,3,3,3,1,1,3,1,1,1,1,1,1,1,
3,0,3,0,3,3,1,1,3,1,1,1,1,1,1,1,
3,0,0,3,3,3,3,1,3,1,1,3,1,1,1,1,
3,0,3,0,3,3,3,1,3,1,1,3,1,1,1,1,
3,0,0,3,3,3,3,1,3,1,1,1,1,1,1,1,
3,0,3,3,3,3,3,1,3,1,1,1,1,1,1,1,
3,0,0,3,3,3,3,1,1,1,1,1,1,1,1,1,


	};

	SiroGen->AddtoTileMap(&t0,0);
	SiroGen->AddtoTileMap(&t1,1);
	SiroGen->AddtoTileMap(&t2,2);
	SiroGen->AddtoTileMap(&t3,3);
	SiroGen->AddtoTileMap(&t4,4);

	Nametables[0] = new Nametable{
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
		1,2,4,4,1,2,1,2,1,2,4,4,1,2,1,2,
		2,1,4,4,2,1,2,1,2,1,4,4,2,1,2,1,
		1,2,4,4,1,2,1,2,1,2,4,4,1,2,1,2,
		2,1,4,4,2,1,2,1,2,1,4,4,2,1,2,1,
		1,2,4,4,1,2,1,2,1,2,4,4,1,2,1,2,
		2,1,4,4,2,1,2,1,2,1,4,4,2,1,2,1,
		1,2,4,4,1,2,1,2,1,2,4,4,1,2,1,2,
		2,1,4,4,2,1,2,1,2,1,4,4,2,1,2,1,
		1,2,4,4,1,2,1,2,1,2,4,4,1,2,1,2,
		2,1,4,4,2,1,2,1,2,1,4,4,2,1,2,1,
		1,2,4,4,1,2,1,2,1,2,4,4,1,2,1,2,
		1,2,3,3,1,2,1,2,1,2,3,3,1,2,1,2,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,

		0,0,0,4,1,2,3,0,0,0,0,4,0,0,0,0,
		0,0,0,4,1,2,3,0,0,0,0,4,0,0,0,0,
		0,0,0,4,1,2,3,0,0,0,0,4,0,0,0,0,
		0,0,0,4,1,2,3,0,0,0,0,4,0,0,0,0,
		0,0,0,4,1,2,3,0,0,0,0,4,0,0,0,0,
		0,0,0,4,1,2,3,0,0,0,0,4,0,0,0,0,
		0,0,0,4,1,2,3,0,0,0,0,4,0,0,0,0,
		0,0,0,4,1,2,3,0,0,0,0,4,0,0,0,0,
		0,0,0,4,1,2,3,0,0,0,0,4,0,0,0,0,
		0,0,0,4,1,2,3,0,0,0,0,4,0,0,0,0,
		0,0,0,4,1,2,3,0,0,0,0,4,0,0,0,0,
		0,0,0,4,1,2,3,0,0,0,0,4,0,0,0,0,
		0,0,0,4,1,2,3,0,0,0,0,4,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	};

	Nametables[1] = new Nametable{
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
		1,2,4,4,1,2,1,2,1,2,4,4,1,2,1,2,
		2,1,4,4,2,1,2,1,2,1,4,4,2,1,2,1,
		1,2,4,4,1,2,1,2,1,2,4,4,1,2,1,2,
		2,1,4,4,2,1,2,1,2,1,4,4,2,1,2,1,
		1,2,4,4,1,2,1,2,1,2,4,4,1,2,1,2,
		2,1,4,4,2,1,2,1,2,1,4,4,2,1,2,1,
		1,2,4,4,1,2,1,2,1,2,4,4,1,2,1,2,
		2,1,4,4,2,1,2,1,2,1,4,4,2,1,2,1,
		1,2,4,4,1,2,1,2,1,2,4,4,1,2,1,2,
		2,1,4,4,2,1,2,1,2,1,4,4,2,1,2,1,
		1,2,4,4,1,2,1,2,1,2,4,4,1,2,1,2,
		1,2,3,3,1,2,1,2,1,2,3,3,1,2,1,2,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,

		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	};

	Nametables[2] = new Nametable{
		2,1,4,4,2,1,2,1,2,1,4,4,2,1,2,1,
		1,2,4,4,1,2,1,2,1,2,4,4,1,2,1,2,
		2,1,4,4,2,1,2,1,2,1,4,4,2,1,2,1,
		1,2,4,4,1,2,1,2,1,2,4,4,1,2,1,2,
		2,1,4,4,2,1,2,1,2,1,4,4,2,1,2,1,
		1,2,4,4,1,2,1,2,1,2,4,4,1,2,1,2,
		2,1,4,4,2,1,2,1,2,1,4,4,2,1,2,1,
		1,2,4,4,1,2,1,2,1,2,4,4,1,2,1,2,
		2,1,4,4,2,1,2,1,2,1,4,4,2,1,2,1,
		1,2,4,4,1,2,1,2,1,2,4,4,1,2,1,2,
		2,1,4,4,2,1,2,1,2,1,4,4,2,1,2,1,
		1,2,4,4,1,2,1,2,1,2,4,4,1,2,1,2,
		1,2,3,3,1,2,1,2,1,2,3,3,1,2,1,2,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,

		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	};

	Nametables[3] = new Nametable{
		2,1,4,4,2,1,2,1,2,1,4,4,2,1,2,1,
		1,2,4,4,1,2,1,2,1,2,4,4,1,2,1,2,
		2,1,4,4,2,1,2,1,2,1,4,4,2,1,2,1,
		1,2,4,4,1,2,1,2,1,2,4,4,1,2,1,2,
		2,1,4,4,2,1,2,1,2,1,4,4,2,1,2,1,
		1,2,4,4,1,2,1,2,1,2,4,4,1,2,1,2,
		2,1,4,4,2,1,2,1,2,1,4,4,2,1,2,1,
		1,2,4,4,1,2,1,2,1,2,4,4,1,2,1,2,
		2,1,4,4,2,1,2,1,2,1,4,4,2,1,2,1,
		1,2,4,4,1,2,1,2,1,2,4,4,1,2,1,2,
		2,1,4,4,2,1,2,1,2,1,4,4,2,1,2,1,
		1,2,4,4,1,2,1,2,1,2,4,4,1,2,1,2,
		1,2,3,3,1,2,1,2,1,2,3,3,1,2,1,2,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,

		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	};

	//Nametables[0]->tiles[3] = 0;
	//Nametables[0]->flip[3] = 3;

	//_instance->GenerateSprite(entity, canvas, 5, 5);
	//entities.push_front(entity);

	Sprite jojospr = Sprite{ 16,32,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,
		0,0,0,0,0,0,0,3,3,3,3,3,0,0,0,0,
		0,0,0,0,0,0,0,3,3,3,3,3,3,0,0,0,
		0,0,0,0,0,0,3,3,1,3,1,1,3,0,0,0,
		0,0,0,0,0,0,3,3,1,1,2,2,0,0,0,0,
		0,0,0,0,0,3,3,3,1,1,1,1,0,0,0,0,
		0,0,0,0,0,3,2,2,2,1,1,2,0,0,0,0,
		0,0,0,0,0,2,2,2,2,2,1,1,0,0,0,0,
		0,0,0,3,1,0,2,2,2,2,2,2,3,0,0,0,
		0,0,3,1,1,1,0,2,3,3,3,3,1,3,0,0,
		0,3,1,1,1,1,1,3,3,3,3,3,1,1,3,0,
		0,3,1,1,1,1,3,3,3,3,3,3,1,1,3,0,
		3,1,1,1,1,3,3,3,3,3,3,3,1,1,3,0,
		3,1,1,2,3,0,3,3,3,3,3,3,2,3,0,0,
		0,2,2,2,0,3,3,3,3,3,3,3,2,0,0,0,
		0,0,2,2,1,3,3,3,3,3,3,2,1,2,0,0,
		0,0,2,1,2,2,3,3,3,3,1,3,2,1,0,0,
		0,0,0,2,1,1,2,1,1,1,1,3,0,0,0,0,
		0,0,0,0,1,3,3,2,2,2,2,0,0,0,0,0,
		0,0,0,0,0,3,3,3,3,3,3,0,0,0,0,0,
		0,0,0,0,0,3,3,3,3,3,3,0,0,0,0,0,
		0,0,0,0,3,3,3,3,3,3,3,0,0,0,0,0,
		0,0,0,3,3,3,3,3,0,3,3,3,0,0,0,0,
		0,0,3,2,2,3,3,0,0,3,3,3,0,0,0,0,
		0,3,2,2,2,3,0,0,0,0,2,2,2,0,0,0,
		0,3,2,2,3,0,0,0,0,0,3,2,2,0,0,0,
		0,3,2,2,3,0,0,0,0,0,3,2,2,2,0,0,
		0,3,2,2,2,3,0,0,0,0,3,3,2,2,2,0,
		0,0,3,3,3,0,0,0,0,0,0,3,3,3,3,0,
	};

	Sprite belmspr = Sprite{ 16,32,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,
		0,0,0,0,0,0,0,2,2,2,2,2,2,0,0,0,
		0,0,0,0,0,0,2,2,2,2,1,1,2,0,0,0,
		0,0,0,0,0,0,2,2,2,3,1,3,2,0,0,0,
		0,0,0,2,2,2,2,2,2,3,1,1,2,0,0,0,
		0,0,2,3,3,3,3,2,2,2,3,1,2,0,0,0,
		0,0,2,2,3,3,3,3,3,1,2,2,2,0,0,0,
		0,2,2,2,3,3,3,3,3,3,0,0,0,0,0,0,
		2,1,1,2,2,3,3,2,2,2,2,2,0,0,0,0,
		2,1,2,2,2,2,2,2,2,1,1,2,2,2,2,0,
		2,2,2,2,2,2,2,2,2,1,1,2,2,1,1,2,
		0,0,2,2,2,2,2,2,2,1,2,3,2,1,1,2,
		0,0,2,2,2,2,3,2,2,2,3,3,2,1,2,0,
		0,0,0,3,2,2,2,2,2,2,2,2,2,2,0,0,
		0,0,0,2,3,2,3,2,3,2,0,0,0,0,0,0,
		0,0,2,2,2,2,3,2,2,0,0,0,0,0,0,0,
		0,0,2,2,2,2,3,2,2,3,0,0,0,0,0,0,
		0,0,2,2,2,2,2,2,2,2,3,0,0,0,0,0,
		0,0,0,2,1,1,1,2,2,1,1,2,0,0,0,0,
		0,0,0,2,1,1,1,2,2,1,1,1,2,0,0,0,
		0,0,0,2,1,1,2,2,0,2,1,1,2,2,0,0,
		0,0,0,2,2,1,2,0,0,0,2,2,1,2,0,0,
		0,0,2,3,2,2,2,0,0,0,2,2,2,2,0,0,
		0,2,2,3,3,2,0,0,0,0,2,3,3,2,0,0,
		2,2,3,3,2,0,0,0,0,0,2,3,3,2,0,0,
		2,3,3,2,0,0,0,0,0,0,2,3,3,2,0,0,
		2,3,3,2,0,0,0,0,0,0,0,2,3,2,0,0,
		2,3,3,2,0,0,0,0,0,0,2,3,3,3,2,2,
		2,3,3,3,2,0,0,0,0,0,2,3,3,3,3,2,
		2,2,2,2,2,0,0,0,0,0,2,2,2,2,2,2,
	};
	Sprite belmspr1 = Sprite{ 16,16,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,
		0,0,0,0,0,0,0,3,3,3,3,3,3,0,0,0,
		0,0,0,0,0,0,3,3,3,3,1,1,3,0,0,0,
		0,0,0,0,0,0,3,3,3,2,1,2,3,0,0,0,
		0,0,0,3,3,3,3,3,3,2,1,1,3,0,0,0,
		0,0,3,2,2,2,2,3,3,3,2,1,3,0,0,0,
		0,0,3,3,2,2,2,2,2,1,3,3,3,0,0,0,
		0,3,3,3,2,2,2,2,2,2,0,0,0,0,0,0,
		3,1,1,3,3,2,2,3,3,3,3,3,0,0,0,0,
		3,1,3,3,3,3,3,3,3,1,1,3,3,3,3,0,
		3,3,3,3,3,3,3,3,3,1,1,3,3,1,1,3,
		0,0,3,3,3,3,3,3,3,1,3,2,3,1,1,3,
		0,0,3,3,3,3,2,3,3,3,2,2,3,1,3,0,
		0,0,0,2,3,3,3,3,3,3,3,3,3,3,0,0,
	};
	SiroGen->AddSpritetoMemory(&jojospr, 0);
	SiroGen->AddSpritetoMemory(&belmspr, 1);
	SiroGen->AddSpritetoMemory(&belmspr1, 2);

	Entity* entity2 = new Entity();
	entity2->attributes = 0;
	entity2->position.x = 16 * 6;
	entity2->position.y = 200 - 16;
	SiroGen->SetSpritetoEntity(entity2, 0);
	entities.push_front(entity2);

	entity->attributes = 1;
	entity->position.x = 16 * 5;
	entity->position.y = 200 - 16;
	SiroGen->SetSpritetoEntity(entity, 1);
	entities.push_front(entity);
	//entity2->position.y = 232.0f;

	renderpos = 0;

	//GetCamera()->SetZoom(1.0f); //4.5f = Pixel Perfect Zoom
	GetCamera()->X = 0;
	GetCamera()->Y = 0;
	//gro.spriteTL = drt.spriteTL;
	//_instance->EditTile(3, 1, 3);
	//Nametables[0]->tiles[3 + (3 * 16) ] = 0;
	//Nametables[0]->flip[3 + (3 * 16)] = 3;
}

void World1::update() {
	if (GetInput()->KeyDown(KeyCode::Left) && SiroGen->rendermode == 1) {
		GetCamera()->X -= 2;
		entity->position.x-=2;
		GetCamera()->scrolldir.x = 0;
	}
	else if (GetInput()->KeyDown(KeyCode::Right) && SiroGen->rendermode == 1) {
		GetCamera()->X += 2;
		entity->position.x+=2;
		GetCamera()->scrolldir.x = 1;
	}
	else if (GetInput()->KeyDown(KeyCode::Up) && SiroGen->rendermode == 2) {
		GetCamera()->Y -= 2;
		GetCamera()->scrolldir.y = 0;
	}
	else if (GetInput()->KeyDown(KeyCode::Down) && SiroGen->rendermode == 2) {
		GetCamera()->Y += 2;
		GetCamera()->scrolldir.y = 1;
	}
	if (GetInput()->KeyPressed(KeyCode::LeftControl)) {
		//if (_instance->rendermode == 1) {
		//	_instance->SetRenderMode(this, 2);
		//}
		//else {
		//	_instance->SetRenderMode(this, 1);
		//}
		//_instance->UpdateMainTile(Nametables[0], 1);
		//SiroGen->BackgroundPalette[0] = Palette{200,120,0, 43,54,3, 165,20,65};
		//printf("entity->texture_buffer = %d\n", entity->texture_buffer);
		//entity->attributes++;
	}
	if (GetInput()->KeyPressed(KeyCode::Backspace)) {
	}
	//entity->position.x += 0.5f;
	//GetCamera()->X = entity->position.x;
}
