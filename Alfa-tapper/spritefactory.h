#ifndef SPRITEFACTORY_H_
#define SPRITEFACTORY_H_

#include <SiroGen83/tile.h>
#include <SiroGen83/renderer.h>

void process(void) {
	Renderer* SiroGen = SiroGen->GetInstance();

	SiroGen->AddtoTileMap(Tile{
0,1,2,3,31,1,1,1,
1,31,31,1,31,31,1,1,
31,31,1,1,31,31,1,1,
31,31,1,1,1,31,31,1,
31,31,1,1,1,31,31,1,
1,31,31,1,1,31,1,1,
1,1,31,31,31,1,1,1,
1,1,1,1,1,1,1,1, }, 0);

	SiroGen->AddtoTileMap(Tile{
1,1,1,3,3,1,1,1,
1,1,3,3,3,1,1,1,
1,1,1,3,3,1,1,1,
1,1,1,3,3,1,1,1,
1,1,1,3,3,1,1,1,
1,1,1,3,3,1,1,1,
1,3,3,3,3,3,3,1,
1,1,1,1,1,1,1,1, }, 1);

	SiroGen->AddtoTileMap(Tile{
1,3,3,3,3,3,1,1,
3,3,1,1,3,3,3,1,
3,1,1,1,1,3,3,1,
1,1,3,3,3,3,1,1,
1,3,3,3,3,1,1,1,
3,3,3,1,1,1,1,1,
3,3,3,3,3,3,3,1,
1,1,1,1,1,1,1,1, }, 2);

	SiroGen->AddtoTileMap(Tile{
1,1,3,3,3,3,1,1,
3,3,1,1,3,3,3,1,
1,1,1,3,3,1,1,1,
1,1,3,3,3,3,1,1,
1,1,1,1,1,3,3,1,
3,3,1,1,1,3,3,1,
1,3,3,3,3,3,1,1,
1,1,1,1,1,1,1,1, }, 3);

	SiroGen->AddtoTileMap(Tile{
1,1,1,3,3,1,1,1,
1,1,3,3,3,3,1,1,
1,3,3,1,3,3,1,1,
3,3,1,1,3,3,1,1,
3,3,3,3,3,3,1,1,
1,1,1,1,3,3,3,1,
1,1,1,1,3,3,1,1,
1,1,1,1,1,1,1,1, }, 4);

	SiroGen->AddtoTileMap(Tile{
3,3,3,3,3,3,1,1,
3,3,1,1,1,1,3,1,
3,3,3,3,3,1,1,1,
3,1,1,1,3,3,1,1,
1,1,1,1,1,3,3,1,
3,3,1,1,1,3,3,1,
1,3,3,3,3,3,1,1,
1,1,1,1,1,1,1,1, }, 5);

	SiroGen->AddtoTileMap(Tile{
1,1,3,3,3,3,1,1,
1,3,3,1,1,3,1,1,
3,3,1,1,1,1,1,1,
3,3,3,3,3,1,1,1,
3,3,1,1,3,3,1,1,
3,3,1,1,1,3,1,1,
1,3,3,3,3,3,1,1,
1,1,1,1,1,1,1,1, }, 6);

	SiroGen->AddtoTileMap(Tile{
1,3,3,3,3,3,1,1,
3,3,1,1,1,3,3,1,
3,1,1,1,3,3,3,1,
1,1,1,3,3,1,1,1,
1,1,3,3,1,1,1,1,
1,1,3,3,1,1,1,1,
1,1,3,3,1,1,1,1,
1,1,1,1,1,1,1,1, }, 7);

	SiroGen->AddtoTileMap(Tile{
1,3,3,3,3,1,1,1,
3,3,1,1,3,3,1,1,
3,3,1,1,1,3,3,1,
1,3,3,3,3,3,3,1,
3,3,1,1,3,3,1,1,
3,3,1,1,1,3,3,1,
1,3,3,3,3,3,1,1,
1,1,1,1,1,1,1,1, }, 8);

	SiroGen->AddtoTileMap(Tile{
1,1,3,3,3,3,1,1,
1,3,3,1,3,3,3,1,
3,3,1,1,1,3,3,1,
3,3,3,3,3,3,3,1,
1,3,3,1,1,3,3,1,
1,1,1,1,3,3,1,1,
1,3,3,3,3,1,1,1,
1,1,1,1,1,1,1,1, }, 9);

	Sprite BartenderStand = Sprite{
		16,32,
0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,
0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,
0,0,0,0,1,1,1,2,2,1,2,2,1,0,0,0,
0,0,0,1,2,1,2,12,12,1,12,12,1,1,0,0,
0,0,0,1,2,2,2,12,6,1,12,6,2,1,0,0,
0,0,0,0,1,3,1,2,1,2,2,1,2,3,1,0,
0,0,0,0,1,2,1,1,1,1,1,1,1,1,1,0,
0,0,0,0,0,1,2,1,1,1,1,1,1,2,1,0,
0,0,0,0,1,1,1,2,1,1,1,2,2,1,0,0,
0,0,0,1,5,1,1,1,2,2,2,2,1,0,0,0,
0,0,1,12,1,5,1,4,1,1,1,1,4,1,0,0,
0,1,12,12,12,1,1,4,1,4,4,1,4,1,1,0,
0,1,12,1,12,1,1,4,1,1,1,1,4,1,1,0,
0,1,1,12,12,1,5,1,5,1,5,5,1,1,1,0,
0,1,12,12,1,5,5,5,5,1,5,5,5,1,1,0,
0,1,1,12,1,5,5,5,5,1,1,5,5,1,1,0,
0,1,12,12,1,5,5,5,5,14,1,5,5,1,1,0,
0,1,1,1,1,5,5,5,5,5,1,5,5,1,1,0,
0,1,12,12,1,5,5,5,5,14,1,5,5,1,1,0,
0,1,1,1,1,1,1,1,5,5,1,5,1,1,2,1,
0,1,2,2,2,1,7,7,1,1,1,1,7,1,2,1,
0,1,2,2,1,7,7,7,7,7,7,7,7,1,1,0,
0,0,1,1,7,7,7,7,1,7,1,7,7,1,0,0,
0,0,0,0,1,7,7,7,7,1,7,7,7,1,0,0,
0,0,0,0,1,7,7,7,7,1,7,7,1,0,0,0,
0,0,0,0,1,7,7,7,7,1,7,7,1,0,0,0,
0,0,0,0,1,7,7,7,1,7,7,7,1,0,0,0,
0,0,0,1,7,7,7,7,1,7,7,7,1,0,0,0,
0,0,0,1,7,7,1,1,1,7,1,1,1,0,0,0,
0,0,0,1,1,1,14,14,1,1,14,14,14,1,0,0,
0,0,0,1,14,14,14,14,14,1,1,14,14,14,1,0,
0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,
	};

	Sprite BeerEmpty = Sprite{
		8,8,
 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0,13,13,13,13,13,
 0, 0,13,13,13,13,13,13,
 0,13, 0,13,13,13,13,13,
 0,13, 0,13,13,13,13,13,
 0, 0,13,13,12,13,12,13,
 0, 0, 0,13,12,13,12,13,
 0, 0, 0, 0,13,13,13, 0,
	};

	Sprite BeerOneThird = Sprite{
		8,8,
 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0,13,13,13,13,13,
 0, 0,13,13,13,13,13,13,
 0,13, 0,13,13,13,13,13,
 0,13, 0,13,13,13,13,13,
 0, 0,13,12,12,12,12,12,
 0, 0, 0,14,12,14,12,14,
 0, 0, 0, 0,14,14,14, 0,
	};

	Sprite BeerTwoThird = Sprite{
		8,8,
 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0,13,13,13,13,13,
 0, 0,13,13,13,13,13,13,
 0,13, 0,12,12,12,12,12,
 0,13, 0,14,12,14,12,14,
 0, 0,13,14,15,14,15,14,
 0, 0, 0,14,15,14,15,14,
 0, 0, 0, 0,14,14,14, 0,
	};

	Sprite BeerFull = Sprite{
		8,8,
 0, 0,12, 0,12, 0,12, 0,
 0, 0, 0,12,12,12,12,12,
 0, 0,13,14,12,14,12,14,
 0,13, 0,14,14,14,14,14,
 0,13, 0,14,14,14,14,14,
 0, 0,13,14,15,14,15,14,
 0, 0, 0,14,15,14,15,14,
 0, 0, 0, 0,14,14,14, 0,
	};


	Sprite MCWalk1 = Sprite{
		16,16,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,
0,0,0,1,8,8,8,8,1,0,0,0,0,0,0,0,
0,0,1,8,2,2,2,8,2,1,0,0,0,0,0,0,
0,1,8,2,2,2,8,2,2,2,1,0,0,0,0,0,
0,1,8,2,2,2,2,2,2,2,1,0,0,0,0,0,
1,2,8,2,12,1,2,12,1,2,1,0,0,0,0,0,
1,2,8,2,2,2,2,2,2,2,1,0,0,0,0,0,
0,1,8,8,8,8,2,2,8,8,1,0,0,0,0,0,
0,1,8,8,1,8,8,8,8,8,1,0,0,0,0,0,
0,0,1,8,8,1,1,1,8,1,0,0,0,0,0,0,
0,0,1,1,8,8,8,8,8,1,0,0,0,0,0,0,
0,1,9,9,1,1,1,1,1,9,1,0,0,0,0,0,
1,9,9,9,9,10,9,9,10,9,9,1,0,0,0,0,
1,9,9,1,9,10,9,9,10,1,9,1,0,0,0,0,
1,9,9,1,9,9,9,9,9,9,1,1,0,0,0,0,
	};

	Sprite MCWalk2 = Sprite{
		16,16,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,
0,0,0,1,8,8,8,8,1,0,0,0,0,0,0,0,
0,0,1,8,2,2,2,8,2,1,0,0,0,0,0,0,
0,1,8,2,2,2,8,2,2,2,1,0,0,0,0,0,
0,1,8,2,2,2,2,2,2,2,1,0,0,0,0,0,
1,2,8,2,12,1,2,12,1,2,1,0,0,0,0,0,
1,2,8,2,2,2,2,2,2,2,1,0,0,0,0,0,
0,1,8,8,8,8,2,2,8,8,1,0,0,0,0,0,
0,1,8,8,1,8,8,8,8,8,1,0,0,0,0,0,
0,0,1,8,8,1,1,1,8,1,0,0,0,0,0,0,
0,1,9,1,8,8,8,8,8,1,1,0,0,0,0,0,
1,9,9,9,1,1,1,1,1,9,9,1,0,0,0,0,
1,9,9,1,9,10,9,9,10,1,9,1,0,0,0,0,
1,9,9,1,9,9,9,9,9,9,1,1,0,0,0,0,
	};
	Sprite MCCatch = Sprite{
		16,16,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,					
0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,					
0,0,0,1,8,8,8,8,1,0,0,0,0,0,0,0,					
0,0,1,8,2,2,2,8,2,1,0,0,0,0,0,0,					
0,1,8,2,2,2,8,2,2,2,1,0,0,0,0,0,					
0,1,8,2,2,2,2,2,2,2,1,0,0,0,0,0,					
1,2,8,2,12,1,2,12,1,2,1,0,0,0,0,0,					
1,2,8,2,2,2,2,2,2,2,1,0,0,0,0,0,					
0,1,8,8,8,8,2,2,8,8,1,0,0,0,0,0,					
0,1,8,8,1,8,8,8,8,8,1,0,0,0,0,0,					
0,0,1,8,8,1,1,1,8,1,0,0,0,0,0,0,					
0,0,1,1,8,8,8,8,8,1,1,1,1,1,1,0,					
0,1,9,9,1,1,1,1,1,9,9,9,1,2,2,1,					
1,9,9,9,9,10,9,9,10,1,9,9,1,2,2,1,					
1,9,9,1,9,10,9,9,10,9,1,1,1,1,1,0,					
1,9,9,1,9,9,9,9,9,9,1,0,0,0,0,0,					
	};
	Sprite MCDrinkFull = Sprite{
		20,16,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,1,8,8,8,2,1,0,0,0,0,0,0,0,0,0,0,0,0,
0,1,8,8,2,2,8,2,1,0,0,0,0,0,0,0,0,0,0,0,
1,8,8,2,2,8,2,2,2,1,0,12,12,12,12,12,12,0,0,0,
1,8,8,2,2,2,2,12,1,2,1,14,14,14,14,15,15,14,0,0,
1,8,8,2,12,1,2,2,2,2,1,14,14,14,14,14,14,14,0,0,
1,2,8,2,2,2,2,2,2,8,1,14,14,14,14,15,15,14,0,0,
1,2,8,2,2,2,2,8,8,1,14,14,14,14,14,14,14,0,0,0,
0,1,8,8,2,2,8,1,1,14,1,0,1,1,0,13,0,0,0,0,
0,0,1,8,8,8,8,8,1,1,1,1,2,2,1,0,0,0,0,0,
0,0,1,1,1,8,8,8,8,1,1,9,2,2,1,0,0,0,0,0,
0,1,9,9,9,1,1,1,1,1,9,9,9,1,0,0,0,0,0,0,
1,9,9,9,9,10,9,9,10,1,1,9,1,0,0,0,0,0,0,0,
1,9,9,1,9,10,9,9,10,9,1,1,0,0,0,0,0,0,0,0,
1,9,9,1,9,9,9,9,9,9,1,0,0,0,0,0,0,0,0,0
	};
	Sprite MCDrinkTwoThird = Sprite{
		20,16,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,1,8,8,8,2,1,0,0,0,0,0,0,0,0,0,0,0,0,
0,1,8,8,2,2,8,2,1,0,0,0,0,0,0,0,0,0,0,0,
1,8,8,2,2,8,2,2,2,1,0,13,13,13,13,13,13,0,0,0,
1,8,8,2,2,2,2,12,1,2,1,13,13,13,13,12,12,13,0,0,
1,8,8,2,12,1,2,2,2,2,1,12,12,12,12,12,12,12,0,0,
1,2,8,2,2,2,2,2,2,8,1,14,14,14,14,15,15,14,0,0,
1,2,8,2,2,2,2,8,8,1,14,14,14,14,14,14,14,0,0,0,
0,1,8,8,2,2,8,1,1,14,1,0,1,1,0,13,0,0,0,0,
0,0,1,8,8,8,8,8,1,1,1,1,2,2,1,0,0,0,0,0,
0,0,1,1,1,8,8,8,8,1,1,9,2,2,1,0,0,0,0,0,
0,1,9,9,9,1,1,1,1,1,9,9,9,1,0,0,0,0,0,0,
1,9,9,9,9,10,9,9,10,1,1,9,1,0,0,0,0,0,0,0,
1,9,9,1,9,10,9,9,10,9,1,1,0,0,0,0,0,0,0,0,
1,9,9,1,9,9,9,9,9,9,1,0,0,0,0,0,0,0,0,0,
	};
	Sprite MCDrinkOneThird = Sprite{
		20,16,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,1,8,8,8,2,1,0,0,0,0,0,0,0,0,0,0,0,0,
0,1,8,8,2,2,8,2,1,0,0,0,0,0,0,0,0,0,0,0,
1,8,8,2,2,8,2,2,2,1,0,13,13,13,13,13,13,0,0,0,
1,8,8,2,2,2,2,12,1,2,1,13,13,13,13,12,12,13,0,0,
1,8,8,2,12,1,2,2,2,2,1,13,13,13,13,13,13,13,0,0,
1,2,8,2,2,2,2,2,2,8,1,13,13,13,13,12,12,13,0,0,
1,2,8,2,2,2,2,8,8,1,14,14,14,14,12,12,12,0,0,0,
0,1,8,8,2,2,8,1,1,14,1,0,1,1,0,13,0,0,0,0,
0,0,1,8,8,8,8,8,1,1,1,1,2,2,1,0,0,0,0,0,
0,0,1,1,1,8,8,8,8,1,1,9,2,2,1,0,0,0,0,0,
0,1,9,9,9,1,1,1,1,1,9,9,9,1,0,0,0,0,0,0,
1,9,9,9,9,10,9,9,10,1,1,9,1,0,0,0,0,0,0,0,
1,9,9,1,9,10,9,9,10,9,1,1,0,0,0,0,0,0,0,0,
1,9,9,1,9,9,9,9,9,9,1,0,0,0,0,0,0,0,0,0
	};
	Sprite MCDrinkEmpty = Sprite{
		20,16,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,1,8,8,8,2,1,0,0,0,0,0,0,0,0,0,0,0,0,
0,1,8,8,2,2,8,2,1,0,0,0,0,0,0,0,0,0,0,0,
1,8,8,2,2,8,2,2,2,1,0,13,13,13,13,13,13,0,0,0,
1,8,8,2,2,2,2,12,1,2,1,13,13,13,13,12,12,13,0,0,
1,8,8,2,12,1,2,2,2,2,1,13,13,13,13,13,13,13,0,0,
1,2,8,2,2,2,2,2,2,8,1,13,13,13,13,12,12,13,0,0,
1,2,8,2,2,2,2,8,8,1,1,13,13,13,13,13,13,0,0,0,
0,1,8,8,2,2,8,1,1,3,1,0,1,1,0,13,0,0,0,0,
0,0,1,8,8,8,8,8,1,1,1,1,2,2,1,0,0,0,0,0,
0,0,1,1,1,8,8,8,8,1,1,9,2,2,1,0,0,0,0,0,
0,1,9,9,9,1,1,1,1,1,9,9,9,1,0,0,0,0,0,0,
1,9,9,9,9,10,9,9,10,1,1,9,1,0,0,0,0,0,0,0,
1,9,9,1,9,10,9,9,10,9,1,1,0,0,0,0,0,0,0,0,
1,9,9,1,9,9,9,9,9,9,1,0,0,0,0,0,0,0,0,0,
	};


	Sprite nothing = Sprite{
		1,1,
0,
	};

	SiroGen->AddSpritetoMemory(&BartenderStand, 0);
	SiroGen->AddSpritetoMemory(&BeerEmpty, 1);
	SiroGen->AddSpritetoMemory(&BeerOneThird, 2);
	SiroGen->AddSpritetoMemory(&BeerTwoThird, 3);
	SiroGen->AddSpritetoMemory(&BeerFull, 4);
	SiroGen->AddSpritetoMemory(&nothing, 5);
	SiroGen->AddSpritetoMemory(&MCCatch, 6);
	SiroGen->AddSpritetoMemory(&MCDrinkFull, 7);
	SiroGen->AddSpritetoMemory(&MCDrinkTwoThird, 8);
	SiroGen->AddSpritetoMemory(&MCDrinkOneThird, 9);
	SiroGen->AddSpritetoMemory(&MCDrinkEmpty, 10);
	SiroGen->AddSpritetoMemory(&MCWalk1, 11);
	SiroGen->AddSpritetoMemory(&MCWalk2, 12);


	return;
};

#endif
