struct Tile {
	unsigned char pixels[256];
};

struct Nametable {
	unsigned char tiles[16 * 15];
	unsigned char flips[16 * 15];
};