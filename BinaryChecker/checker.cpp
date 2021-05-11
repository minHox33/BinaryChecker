#include "editor.h" 
#include "checker.h" 

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <array>
 

using namespace std;


int takeLengthOfArray(char* binaryArray) {

	int index = 0;
	int numberOfAllDigits = 0;

	while (binaryArray[index] != NULL) {

		index++;
		numberOfAllDigits++;
	}

	cout << "Number of digits in array: " << numberOfAllDigits << "\n";

	return numberOfAllDigits;
}

int checkIfOnlyZero(int numberOfAllDigits, char* binaryArray, bool* isCorrectIndex) {

	int objectsCounter = 0;
	int zeroCounter = 0;
	int numberOfWrongObjects = 0;
	int index = 0;

	for (int i = 0; i < numberOfAllDigits; i++) {

		objectsCounter++;
		index = i;

		if (binaryArray[i] == '0') {
			zeroCounter++;
		}

		if (binaryArray[i] == '1') {
			zeroCounter = 0;
		}

		if (zeroCounter == 8 && objectsCounter % 8 == 0) {

			numberOfWrongObjects++;
			zeroCounter = 0;

			index = index - 7;
			for (int j = 0; j < 8; j++)
			{
				isCorrectIndex[index] = false;
				index++;
			}
			objectsCounter = 0;
		}
	}

	return numberOfWrongObjects;
}

int checkIfFirstLastAreEqual(int numberOfAllDigits, char* binaryArray, bool* isCorrectIndex) {

	int numberOfWrongObjects = 0;
	int objectsCounter = 0;
	int index = 0;

	for (int i = 0; i < numberOfAllDigits; i++) {
		objectsCounter++;
		index = i;

		if (objectsCounter % 8 == 0) {

			if (binaryArray[index] != binaryArray[index - 7]) {
				numberOfWrongObjects++;

				index = index - 7;
				for (int j = 0; j < 8; j++)
				{
					isCorrectIndex[index] = false;
					index++;
				}
			}
			objectsCounter = 0;
		}
	}

	return numberOfWrongObjects;
}

int checkWrongObjects(int numberOfAllDigits, char* binaryArray, char* binaryArrayWrong, bool* isCorrectIndex) {

	int numberOfWrongObjects = 0;
	int numberOfWrongObjectsZero = 0;
	int numberOfWrongObjectsFirstLast = 0;

	numberOfWrongObjectsZero = checkIfOnlyZero(numberOfAllDigits, binaryArray, isCorrectIndex);

	int counter = 0;
	for (int i = 0; i < numberOfAllDigits; i++) {
		if (isCorrectIndex[i] == false) {
			binaryArrayWrong[counter] = binaryArray[i];
			counter++;
		}
	}

	numberOfWrongObjectsFirstLast = checkIfFirstLastAreEqual(numberOfAllDigits, binaryArray, isCorrectIndex);

	for (int j = numberOfAllDigits; j < numberOfAllDigits * 2; j++) {
		if (isCorrectIndex[j - numberOfAllDigits] == false) {
			binaryArrayWrong[counter] = binaryArray[j - numberOfAllDigits];
			counter++;
		}
	}

	return numberOfWrongObjectsZero + numberOfWrongObjectsFirstLast;
}

int checkCorrectObjects(int numberOfAllDigits, char* binaryArray, char* binaryArrayCorrect, bool* isCorrectIndex) {

	int numberOfCorrectObjects = 0;
	int counter = 0;

	for (int i = 0; i < numberOfAllDigits; i++) {

		if (isCorrectIndex[i] == true) {
			binaryArrayCorrect[counter] = binaryArray[i];
			numberOfCorrectObjects++;
			counter++;
		}
	}

	return numberOfCorrectObjects / 8;
}