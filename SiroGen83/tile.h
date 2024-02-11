#ifndef TILE_H_
#define TILE_H_

struct Tile {
	unsigned char pixels[256];
};

struct Color {
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

struct TileScreen {
	unsigned char tiles[16 * 15];
	unsigned char attributes[16 * 15];
};

#endif
