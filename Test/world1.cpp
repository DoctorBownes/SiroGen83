#include "world1.h"
#include <stdio.h>
#include <stack>

Entity* entity = new Entity();
Entity* entity2 = new Entity();
Entity* text = new Entity();
Animation animation = Animation{ 0.15f, 1, 2, 4,0, 5,6};

	Sprite hightext = Sprite{ 72,8,
0,2,2,0,0,2,2,0,0,0,0,2,2,0,0,0,0,0,0,2,2,2,0,0,0,2,2,0,0,2,2,0,0,0,2,2,2,2,0,0,0,0,2,2,2,2,0,0,0,0,2,2,2,2,0,0,0,0,2,2,2,0,0,0,0,0,2,2,2,2,2,0,
0,2,2,0,0,2,2,0,0,0,0,2,2,0,0,0,0,0,2,2,2,2,2,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,2,2,2,2,0,0,2,2,2,2,2,2,0,0,2,2,2,2,2,0,0,0,2,2,2,2,2,2,0,
0,2,2,0,0,2,2,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,2,2,0,0,2,2,0,0,2,2,0,0,0,2,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,0,0,0,0,0,
0,2,2,2,2,2,2,0,0,0,2,2,2,0,0,0,0,2,2,0,0,0,0,0,0,2,2,2,2,2,2,0,0,0,2,2,0,0,0,0,0,2,2,0,0,0,0,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,2,2,2,0,0,
0,2,2,2,2,2,2,0,0,0,0,2,2,0,0,0,0,2,2,0,2,2,2,0,0,2,2,2,2,2,2,0,0,0,0,2,2,2,0,0,0,2,2,0,0,0,0,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,2,2,2,0,0,
0,2,2,0,0,2,2,0,0,0,0,2,2,0,0,0,0,2,2,0,0,0,2,0,0,2,2,0,0,2,2,0,0,2,0,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,2,2,2,0,0,0,2,2,0,0,0,0,0,
0,2,2,0,0,2,2,0,0,0,0,2,2,0,0,0,0,0,2,2,2,2,2,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,2,2,2,2,0,0,2,2,2,2,2,2,0,0,2,2,0,2,2,2,0,0,2,2,2,2,2,2,0,
0,2,2,0,0,2,2,0,0,2,2,2,2,2,2,0,0,0,0,2,2,2,0,0,0,2,2,0,0,2,2,0,0,0,2,2,2,2,0,0,0,0,2,2,2,2,0,0,0,0,2,2,2,2,0,0,0,2,2,0,0,2,2,0,0,0,2,2,2,2,2,0,

	};

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
		0, 42, 136,		173, 101, 24,		11, 72, 0,
	};
	SiroGen->BackgroundPalette[3] = {
		0, 0, 0,	254, 252, 221,	253, 169, 100,
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
		0, 0, 0,	254, 252, 221,	253, 169, 100,
	};

	Tile t0 = {
1,1,1,1,1,1,1,1,
1,1,1,3,3,1,1,1,
1,1,3,3,3,3,1,1,
1,3,3,1,1,3,3,1,
1,3,3,1,1,3,3,1,
1,3,3,1,1,3,3,1,
1,1,3,3,3,3,1,1,
1,1,1,3,3,1,1,1,
	};

	Tile t1 = {
1,1,1,1,1,1,1,1,
1,1,1,1,3,3,1,1,
1,1,1,3,3,3,1,1,
1,1,3,3,3,3,1,1,
1,1,1,3,3,3,1,1,
1,1,1,3,3,3,1,1,
1,1,1,3,3,3,1,1,
1,1,1,3,3,3,1,1,
	};

	Tile t2 = {
1,1,1,1,1,1,1,1,
1,3,3,3,3,3,1,1,
3,3,3,1,3,3,3,1,
1,3,1,1,3,3,3,1,
1,1,1,3,3,3,1,1,
1,3,3,3,3,1,1,1,
3,3,3,1,1,3,3,1,
3,3,3,3,3,3,1,1,
	};

	Tile t3 = {
1,1,1,1,1,1,1,1,
3,3,3,3,3,3,1,1,
1,1,1,3,3,1,1,1,
1,1,3,3,3,3,1,1,
1,3,3,1,3,3,3,1,
1,1,1,1,3,3,3,1,
1,1,3,3,3,3,1,1,
1,3,3,3,1,1,1,1,
	};

	Tile t4 = {
1,1,1,1,1,1,1,1,
1,1,1,3,3,1,1,1,
1,1,3,3,3,1,1,1,
1,3,3,3,1,1,1,1,
1,3,3,1,3,3,1,1,
3,3,3,1,3,3,3,1,
3,3,3,3,3,3,3,1,
1,1,1,3,3,3,1,1,
	};

	Tile t5 = {
1,1,1,1,1,1,1,1,
1,1,3,3,3,3,3,1,
1,1,3,1,1,1,1,1,
1,3,3,3,3,3,1,1,
1,3,3,1,3,3,3,1,
1,1,1,1,3,3,3,1,
1,1,1,3,3,3,1,1,
1,1,3,3,1,1,1,1,
	};

	Tile t6 = {
1,1,1,1,1,1,1,1,
1,1,1,1,1,3,3,1,
1,1,1,3,3,3,1,1,
1,1,3,3,3,1,1,1,
1,3,3,3,3,3,1,1,
1,3,3,1,1,3,3,1,
1,3,1,1,3,3,3,1,
1,1,3,3,3,3,1,1,
	};

	Tile t7 = {
1,1,1,1,1,1,1,1,
1,3,3,3,3,3,3,1,
3,3,1,1,3,3,3,1,
1,1,1,3,3,3,1,1,
1,1,1,3,3,1,1,1,
1,1,3,3,3,1,1,1,
1,1,3,3,1,1,1,1,
1,1,3,3,1,1,1,1,
	};

	Tile t8 = {
1,1,1,1,1,1,1,1,
1,1,3,3,3,3,1,1,
1,3,3,3,1,3,3,1,
1,1,3,1,1,3,3,1,
1,3,3,3,3,3,1,1,
3,3,1,1,3,3,3,1,
3,3,1,1,3,3,1,1,
1,3,3,3,3,1,1,1,
	};

	Tile t9 = {
1,1,1,1,1,1,1,1,
1,1,3,3,3,3,1,1,
1,3,3,1,1,3,3,1,
1,3,3,1,1,3,3,1,
1,1,3,3,3,3,3,1,
1,1,1,3,3,3,1,1,
1,1,3,3,3,1,1,1,
1,3,3,1,1,1,1,1,
	};

	Tile t11 = {
1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,
	};

	SiroGen->AddtoTileMap(&t0, 0);
	SiroGen->AddtoTileMap(&t1, 1);
	SiroGen->AddtoTileMap(&t2, 2);
	SiroGen->AddtoTileMap(&t3, 3);
	SiroGen->AddtoTileMap(&t4, 4);
	SiroGen->AddtoTileMap(&t5, 5);
	SiroGen->AddtoTileMap(&t6, 6);
	SiroGen->AddtoTileMap(&t7, 7);
	SiroGen->AddtoTileMap(&t8, 8);
	SiroGen->AddtoTileMap(&t9, 9);
	SiroGen->AddtoTileMap(&t11, 11);

	TileScreens[0] = new TileScreen{
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,
1,1,1,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,1,1,1,
1,1,1,2,2,2,2,1,1,2,2,2,2,1,1,1,1,1,1,2,2,2,2,1,1,2,2,2,2,1,1,1,
1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,
1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,
1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,
1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,
1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,
1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,
1,1,1,2,2,2,2,1,1,2,2,2,2,1,1,1,1,1,1,2,2,2,2,1,1,2,2,2,2,1,1,1,
1,1,1,1,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,1,1,1,
1,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,
1,1,1,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,1,1,1,
1,1,1,2,2,2,2,1,1,2,2,2,2,1,1,1,1,1,1,2,2,2,2,1,1,2,2,2,2,1,1,1,
1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,
1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,
1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,
1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,
1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,
1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,
1,1,1,2,2,2,2,1,1,2,2,2,2,1,1,1,1,1,1,2,2,2,2,1,1,2,2,2,2,1,1,1,
1,1,1,1,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,1,1,1,
1,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,

1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
	};

	TileScreens[1] = new TileScreen{
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,
1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,
1,1,1,1,1,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,1,1,1,1,
1,1,1,2,2,2,2,1,2,2,2,2,1,1,1,1,1,1,1,2,2,2,2,1,2,2,2,2,1,1,1,1,
1,1,1,2,2,1,1,1,2,2,2,2,1,1,1,1,1,1,1,2,2,1,1,1,2,2,2,2,1,1,1,1,
1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,
1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,
1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,
1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,
1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,
1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,
1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,
1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,
1,1,1,1,1,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,1,1,1,1,
1,1,1,2,2,2,2,1,2,2,2,2,1,1,1,1,1,1,1,2,2,2,2,1,2,2,2,2,1,1,1,1,
1,1,1,2,2,1,1,1,2,2,2,2,1,1,1,1,1,1,1,2,2,1,1,1,2,2,2,2,1,1,1,1,
1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,
1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,
1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,
1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,
1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,
1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,
1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,

3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
	};

	TileScreens[2] = new TileScreen{
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,
1,1,1,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,1,1,1,
1,1,2,2,2,2,2,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,2,1,1,1,2,2,2,2,1,1,
1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,
1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,
1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,
1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,
1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,
1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,1,
1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,
1,1,1,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,1,1,
1,1,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,
1,1,1,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,1,1,1,
1,1,2,2,2,2,2,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,2,1,1,1,2,2,2,2,1,1,
1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,
1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,
1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,
1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,
1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,
1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,1,
1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,
1,1,1,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,1,1,
1,1,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,

3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
	};

	TileScreens[3] = new TileScreen{
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,1,1,1,1,1,
1,1,1,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,1,1,1,1,
1,1,2,2,2,2,1,1,1,2,2,2,2,1,1,1,1,1,2,2,2,2,1,1,1,2,2,2,2,1,1,1,
1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,
1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,
1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,
1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,
1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,
1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,
1,1,2,2,2,2,2,1,1,2,2,2,2,2,1,1,1,1,2,2,2,2,2,1,1,2,2,2,2,2,1,1,
1,1,1,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,1,1,1,
1,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,1,1,1,1,1,
1,1,1,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,1,1,1,1,
1,1,2,2,2,2,1,1,1,2,2,2,2,1,1,1,1,1,2,2,2,2,1,1,1,2,2,2,2,1,1,1,
1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,
1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,
1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,
1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,
1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,
1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,
1,1,2,2,2,2,2,1,1,2,2,2,2,2,1,1,1,1,2,2,2,2,2,1,1,2,2,2,2,2,1,1,
1,1,1,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,1,1,1,
1,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,

3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
	};

	//TileScreens[0]->tiles[3] = 0;
	//TileScreens[0]->flip[3] = 3;

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
	Sprite jojospr2 = Sprite{ 16,32,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,0,
0,0,0,0,0,0,3,3,3,3,3,0,0,0,0,0,
0,0,0,0,0,0,3,3,3,3,3,3,0,0,0,0,
0,0,0,0,0,3,3,1,3,1,1,3,0,0,0,0,
0,0,0,0,0,3,3,1,1,2,2,0,0,0,0,0,
0,0,0,0,3,3,3,1,1,1,1,0,0,0,0,0,
0,0,0,0,3,2,2,2,1,1,2,0,0,0,0,0,
0,0,0,3,2,2,2,2,2,1,1,0,0,0,0,0,
0,0,3,1,0,2,2,2,2,2,2,3,0,0,0,0,
0,3,1,1,1,0,2,3,3,3,3,1,3,0,0,0,
0,3,1,1,1,1,3,3,3,3,3,3,1,3,0,0,
0,3,1,1,1,1,3,3,3,3,3,3,1,3,0,0,
0,3,1,1,1,1,1,3,3,2,1,3,1,3,0,0,
0,0,3,1,1,1,2,2,2,1,1,1,3,0,0,0,
0,0,3,1,1,1,2,2,1,2,1,3,0,0,0,0,
0,0,0,3,3,2,3,3,3,3,3,0,0,0,0,0,
0,0,0,0,0,3,3,3,3,1,0,0,0,0,0,0,
0,0,0,0,0,2,1,1,1,1,0,0,0,0,0,0,
0,0,0,0,0,3,3,3,3,3,2,0,0,0,0,0,
0,0,0,0,0,0,3,3,3,3,3,0,0,0,0,0,
0,0,0,0,0,0,3,3,2,3,3,3,0,0,0,0,
0,0,0,0,0,0,3,3,2,3,3,3,0,0,0,0,
0,0,0,0,0,3,3,3,3,3,3,0,0,0,0,0,
0,0,0,0,3,2,3,2,3,3,0,0,0,0,0,0,
0,0,0,3,2,3,2,2,2,3,0,0,0,0,0,0,
0,0,0,3,2,3,2,2,3,0,0,0,0,0,0,0,
0,0,0,0,3,2,2,2,3,0,0,0,0,0,0,0,
0,0,0,0,0,3,2,2,2,3,0,0,0,0,0,0,
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
	Sprite belmspr1 = Sprite{ 16,32,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,2,2,2,2,2,0,0,0,
		0,0,0,0,0,0,0,0,2,2,2,2,2,2,0,0,
		0,0,0,0,0,0,0,2,2,2,2,1,1,2,0,0,
		0,0,0,0,0,0,0,2,2,2,3,1,3,2,0,0,
		0,0,0,0,0,2,2,2,2,3,3,1,1,2,0,0,
		0,0,0,0,2,3,3,1,2,3,3,3,1,2,0,0,
		0,0,0,0,3,2,3,3,1,2,3,2,2,2,0,0,
		0,0,0,3,2,1,2,2,3,2,2,2,2,0,0,0,
		0,0,0,2,1,1,1,2,2,3,3,2,3,2,0,0,
		0,0,0,2,1,1,2,2,2,2,3,3,2,0,0,0,
		0,0,0,1,2,2,2,2,2,2,2,3,0,0,0,0,
		0,0,2,1,3,2,1,2,2,2,2,2,0,0,0,0,
		0,0,2,3,2,3,3,1,2,2,1,2,0,0,0,0,
		0,0,2,2,2,3,3,3,1,1,1,1,2,0,0,0,
		0,0,2,2,2,2,2,3,1,1,1,1,2,0,0,0,
		0,0,2,2,2,3,2,2,2,2,2,2,0,0,0,0,
		0,0,0,2,2,3,2,2,2,2,3,0,0,0,0,0,
		0,0,0,2,2,2,2,2,2,2,3,0,0,0,0,0,
		0,0,0,2,2,2,1,1,2,2,2,0,0,0,0,0,
		0,0,0,0,0,2,1,1,2,2,0,0,0,0,0,0,
		0,0,0,0,0,2,1,1,2,1,2,0,0,0,0,0,
		0,0,0,0,0,2,1,1,2,1,1,2,0,0,0,0,
		0,0,0,0,0,2,1,1,2,1,1,2,0,0,0,0,
		0,0,0,0,0,2,2,2,2,1,2,2,0,0,0,0,
		0,0,0,0,2,2,3,3,3,2,2,0,0,0,0,0,
		0,0,2,2,2,2,3,3,2,0,0,0,0,0,0,0,
		0,0,2,3,2,3,3,2,0,0,0,0,0,0,0,0,
		0,0,2,3,2,3,3,2,0,0,0,0,0,0,0,0,
		0,0,0,2,3,3,3,2,0,0,0,0,0,0,0,0,
		0,0,0,2,3,3,3,3,2,0,0,0,0,0,0,0,
		0,0,0,0,2,2,2,2,2,0,0,0,0,0,0,0,
	};
	Sprite belmspr2 = Sprite{ 16,32,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,0,
0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,
0,0,0,0,0,0,0,0,0,2,2,2,2,1,1,2,
0,0,0,0,0,0,0,0,2,2,2,2,3,1,3,2,
0,0,0,0,0,0,0,2,2,2,2,3,3,1,1,2,
0,0,0,0,0,0,0,3,1,2,2,3,3,3,1,2,
0,0,0,0,0,2,3,3,3,1,2,2,3,2,2,2,
0,0,0,0,0,2,2,2,2,3,3,2,2,2,0,0,
0,0,0,0,2,1,1,1,2,2,3,3,2,1,2,0,
0,0,0,2,2,2,1,2,2,2,2,3,3,2,0,0,
0,0,0,2,3,2,2,2,2,2,2,2,3,2,0,0,
0,0,0,2,2,2,1,1,2,2,1,2,2,2,0,0,
0,0,0,2,2,3,3,3,1,1,1,1,2,0,0,0,
0,0,2,3,2,2,2,3,3,1,1,1,2,0,0,0,
0,0,2,3,2,2,3,2,2,2,3,3,2,0,0,0,
0,0,2,3,3,3,2,1,1,2,2,2,2,2,0,0,
0,0,2,2,2,2,1,1,1,1,2,0,0,0,0,0,
0,0,2,2,2,2,2,1,1,1,1,2,0,0,0,0,
0,0,0,0,2,2,2,2,2,1,1,1,2,2,0,0,
0,0,0,0,2,1,1,2,2,2,1,1,1,2,2,0,
0,0,0,0,2,1,1,2,0,0,2,2,2,2,2,0,
0,0,0,0,2,2,2,2,0,0,0,2,2,2,2,0,
0,0,0,2,3,2,2,2,0,0,0,2,3,3,2,0,
0,0,2,3,3,3,2,0,0,0,2,3,3,3,2,0,
0,2,2,3,3,2,0,0,0,0,2,3,3,3,2,0,
0,2,3,3,2,0,0,0,0,0,0,3,3,3,2,0,
0,3,3,2,0,0,0,0,0,0,0,2,3,3,2,0,
0,2,3,3,2,0,0,0,0,0,0,2,3,3,3,2,
0,2,3,3,3,1,0,0,0,0,0,2,3,3,3,3,
0,2,2,2,2,2,2,0,0,0,0,2,2,2,2,2,

	};
	Sprite bb1 = Sprite{ 16,16,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,2,2,2,2,2,2,2,0,0,0,0,0,
0,0,0,0,2,2,2,2,2,2,2,0,0,0,0,0,
0,0,0,0,1,1,1,1,3,1,3,0,0,0,0,0,
0,0,0,1,1,1,1,1,3,3,3,3,0,0,0,0,
0,0,0,1,1,1,3,3,3,1,1,0,0,0,0,0,
0,0,0,0,3,3,3,3,3,3,3,0,0,0,0,0,
0,0,0,0,3,2,2,2,3,3,3,0,0,0,0,0,
0,0,0,0,2,2,3,3,2,2,2,0,0,0,0,0,
0,0,0,2,2,2,3,3,2,2,2,2,0,0,0,0,
0,0,0,2,2,2,3,3,2,2,2,2,0,0,0,0,
0,0,0,0,0,1,1,1,1,1,2,0,0,0,0,0,
0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,
0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0,
	};
	Sprite bb2 = Sprite{ 8,72,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,2,2,2,2,
0,0,0,0,2,2,2,2,
0,0,0,0,1,1,1,1,
0,0,0,1,1,1,1,1,
0,0,0,1,1,1,3,3,
0,0,0,0,3,3,3,3,
0,0,3,3,3,3,2,2,
0,0,3,3,2,2,2,2,
0,0,0,2,2,2,2,2,
0,0,0,2,2,2,2,2,
0,0,2,1,1,1,1,1,
0,0,0,2,1,0,0,0,
0,0,0,0,2,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,2,2,2,2,
0,0,0,0,2,2,2,2,
0,0,0,0,1,1,1,1,
0,0,0,1,1,1,1,1,
0,0,0,1,1,1,3,3,
0,0,0,0,3,3,3,3,
0,0,3,3,3,3,2,2,
0,0,3,3,2,2,2,2,
0,0,0,2,2,2,2,2,
0,0,0,2,2,2,2,2,
0,0,2,1,1,1,1,1,
0,0,0,2,1,0,0,0,
0,0,0,0,2,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,2,2,2,2,
0,0,0,0,2,2,2,2,
0,0,0,0,1,1,1,1,
0,0,0,1,1,1,1,1,
0,0,0,1,1,1,3,3,
0,0,0,0,3,3,3,3,
0,0,3,3,3,3,2,2,
0,0,3,3,2,2,2,2,
0,0,0,2,2,2,2,2,
0,0,0,2,2,2,2,2,
0,0,2,1,1,1,1,1,
0,0,0,2,1,0,0,0,
0,0,0,0,2,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,2,2,2,2,
0,0,0,0,2,2,2,2,
0,0,0,0,1,1,1,1,
0,0,0,1,1,1,1,1,
0,0,0,1,1,1,3,3,
0,0,0,0,3,3,3,3,
0,0,3,3,3,3,2,2,
0,0,3,3,2,2,2,2,
0,0,0,2,2,2,2,2,
0,0,0,2,2,2,2,2,
0,0,2,1,1,1,1,1,
0,0,0,2,1,0,0,0,
0,0,0,0,2,0,0,0,
0,0,0,0,3,3,3,3,
0,0,3,3,3,3,2,2,
0,0,3,3,2,2,2,2,
0,0,0,2,2,2,2,2,
0,0,0,2,2,2,2,2,
0,0,2,1,1,1,1,1,
0,0,0,2,1,0,0,0,
0,0,0,0,2,0,0,0,
	};

//	unsigned char bxt[] = {
//0,1,1,1,0,0,0,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,1,0,0,1,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,0,1,1,1,0,
//1,0,0,0,1,0,1,1,0,0,1,0,0,0,1,1,0,0,0,1,0,0,1,1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,1,1,0,0,0,1,
//1,0,0,0,1,1,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,1,0,1,1,1,1,0,1,1,1,1,0,0,0,0,1,0,1,0,0,0,1,1,0,0,0,1,
//1,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,1,1,0,1,0,0,1,0,1,0,0,0,1,1,0,0,0,1,0,0,1,0,0,0,1,1,1,0,1,0,0,0,1,
//1,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,1,0,0,1,0,0,1,0,0,0,1,0,1,1,1,1,
//1,0,0,0,1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,1,1,0,0,0,1,0,1,0,0,0,1,0,0,0,1,1,0,0,0,1,
//0,1,1,1,0,0,0,1,0,0,1,1,1,1,1,0,1,1,1,0,0,0,0,1,0,0,1,1,1,0,0,1,1,1,0,0,1,0,0,0,0,1,1,1,0,0,1,1,1,0,
//
//	};

	SiroGen->AddSpritetoMemory(&jojospr, 0);
	SiroGen->AddSpritetoMemory(&belmspr, 1);
	SiroGen->AddSpritetoMemory(&belmspr1, 2);
	SiroGen->AddSpritetoMemory(&belmspr2, 3);
	SiroGen->AddSpritetoMemory(&jojospr2, 4);
	SiroGen->AddSpritetoMemory(&bb1, 5);
	SiroGen->AddSpritetoMemory(&bb2, 6);
	SiroGen->AddSpritetoMemory(&hightext, 7);

	entity2->position.x =  6 * 16;
	entity2->position.y = 13 * 15;
	SiroGen->SetSpritetoEntity(entity2, 6);
	SiroGen->SetAttributetoEntity(entity2, 1);
	entities.push_front(entity2);

	entity->position.x =  5 * 16;
	entity->position.y = 13 * 15;
	SiroGen->SetAttributetoEntity(entity, 0);
	SiroGen->SetSpritetoEntity(entity, 0);
	entities.push_front(entity);

	text->position.x = 0;
	text->position.y = 4;
	//SiroGen->SetSpritetoEntity(text, 7);
	//SiroGen->SetAttributetoEntity(text, 3);
	//entities.push_front(text);

	//entity2->position.y = 232.0f;
	ScoreScreen = new TileScreen{
		11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,9,11,11,
		11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
		11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
		11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
		11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
		11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
		11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
		11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
		10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,

		3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
		3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
		3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
		3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
		3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
		3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
		3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
		3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
		3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
		3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
		3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
		3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
		3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
		3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
		3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
	};
	SiroGen->SetGUIScreen(ScoreScreen);
	//SiroGen->UpdateGUITile(14);

	renderpos = 0;

	//GetCamera()->SetZoom(1.0f); //4.5f = Pixel Perfect Zoom
	GetCamera()->X = 0;
	GetCamera()->Y = 0;
}

