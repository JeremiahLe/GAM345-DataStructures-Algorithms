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
		for (int i = 0; i < aSize; i++) {
			while (index < aSize) {
				if (aArray[index] < aArray[index - 1]) { // is second index smaller than first? if yes than swap // 5, 2, 4, 3, 6 // is 2 < 5? yes, 
					int temp = aArray[index - 1]; // value to be moved over to the left
					aArray[index - 1] = aArray[index]; // left value to right value
					aArray[index] = temp; // right value to left value
					index--; // move back
				}
				else
					index++;
			}
		}
	}

};

