#include <iostream>
#include "LinkedList.h"

// A test element
class TestElement
{
public:
	TestElement() { elementId = ++lastElementId; }
	int elementId;
private:
	static int lastElementId;
};
int TestElement::lastElementId = 0;

// Main function
int main(int argc, char **argv)
{
	// Initialize an empty linked list
	GAM345::LinkedList<TestElement> myList;

	TestElement newElement;

	// Insert test element at position 0 in List
	myList.insert(newElement, 0);

	// Print each element's id 
	for (int i = 0; i < myList.size(); i++)
	{
		std::cout << myList[i].elementId << " ";
	}

	// get and print list size
	int size = myList.size();
	std::cout << size << " ";

	// Erase element at index 0
	myList.erase(0);

	// get and print list size
	int size = myList.size();
	std::cout << size << " ";

	// Insert 10 test elements
	for (int i = 0; i < 10; i++) {
		myList.insert(newElement, 0);
	}

	// get and print list size
	int size = myList.size();
	std::cout << size << " ";

	// clear entire linked list
	myList.clear();

	return 0;
}
