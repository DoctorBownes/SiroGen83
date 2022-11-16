struct Tile {
	char* canvas;
	char col;
	char rot;
};

struct Screen {
	Tile* screen[16 * 15];
};