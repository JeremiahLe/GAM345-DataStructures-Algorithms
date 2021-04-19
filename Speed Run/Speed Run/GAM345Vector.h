#pragma once
	class Vector {
		public:

			Vector() {
				m_size = 0;
				m_capacity = 10;
				data = reinterpret_cast<int*>(new char[sizeof(int) * m_capacity]);
			}

			~Vector() {
				clear();
			}

			int operator[](int i){
				return *(data + i);
			}

			int size(){
				return m_size;
			}

			int capacity(){
				return m_capacity;
			}

			void push_back(int element) {
				if (m_size + 1 > m_capacity)
				{
					m_capacity *= 2;
					int *newVector = reinterpret_cast<int*>(new char[sizeof(int) * m_capacity]);
					for (int i = 0; i < m_size; i++) {
						newVector[i] = data[i];
					}

					delete[] data;

					data = newVector;
					data[m_size] = element;
				}
				else {
					data[m_size] = element;
				}
				m_size++;
			}

			bool empty(){

				// check if vector is empty, if so return true
				if (m_size == 0) {
					return true;
				}
				// else, return false
				else
					return false;
			}

			
			void resize(int newSize) {

				if (newSize < m_size) {  // if size we want to resize to is less than current size (aka shrink the vector)

					m_capacity = newSize; // set capacity to new size

					int* newVector = reinterpret_cast<int*>(new char[sizeof(int) * newSize]);

					for (int i = 0; i < newSize; i++) {
						newVector[i] = data[i];
					}

					delete[] data;
					data = newVector;
				}
				else {
					int temp = newSize - m_size;
					for (int i = 0; i < temp; i++)
					{
						push_back(newSize);
					}
				}
				m_size = newSize;
			}
			

			void reserve(int newCapacity) {
				m_capacity += newCapacity;
				data = reinterpret_cast<int*>(new char[sizeof(int) * m_capacity]);
			}

			void remove(int index) {
				int* newVector = reinterpret_cast<int*>(new char[sizeof(int) * m_capacity]);

				for (int i = 0; i < m_size; i++) {
					if (i >= index)
					{
						newVector[i] = data[i + 1];
					}
					else {
						newVector[i] = data[i];
					}
				}
					m_size--;
			}


			void insert(int element, int index)
			{
				if (index < m_capacity)
				{
					for (int i = 0; i < m_size; i++) {
						if (i >= index)
						{
							data[index] = element;
						}
					}
				}
				else {
					m_capacity *= 2;
					int* newVector = reinterpret_cast<int*>(new char[sizeof(int) * m_capacity]);
					for (int i = 0; i < m_size; i++) {
						newVector[i] = data[i];
					}

					delete[] data;

					data = newVector;
					data[index] = element;
					}
				m_size++;
			}

			bool SequentialSearch(int aValue) {
				for (int i = 0; i < m_size; i++){
					if (data[i] == aValue)
						return true;
				}
				return false;
			}

			// helper function for BinarySearch to use Data and return number
			int BinarySearch(int aValue) {
				int bsResult = BinarySearch(data, 0, m_size - 1, aValue);
				return bsResult;
			}

			int BinarySearch(int *aArray, int left, int right, int aValue) {
				if (right >= left) {
					int midpoint = left + (right - left) / 2; // Half data

					// Is the middle element the value?
					if (aArray[midpoint] == aValue)
						return midpoint;

					// Check only left
					if (aArray[midpoint] > aValue)
						return BinarySearch(aArray, left, midpoint - 1, aValue);

					// Check only right
					return BinarySearch(aArray, midpoint + 1, right, aValue);
				}

				// Element not found
				return -1;
			}

			void merge(int *aArray, int left, int midpoint, int right) {

				int leftArraySize = midpoint - left + 1;
				int rightArraySize = right - midpoint;

				int* leftArray = new int[leftArraySize];
				int* rightArray = new int[rightArraySize];

				// temp arrays data copy
				for (int i = 0; i < leftArraySize; i++) {
					leftArray[i] = aArray[left + i];
				}
				for (int j = 0; j < rightArraySize; j++) {
					rightArray[j] = aArray[midpoint + 1 + j];
				}

				int leftIndex = 0;
				int rightIndex = 0;
				int answerIndex = left;

				// Loop through both left and right at same time, taking smaller element from each side,
				// until we reach end of one the arrays

				while (leftIndex < leftArraySize && rightIndex < rightArraySize) {
					if (leftArray[leftIndex] <= rightArray[rightIndex]) {
						aArray[answerIndex] = leftArray[leftIndex];
						leftIndex++;
						answerIndex++;
					}
					else {
						aArray[answerIndex] = rightArray[rightIndex];
						rightIndex++;
						answerIndex++;
					}
				}

				// check if there's remaining data in left - add it to answer
				while (leftIndex < leftArraySize) {
					aArray[answerIndex] = leftArray[leftIndex];
					leftIndex++;
					answerIndex++;
				}

				// check if there's remaining data in right - add it to answer
				while (rightIndex < rightArraySize) {
					aArray[answerIndex] = rightArray[rightIndex];
					rightIndex++;
					answerIndex++;
				}

			}

			// Merge sort helper function
			void MergeSort() {
				MergeSort(data, 0, m_size - 1);
			}

			void MergeSort(int *aArray, int left, int right) {
				if (left >= right) {
					return; // base case
				}
				// where to split array
				int midpoint = left + (right - left) / 2;

				// call mergesort on left
				MergeSort(aArray, left, midpoint);

				// call mergesort on right
				MergeSort(aArray, midpoint + 1, right);

				// merge back together
				merge(aArray, left, midpoint, right);
			}

			// checking if the array is sorted before calling functions
			bool Sorted() {
				for (int i = 0; i < m_size - 1; i++) {
					if (data[i] > data[i + 1]) { // if last element greater than element before it, not sorted
						return false;
					}
				}
				return true;
			}

			bool Duplicates() {
				for (int i = 1; i < m_size; ++i) {
					if (data[i] == data[i - 1]) {
						return true;
					}
				}
				return false;
			}

			void clear() {
				m_size = 0;
				delete[] data;
				data = nullptr;
			}

		private:
			int m_size;
			int m_capacity;
			int* data;
	};