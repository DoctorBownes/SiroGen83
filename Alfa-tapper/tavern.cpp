#include "tavern.h"
#include "time.h"

Tavern::Tavern() {
	SiroGen->BackgroundColor = {
		0,55,130
	};
	SiroGen->BackgroundPalette = {
		35,34,30, 239,239,239,	137, 135, 129,
		170, 168, 160,  229, 227, 218, 100,99,97,
		144, 145,147, 216,216,216, 183, 181, 174,
		255,255,255, 222, 0, 0,13,27,96,
		 119, 182, 255, 109,36,0, 73,36,0,
	};
	SiroGen->ForgroundPalette[0] = {
		0,0,0,	255, 146, 73, 255,0,73, 
		255, 30, 39,  0, 73, 146, 36,146,255,
		146, 36,0,	124, 108, 88,	196,23,32,
		 145, 17, 25, 56,56,56,	255,255,255,
		 119, 182, 255, 105,11,12, 132,35,35,
	};
	SiroGen->ForgroundPalette[1] = {
		0,0,0,	255, 146, 73, 255,0,73,
		255, 30, 39,  229, 214, 172, 232,242,255,
		146, 36,0,	124, 108, 88,	22,22,22,
		 128, 128, 128, 56,56,56,	255,255,255,
		 119, 182, 255, 105,11,12, 132,35,35,
	};
	
	TileScreens[0] = new TileScreen{
63,62,61,60,63,62,61,60,63,62,61,60,63,62,61,60,63,62,61,60,63,62,61,60,63,62,61,60,63,62,11,11,
24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,11,11,
24,24,24,24,24,24,24,25,41,50,49,25,48,47,46,25,25,25,25,45,25,25,25,25,24,24,24,24,24,24,11,11,
24,59,58,57,56,24,24,25,44,43,42,41,40,39,38,37,36,35,34,33,31,32,31,25,24,59,58,57,56,24,11,11,
24,55,54,53,52,24,24,25,30,29,28,27,25,25,25,25,25,25,25,25,25,26,25,25,24,55,54,53,52,24,11,11,
24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,73,72,11,11,
23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,69,68,11,11,
14,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,21,14,14,14,67,66,11,11,
14,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,21,14,14,14,22,74,11,11,
14,65,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,19,14,14,14,74,22,11,11,
14,64,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,17,14,14,14,22,22,11,11,
14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,71,70,11,11,
14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,69,68,11,11,
14,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,21,14,14,14,67,66,11,11,
14,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,21,14,14,14,22,74,11,11,
14,65,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,19,14,14,14,74,22,11,11,
14,64,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,17,14,14,14,22,22,11,11,
14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,71,70,11,11,
14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,69,68,11,11,
14,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,21,14,14,14,67,66,11,11,
14,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,21,14,14,14,22,74,11,11,
14,65,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,19,14,14,14,74,22,11,11,
14,64,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,17,14,14,14,22,22,11,11,
14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,71,70,11,11,
14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,69,68,11,11,
14,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,21,14,14,14,67,66,11,11,
14,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,21,14,14,14,22,74,11,11,
14,65,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,19,14,14,14,16,15,11,11,
14,64,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,17,14,14,14,13,12,11,11,
14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,11,11,
	};

	TileScreens[1] = new TileScreen{
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,76,77,78,75,79,77,80,81,82,75,78,83,75,84,77,79,85,77,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	};

	TileScreens[16] = new TileScreen{
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,75,75,75,75,75,
75,75,75,75,25,94,95,96,97,98,99,100,101,102,25,103,104,105,106,107,108,109,25,25,25,25,25,75,75,75,75,75,
75,75,75,75,25,110,111,112,152,113,114,115,116,117,103,105,118,119,120,121,122,121,122,123,124,125,25,75,75,75,75,75,
75,75,75,75,25,126,127,128,129,153,154,132,133,134,25,25,135,136,137,138,139,138,139,140,141,142,25,75,75,75,75,75,
75,75,75,75,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,143,25,143,25,25,25,25,25,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,151,89,90,86,86,75,86,151,80,87,90,75,78,83,75,86,78,80,89,78,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,144,80,81,90,75,145,82,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,86,147,144,88,148,75,89,88,90,149,88,150,150,86,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
	};

	TileScreens[3] = new TileScreen{
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
10,86,87,88,89,90,10,10,10,10,10,10,10,10,10,91,92,93,86,87,88,89,90,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
	};

	SiroGen->SetGUIScreen(TileScreens[3]);
	SiroGen->SetTileDigits(score, 44,10);

	player = new Entity();
	player->position.y = 88 + barpos * 48;
	player->position.x = 189;
	SiroGen->SetSpritetoEntity(player, 0);
	playerwalking = new Animation{20, 0,78,79,79,80,81,82, 85,86,87,88};

	glass = new Entity();
	glass->position.x = player->position.x + 16;
	glass->position.y = player->position.y - 24;
	glassshattering = new Animation{8, 16,17,16,17,16,17,16,17,16,17,16,17, };

	mc = new Barfly();
	mc->position.x = 16;
	mc->position.y = 60;
	mc->id = 0;
	drinkanim[mc->id] = new Animation{ 20, 6,7,8,9,10,11,11,11 };
	walkanim[mc->id] = new Animation{ 10, 12,13,12,13,14,15 };
	People[mc->id] = mc;

	jk = new Barfly();
	jk->position.x = 16;
	jk->position.y = 60;
	jk->id = 1;
	drinkanim[jk->id] = new Animation{ 20, {22,23,24,25,26,27,27,27},{1,1,1,1,1,1,1,1} };
	walkanim[jk->id] = new Animation{ 10, {18,19,18,19,20,21},{1,1,1,1,1,1} };
	People[jk->id] = jk;

	st = new Barfly();
	st->position.x = 16;
	st->position.y = 60;
	st->id = 2;
	drinkanim[st->id] = new Animation{ 20, {32,33,34,35,36,37,37,37},{1,1,1,1,1,1,1,1} };
	walkanim[st->id] = new Animation{ 10, {28,29,28,29,30,31},{1,1,1,1,1,1} };
	People[st->id] = st;

	dp = new Barfly();
	dp->position.x = 16;
	dp->position.y = 60;
	dp->id = 3;
	drinkanim[dp->id] = new Animation{ 20, {42,43,44,45,46,47,47,47},{1,1,1,1,1,1,1,1} };
	walkanim[dp->id] = new Animation{ 10, {38,39,38,39,40,41},{1,1,1,1,1,1} };
	People[dp->id] = dp;

	gw = new Barfly();
	gw->position.x = 16;
	gw->position.y = 60;
	gw->id = 4;
	drinkanim[gw->id] = new Animation{ 20, {52,53,54,55,56,57,57,57},{1,1,1,1,1,1,1,1} };
	walkanim[gw->id] = new Animation{ 10, {48,49,48,49,50,51},{1,1,1,1,1,1} };
	People[gw->id] = gw;

	ep = new Barfly();
	ep->position.x = 16;
	ep->position.y = 60;
	ep->id = 5;
	drinkanim[ep->id] = new Animation{ 20, {62,63,64,65,66,67,67,67},{1,1,1,1,1,1,1,1} };
	walkanim[ep->id] = new Animation{ 10, {58,59,58,59,60,61},{1,1,1,1,1,1} };
	People[ep->id] = ep;

	rt = new Barfly();
	rt->position.x = 16;
	rt->position.y = 60;
	rt->id = 6;
	drinkanim[rt->id] = new Animation{ 20, {72,73,74,75,76,77,77,77},{1,1,1,1,1,1,1,1} };
	walkanim[rt->id] = new Animation{ 10, {68,69,68,69,70,71},{1,1,1,1,1,1} };
	People[rt->id] = rt;

	for (int i = 0; i < 4; i++) {
		Taps[i] = new Entity();
		Taps[i]->position.x = 213;
		Taps[i]->position.y = 66 + i * 48;
		SiroGen->SetSpritetoEntity(Taps[i], 92);
	}


	entities.push_front(player);
	entities.push_front(glass);
	entities.push_front(Taps[0]);
	entities.push_front(Taps[1]);
	entities.push_front(Taps[2]);
	entities.push_front(Taps[3]);
	BeerFilling = new Animation{ 2, 1,2,3,4 };
	barspeeds[0] = 150;
	barspeeds[1] = 100;
	barspeeds[2] = 70;
	barspeeds[3] = 50;
	spawntimer = 160;
	multiplier = 800;
	status = 3;
}

