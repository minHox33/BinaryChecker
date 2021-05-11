#include "editor.h" 
#include "checker.h" 

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <array>


using namespace std;

int main()
{ 
	//deklaracja tablic
	char* binaryArray = new char[1000];
	char* binaryArrayWrong = new char[1000];
	char* binaryArrayCorrect = new char[1000];
	bool* isCorrectIndex = new bool[1000];
	for (int i = 0; i < 1000; i++)
	{
		isCorrectIndex[i] = true;
	}

	fillNull(binaryArray);
	fillNull(binaryArrayWrong);
	fillNull(binaryArrayCorrect);


	int numberOfAllDigits = 0;

	int numberOfAllObjects = 0;
	int numberOfWrongObjects = 0;
	int numberOfCorrectObjects = 0;


	//open file and write to array
	ifstream file("input.txt");		//ifstream: Stream class to read from files
	if (file.is_open())
	{
		while (!file.eof())
		{
			file >> binaryArray;
		}
	}
	else { cout << "Unable to open file"; }

	file.close();


	//pobranie ilosci cyferek w pliku
	numberOfAllDigits = takeLengthOfArray(binaryArray);

	//zad 1 - zliczanie wszystkich obiektow
	numberOfAllObjects = numberOfAllDigits/8;
	cout << "All " << numberOfAllObjects << " objects:\n\n";
	print(numberOfAllObjects, binaryArray);
	cout << "\n\n";

	//zad 2 - bledne obiekty
	numberOfWrongObjects = checkWrongObjects(numberOfAllDigits, binaryArray, binaryArrayWrong, isCorrectIndex);
	cout << "All " << numberOfWrongObjects << " wrong objects:\n\n";
	print(numberOfWrongObjects, binaryArrayWrong);
	cout << "\n\n";

	//zad 3 - poprawne obiekty
	numberOfCorrectObjects = checkCorrectObjects(numberOfAllDigits, binaryArray, binaryArrayCorrect, isCorrectIndex);
	cout << "All " << numberOfCorrectObjects << " correct objects:\n\n";
	print(numberOfCorrectObjects, binaryArrayCorrect);

	//write array to txt file and close
	ofstream output("output.txt");
	if (!output)
	{
		cout << "Cannot open output file\n";
		return 1;
	}

	int numberOfAllWrongDigits, numberOfAllCorrectDigits = 0;
	numberOfAllWrongDigits = numberOfWrongObjects * 8;
	numberOfAllCorrectDigits = numberOfCorrectObjects * 8;

	output.write((char*)binaryArray, numberOfAllDigits);
	output << "\n\n";
	output.write((char*)binaryArrayWrong, numberOfAllWrongDigits);
	output << "\n\n";
	output.write((char*)binaryArrayCorrect, numberOfAllCorrectDigits);
	output.close();

	return 0;
}
