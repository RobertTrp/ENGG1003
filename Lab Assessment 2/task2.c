/*
 * task2.c
 *
 *  Created on: 7 May 2019
 *      Author: Vectose
 */


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void pixelMean(float *r, float *g, float *b);

int main() {
	float image[5][5][3];
	int x, y;

	// Don’t change this srand() line!
	srand(0);

	for(y = 0; y < 5; y++) {
		for(x = 0; x < 5; x++) {
			image[x][y][0] = (float)rand()/(float)INT_MAX; //r
			image[x][y][1] = (float)rand()/(float)INT_MAX; //g
			image[x][y][2] = (float)rand()/(float)INT_MAX; //b
			pixelMean(&image[x][y][0], &image[x][y][1], &image[x][y][2]);
			printf("%d %d: %f %f %f\n", x, y, image[x][y][0], image[x][y][1], image[x][y][2]);
		}
	}

	// ----------------------------------------
	// Write your code below this comment block
	// ----------------------------------------


return 0;
}

void pixelMean(float *r, float *g, float *b) {
	*r = (*r + *g + *b)/3.0;
	*g = *r;
	*b = *r;
}
