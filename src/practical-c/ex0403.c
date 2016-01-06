#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	if (argc != 3) {
		printf("Usage: %s width height", argv[0]);
		return 1;
	} else {
		double width = atof(argv[1]);
		double height = atof(argv[2]);
		printf("The perimeter of a %.3fx%.3f rectangle is %.3f and it's area is %.3f\n", 
			width, height, (width * 2) + (height * 2), width * height);
		return 0;
	}
}
