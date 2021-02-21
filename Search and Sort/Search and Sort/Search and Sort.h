#pragma once
#include <iostream>

namespace GAM345 {

	bool SequentialSearch(int *aArray, int aSize, int aValue) {
		if (aSize == 0) // faulty array?
			return false; 
		for (int i = 0; i < aSize; i++) { // find value
			if (aArray[i] == aValue) {
				std::cout << "Value " << aValue << " found!" << std::endl;
				return true;
			}
		}
			std::cout << "Value " << aValue << " not found!" << std::endl;
			return false;
	}

	void InsertionSort(int *aArray, int aSize) {
		// pass-by value
	}

};

