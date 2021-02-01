#pragma once
namespace GAM345 {

	template<typename T>
	class Vector {
		public:

			Vector() {
				m_size = 0;
				m_capacity = 10;
				data = reinterpret_cast<T*>(new char[sizeof(T) * m_capacity]);
			}

			~Vector() {
				delete[] data;
			}

			T& operator[](int i){
				return *(data + i);
			}

			int size(){
				return m_size;
			}

			int capacity(){
				return m_capacity;
			}

			void push_back(T element) {
				if (m_size + 1 > m_capacity)
				{
					m_capacity *= 2;
					T* newVector = reinterpret_cast<T*>(new char[sizeof(T) * m_capacity]);
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

					T* newVector = reinterpret_cast<T*>(new char[sizeof(T) * newSize]);

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
						push_back(T());
					}
				}
				m_size = newSize;
			}
			

			void reserve(int newCapacity) {
				m_capacity += newCapacity;
			}

			void remove(int index) {
				T* newVector = reinterpret_cast<T*>(new char[sizeof(T) * m_capacity]);

				for (int i = 0; i < m_size; i++) {
					if (i >= index)
					{
						newVector[i] = data[i + 1];
					}
					else {
						newVector[i] = data[i];
					}
				}
					size--;
			}

			void insert(T, int index)
			{
				if (index < m_capacity)
				{

				}
				else {

				}
				size++;
			}

			void clear() {
				m_size = 0;
			}

		private:
			int m_size;
			int m_capacity;
			T* data;
	};

}