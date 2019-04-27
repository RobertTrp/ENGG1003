/*
 * project1.c
 *
 *  Created on: 3 Apr 2019
 *      Author: Robert Trpeski
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void rotEncrypt(char *message, int rotKey);
void rotDecrypt(char *message, int rotKey);
void rotDecryptWoKey(char *message);
void subEncrypt(char *message, char *subKey, const char *alphabet);
void subDecrypt(char *message, char *subKey, const char *alphabet);
void subDecryptWoKey(char *message);
int readFile(char *fileName, char *message, char *rotKeyS, char *subKey);

int main() {
	/* change filename to one of below
	 * Rotation cipher encryption with key:        rot1
	 * Rotation cipher decryption with key:        rot2
	 * Rotation cipher decryption without key:     rot3
	 * Substitution cipher encryption with key:    sub1
	 * Substitution cipher decryption with key:    sub2
	 * Substitution cipher decryption without key: sub3
	 */
	FILE *selection;
	selection = fopen("selection", "r");
	char fileName[10]; // The name of the file to read from
	char message[1024]; // The message to be encrypted or decrypted read from the file
	char rotKeyS[26]; // Rotation cipher key string read from file
	char subKey[26]; // Substitution cipher key read from file
	const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Alphabet for comparison of letters
	fgets(fileName, 10, selection);
	int task = readFile(fileName, message, rotKeyS, subKey); // task selection read from file
	int rotKey = atoi(rotKeyS); // Convert rotation key string to integer
	//printf("%d\n", rotKey);
	//printf("Original message: %s\n", message);

	// convert input to upper case
	for(int i = 0; message[i] != '\0'; i++) {
		if (message[i] >= 'a' && message[i] <= 'z')
			message[i] -= 32;
	}

	// After the task integer is read from file, run selected function
	switch (task) {

		case 1:
			rotEncrypt(message, rotKey);
			break;
		case 2:
			rotDecrypt(message, rotKey);
			break;
		case 3:
			rotDecryptWoKey(message);
			break;
		case 4:
			subEncrypt(message, subKey, alphabet);
			break;
		case 5:
			subDecrypt(message, subKey, alphabet);
			break;
		case 6:
			subDecryptWoKey(message);
			break;
		default:
			printf("Invalid task number");
	}
}

/***********************************************************************************************/
//Rotation cipher encryption

void rotEncrypt(char *message, int rotKey) {
	FILE *output;
	output = fopen("output.txt", "w");
	printf("Rotation cipher encryption with key\n\n");
	printf("Message to encrypt: %s\n", message);
	fprintf(output, "Rotation cipher encryption with key\n\n");
	fprintf(output, "Message to encrypt: %s", message);
	for(int i = 0; message[i] != '\0'; i++) {				 //loop if message character at index i does not equal NULL
		if (message[i] >= 'A' && message[i] <= 'Z') {		 //check if character is between A and Z
			message[i] = (message[i]-65 + rotKey)%26 + 65;   //shift character by key value
		}
	}
	printf("Key: %d\n\n", rotKey);
	printf("Encrypted message: %s\n", message);				//print encrypted message
	fprintf(output, "Key: %d\n\n", rotKey);
	fprintf(output, "Encrypted message: %s\n", message);
	fclose(output);
}



/***********************************************************************************************/
// Rotation cipher decryption

void rotDecrypt(char *message, int rotKey) {
	FILE *output;
	output = fopen("output.txt", "w");
	printf("Rotation cipher decryption with key\n\n");
	printf("Message to decrypt: %s\n", message);
	fprintf(output, "Rotation cipher decryption with key\n\n");
	fprintf(output, "Message to decrypt: %s\n", message);
		for(int i = 0; message[i] != '\0'; ++i) {						//loop if message character at index i does not equal NULL
			if (message[i] >= 'A' && message[i] <= 'Z') {				//check if character is between A and Z
				message[i] = (message[i]-65 + (26-rotKey))%26 + 65;		//shift character opposite direction by key value
			}
		}
	printf("Key: %d\n\n", rotKey);
	printf("Decrypted message: %s\n", message);						//print decrypted message
	fprintf(output, "Key: %d\n\n", rotKey);
	fprintf(output, "Decrypted message: %s\n", message);
	fclose(output);
}

/***********************************************************************************************/
// Rotation cipher decryption without key

