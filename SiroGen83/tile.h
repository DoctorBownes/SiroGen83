struct Tile {
	unsigned char pixels[256];
};

struct Nametable {
	unsigned char tiles[16 * 15];
};