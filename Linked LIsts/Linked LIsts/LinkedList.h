#pragma once
namespace GAM345
{
	template<typename T>
	class LinkedList {
	
	public:

		class Node
		{
		public:
			Node() {
				data = reinterpret_cast<T*>(new char[sizeof(Node)]);
				m_size++;
			}

		private:
			T* data;
			Node* next;
		};


		LinkedList() {
			Node* temp = new Node();
			temp->data = 2;
			temp->next = NULL;
			head = temp;
		}

		~LinkedList(){

		}


		void insert(T element, int aIndex) {
			if (aIndex < m_size) {


			}
			if (head == NULL) {


			}

			Node* temp = new Node(); // create new node
			temp->data = element; // set node's data to variable
			temp->next = head; // set node's link to current head
			head = temp; // set head node to newly created node
		}

		void erase(int aIndex) {

		}

		T&operator[](int aIndex) {
			return *(data + aIndex);
		}

		void clear() {

		}

		int size() {
			return m_size();
		}

	private:
		Node* head;
		int m_size;

	};
}
