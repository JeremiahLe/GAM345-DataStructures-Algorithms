// Search and Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Search and Sort.h"


int main()
{
	
	int array[5];
	int *p;
	p = array;

	p = &array[0]; *p = 17;
	p = &array[1]; *p = 8;
	p = &array[2]; *p = 25;
	p = &array[3]; *p = 10;
	p = &array[4]; *p = 1; // value 1 is here

	for (int i = 0; i < 5; i++)
		std::cout << array[i] << ", ";

	GAM345::SequentialSearch(array, 5, 1); // value "1" found!

	p = &array[4]; *p = 6; // change address holding 1 to something else

	for (int i = 0; i < 5; i++)
		std::cout << array[i] << ", ";

	GAM345::SequentialSearch(array, 5, 1); // value "1" not found!

	GAM345::InsertionSort(array, 5);

	for (int i = 0; i < 5; i++)
		std::cout << array[i] << ", ";
	
	
	int newArray[2];
	int*ptr;
	ptr = newArray;

	ptr = &newArray[0]; *ptr = 1;
	ptr = &newArray[1]; *ptr = 0;

	GAM345::InsertionSort(newArray, 2); 

	for (int i = 0; i < 2; i++)
		std::cout << newArray[i] << ", "; 
		

};


