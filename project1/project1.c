/*
 * project1.c
 *
 *  Created on: 3 Apr 2019
 *      Author: Robert Trpeski
 */

#include <stdio.h>

void *rotEncrypt(char message[], int key);
void *rotDecrypt(char message[], int key);

int main() {
	char message[] = "USZ BOE EFDPEF NF CCZ";
	int key = 1;
	rotEncrypt(message, key);
	rotDecrypt(message, key);
}

void *rotEncrypt(char message[], int key) {
	char encrypted[1024];
	for(int i = 0; message[i] != '\0'; ++i) {
		char letter = message[i];
		if (letter >= 'a' && letter <= 'z')
			letter = letter -32;
		if (letter >= 'A' && letter <= 'Z')
			letter = letter + key;
		encrypted[i] = letter;
		}
	printf("%s", encrypted);
}

void *rotDecrypt(char message[], int key) {
	key = key*-1;
	char decrypted[1024];
		for(int i = 0; message[i] != '\0'; ++i) {
			char letter = message[i];
			if (letter >= 'a' && letter <= 'z')
				letter = letter -32;
			if (letter >= 'A' && letter <= 'Z')
				letter = letter + key;
			decrypted[i] = letter;
			}
		printf("%s", decrypted);
}

