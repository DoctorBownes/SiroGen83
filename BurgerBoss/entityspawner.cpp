#include "entityspawner.h"
#include <SiroGen83/entity.h>

EntitySpawner::EntitySpawner(Entity* entity) {
	heldentity = entity;
	page = (entity->position.x >> 8) + (entity->position.y >> 8) * 16;
	posx = entity->position.x;
}
