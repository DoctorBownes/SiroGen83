#include <stdio.h>
#include <list>
#include <array>
#include <vector>
#include <queue>
#include <forward_list>

struct Nothing {
	int something = 1;
};

template <typename T>
class SmallVector {
public:
	SmallVector();

	T* at;

	int arraySize = 0;


	void push_back(T newval);
};

template<typename T>
SmallVector<T>::SmallVector() {
	at = nullptr;
}

template <typename T>
void SmallVector<T>::push_back(T newval) {
	// Allocate memory for the array in the temporary array.
	T* tmpArray = new T[arraySize + 1];

	// Copy the elements of old array.
	for (int count = 0; count < arraySize; count++) {
		*(tmpArray + count) = *(at + count);
	}

	// Push new value
	*(tmpArray + arraySize) = newval;

	// Delete old array
	delete[] at;

	// Copy array
	at = tmpArray;

	// Increase size
	arraySize++;
};

void canvastest() {

	/*static char mario[16] = {
		1,1,1,1,
		1,1,1,1,
		1,1,1,1,
		1,1,1,1,
	};
	Tile Grass1 = {
		mario,1,0
	};
	Tile Grass3 = {
		mario,3,1
	};
	printf("%d\n", Grass1.rot);
	printf("%d\n", Grass3.rot);
	TileMap map1 = {
		&Grass1,&Grass1,&Grass1,&Grass1,
		&Grass1,&Grass3,&Grass1,&Grass1,
		&Grass1,&Grass3,&Grass1,&Grass1,
		&Grass1,&Grass1,&Grass1,&Grass1,
	};
	printf("%d\n", sizeof(map1));*/


	int canvas1[240] = {
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,
	};
	int canvas2[240] = {
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
		5,4,3,0,0,0,0,0,0,0,0,0,0,0,2,1,
		5,4,3,0,0,0,0,0,0,0,0,0,0,0,2,1,
		5,4,3,0,0,0,0,0,0,0,0,0,0,0,2,1,
		5,4,3,0,0,0,0,0,0,0,0,0,0,0,2,1,
		5,4,3,0,0,0,0,0,0,0,0,0,0,0,2,1,
		5,4,3,0,0,0,0,7,8,1,0,0,0,0,2,1,
		5,4,3,0,0,0,0,6,9,2,0,0,0,0,2,1,
		5,4,3,0,0,0,0,5,4,3,0,0,0,0,2,1,
		5,4,3,0,0,0,0,0,0,0,0,0,0,0,2,1,
		5,4,3,0,0,0,0,0,0,0,0,0,0,0,2,1,
		5,4,3,0,0,0,0,0,0,0,0,0,0,0,2,1,
		5,4,3,0,0,0,0,0,0,0,0,0,0,0,2,1,
		5,4,3,0,0,0,0,0,0,0,0,0,0,0,2,1,
		8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	};
	int cameravas[960] = {
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	};
	//int varx = 0;
	//int vary = 0;
	//int x = 0;
	//for (int y = 1; y <= 15; y++) {
	//	for (x = x; x < 16 * y; x++) {
	//		cameravas[varx + vary] = canvas1[varx];
	//		varx++;
	//	}
	//	vary += 16;
	//}
	int overwrite_pos = 0; //change overwrite_pos // + (y * width)
	for (int y = 0; y < 16; y++) {
		overwrite_pos = 0 + y; //change overwrite_pos // + (y * width)
		for (int x = 0 + y; x < 240; x += 16) {
			cameravas[overwrite_pos] = canvas1[x];
			overwrite_pos += 32;
		}
	}
	//int varz = 0;
	//int varw = 1;
	//for (int i = 0; i < 240; i++) {
	//	if (i == 15 * varw) {
	//		varz += 16;
	//		varw++;
	//	}
	//	cameravas[i + varz] = canvas1[i];
	//}

	//COORDINATE = X + (Y * Width);

	// varx = 0;
	// vary = 0;
	// x = 16;
	//for (int y = 1; y <= 15; y++) {
	//int varz = 16;
	//for (int x = 0; x < 240; x+=16) {
	//	cameravas[varz] = canvas2[x];
	//	varz += 32;
	//}
	//varz = 17;
	//for (int x = 1; x < 240; x += 16) {
	//	cameravas[varz] = canvas2[x];
	//	varz += 32;
	//}
	//varz = 30;
	//for (int x = 14; x < 240; x += 16) {
	//	cameravas[varz] = canvas2[x];
	//	varz += 32;
	//}

	//HORIZONTAL SCROLLING
	//change overwrite_pos & x
	overwrite_pos = 0; // + (y * width)
	for (int x = 0; x < 240; x += 16) {
		cameravas[overwrite_pos] = canvas2[x];
		overwrite_pos += 32;
	}

	//VERTICAL SCROLLING
	//change overwrite_pos & x
	//overwrite_pos = 0; // + (y * width)
	//for (int x = 0; x < 16; x ++) {
	//	cameravas[overwrite_pos] = canvas2[x];
	//	overwrite_pos++;
	//}

	//overwrite_pos = 1; //change overwrite_pos
	//for (int y = 1; y < 16; y++) {
	//	overwrite_pos = 1 + y; //change overwrite_pos
	//	for (int x = 0; x < 240; x += 16) {
	//		cameravas[overwrite_pos] = canvas2[x];
	//		overwrite_pos += 32;
	//	}
	//}
		//for (int x = 0; x < 16; x++) {
		//	cameravas[16] = canvas2[0];
		//	cameravas[48] = canvas2[16];
		//	cameravas[80] = canvas2[32];
		//	cameravas[17] = canvas2[1];
		//}
	//}
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	int cound = 0;
	for (int i = 0; i < 960; i++) {
		if (cound == 32) {
			printf("\n");
			cound = 0;
		}
		cound++;
		printf("%d,", cameravas[i]);
	}
}

int main(void) {

	canvastest();

	return 0;
}