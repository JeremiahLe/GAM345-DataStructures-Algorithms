#pragma once
#include <iostream>

namespace GAM345 {

	bool SequentialSearch(int *aArray, int aSize, int aValue) {
		if (aSize == 0) { // empty array?
			return false;
			std::cout << "Invalid array" << std::endl;
		}
		for (int i = 0; i < aSize; i++) { // find value
			if (aArray[i] == aValue) {
				std::cout << "Value " << aValue << " found!" << std::endl;
				return true;
			}
		}
			std::cout << "Value " << aValue << " not found!" << std::endl; // value doesn't exist
			return false;
	}

	void InsertionSort(int *aArray, int aSize) {
		if (aSize == 0) // empty array?
			return;
		int index = 1;
			while (index < aSize) {
				if (aArray[index] < aArray[index - 1] && index >= 1) { // is second index smaller than first?
					int temp = aArray[index - 1]; // value to be moved over to the left
					aArray[index - 1] = aArray[index]; // left value to right value
					aArray[index] = temp; // right value to left value
					index--; // move back
				}
				else
					index++;
			}
		}

	void merge(int* leftArray, int leftSize, int* rightArray, int rightSize) {

		int* answer = new int[leftSize + rightSize];

		// Loop through both left and right at same time, taking smaller element from each side, 
		// until we reach end of one the arrays

		int leftIndex = 0;
		int rightIndex = 0;
		int answerIndex = 0;

		while (leftIndex < leftSize && rightIndex < rightSize) {  
			if (leftArray[leftIndex] < rightArray[rightIndex]) { // if left array index > right array index, add it to answer
				answer[answerIndex] = leftArray[leftIndex]; 
				leftIndex++;
				answerIndex++;
			}
			else {
				answer[answerIndex] = rightArray[rightIndex]; // else add the right array index to answer
				rightIndex++;
				answerIndex++;
			}
		}

		// check if there's remaining data in left - add it to answer
		while (leftIndex < leftSize) {
			answer[answerIndex] = leftArray[leftIndex];
			leftIndex++;
			answerIndex++;
		}

		// check if there's remaining data in right - add it to answer
		while (rightIndex < rightSize) {
			answer[answerIndex] = rightArray[rightIndex];
			rightIndex++;
			answerIndex++;
		}

		// copy data from answer into array Left
		int i = 0;
		while (i < (leftSize + rightSize)) {
			leftArray[i] = answer[i];
			i++;
		}
	}

	void MergeSort(int *aArray, int aSize) {
		if (aSize <= 2)
			return;
		if (aSize > 2) {
			// Divide the data in half
			int halfSize = aSize / 2;

			// Sort the left side
			MergeSort(aArray, halfSize);

			// Sort the right side
			MergeSort(aArray + halfSize, halfSize);

			// Merge the data together
			merge(aArray, halfSize, aArray + halfSize, halfSize);
		}
	}
	
	/*

	int BinarySearch(int *aArray, int value) {

	}

	*/
	
};

