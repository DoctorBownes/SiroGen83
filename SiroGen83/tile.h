struct Tile {
	char pixels[256];
};

struct Nametable {
	Tile* tiles[16 * 15];
};