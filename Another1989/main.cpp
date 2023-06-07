#include <SiroGen83/core.h>
#include <Another1989/playground.h>
#include <Another1989/spritefactory.h>

int main(void) {
	Core core;
	process();
	PlayGround* playground = new PlayGround();
	core.Run(playground);
}