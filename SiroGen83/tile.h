struct Tile {
	unsigned char pixels[256];
};

struct Color {
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

struct Nametable {
	unsigned char tiles[16 * 15];
	unsigned char attributes[16 * 15];
};