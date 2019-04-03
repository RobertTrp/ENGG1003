/*
 * assessment1.c
 *
 *  Created on: 19 Mar 2019
 *      Author: Robert Trpeski
 */
#include <stdio.h>

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	float x0 = 0.65;
	float xn = 0.0;
	float xnm1 = x0;

	printf("0 %f\n", x0);

	for(int n = 1; n<10; n++) {
		xn = 0.2*xnm1 + 5.0;
		if (xn-xnm1 < 0.001){
			xnm1 = xn;
			printf("%d %f\n", n, xn);
			return 0;
		}
		xnm1 = xn;
		printf("%d %f\n", n, xn);
	}
}
