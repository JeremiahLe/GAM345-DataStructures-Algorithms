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

		private:
			T* data;
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

			if (m_size == 0) { // insert with nothing
				head->data = element; // set pointer of head to first element
				m_size++;
			}
			else if (aIndex == 0) { // insert at first position
				Node* temp = new Node();
				temp->data = element;
				temp->next = head;
				head = temp;
				m_size++;
			}
			else {

				int i = 0;

				while (i < aIndex) 
				{
					temp = temp->next;
					i++;
				}

				Node* temp = new Node();
				temp->data = element;
				temp->next = head;
				head = temp;
				m_size++;

			}
		}

		void erase(int aIndex) {
			// erase at index 0

			// index < m_size
			// iterate, are we at tail? then delete node. If not two temps (current and previous node) previous is last node; current is eventually deleted.
			// m_size--;
		}

		// iterate through list
		T&operator[](int aIndex) {
			return *(data + aIndex);
		}


		void clear() {
			// erase at index 0
			// 
		}

		int size() {
			return m_size();
		}

	private:
		Node<T>* head;
		int m_size;

	};


}
