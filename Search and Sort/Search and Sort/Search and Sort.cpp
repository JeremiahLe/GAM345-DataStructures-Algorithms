// Search and Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Search and Sort.h"
#include <Windows.h>
#include <sysinfoapi.h>


int main()
{
	GAM345Namespace::GAM345 myClass;

	// Sequential Search //

	std::cout << "Sequential Search:" << std::endl;

	int array[6];
	int *p;
	p = array;

	p = &array[0]; *p = 17;
	p = &array[1]; *p = 8;
	p = &array[2]; *p = 25;
	p = &array[3]; *p = 10;
	p = &array[4]; *p = 1; // value 1 is here
	p = &array[5]; *p = 43;
	p = &array[6]; *p = 12;

	for (int i = 0; i < 6; i++)
		std::cout << array[i] << " ";

	myClass.GAM345::SequentialSearch(array, 6, 1); // value "1" found!

	p = &array[4]; *p = 6; // change address holding 1 to something else

	for (int i = 0; i < 6; i++)
		std::cout << array[i] << " ";

	myClass.GAM345::SequentialSearch(array, 6, 1); // value "1" not found!

	// Insertion Sort //

	std::cout << std::endl;

	myClass.GAM345::InsertionSort(array, 6);

	std::cout << "Insertion Sort: ";

	for (int i = 0; i < 6; i++)
		std::cout << array[i] << " ";

	// Merge Sort //

	std::cout << std::endl;

	int mergeSortArray[] = { 7, 6, 4, 3, 5};
	std::cout << "Merge Sort: ";

	myClass.GAM345::MergeSort(mergeSortArray, 5);

	for (int i = 0; i < 5; i++)
		std::cout << mergeSortArray[i] << " ";

	std::cout << std::endl;

	// Binary Search //

	std::cout << std::endl;

	std::cout << "Binary Search:" << std::endl;

	int newArray[] = { 1, 2, 3, 4, 5, 6 };
	int value = 6;
	int bsResult = myClass.GAM345::BinarySearch(newArray, 6, value);

	for (int i = 0; i < 6; i++)
		std::cout << newArray[i] << " ";

	std::cout << std::endl;

	if (bsResult == -1)
		std::cout << "Value " << value << " not found!";
	else
		std::cout << "Value " << value << " found at index " << bsResult;

	value = 20;
	bsResult = myClass.GAM345::BinarySearch(newArray, 6, value);

	std::cout << std::endl;

	for (int i = 0; i < 6; i++)
		std::cout << newArray[i] << " ";

	std::cout << std::endl;

	if (bsResult == -1)
		std::cout << "Value " << value << " not found!";
	else
		std::cout << "Value " << value << " found at index " << bsResult;

	std::cout << std::endl;

	// Quick Sort //

	std::cout << std::endl;

	int newArray2[] = { 1, 20, 14, 56, 44, 6 };
	int low = newArray2[0];
	int high = newArray2[5];

	std::cout << "Before QuickSort: ";
	for (int i = 0; i < 6; i++)
		std::cout << newArray2[i] << " ";

	std::cout << std::endl;

	myClass.GAM345::QuickSort(newArray2, 0, 5);

	std::cout << "After QuickSort: ";
	for (int i = 0; i < 6; i++)
		std::cout << newArray2[i] << " ";

	std::cout << std::endl;
	std::cout << std::endl;

	
	////////////////////////////////////////////////////////////// Mergesort vs Quicksort Testing ////////////////////////////////////

	std::cout << "Mergesort vs Quicksort Testing:" << std::endl;

	std::cout << std::endl;

	unsigned long long startTime;
	unsigned long long endTime;

	startTime = GetTickCount64();

	 // 10,000 randomized unsorted elements - quicksort
	const int iterativeSize = 20000;
	int randomArray[iterativeSize];
	int sortedArray[iterativeSize];

	for (int i = 0; i < iterativeSize; i++)
		randomArray[i] = rand()%100;
	for (int i = 0; i < iterativeSize; i++)
		sortedArray[i] = 0 + i;

	myClass.GAM345::QuickSort(sortedArray, 0, iterativeSize - 1);

	for (int i = 0; i < iterativeSize; i++)
		std::cout << sortedArray[i] << " ";
	

	endTime = GetTickCount64();

	std::cout << std::endl;

	double elapsedTime = (endTime - startTime)*1e-3;

	std::cout << "Elapsed Time: " << elapsedTime << std::endl;


	
};


