#ifndef SPRITE_H_
#define SPRITE_H_

struct Sprite {
	unsigned char width;
	unsigned char height;
	unsigned char pixels[32 * 32];
};

struct Animation {
	unsigned char framerate;
	unsigned char sprites[12];
	unsigned char attribs[12];
};

#endif
