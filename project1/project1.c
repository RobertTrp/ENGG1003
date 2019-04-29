/*
 * project1.c
 *
 *  Created on: 3 Apr 2019
 *      Author: Robert Trpeski
 */

/**********************************************************************************************
 * To change the task, enter the following in the first line of the file "selection"
 * Rotation cipher encryption with key:         rot1
 * Rotation cipher decryption with key:         rot2
 * Rotation cipher decryption without key:      rot3
 * Substitution cipher encryption with key:     sub1
 * Substitution cipher decryption with key:     sub2
 * Substitution cipher decryption without key:  sub3
 **********************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**********************************************************************************************
 * Function Prototypes
 **********************************************************************************************/
void rotEncrypt(char *message, int rotKey);
void rotDecrypt(char *message, int rotKey);
void rotDecryptWoKey(char *message);
void subEncrypt(char *message, char *subKey, const char *alphabet);
void subDecrypt(char *message, char *subKey, const char *alphabet);
void subDecryptWoKey(char *message);
int readFile(char *fileName, char *message, char *rotKeyS, char *subKey);
void caseConversion(char *message, char*subKey);

/**********************************************************************************************
 * The main function holds the variables for the message, keys and alphabet
 * The name of the file to be opened is read from a file named selection
 * FileName, message, rotKeyS and subKey are passed down to the readFile function as pointers and values changed to what is read from a file
 * The rotation key is converted from a string to an integer using the atoi function
 * message and subKey are converted to upper case after read from file
 **********************************************************************************************/
