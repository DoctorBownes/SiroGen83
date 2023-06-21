#include <SiroGen83/core.h>
#include <Alfa-tapper/tavern.h>
#include <Alfa-tapper/spritefactory.h>

int main(void) {
	Core core;
	process();
	Tavern* tavern = new Tavern();
	core.Run(tavern);
}