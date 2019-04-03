/*
 * assessment1(2).c
 *
 *  Created on: 19 Mar 2019
 *      Author: Vectose
 */

#include <stdio.h>

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	float x0 = -0.6;
	float x1 = -0.4;
	float xn = 0.0;
	float xnm1 = x1;
	float xnm2 = x0;
	float dxn = 0.0;
	float dx1 = x1-x0;
	int sign = 0;

	if (dx1 >= 0)
		sign = 1;
	else if (dx1 < 0)
		sign = 2;

	printf("0 %f\n1 %f\n", x0, x1);
	//printf("dx1 = %f\n", dx1);
	for(int n = 2; n<=10; n++) {
		xn = 0.8*xnm1 + 0.1*xnm2;
		dxn = xn - xnm1;
		//printf("dxn = %f\n", dxn);
		if (dxn >= 0 && sign == 2)
			sign = 3;
		else if (dxn < 0 && sign == 1)
			sign = 3;
		xnm2 = xnm1;
		xnm1 = xn;
		if (xn > 10e10)
			return 0;
		printf("%d %f\n", n, xn);
	}
	if (sign == 1)
		printf("dx/dn is always positive or zero\n");
	else if (sign == 2)
		printf("dx/dn is always negative\n");
	else if (sign == 3)
		printf("The sign of dx/dn varies\n");
}

