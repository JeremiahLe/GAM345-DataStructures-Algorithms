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
		if (aSize <= 1)
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


	int BinarySearch(int *aArray, int aSize, int value){

		int left = aArray[0]; // first element
		int right = aArray[aSize - 1]; // last element

		while (left <= right) {

			int midpoint = left + (right - left) / 2; // split the data in half

			if (aArray[midpoint] == value) // if the current middle index is the value, return index
				return midpoint;

			if (aArray[midpoint] < value) // otherwise, if value is greater than current middle index, check right side
				left = midpoint + 1;
			else
				right = midpoint - 1; // value is smaller than current middle index, check left side
		}
		return -1; // value not found
	}
	

	int Partition(int *aArray, int low, int high) {

		// 3, 6, 5, 1, 2, 4

		int pivot = aArray[high]; // set the pivot to the last element // 4
		int pivotIndex = high; // last index // 5
		int i = low; // while loop

		while (i < pivotIndex) { // while 0 < 5
 			if (aArray[i] < pivot) {
				i++; // number doesn't need to be swapped
			}
			else // current array[i] > pivot (6 > 4)
			{
				// 3 way swap
				int lastPivotIndex = pivotIndex; // keep track of where the pivot was // lastpivotindex = [5]
				int kickedToLeft = aArray[pivotIndex - 1]; // keep track of number that is replaced by pivot // int kickedtoleft = 2 ([4])

				aArray[pivotIndex - 1] = aArray[pivotIndex]; // move the pivot left one //  2 [4] = 4 [5] // 3, -6-, 5, 1, 4, [4]
				aArray[lastPivotIndex] = aArray[i]; // move the larger number to where the pivot was // 4 [5] = 6 [1] // 3, -6-, 5, 1, [4], -6-
				aArray[i] = kickedToLeft; // kick the number replaced by the pivot all the way down to where the larger number was // 6 [1] = 2 [4] // 3, 2, 5, 1, [4], -6-
				i++; // 3, 2, 5, 1, [4], 6

				// 2 way quick swap
				if (aArray[i] < aArray[i - 1]) { // if 2 < 3
					int temp = aArray[i]; // set temp to [1] (2)
					aArray[i] = aArray[i - 1]; // set [1] to [1 - 1] (3)
					aArray[i - 1] = temp; // set [0] to temp (2)
				}
			}
		}
		return pivotIndex;
	}

	void QuickSort(int *aArray, int low, int high) {
		if (low < high) { // base case

			int partIndex = Partition(aArray, low, high);

			QuickSort(aArray, partIndex + 1, high);

			QuickSort(aArray, low, partIndex - 1);

		}
	}

	/*
	void mergeAbilities(AbilityChain *first, AbilityChain *second) {

		int firstIndex = 0;
		int secondIndex = 0;

		AbilityChain* currentFirst = first;
		AbilityChain* currentSecond = second;

		while (currentFirst != nullptr && currentSecond != nullptr)
		{
			if (currentFirst->level < currentSecond->level) {
				first[firstIndex] = currentFirst->level;
				firstIndex++;
				currentFirst = currentFirst->next;
			}
			else
			{
				second[secondIndex] = currentSecond->level;
				secondIndex++;
				currentSecond = currentSecond->next;
			}

		}
	}
	*/

	/*
	void MergeAbility(int *aArray, int *Array2, int aSize, int aSize2) {

		int firstIndex = 0;
		int secondIndex = 0;

		while (firstIndex < aSize && secondIndex < aSize2) {
			if (aArray[firstIndex] < Array2[secondIndex]) {
				aArray[firstIndex] = aArray[firstIndex];
				firstIndex++;
			}
			else
			{
				aArray[firstIndex] = Array2[secondIndex];
				secondIndex++;
			}
		}
	}
	*/
	
};

