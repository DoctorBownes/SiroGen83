#ifndef CHECKPOINT_H_
#define CHECKPOINT_H_

class Entity;

struct CheckPoint {
	unsigned short posx = 0;
	unsigned char flag = 0;

};

struct Entitiy_CheckPoint : public CheckPoint {
	Entity* heldentity = nullptr;
};

#endif
