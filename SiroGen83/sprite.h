#ifndef SPRITE_H_
#define SPRITE_H_

struct Sprite {
	unsigned char width;
	unsigned char height;
	unsigned char pixels[24 * 24];
};

struct Animation {
	unsigned char framerate;
	unsigned char sprites[16];
};

#endif
