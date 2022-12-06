struct Tile {
	char* pixels;
	char rot;
};

struct Nametable {
	Tile* tiles[16 * 15];
};