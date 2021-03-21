// Search and Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Search and Sort.h"


int main()
{
	int array[6];
	int *p;
	p = array;

	p = &array[0]; *p = 17;
	p = &array[1]; *p = 8;
	p = &array[2]; *p = 25;
	p = &array[3]; *p = 10;
	p = &array[4]; *p = 1; // value 1 is here
	p = &array[5]; *p = 43;

	for (int i = 0; i < 6; i++)
		std::cout << array[i] << " ";

	GAM345::SequentialSearch(array, 6, 1); // value "1" found!

	p = &array[4]; *p = 6; // change address holding 1 to something else

	for (int i = 0; i < 6; i++)
		std::cout << array[i] << " ";

	GAM345::SequentialSearch(array, 6, 1); // value "1" not found!

	std::cout << std::endl;

	GAM345::InsertionSort(array, 6);

	std::cout << "Insertion Sort: ";

	for (int i = 0; i < 6; i++)
		std::cout << array[i] << " ";

	std::cout << std::endl;

	std::cout << "Merge Sort: ";

	GAM345::MergeSort(array, 6);

	for (int i = 0; i < 6; i++)
		std::cout << array[i] << " ";

	std::cout << std::endl;

};


