/*
 * task5.c
 *
 *  Created on: 6 May 2019
 *      Author: Vectose
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *input;
	input = fopen("task5input", "r");
	int a1 = 3, a2 = 3;
	int array[a1][a2];
	char tmp[10];
	int tmpnum;
	int maximum = 0;

	for (int i = 0; !feof(input); i++) {
		for (int j = 0; j < a1; j++) {
			for (int k = 0; k < a2; k++)
			{
				fscanf(input, "%s", tmp);
				tmpnum = atoi(tmp);
				array[j][k] = tmpnum;
			}
		}
	}

	maximum = array[0][0];
	for (int i = 0; i < a1; i++) {
		for (int j = 0; j < a2; j++) {
			printf("%d ", array[i][j]);
			if (array[i][j] > maximum)
				maximum = array[i][j];
		}
	}
	printf("\nMaximum: %d\n", maximum);
}