int main() {
	FILE *selection;
	selection = fopen("selection", "r"); 								//open selection file
	char fileName[10]; 													//The name of the file to read from
	char message[1024]; 												//The message to be encrypted or decrypted read from the file
	char rotKeyS[26]; 													//Rotation cipher key string read from file
	char subKey[26]; 													//Substitution cipher key read from file
	const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 				//Alphabet for comparison of letters
	fscanf(selection, "%s", fileName); 									//retrieve fileName from selection file
	int task = readFile(fileName, message, rotKeyS, subKey);			//task selection read from file
	int rotKey = atoi(rotKeyS); 										//Convert rotation key string to integer
	caseConversion(message, subKey);
	fclose(selection);													//close selection file


	//After the task integer is read from file, run selected function
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

/**********************************************************************************************
 * Rotation cipher encryption
 * message and rotation cipher key are passed to this function
 * This function takes a message and key and encrypts it using a rotation cipher key
 * The ASCII value of 'A' to 'Z' is shifted down to 0-25
 * The value is then shifted by the key value and using the modulus operator is constrained to 0-25;
 * The ASCII value is then shifted back up by the initial ASCII value to output the new letter shifted by the key value
 * output is printed to both console and file named output
 **********************************************************************************************/
void rotEncrypt(char *message, int rotKey) {
	FILE *output;														//declare pointer of FILE type
	output = fopen("output", "w");								    	//open output file
	printf("Rotation cipher encryption with key\n\n");					//print task name to console
	printf("Message to encrypt:\n%s\n\n", message);						//print message to console
	fprintf(output, "Rotation cipher encryption with key\n\n");			//print task name to file
	fprintf(output, "Message to encrypt:\n%s\n\n", message);			//print message to file

	for(int i = 0; message[i] != '\0'; i++) {				 	    	//loop if message character at index i does not equal NULL
		if (message[i] >= 'A' && message[i] <= 'Z') {					//check if character is between A and Z
			message[i] = (message[i]-65 + rotKey)%26 + 65;  			//shift character by key value
		}
	}

	printf("Key: %d\n\n", rotKey);										//print key to console
	printf("Encrypted message:\n%s\n", message);				 		//print encrypted message to console
	fprintf(output, "Key: %d\n\n", rotKey);								//print key to file
	fprintf(output, "Encrypted message:\n%s\n", message);   			//print encrypted message to file
	fclose(output);
}

/**********************************************************************************************
 * Rotation cipher decryption
 * message and rotation cipher key are passed to this function
 * This function takes an encrypted message and key and decrypts is using a rotation cipher key
 * The ASCII value of 'A' to 'Z' is shifted down to 0-25
 * The value is then shifted in the negative direction by the key value and using the modulus operator is constrained to 0-25;
 * The ASCII value is then shifted back up by the initial ASCII value to output the new letter shifted by the key value
 * output is printed to both console and a file named output
 **********************************************************************************************/
void rotDecrypt(char *message, int rotKey) {
	FILE *output;														//declare pointer of FILE type
	output = fopen("output", "w");										//open output file
	printf("Rotation cipher decryption with key\n\n");					//print task name to console
	printf("Message to decrypt:\n%s\n\n", message);						//print message to console
	fprintf(output, "Rotation cipher decryption with key\n\n");			//print task name to file
	fprintf(output, "Message to decrypt:\n%s\n\n", message);			//print message to file

		for(int i = 0; message[i] != '\0'; ++i) {						//loop if message character at index i does not equal NULL
			if (message[i] >= 'A' && message[i] <= 'Z') {				//check if character is between A and Z
				message[i] = (message[i]-65 + (26-rotKey))%26 + 65;		//shift character opposite direction by key value
			}
		}

	printf("Key: %d\n\n", rotKey);										//print key to console
	printf("Decrypted message:\n%s\n", message);						//print decrypted message to console
	fprintf(output, "Key: %d\n\n", rotKey);								//print key to file
	fprintf(output, "Decrypted message:\n%s\n", message);				//print decrypted message to console
	fclose(output);														//close output file
}

/***********************************************************************************************
 * Rotation cipher decryption without key
 * message is passed to this function
 * This function takes a message encrypted with a rotation cipher and decrypts it without a known key as well as finding the key
 * The ASCII value of 'A' to 'Z' is shifted down to 0-25
 * The value is then shifted in the negative direction by the key value and using the modulus operator is constrained to 0-25;
 * The ASCII value is then shifted back up by the initial ASCII value to output the new letter shifted by the key value
 * The message is tested with each key value between 0-25 and all are output to the console and file named output
 **********************************************************************************************/
void rotDecryptWoKey(char *message) {
	FILE *output;														//declare pointer of FILE type
	output = fopen("output", "w");										//open output file
	char buff[1024];													//declare temporary message array
	printf("Rotation cipher decryption without key\n\n");				//print task name to console
	printf("Message to decrypt:\n%s\n\n", message);						//print message to console
	fprintf(output, "Rotation cipher decryption without key\n\n");		//print task name to file
	fprintf(output, "Message to decrypt:\n%s\n\n", message);			//print message to file

	int i, j;															//declare variables for counters
	for(j = 0; j < 26; j++) {											//loop increasing key value between 0-25
		for(i = 0; message[i] != '\0'; ++i) {							//loop if message character at index i does not equal NULL
			if (message[i] >= 'A' && message[i] <= 'Z') {				//check if character is between A and Z
				buff[i] = (message[i]-65 + (26-j))%26 + 65;				//shift character opposite direction by key value and store in temp variable
			}
			else buff[i] = message[i];									//if the character is not a letter copy directly from buff[i] to message[i]
		}
		buff[i] = '\0';													//add null to end of temporary array
		printf("Decrypted message, Key %d:\n%s\n\n", j, buff);			//print decrypted message and key to console
		fprintf(output, "Decrypted message, Key %d:\n%s\n\n", j, buff); //print decrypted message and key to file
	}

	fclose(output);														//close output file
}

/***********************************************************************************************
 * Substitution cipher encryption
 * message, substitution cipher key and alphabet are passed to this function
 * This function takes a message and scrambled alphabet key and encrypts the message by searching for the letter
 * in the plain alphabet array and replacing it with the letter with the same index value from the key array
 * If the character is not a letter, it is left as is and the next character is checked until the end of the message array is reached
 * Output is printed to both the console and a file named output
************************************************************************************************/
void subEncrypt(char *message, char *subKey, const char *alphabet) {
	FILE *output;														//declare pointer of FILE type
	output = fopen("output", "w");										//open output file
	printf("Substitution cipher encryption with key\n\n");				//print task name to console
	printf("Message to encrypt:\n%s\n\n", message);						//print message to console
	fprintf(output, "Substitution cipher encryption with key\n\n");		//print task name to file
	fprintf(output, "Message to encrypt:\n%s\n\n", message);			//print message to file

	for(int i = 0, j = 0; message[i] != '\0';) {						//loop if message character at index i does not equal NULL
		if (message[i] >= 'A' && message[i] <= 'Z') {					//check if character is between A and Z
			if (message[i] == alphabet[j]) {							//check if character is equal to a character in the plain alphabet
				message[i] = subKey[j];									//if so, assign character with same index from key
				i++;													//increment i to continue and check next character
				j=0;													//reset j to 0 to start check at beginning of key
			}
			else														//else if the character isn't a match to a character in the plain alphabet
				j++;													//increment j to check the rest of the plain alphabet for a match
		}
		else
		i++;															//else if message character is not between A and Z, leave as is and skip
		}

	printf("Key: %s\n", subKey);										//print key to console
	printf("Encrypted message:\n%s\n\n", message);						//print encrypted message to console
	fprintf(output, "Key: %s\n", subKey);								//print key to file
	fprintf(output, "Encrypted message:\n%s\n", message);				//print encrypted message to file
	fclose(output);														//close output file
}

/**********************************************************************************************
 * Substitution cipher decryption with key
 * message, substitution cipher key and alphabet are passed to this function
 * This function takes a encrypted message and scrambled alphabet key and decrypts the message by searching for the letter
 * in the key array and replacing it with the letter with the same index value from the alphabet array
 * If the character is not a letter, it is left as is and the next character is checked until the end of the message array is reached
 * Output is printed to both the console and a file named output
************************************************************************************************/
void subDecrypt(char *message, char *subKey, const char *alphabet) {
	FILE *output;														//declare pointer of FILE type
	output = fopen("output", "w");										//open output file
	printf("Substitution cipher decryption with key\n\n");				//print task name to console
	printf("Message to decrypt:\n%s\n\n", message);						//print message to console
	fprintf(output, "Substitution cipher decryption with key\n\n");		//print task name to file
	fprintf(output, "Message to decrypt:\n%s\n\n", message);			//print message to file

	for(int i = 0, j = 0; message[i] != '\0';) {						//loop if message character at index i does not equal NULL
		if (message[i] >= 'A' && message[i] <= 'Z') {					//check if character is between A and Z
			if (message[i] == subKey[j]) {								//check if encrypted character is equal to a character in the key
				message[i] = alphabet[j];								//if so, assign character with same index from normal alphabet
				i++;													//increment i to continue and check next character
				j = 0;													//reset j to 0 to start check at beginning of key
			}
			else														//if the character isn't a match to a character in the key
				j++;													//increment j to check the rest of the key for a match
		}
		else															//else if message character is not between A and Z, leave as is and skip
		i++;
		}

	printf("Key: %s\n\n", subKey);										//print key to console
	printf("Decrypted message:\n%s\n\n", message);						//print decrypted message to console
	fprintf(output, "Key: %s\n\n", subKey);								//print key fo file
	fprintf(output, "Decrypted message:\n%s\n\n", message);				//print decrypted message to file
	fclose(output);														//close output file
}

/***********************************************************************************************
 * Substitution cipher decryption without key [INCOMPLETE]
************************************************************************************************/
void subDecryptWoKey(char *message) {
	FILE *output;														//declare pointer of FILE type
	output = fopen("output", "w");										//open output file
	printf("Substitution cipher decryption without key\n\n");			//print task name to console
	printf("Message to decrypt:\n%s\n\n", message);						//print message to console
	fprintf(output, "Substitution cipher decryption without key\n\n");	//print task name to file
	fprintf(output, "Message to decrypt:\n%s\n\n", message);			//print message to file

	//add code here

	printf("Decrypted message:\n%s\n\n", message);						//print decrypted message to console
	fprintf(output, "Decrypted message:\n%s\n\n", message);				//print decrypted message to file
	fclose(output);														//close output file
}

/**********************************************************************************************
 * readFile
 * fileName, message, rotation key and subKey are passed to this function
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
 **********************************************************************************************/
int readFile(char *fileName, char *message, char *rotKeyS, char *subKey) {
	char buff[1024];													//declare temporary array													//
	int i;																//declare variable for counter
	FILE *input;														//declare pointer of FILE type
	input = fopen(fileName, "r");										//open input file

	if (input == NULL) {												//if no file exists
		perror("fopen()\n");											//print error to console
		fclose(input);													//close input file
		return 0;
	}

	else {																//else if file exists
		fgets(buff, 255, input);										//read first line of file to retrieve task
		int task = atoi(buff);											//convert task from string to integer

		if (task < 3) {													//1 = rotation enrypt with key, 2 = rotation decrypt with key
			fgets(buff, 255, input);									//read next line to retrieve rotation key
			strcpy(rotKeyS, buff);										//copy from temporary array to rotKeyS array
			for(i = 0; !feof(input); i++) {								//read rest of file to retrieve message
				fscanf(input, "%c", &buff[i]);
			}
			buff[i-1] = '\0';											//add NULL character to end of array
			strcpy(message, buff);										//copy message string from temporary array to message array
			return task;												//return task number
		}

		else if (task == 3) {                      						//3 = rotation decrypt without key
			for(i = 0; !feof(input); i++) {								//read rest of file to retrieve message
				fscanf(input, "%c", &buff[i]);
			}
			buff[i-1] = '\0';											//add NULL character to end of array
			strcpy(message, buff);										//copy message string from temporary array to message array
			return task;												//return task number
		}

		else if (task > 3 && task < 6) {     					      	//4 = substitution encrypt with key, 5 = substitution decrypt with key
			fgets(buff, 255, input);									//rear first line to retried substitution key
			strcpy(subKey, buff);										//copy substition key from temporary array to subKey array
			for(i = 0; !feof(input); i++) {								//read rest of file to retrieve message
				fscanf(input, "%c", &buff[i]);
			}
			buff[i-1] = '\0';											//add NULL character to end of array
			strcpy(message, buff);										//copy message string from temporary array to message array
			return task;												//return task number
		}

		else if (task == 6) {											//6 = substitution decrypt without key
			for(i = 0; !feof(input); i++) {								//read rest of file to retrieve message
				fscanf(input, "%c", &buff[i]);
			}
			buff[i-1] = '\0';											//add NULL character to end of array
			strcpy(message, buff);										//copy message string from temporary array to message array
			return task;												//return task number
		}
		fclose(input);													//close input file
	}

	return 0;
}

/***********************************************************************************************
 * Case conversion
 * message and substitution cipher key are passed to this function
 * This function converts any lower case letters in message and subKey to upper case
 * pointers to message and subKey are passed as arguments
 * Any characters that are not english alphabet letters remain the same
************************************************************************************************/
void caseConversion(char *message, char*subKey) {

	for(int i = 0; message[i] != '\0'; i++) {							//loop if message character at index i does not equal NULL
			if (message[i] >= 'a' && message[i] <= 'z')					//if character ASCII value is between 'a' and 'z'
				message[i] -= 32;										//subtract 32 from ASCII value to convert to upper case
		}

		for(int i = 0; subKey[i] != '\0'; i++) {						//loop is subKey character at index i does not equal NULL
			if (subKey[i] >= 'a' && subKey[i] <= 'z')					//if character ASCII value is between 'a' and 'z'
				subKey[i] -= 32;										//subtract 32 from ASCII value to convert to upper case
		}
}
