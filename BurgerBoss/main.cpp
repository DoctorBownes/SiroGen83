#include <SiroGen83/core.h>
#include <BurgerBoss/world1.h>
#include <BurgerBoss/spritefactory.h>

int main(void) {
	Core core;
	process();
	World1* world = new World1();
	core.Run(world);
	//printf("Hello World\n");
}