void rotDecryptWoKey(char *message) {
	FILE *output;
		output = fopen("output.txt", "w");
		printf("Rotation cipher decryption without key\n\n");
		printf("Message to decrypt: %s\n", message);
		fprintf(output, "Rotation cipher decryption without key\n\n");
		fprintf(output, "Message to decrypt: %s\n", message);
		//add code here
		printf("Decrypted message: %s\n", message);						//print decrypted message
		fprintf(output, "Decrypted message: %s\n", message);
		fclose(output);
}

/***********************************************************************************************/
// Substitution cipher encryption
void subEncrypt(char *message, char *subKey, const char *alphabet) {
	FILE *output;
	output = fopen("output.txt", "w");
	printf("Substitution cipher encryption with key\n\n");
	printf("Message to encrypt: %s\n", message);
	fprintf(output, "Substitution cipher encryption with key\n\n");
	fprintf(output, "Message to encrypt: %s\n", message);
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
	printf("Key: %s\n", subKey);
	printf("Encrypted message: %s\n", message);
	fprintf(output, "Key: %s\n\n", subKey);
	fprintf(output, "Encrypted message: %s\n", message);
	fclose(output);
}


/**********************************************************************************************
 * Substitution cipher decryption
 *
 */
void subDecrypt(char *message, char *subKey, const char *alphabet) {
	FILE *output;
	output = fopen("output.txt", "w");
	printf("Substitution cipher decryption with key\n\n");
	printf("Message to decrypt: %s\n", message);
	fprintf(output, "Substitution cipher decryption with key\n\n");
	fprintf(output, "Message to decrypt: %s\n", message);
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
		}
	printf("Key: %s\n\n", subKey);
	printf("Decrypted message: %s\n", message);
	fprintf(output, "Key: %s\n\n", subKey);
	fprintf(output, "Decrypted message: %s\n", message);
	fclose(output);
}

/***********************************************************************************************/
// Rotation cipher decryption

void subDecryptWoKey(char *message) {
	FILE *output;
	output = fopen("output.txt", "w");
	printf("Substitution cipher decryption without key\n\n");
	printf("Message to decrypt: %s\n", message);
	fprintf(output, "Substitution cipher decryption without key\n\n");
	fprintf(output, "Message to decrypt: %s\n", message);
	//add code here
	printf("Decrypted message: %s\n", message);
	fprintf(output, "Decrypted message: %s\n", message);
	fclose(output);
}


/**********************************************************************************************
 * When this function is called, the selected file (fileName) is opened and first line is read,
 * which is an integer between 1 and 6 for task selection. The string is read and converted to an integer variable
 * named "task".
 * If the task integer is 1,2,4 or 5, the second line is read which is a key for encryption/decryption followed by reading
 * the third line which is the message to be encrypted/decrypted.
 *
 * If the task integer is 3 or 6, there is no key to be read so the second line is read, which is the message to be
 * encrypted/decrypted without a key.
 *
 * "task" is returned if a valid integer is found in the first line
 *
 * If the file cannot be found or is empty, an error is displayed and 0 is returned
 */

int readFile(char *fileName, char *message, char *rotKeyS, char *subKey) {
	char buff[1024];
	FILE *input;
	input = fopen(fileName, "r");
	if (input == NULL) {
		perror("fopen()");
		return 0;
	}
	else {
		fgets(buff, 255, input);
		int task = atoi(buff);
		if (task < 3) {							//1 = rotation enrypt with key, 2 = rotation decrypt with key
			fgets(buff, 255, input);
			strcpy(rotKeyS, buff);
			fgets(buff, 1024, input);
			strcpy(message, buff);
			return task;
		}
		else if (task == 3) {                       //3 = rotation decrypt without key
			fgets(buff, 1024, input);
			strcpy(message, buff);
			return task;
		}
		else if (task > 3 && task < 6) {            // 4 = substitution encrypt with key, 5 = substitution decrypt with key
			fgets(buff, 255, input);
			strcpy(subKey, buff);
			fgets(buff, 1024, input);
			strcpy(message, buff);
			return task;
		}
		else if (task == 6) {						// 6 = substitution decrypt without key

			for(int i = 0; !feof(input); i++) {
				fscanf(input, "%c", &buff[i]);
			}
			strcpy(message, buff);
			return task;
		}
	}
	fclose(input);
	return 0;
}
