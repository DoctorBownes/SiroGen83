#ifndef TILE_H_
#define TILE_H_

struct Tile {
	unsigned char pixels[64];
};

struct Color {
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

struct TileScreen {
	unsigned char tiles[32 * 30];
	unsigned char attributes[16 * 15];
};

#endif
