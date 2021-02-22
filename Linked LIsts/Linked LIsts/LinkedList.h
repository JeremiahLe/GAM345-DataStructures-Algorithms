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
					//
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

			Node<T>* temp = head;
			Node<T>* previous = nullptr;

			if (aIndex == 0) {
				head = temp->next;   
				free(temp);          
				return;
			}

			for (int i = 0; temp != NULL && i < aIndex - 1; i++)
				temp = temp->next;

			if (temp == NULL || temp->next == NULL)
				return;

			Node<T> *next = temp->next->next;

			free(temp->next); 
			temp->next = next;
			m_size--;

			// index < m_size
			// iterate, are we at tail? then delete node. If not two temps (current and previous node) previous is last node; current is eventually deleted.
			// m_size--;
		}

		T& operator[](int aIndex) {
			Node<T>* current = head;

			while (current != nullptr && aIndex-- > 0)
			{
				current = current->next;
			}
			return (current->data);
		}
		

		void clear() {
			int i = 0;
			while (i < m_size) {
				erase(i);
				i++;
			}
		}

		int size() {
			return m_size;
		}

		T returnHead() {
			return head;
		}

	private:
		Node<T>* head;
		int m_size;
	};


}
