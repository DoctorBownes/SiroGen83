struct Tile {
	char pixel[256];
	char col;
};

struct Screen {
	Tile* screen[16 * 15];
};

struct LevelMap {
	Screen* levelmap[];
};