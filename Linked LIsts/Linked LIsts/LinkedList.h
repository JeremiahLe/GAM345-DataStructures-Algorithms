#pragma once
namespace GAM345
{
	template<typename T>
	class LinkedList {
	
	public:

		template<typename T>
		class Node
		{
		public:
			Node() {
				//data = reinterpret_cast<T*>(new char[sizeof(Node)]);
				next = nullptr;
				//m_size++;
			}

			~Node() {
				if (next != nullptr) {

				}
			}

		
			T data;
			Node<T>* next;
		};


		LinkedList() {
			head = nullptr;
			m_size = 0;
		}

		~LinkedList(){
			clear();
		}


		void insert(T element, int aIndex) {

			if (aIndex == 0) { // insert at first position
				Node<T>* temp = new Node<T>();
				temp->data = element;
				temp->next = head;
				head = temp;
				m_size++;
			}
			else { // insert at some position
				Node<T>* temp = new Node<T>();
				temp->data = element;
				temp->next = nullptr;

				Node<T>* iterator = head;
				Node<T>* previous = nullptr;

				int i = 0;

				while (i < aIndex) {
					previous = iterator;
					iterator = iterator->next;
					i++;
				}
			
				temp->next = temp;
				m_size++;
			}
		}

		void erase(int aIndex) {
			// erase at index 0

			// index < m_size
			// iterate, are we at tail? then delete node. If not two temps (current and previous node) previous is last node; current is eventually deleted.
			// m_size--;
		}

		/*
		// iterate through list
		T& operator[](int aIndex) {
			Node* temp = new Node();
			int i = 0;
			while (i < aIndex) {
				temp = temp->next;
			}
			return *(temp->data + aIndex);
		}
		*/


		void clear() {
			// erase at index 0
			// 
		}

		int size() {
			return m_size;
		}

	private:
		Node<T>* head;
		int m_size;
	};


}
