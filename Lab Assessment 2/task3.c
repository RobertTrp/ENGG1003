/*
 * task3.c
 *
 *  Created on: 7 May 2019
 *      Author: Vectose
 */


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void pixelMean(float *r, float *g, float *b);

int main() {
	FILE *input;
	input = fopen("imagedata", "r");
	float image[5][5][3];

	for (int i = 0; !feof(input); i++) {
		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 5; x++) {
				fscanf(input, "%f %f %f", &image[x][y][0], &image[x][y][1], &image[x][y][2]);
				pixelMean(&image[x][y][0], &image[x][y][1], &image[x][y][2]);
				printf("%d %d: %f %f %f\n", x, y, image[x][y][0], image[x][y][1], image[x][y][2]);
			}
		}
	}

	fclose(input);
	return 0;
}

void pixelMean(float *r, float *g, float *b) {
	*r = (*r + *g + *b)/3.0;
	*g = *r;
	*b = *r;
}
