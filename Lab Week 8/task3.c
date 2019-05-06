/*
 * Lab: Week 8
 * task3.c
 *
 *  Created on: 6 May 2019
 *      Author: Vectose
 */

#include<stdio.h>

void mean(int *a, int *b, int *c);

int main() {
	int a = 5, b = 22, c = 9;
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("c = %d\n\n", c);
	mean(&a, &b, &c);
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("c = %d\n", c);


}

void mean(int *a, int *b, int *c) {
	float mean;
	mean = (*a + *b + *c)/3;
	*a = mean;
	*b = 0;
	*c = 0;
}
