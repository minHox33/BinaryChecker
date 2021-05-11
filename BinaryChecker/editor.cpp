#include "editor.h" 
#include "checker.h" 

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <array>

using namespace std;


void fillNull(char* binaryArray) {

	for (int i = 0; i < 1000; i++)
	{
		binaryArray[i] = NULL;
	}

}


void print(int numberOfObjects, char* array)
{
	int objectCounter = 0;
	//cout << "\nNumber of objects: " << numberOfObjects << "\n\n";

	for (int i = 0; i < numberOfObjects * 8; i++) {
		cout << array[i];
		objectCounter++;

		if (objectCounter % 8 == 0) cout << "\n";
	}
}