#include <SiroGen83/core.h>
#include <SiroGen83/scene.h>
#include <stdio.h>

int main(void) {
	Core core;
	Scene* scene1 = new Scene();
	core.Run(scene1);
	//printf("Hello World\n");
}