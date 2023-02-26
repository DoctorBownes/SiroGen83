#ifndef SPRITEFACTORY_H_
#define SPRITEFACTORY_H_

#include <SiroGen83/tile.h>
#include <SiroGen83/renderer.h>

void process(void) {
	Renderer* SiroGen = SiroGen->GetInstance();

	Tile t00 = {
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,3,3,3,3,3,3,1,1,1,1,1,
1,1,1,3,3,3,3,3,3,3,3,3,3,1,1,1,
1,1,1,3,3,3,3,1,1,3,3,3,3,1,1,1,
1,1,3,3,3,3,1,1,1,1,3,3,3,3,1,1,
1,1,3,3,3,3,1,1,1,1,3,3,3,3,1,1,
1,1,3,3,3,3,1,1,1,1,3,3,3,3,1,1,
1,1,3,3,3,3,1,1,1,1,3,3,3,3,1,1,
1,1,3,3,3,3,1,1,1,1,3,3,3,3,1,1,
1,1,3,3,3,3,1,1,1,1,3,3,3,3,1,1,
1,1,1,3,3,3,3,1,1,3,3,3,3,1,1,1,
1,1,1,1,3,3,3,3,3,3,3,3,3,1,1,1,
1,1,1,1,1,3,3,3,3,3,3,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	};
	Tile t01 = {
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,3,3,3,3,1,1,1,1,
1,1,1,1,1,1,1,3,3,3,3,3,1,1,1,1,
1,1,1,1,1,3,3,3,3,3,3,3,1,1,1,1,
1,1,1,3,3,3,3,1,3,3,3,3,1,1,1,1,
1,1,1,3,3,1,1,1,3,3,3,3,1,1,1,1,
1,1,1,1,1,1,1,1,3,3,3,3,1,1,1,1,
1,1,1,1,1,1,1,1,3,3,3,3,1,1,1,1,
1,1,1,1,1,1,1,1,3,3,3,3,1,1,1,1,
1,1,1,1,1,1,1,1,3,3,3,3,1,1,1,1,
1,1,1,1,1,1,1,1,3,3,3,3,1,1,1,1,
1,1,1,1,1,1,1,1,3,3,3,3,1,1,1,1,
1,1,1,1,1,1,1,1,3,3,3,3,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	};
	Tile t02 = {
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,3,3,3,3,3,3,1,1,1,1,1,
1,1,1,3,3,3,3,3,3,3,3,3,3,1,1,1,
1,1,3,3,3,3,3,1,1,1,3,3,3,3,1,1,
1,1,3,3,3,3,1,1,1,1,3,3,3,3,1,1,
1,1,1,1,1,1,1,1,1,1,3,3,3,3,1,1,
1,1,1,1,1,1,1,1,1,3,3,3,3,1,1,1,
1,1,1,1,1,1,1,3,3,3,3,3,1,1,1,1,
1,1,1,1,1,1,3,3,3,3,3,1,1,1,1,1,
1,1,1,1,3,3,3,3,3,1,1,1,1,1,1,1,
1,1,1,3,3,3,3,1,1,1,1,1,1,1,1,1,
1,1,1,3,3,3,3,3,3,3,3,3,3,3,1,1,
1,1,3,3,3,3,3,3,3,3,3,3,3,3,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	};
	Tile t03 = {
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,3,3,3,3,3,3,3,1,1,1,1,1,
1,1,1,3,3,3,3,3,3,3,3,3,1,1,1,1,
1,1,3,3,3,3,1,1,1,3,3,3,3,1,1,1,
1,1,1,1,1,1,1,1,1,3,3,3,3,1,1,1,
1,1,1,1,1,1,1,3,3,3,3,1,1,1,1,1,
1,1,1,1,1,1,1,3,3,3,3,3,1,1,1,1,
1,1,1,1,1,1,1,1,1,3,3,3,3,1,1,1,
1,1,1,1,1,1,1,1,1,1,3,3,3,3,1,1,
1,1,3,3,3,3,1,1,1,1,3,3,3,3,1,1,
1,1,3,3,3,3,3,1,1,3,3,3,3,3,1,1,
1,1,1,3,3,3,3,3,3,3,3,3,3,1,1,1,
1,1,1,1,1,3,3,3,3,3,3,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	};
	Tile t04 = {
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,3,3,3,3,1,1,1,1,
1,1,1,1,1,1,1,3,3,3,3,3,1,1,1,1,
1,1,1,1,1,1,3,3,3,3,3,3,1,1,1,1,
1,1,1,1,1,3,3,3,3,3,3,3,1,1,1,1,
1,1,1,1,3,3,3,1,3,3,3,3,1,1,1,1,
1,1,1,3,3,3,1,1,3,3,3,3,1,1,1,1,
1,1,3,3,3,1,1,1,3,3,3,3,1,1,1,1,
1,3,3,3,3,1,1,1,3,3,3,3,1,1,1,1,
1,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,
1,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,
1,1,1,1,1,1,1,1,3,3,3,3,1,1,1,1,
1,1,1,1,1,1,1,1,3,3,3,3,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	};
	Tile t05 = {
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,3,3,3,3,3,3,3,3,3,1,1,1,
1,1,1,1,3,3,3,3,3,3,3,3,3,1,1,1,
1,1,1,3,3,3,3,1,1,1,1,1,1,1,1,1,
1,1,1,3,3,3,1,1,1,1,1,1,1,1,1,1,
1,1,1,3,3,3,3,3,3,3,3,1,1,1,1,1,
1,1,3,3,3,3,3,3,3,3,3,3,3,1,1,1,
1,1,3,3,3,3,1,1,1,3,3,3,3,3,1,1,
1,1,1,1,1,1,1,1,1,1,3,3,3,3,1,1,
1,1,3,3,3,3,1,1,1,1,3,3,3,3,1,1,
1,1,3,3,3,3,3,1,1,3,3,3,3,3,1,1,
1,1,1,3,3,3,3,3,3,3,3,3,3,1,1,1,
1,1,1,1,1,3,3,3,3,3,3,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	};
	Tile t06 = {
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,3,3,3,3,3,3,1,1,1,1,
1,1,1,1,3,3,3,3,3,3,3,3,3,1,1,1,
1,1,1,3,3,3,3,1,1,1,3,3,3,3,1,1,
1,1,3,3,3,3,1,1,1,1,1,1,1,1,1,1,
1,1,3,3,3,3,1,3,3,3,3,1,1,1,1,1,
1,1,3,3,3,3,3,3,3,3,3,3,3,1,1,1,
1,1,3,3,3,3,3,1,1,3,3,3,3,3,1,1,
1,1,3,3,3,3,1,1,1,1,3,3,3,3,1,1,
1,1,3,3,3,3,1,1,1,1,3,3,3,3,1,1,
1,1,1,3,3,3,3,1,1,1,3,3,3,3,1,1,
1,1,1,1,3,3,3,3,3,3,3,3,3,1,1,1,
1,1,1,1,1,3,3,3,3,3,3,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	};
	Tile t07 = {
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,3,3,3,3,3,3,3,3,3,3,3,3,1,1,
1,1,3,3,3,3,3,3,3,3,3,3,3,3,1,1,
1,1,1,1,1,1,1,1,1,3,3,3,3,1,1,1,
1,1,1,1,1,1,1,1,3,3,3,3,1,1,1,1,
1,1,1,1,1,1,1,3,3,3,3,1,1,1,1,1,
1,1,1,1,1,1,1,3,3,3,1,1,1,1,1,1,
1,1,1,1,1,1,3,3,3,3,1,1,1,1,1,1,
1,1,1,1,1,3,3,3,3,1,1,1,1,1,1,1,
1,1,1,1,1,3,3,3,3,1,1,1,1,1,1,1,
1,1,1,1,3,3,3,3,1,1,1,1,1,1,1,1,
1,1,1,1,3,3,3,3,1,1,1,1,1,1,1,1,
1,1,1,1,3,3,3,3,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	};
	Tile t08 = {
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,3,3,3,3,3,3,3,3,1,1,1,1,
1,1,1,3,3,3,3,3,3,3,3,3,3,1,1,1,
1,1,3,3,3,3,1,1,1,1,3,3,3,3,1,1,
1,1,3,3,3,3,1,1,1,1,3,3,3,3,1,1,
1,1,3,3,3,3,1,1,1,1,3,3,3,1,1,1,
1,1,1,1,3,3,3,3,3,3,3,3,1,1,1,1,
1,1,1,1,3,3,3,3,3,3,3,3,1,1,1,1,
1,1,3,3,3,3,1,1,1,1,3,3,3,3,1,1,
1,1,3,3,3,3,1,1,1,1,3,3,3,3,1,1,
1,1,3,3,3,3,1,1,1,1,3,3,3,3,1,1,
1,1,1,3,3,3,3,3,3,3,3,3,3,1,1,1,
1,1,1,1,1,3,3,3,3,3,3,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	};
	Tile t09 = {
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,3,3,3,3,3,3,1,1,1,1,1,
1,1,1,3,3,3,3,3,3,3,3,3,1,1,1,1,
1,1,3,3,3,3,1,1,1,3,3,3,3,1,1,1,
1,1,3,3,3,3,1,1,1,1,3,3,3,3,1,1,
1,1,3,3,3,3,1,1,1,1,3,3,3,3,1,1,
1,1,3,3,3,3,3,1,1,3,3,3,3,3,1,1,
1,1,1,3,3,3,3,3,3,3,3,3,3,3,1,1,
1,1,1,1,1,3,3,3,3,1,3,3,3,3,1,1,
1,1,1,1,1,1,1,1,1,1,3,3,3,3,1,1,
1,1,3,3,3,3,1,1,1,3,3,3,3,1,1,1,
1,1,1,3,3,3,3,3,3,3,3,3,1,1,1,1,
1,1,1,1,3,3,3,3,3,3,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	};

	SiroGen->AddtoTileMap(&t00, 0);
	SiroGen->AddtoTileMap(&t01, 1);
	SiroGen->AddtoTileMap(&t02, 2);
	SiroGen->AddtoTileMap(&t03, 3);
	SiroGen->AddtoTileMap(&t04, 4);
	SiroGen->AddtoTileMap(&t05, 5);
	SiroGen->AddtoTileMap(&t06, 6);
	SiroGen->AddtoTileMap(&t07, 7);
	SiroGen->AddtoTileMap(&t08, 8);
	SiroGen->AddtoTileMap(&t09, 9);

	Tile t11 = {
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,
1,1,1,1,1,1,2,1,2,1,2,1,2,1,1,2,
0,1,1,1,1,1,1,2,1,2,1,2,2,2,2,2,
0,0,1,1,1,1,1,1,2,1,2,1,2,2,2,2,
0,0,0,1,1,1,1,1,1,2,1,2,1,2,2,2,
0,0,0,0,1,1,1,1,1,1,2,1,2,1,2,2,
0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,
0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,
	};
	Tile t12 = {
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,
2,2,1,2,1,2,2,2,1,2,1,1,2,1,2,1,
2,1,2,1,2,1,2,2,2,2,2,2,2,2,2,2,
1,2,1,2,1,2,1,2,2,2,2,2,2,2,2,2,
2,1,2,1,2,1,2,1,2,1,2,2,2,2,2,2,
1,1,1,2,1,1,1,2,1,2,1,2,1,2,2,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	};
	Tile t13 = {
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,3,3,3,3,3,3,3,1,3,3,3,3,3,3,3,
1,3,2,2,2,2,2,2,1,3,1,2,2,2,2,2,
1,3,1,2,2,2,2,2,1,3,2,2,2,2,2,2,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
3,3,3,1,3,3,3,3,3,3,3,1,3,3,3,3,
2,2,2,1,3,2,2,2,2,2,2,1,3,2,2,2,
2,2,2,1,3,2,2,2,2,1,2,1,3,2,2,2,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
3,3,3,3,3,3,3,1,3,3,3,3,3,3,3,1,
3,2,2,2,2,2,2,1,3,2,2,2,2,2,2,1,
3,2,1,2,2,2,2,1,3,2,2,2,2,2,2,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
3,3,3,1,3,3,3,3,3,3,3,1,3,3,3,3,
2,2,2,1,3,2,2,2,2,1,2,1,3,2,2,2,
2,2,2,1,3,2,2,2,2,2,2,1,3,2,2,2,
	};
	Tile t14 = {
2,1,1,1,1,1,1,2,2,1,1,1,1,1,1,2,
1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1,
1,2,2,3,3,2,2,1,1,2,2,3,3,2,2,1,
1,2,3,3,3,3,2,1,1,2,3,3,3,3,2,1,
1,2,3,3,3,3,2,1,1,2,3,3,3,3,2,1,
1,2,3,3,2,3,2,1,1,2,3,3,2,3,2,1,
1,2,3,2,3,3,2,1,1,2,3,2,3,3,2,1,
1,2,3,3,3,3,2,1,1,2,3,3,3,3,2,1,
1,2,3,3,3,3,2,1,1,2,3,3,3,3,2,1,
1,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,
1,2,3,3,3,3,2,1,1,2,3,3,3,3,2,1,
1,2,3,3,3,3,2,1,1,2,3,3,3,3,2,1,
1,2,3,3,2,3,2,1,1,2,3,3,2,3,2,1,
1,2,3,2,3,3,2,1,1,2,3,2,3,3,2,1,
1,2,3,3,3,3,2,1,1,2,3,3,3,3,2,1,
2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	};
	Tile t15 = {
0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,
0,0,0,0,0,0,3,1,3,3,3,3,3,3,3,1,
0,0,0,0,0,0,3,1,3,1,2,2,2,2,2,1,
0,0,0,0,0,0,2,1,3,2,2,2,2,2,2,1,
0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,
0,0,0,0,0,0,3,3,3,3,3,1,3,3,3,3,
0,0,0,0,0,0,3,2,2,2,2,1,3,2,2,2,
0,0,0,0,0,0,2,2,2,1,2,1,3,2,2,2,
0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,
0,0,0,0,0,0,3,1,3,3,3,3,3,3,3,1,
0,0,0,0,0,0,3,1,3,2,2,2,2,2,2,1,
0,0,0,0,0,0,2,1,3,2,2,2,2,2,2,1,
0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,
0,0,0,0,0,0,3,3,3,3,3,1,3,3,3,3,
0,0,0,0,0,0,3,2,2,1,2,1,3,2,2,2,
0,0,0,0,0,0,2,2,2,2,2,1,3,2,2,2,
	};
	Tile t20 = {
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
	};

	SiroGen->AddtoTileMap(&t11, 11);
	SiroGen->AddtoTileMap(&t12, 12);
	SiroGen->AddtoTileMap(&t13, 13);
	SiroGen->AddtoTileMap(&t14, 14);
	SiroGen->AddtoTileMap(&t15, 15);
	SiroGen->AddtoTileMap(&t20, 20);

	Sprite manny1 = Sprite{ 16,16,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,3,3,3,3,3,3,3,0,0,0,0,0,
0,0,0,0,3,3,3,3,3,3,3,0,0,0,0,0,
0,0,0,0,1,1,1,1,2,1,2,0,0,0,0,0,
0,0,0,1,1,1,1,1,2,2,2,2,0,0,0,0,
0,0,0,1,1,1,2,2,2,1,1,0,0,0,0,0,
0,0,0,0,2,2,2,2,2,2,2,0,0,0,0,0,
0,0,0,0,1,1,1,1,3,1,1,0,0,0,0,0,
0,0,0,0,1,1,2,2,3,3,3,0,0,0,0,0,
0,0,0,1,1,3,2,2,3,3,3,3,0,0,0,0,
0,0,0,3,3,3,2,2,3,3,3,3,0,0,0,0,
0,0,0,0,0,1,1,1,1,1,3,3,0,0,0,0,
0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,
0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0,
	};
	Sprite manny2 = Sprite{ 16,16,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,3,3,3,3,3,3,3,0,0,0,0,0,
0,0,0,0,3,3,3,3,3,3,3,0,0,0,0,0,
0,0,0,0,1,1,1,1,2,1,2,0,0,0,0,0,
0,0,0,1,1,1,1,1,2,2,2,2,0,0,0,0,
0,0,0,1,1,1,2,2,2,1,1,0,2,2,0,0,
0,0,0,0,2,2,2,2,2,2,2,0,2,2,0,0,
0,0,2,2,1,1,1,1,3,1,1,2,2,2,0,0,
0,0,2,2,1,1,1,3,1,1,2,2,2,0,0,0,
0,0,0,3,3,3,3,3,3,3,3,3,0,0,0,0,
0,0,0,1,3,1,1,1,3,3,3,3,0,0,0,0,
0,0,3,1,1,1,1,1,1,1,3,1,3,0,0,0,
0,0,0,3,1,0,0,0,0,0,1,3,0,0,0,0,
0,0,0,0,3,0,0,0,0,0,3,0,0,0,0,0,
	};
	Sprite block = Sprite{ 16,16,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,3,1,1,1,1,2,1,2,3,3,3,3,3,
3,3,3,1,1,1,1,1,2,2,2,2,3,3,3,3,
3,3,3,1,1,1,2,2,2,1,1,3,2,2,3,3,
3,3,3,3,2,2,2,2,2,2,2,3,2,2,3,3,
3,3,2,2,1,1,1,1,3,1,1,2,2,2,3,3,
3,3,2,2,1,1,1,3,1,1,2,2,2,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,3,3,1,3,1,1,1,3,3,3,3,3,3,3,3,
3,3,3,1,1,1,1,1,1,1,3,1,3,3,3,3,
3,3,3,3,1,3,3,3,3,3,1,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
	};

	SiroGen->AddSpritetoMemory(&manny1, 0);
	SiroGen->AddSpritetoMemory(&manny2, 1);
	SiroGen->AddSpritetoMemory(&block, 2);

	return;
};

#endif
