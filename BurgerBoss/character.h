#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <SiroGen83/entity.h>

struct sc_Vector2 {
	signed char x;
	signed char y;
};

struct Collider {
	signed char x = 0;
	signed char y = 0;
	unsigned char width = 0;
	unsigned char height = 0;
};

class Character : public Entity {

public:
	Character();

	virtual void update() override;

	Collider hitbox;

	unsigned char colstat = 0;
	unsigned char gravity_damper = 0;
	sc_Vector2 velocity = { 0,0 };
	unsigned char gravity = 0;
	bool onground = false;

protected:
	unsigned char TileCol(Entity* entity, unsigned char tiletype);

};

#endif
