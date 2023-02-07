#pragma once
struct Sprite {
	unsigned char width;
	unsigned char height;
	unsigned char pixels[24 * 24];
};

struct Animation {
	float framerate;
	unsigned int sprites[16];
};