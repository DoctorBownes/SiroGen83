#ifndef ENTITYSPAWNER_H_
#define ENTITYSPAWNER_H_

class Entity;

class EntitySpawner {

public:
	EntitySpawner(Entity* entity);

	Entity* GetEntity() { return heldentity; };
	Entity* heldentity = nullptr;
	unsigned char page = 0;
	unsigned char posx = 0;

private:

};

#endif
