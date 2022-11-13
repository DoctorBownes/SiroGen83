#include <SiroGen83/core.h>
#include <Test/world1.h>
#include <stdio.h>

int main(void) {
	Core core;
	World1* scene1 = new World1();
	core.Run(scene1);
	//printf("Hello World\n");
}