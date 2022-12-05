struct Tile {
	char* canvas;
	char rot;
};

struct Nametable {
	Tile* tiles[16 * 15];
};