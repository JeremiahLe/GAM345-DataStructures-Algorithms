namespace GAM345 {

	template <typename T>
	struct Node {
		T data;
		Node<T>* next;
	};

	template <typename T>
	class LinkedList {
	private:
		Node<T>* head;
	public:
		LinkedList() {
			head = nullptr;
		}

		//Inserts a new element at the given position
		void insert(T newElement, int position) {
			Node<T>* newNode = new Node<T>();
			newNode->data = newElement;
			newNode->next = NULL;

			if (position == 1) {
				newNode->next = head;
				head = newNode;
			}
			else {

				Node<T>* temp = head;
				for (int i = 1; i < position - 1; i++) {
					if (temp != NULL) {
						temp = temp->next;
					}
				}

				if (temp != NULL) {
					newNode->next = temp->next;
					temp->next = newNode;
				}
			}
		}
	};
}