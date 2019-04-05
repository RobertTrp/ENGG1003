/*
 * project1.c
 *
 *  Created on: 3 Apr 2019
 *      Author: Robert Trpeski
 */

#include <stdio.h>
#include <string.h>

void rotEncrypt(char message[], int rotKey);
void rotDecrypt(char message[], int rotKey);
void subEncrypt(char message[], char subKey[], char alphabet[]);
void subDecrypt(char message[], char subKey[], char alphabet[]);

int main() {
	char message[] = "hello world";
	int length = strlen(message);
	int rotKey = 0;
	char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char subKey[]   = "QWERTYUIOPASDFGHJKLZXCVBNM";
	printf("Original message: %s\n", message);

	// convert input to upper case
	for(int i = 0; message[i] != '\0'; i++) {
		if (message[i] >= 'a' && message[i] <= 'z')
			message[i] += -32;
	}


	//rotEncrypt(message, rotKey);
	//rotDecrypt(message, rotKey);
	//subEncrypt(message, subKey, alphabet);
	subDecrypt(message, subKey, alphabet);
}

/***********************************************************************************************/
//Rotation cipher encryption

void rotEncrypt(char message[], int rotKey) {
	for(int i = 0; message[i] != '\0'; i++) {
		if (message[i] >= 'A' && message[i] <= 'Z') {
			message[i] = (message[i]-65 + rotKey)%26 + 65;
		}
	}
	printf("Encrypted message: %s\n", message);
}



/***********************************************************************************************/
// Rotation cipher decryption

void rotDecrypt(char message[], int rotKey) {
		for(int i = 0; message[i] != '\0'; ++i) {
			if (message[i] >= 'A' && message[i] <= 'Z') {
				message[i] = (message[i]-65 + (26-rotKey))%26 + 65;
			}
		}
		printf("Decrypted message: %s\n", message);
}

/***********************************************************************************************/
// Substitution cipher encryption
void subEncrypt(char message[], char subKey[], char alphabet[]) {
	int i, j;
	for(i = 0, j = 0; message[i] != '\0';) {
		if (message[i] >= 'A' && message[i] <= 'Z') {
			if (message[i] == alphabet[j]) {
				message[i] = subKey[j];
				i++;
				j=0;
			}
			else
				j++;
		}
		else
		i++;
		//printf("%d\n", message[i]);
		}
	printf("Encrypted message: %s", message);
}

/***********************************************************************************************/
// Substitution cipher decryption
void subDecrypt(char message[], char subKey[], char alphabet[]) {
	for(int i = 0, j = 0; message[i] != '\0';) {
		if (message[i] >= 'A' && message[i] <= 'Z') {
			if (message[i] == subKey[j]) {
				message[i] = alphabet[j];
				i++;
				j = 0;
			}
			else
				j++;
		}
		else
		i++;
		//printf("%d\n", message[i]);
		}
	printf("Decrypted message: %s", message);
}

