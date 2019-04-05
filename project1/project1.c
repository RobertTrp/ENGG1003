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
	char message[] = "HELLO WORLD";
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
	subEncrypt(message, subKey, alphabet);
	//subDecrypt(message, subKey, alphabet);
}

/***********************************************************************************************/
//Rotation cipher encryption

void rotEncrypt(char message[], int rotKey) {
	for(int i = 0; message[i] != '\0'; i++) {				 //loop if message character at index i does not equal NULL
		if (message[i] >= 'A' && message[i] <= 'Z') {		 //check if character is between A and Z
			message[i] = (message[i]-65 + rotKey)%26 + 65;   //shift character by key value
		}
	}
	printf("Encrypted message: %s\n", message);				//print encrypted message
}



/***********************************************************************************************/
// Rotation cipher decryption

void rotDecrypt(char message[], int rotKey) {
		for(int i = 0; message[i] != '\0'; ++i) {						//loop if message character at index i does not equal NULL
			if (message[i] >= 'A' && message[i] <= 'Z') {				//check if character is between A and Z
				message[i] = (message[i]-65 + (26-rotKey))%26 + 65;		//shift character opposite direction by key value
			}
		}
		printf("Decrypted message: %s\n", message);						//print decrypted message
}

/***********************************************************************************************/
// Substitution cipher encryption
void subEncrypt(char message[], char subKey[], char alphabet[]) {
	for(int i = 0, j = 0; message[i] != '\0';) {			//loop if message character at index i does not equal NULL
		if (message[i] >= 'A' && message[i] <= 'Z') {		//check if character is between A and Z
			if (message[i] == alphabet[j]) {				//check if character is equal to a character in the plain alphabet
				message[i] = subKey[j];						//if so, assign character with same index from key
				i++;										//increment i to continue and check next character
				j=0;										//reset j to 0 to start check at beginning of key
			}
			else											//else if the character isn't a match to a character in the plain alphabet
				j++;										//increment j to check the rest of the plain alphabet for a match
		}
		else
		i++;												//else if message character is not between A and Z, leave as is and skip
		//printf("%d\n", message[i]);
		}
	printf("Encrypted message: %s", message);
}

/***********************************************************************************************/
// Substitution cipher decryption
void subDecrypt(char message[], char subKey[], char alphabet[]) {
	for(int i = 0, j = 0; message[i] != '\0';) {			//loop if message character at index i does not equal NULL
		if (message[i] >= 'A' && message[i] <= 'Z') {		//check if character is between A and Z
			if (message[i] == subKey[j]) {					//check if encrypted character is equal to a character in the key
				message[i] = alphabet[j];					//if so, assign character with same index from normal alphabet
				i++;										//increment i to continue and check next character
				j = 0;										//reset j to 0 to start check at beginning of key
			}
			else											//if the character isn't a match to a character in the key
				j++;										//increment j to check the rest of the key for a match
		}
		else												//else if message character is not between A and Z, leave as is and skip
		i++;
		//printf("%d\n", message[i]);
		}
	printf("Decrypted message: %s", message);
}