unsigned char gridmap[16 * 15]{
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
	0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
};

bool TileCol(Entity* entity, unsigned char grid[16 * 15]) {
	unsigned char posz = entity->position.x * 0.0625f + (entity->position.y * 0.0667f) * 15;
	if (grid[posz] == 1) {
		return true;
	}
	return false;
}

void World1::update() {
	if (GetInput()->KeyDown(KeyCode::Left)) {
		GetCamera()->X -= 2;
	//	entity->position.x -= 2;
		GetCamera()->scrolldir.x = 0;
		SiroGen->SetAttributetoEntity(entity, 4);
		SiroGen->PlayAnimation(entity, &animation, 3,2);
	}
	if (GetInput()->KeyDown(KeyCode::Right)) {
		GetCamera()->X += 2;
	//	entity->position.x += 2;
		GetCamera()->scrolldir.x = 1;
		SiroGen->SetAttributetoEntity(entity, 0);
		SiroGen->PlayAnimation(entity, &animation, 3,2);
	}
	if (GetInput()->KeyDown(KeyCode::Up)) {
		GetCamera()->Y -= 2;
		entity->position.y -= 2;
		GetCamera()->scrolldir.y = 0;
	}
	else if (GetInput()->KeyDown(KeyCode::Down)) {
		GetCamera()->Y += 2;
		entity->position.y += 2;
		GetCamera()->scrolldir.y = 1;
	}

	if (GetInput()->KeyDown(KeyCode::A)) {
		entity2->position.x -= 2;
		SiroGen->SetAttributetoEntity(entity2, 5);
		SiroGen->PlayAnimation(entity2, &animation, 1);
	}
	else if (GetInput()->KeyDown(KeyCode::D)) {
		entity2->position.x += 2;
		SiroGen->SetAttributetoEntity(entity2, 1);
		SiroGen->PlayAnimation(entity2, &animation, 1);
	}
	text->position.x = GetCamera()->X;
	if (GetInput()->KeyPressed(KeyCode::LeftControl)) {
		ScoreScreen->tiles[66] = 7;
		SiroGen->UpdateGUITile(66,0);
	}
	if (GetInput()->KeyDown(KeyCode::Y)) {
		upscore+=10;
	}
	if (GetInput()->KeyDown(KeyCode::H)) {
		upscore-=10;
	}

	SiroGen->SetTileDigits(upscore, 16);
	//SiroGen->SetTileDigits(upscore, 13 + 16);

	

	//entity->position.x += 0.5f;
	entity->position.x = GetCamera()->X + 128;
}