Entity* Tavern::SpawnPeople()
{
	std::srand(randomnumber * time(0));
	unsigned char randbar = std::rand() & 3;
	unsigned char randpeep = std::rand() % 7;
	Barfly* ghost = new Barfly();
	ghost->id = People[randpeep]->id;
	ghost->position.x = 8;
	ghost->position.y = 55 + randbar * 48;


	WaitLine[randbar].push_back(ghost);
	entities.push_front(ghost);
	peopleamount++;
	return ghost;
}

Entity* Tavern::SpawnBeer(unsigned char bar, Entity* near, bool full) {
	Beer* beer = new Beer();
	beer->position.x = near->position.x + 16;
	beer->position.y = 59 + bar * 48;
	beer->barpos = bar;
	if (full) {
		SiroGen->SetSpritetoEntity(beer, 4);
		beer->position.x = near->position.x - 4;
		beer->full = true;
	}
	else {
		SiroGen->SetSpritetoEntity(beer, 1);
		beer->full = false;
	}
	Bar[bar].push_back(beer);
	entities.push_front(beer);
	return beer;
}

void Tavern::update() {
	switch (status) {
	case 0://GameRunning
		if (!moving) {
			//PlayerMovement
			if (GetInput()->KeyDown(KeyCode::Space)) {
				idle = false;
				SiroGen->SetAttributetoEntity(player, 0);
				dir = 0;
				player->position.x = 189;
				glass->position.x = player->position.x + 27;
				glass->position.y = player->position.y - 15;
				if (!done) {
					SiroGen->SetSpritetoEntity(player, 90);
					SiroGen->SetSpritetoEntity(Taps[barpos], 93);
					if (SiroGen->PlayAnimation(glass, BeerFilling, 3) || glass->frame == 3) {
						done = true;
					}
				}
			}
			if (GetInput()->KeyReleased(KeyCode::Space)) {
				SiroGen->SetSpritetoEntity(player, 89);
				SiroGen->SetSpritetoEntity(Taps[barpos], 92);
				if (done) {
					SiroGen->SetSpritetoEntity(player, 91);
					glass->frame = 0;
					glass->starttime = 0;
					SiroGen->SetSpritetoEntity(glass, 5);
					SpawnBeer((player->position.y - 80) / 48, player);
					done = false;
				}
			}
			if (GetInput()->KeyPressed(KeyCode::Up)) {
				idle = true;
				glass->frame = 0;
				glass->starttime = 0;
				SiroGen->SetSpritetoEntity(Taps[barpos], 92);
				SiroGen->SetSpritetoEntity(glass, 5);
				done = false;
				moving = 1;
				dir = 0;
				player->starttime = 0;
			}
			else if (GetInput()->KeyPressed(KeyCode::Down)) {
				idle = true;
				glass->frame = 0;
				glass->starttime = 0;
				SiroGen->SetSpritetoEntity(Taps[barpos], 92);
				SiroGen->SetSpritetoEntity(glass, 5);
				done = false;
				moving = 2;
				dir = 0;
				player->starttime = 0;
			}
			else if (GetInput()->KeyDown(KeyCode::Left)) {
				idle = true;
				if (player->position.x > 16) {
					player->position.x--;
				}
				dir = 4;
				playerwalking->framerate = 8;
				SiroGen->SetSpritetoEntity(Taps[barpos], 92);
				SiroGen->SetSpritetoEntity(glass, 5);
				SiroGen->PlayAnimation(player, playerwalking, 10, 7);
				SiroGen->SetAttributetoEntity(player, 4);
			}
			else if (GetInput()->KeyDown(KeyCode::Right)) {
				idle = true;
				if (player->position.x < 190) {
					player->position.x++;
				}
				dir = 0;
				playerwalking->framerate = 8;
				SiroGen->SetSpritetoEntity(Taps[barpos], 92);
				SiroGen->SetSpritetoEntity(glass, 5);
				SiroGen->PlayAnimation(player, playerwalking, 10, 7);
				SiroGen->SetAttributetoEntity(player, 0);
			}
			else if (idle) {
				playerwalking->framerate = 20;
				SiroGen->PlayAnimation(player, playerwalking, 1);
				SiroGen->SetAttributetoEntity(player, dir);
			}
		}


		if (moving) {
			playerwalking->framerate = 3;
			if (SiroGen->PlayAnimation(player, playerwalking, 6, 2)) {
				if (moving > 1) {
					barpos++;
				}
				else {
					barpos--;
				}
				barpos &= 3;
				player->position.y = 88 + barpos * 48;
				player->position.x = 189;
				moving = false;
				playerwalking->framerate = 20;
			}
		}


		//WaitingLine
		for (unsigned char j = 0; j < 4; j++) {
			std::vector<Barfly*>::iterator bit = WaitLine[j].begin();
			while (bit != WaitLine[j].end()) {
				bool caught = false;
				if (!(*bit)->yellmeter) {
					if (SiroGen->PlayAnimation((*bit), walkanim[(*bit)->id], 3, 0)) {
						(*bit)->yellmeter = true;
					}
				}
				if ((*bit)->yellmeter > 0) {
					SiroGen->PlayAnimation((*bit), walkanim[(*bit)->id], 5, 4);
					(*bit)->yellmeter++;
					if ((*bit)->yellmeter >= barspeeds[j]) {
						(*bit)->yellmeter = false;
					}
				}
				if ((*bit)->frame < 4) {
					(*bit)->position.x++;
					if ((*bit)->position.x > 180) {
						gameoverman = (*bit);
						randomnumber = 0;
						status = 2;
					}
				}
				std::vector<Beer*>::iterator it = Bar[j].begin();
				while (it != Bar[j].end()) {
					signed char difx = (*bit)->position.x - (*it)->position.x;
					if (difx < 14 && difx > -10 && (*it)->full) {
						//caught
						entities.remove(*it);
						delete* it;
						it = Bar[j].erase(it);
						it = Bar[j].end();

						caught = true;
					}
					else {
						it++;
					}
				}
				if (caught) {
					(*bit)->yellmeter = 40;
					SiroGen->PlayAnimation(*bit, drinkanim[(*bit)->id], 0, 0);
					DrinkLine[j].push_back(*bit);
					bit = WaitLine[j].erase(bit);
					score += 100;
				}
				else {
					bit++;
				}
			}
		}

		//DrinkingLine
		for (unsigned char j = 0; j < 4; j++) {
			std::vector<Barfly*>::iterator it = DrinkLine[j].begin();
			while (it != DrinkLine[j].end()) {

				if ((*it)->yellmeter < 1) {
					if ((*it)->frame == 5) {
						SpawnBeer(((*it)->position.y - 55) / 48, *it, false);
						(*it)->frame++;
					}
					if (SiroGen->PlayAnimation(*it, drinkanim[(*it)->id], 6)) {

						WaitLine[j].push_back(*it);
						it = DrinkLine[j].erase(it);
					}
					else {
						it++;
					}
				}
				else if ((*it)->position.x < 9) {
					entities.remove(*it);
					delete (*it);
					it = DrinkLine[j].erase(it);
					peopleamount--;
					score += 50;
				}
				else {
					(*it)->yellmeter--;
					(*it)->position.x -= 2;
					it++;
				}

			}
		}


		//BeerMovement
		for (unsigned char x = 0; x < 4; x++) {
			std::vector<Beer*>::iterator it = Bar[x].begin();
			while (it != Bar[x].end()) {


				if ((*it)->full) {
					(*it)->position.x -= 4;
					if ((*it)->position.x < 4) {
						shatterglass = (*it);
						status = 1;
					}
					it++;
				}
				else {
					(*it)->position.x += 1;
					signed char difx = player->position.x - (*it)->position.x;
					if (difx < 10 && difx > -10 && barpos == (*it)->barpos) {
						entities.remove(*it);
						delete* it;
						it = Bar[x].erase(it);
						score += 50;
					}
					else if ((*it)->position.x > 193) {
						shatterglass = (*it);
						status = 1;
						it++;
					}
					else {
						it++;
					}
				}
			}
		}
		randomnumber++;
		spawncounter++;
		if ((score) >= multiplier) {
			multiplier *= 2;
			spawntimer *= 0.77f;
		}
		if ((spawncounter / spawntimer) && peopleamount < 7) {
			spawncounter = 0;
			SpawnPeople();
		}
		if (score >= hiscore) {
			hiscore = score;
			SiroGen->SetTileDigits(hiscore, 61,10);
		}
		SiroGen->SetTileDigits(score, 44,10);
		break;
	case 1://GlassOver
		SiroGen->SetSpritetoEntity(player, 83);
		if (shatterglass->position.y < 88 + shatterglass->barpos * 48) {
			shatterglass->position.y++;
		}
		else {
			if (SiroGen->PlayAnimation(shatterglass, glassshattering, 11)) {
				status = 3;
				randomnumber = 0;
			}
		}
		
		break;
	case 2://PeopleOver
		SiroGen->SetSpritetoEntity(player, 83);
		if (randomnumber / 100) {
			SiroGen->PlayAnimation(gameoverman, walkanim[gameoverman->id], 3, 0);
			if (gameoverman->id) {
				SiroGen->SetAttributetoEntity(gameoverman, 5);
			}
			else {
				SiroGen->SetAttributetoEntity(gameoverman, 4);
			}
			SiroGen->SetSpritetoEntity(player, 84);
			SiroGen->SetAttributetoEntity(player, 4);
			if (gameoverman->position.x > 32) {
				player->position.x = gameoverman->position.x - 16;
				player->position.y = gameoverman->position.y + 8;
				gameoverman->position.x -= 2;
			}
			else {
				player->position.x -= 2;
			}
			if ((player->position.x & 511) > 256 && (player->position.x & 511) <= 300) {
				status = 3;
				randomnumber = 0;
			}
		}
		else {
			randomnumber++;
		}
		break;
	case 3://GameReset
		for (unsigned char j = 0; j < 4; j++) {
			std::vector<Barfly*>::iterator bit = DrinkLine[j].begin();
			while (bit != DrinkLine[j].end()) {
				entities.remove(*bit);
				delete* bit;
				bit = DrinkLine[j].erase(bit);
			}
			std::vector<Barfly*>::iterator it = WaitLine[j].begin();
			while (it != WaitLine[j].end()) {
				entities.remove(*it);
				delete* it;
				it = WaitLine[j].erase(it);
			}
			std::vector<Beer*>::iterator sit = Bar[j].begin();
			while (sit != Bar[j].end()) {
				entities.remove(*sit);
				delete* sit;
				sit = Bar[j].erase(sit);
			}
		}
		for (int i = 0; i < 4; i++) {
			SiroGen->SetSpritetoEntity(Taps[i], 92);
		}
		SiroGen->SetSpritetoEntity(glass, 5);
		score = 0;
		TileScreens[3]->tiles[38] = 10;
		TileScreens[3]->tiles[39] = 10;
		TileScreens[3]->tiles[40] = 10;
		TileScreens[3]->tiles[41] = 10;
		TileScreens[3]->tiles[42] = 10;
		TileScreens[3]->tiles[43] = 10;
		TileScreens[3]->tiles[44] = 10;
		SiroGen->UpdateGUITile(3);
		SiroGen->UpdateGUITile(4);
		SiroGen->UpdateGUITile(5);
		SiroGen->UpdateGUITile(6);
		player->position.x = 320;
		status = 5;
		randomnumber = 0;
		break;
	case 4://GetReady
		SiroGen->LoadTileScreen(1);
		player->position.x = 368;
		player->position.y = 128;
		SiroGen->SetSpritetoEntity(player, 79);
		SiroGen->SetAttributetoEntity(player, 0);
		if (randomnumber / 160) {
			barpos = 0;
			peopleamount = 0;
			player->position.y = 88;
			player->position.x = 189;
			idle = true;
			done = false;
			SiroGen->LoadTileScreen(0);
			spawntimer = 160;
			multiplier = 800;
			status = 0;
		}
		else {
			randomnumber++;
		}
		break;
	case 5://Title

		playerwalking->framerate = 8;
		SiroGen->LoadTileScreen(16);
		player->position.y = 376;
		SiroGen->PlayAnimation(player, playerwalking, 10, 7);
		SiroGen->SetSpritetoEntity(glass, 1);
		player->position.x++;
		glass->position.x = player->position.x + 64;
		glass->position.y = player->position.y - 16;
		player->position.x &= 511;
		//player->position.x &= 255;
		if (GetInput()->KeyPressed(KeyCode::Space)) {
			status = 4;
		}
		break;
	}
}
