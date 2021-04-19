// Speed Run.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "GAM345Vector.h"

using namespace std;

int main()
{
	// Declarations
	Vector myVector;
	string numbersToRead;
	ifstream myfile("Numbers.txt");
	bool sorted = false;

	if (!myfile.is_open())
	{
		cout << "Unable to open Numbers.txt";
		return 0;
	}

	// Get the amount of numbers from file
	getline(myfile, numbersToRead);
	int fileNumbers = stoi(numbersToRead);

	// check if outputting correct number
	//cout << fileNumbers << endl;

	myVector.reserve(fileNumbers);

	// check if outputting correctly updated vector capacity
	 //cout << myVector.capacity() << endl;

	// Read the actual numbers to search through
	getline(myfile, numbersToRead);
	stringstream ss(numbersToRead);

	while (getline(ss, numbersToRead, ' ')) {
		int numberToAdd = stoi(numbersToRead);
		myVector.push_back(numberToAdd);
	}

	// check if the vector has the correct elements in it && check if outputting correctly updated vector capacity
	//for (int i = 0; i < myVector.size(); i++)
		//cout << myVector[i] << " ";
	//cout << myVector.capacity() << endl;
	//

	// Get the value to find && close the file since we've read all three lines
	getline(myfile, numbersToRead);
	int numberToFind = stoi(numbersToRead);
	myfile.close();

	// check if numberToFind is correct
	// cout << numberToFind << endl;

	// Find if the value exists
	// if array size = small, sequential search is optimal. Otherwise check if sorted/unsorted. If unsorted, sort and run binary search. If sorted, run binary search.
	int size = myVector.size();
	if (size <= 10)
		cout << (myVector.SequentialSearch(numberToFind) == true ? "True" : "False") << endl;
	else 
	{
		// check if sorted. If yes, then run binary search.
		if (myVector.Sorted() == true) {
			sorted = true;
			cout << (myVector.BinarySearch(numberToFind) == -1 ? "False" : "True") << endl;
		}
		else { // If not sorted, mergesort then run binary search.
			myVector.MergeSort();
			cout << (myVector.BinarySearch(numberToFind) == -1 ? "False" : "True") << endl;
			sorted = true;
		}
	}
	
	//for (int i = 0; i < size; i++)
		//cout << myVector[i] << " ";

	// Check for duplicates
	if (myVector.Sorted() == false) {
		myVector.MergeSort();
		cout << (myVector.Duplicates() == true ? "True" : "False") << endl;
	}
	else
		cout << (myVector.Duplicates() == true ? "True" : "False") << endl;

	myVector.clear();

	return 0;
}


