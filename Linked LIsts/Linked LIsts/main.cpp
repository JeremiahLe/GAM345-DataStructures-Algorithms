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
	for (int i = 0; i < 10; i++)
	myList.insert(newElement, 0);

	// overriding element ids
	for (int i = 0; i < myList.size(); i++)
	{
		myList[i].elementId = (myList[i].elementId + i);
	}
	
	// Print each element's id ( 1 - 10 )
	for (int i = 0; i < myList.size(); i++)
	{
		std::cout << myList[i].elementId << " ";
	}

	// get and print list size - 10
	int v_size = myList.size();
	std::cout << std::endl << "LinkedList size is: " << v_size << " ";

	// Erase element at index 0
	myList.erase(5); // erase element "6"

	std::cout << std::endl;

	// Print each element's id  -> should print all but 6
	for (int i = 0; i < myList.size(); i++)
	{
		std::cout << myList[i].elementId << " ";
	}

	// get and print list size - 9
	v_size = myList.size();
	std::cout << std::endl << "LinkedList size is: " << v_size << " ";

	// clear entire linked list
	myList.clear();

	return 0;
}
