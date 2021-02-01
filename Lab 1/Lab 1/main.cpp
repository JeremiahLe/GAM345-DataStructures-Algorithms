#include <iostream>
#include "GAM345Vector.h"

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
	// Initialize an empty vector
	GAM345::Vector<TestElement> testVector;

	// Resize the vector to contain 5 elements
	testVector.resize(5);

	// Print each element's id (should print 1 2 3 4 5 )
	for (int i = 0; i < testVector.size(); i++)
	{
		std::cout << testVector[i].elementId << " ";
	}

	// Increment each element's id by 1
	for (int i = 0; i < testVector.size(); i++)
	{
		testVector[i].elementId++;
	}

	// Print each element's id (should print 2 3 4 5 6 )
	for (int i = 0; i < testVector.size(); i++)
	{
		std::cout << testVector[i].elementId << std::endl;
	}

	// Change the "capacity" of the vector 20
	testVector.reserve(10);
	// Reduce the size to 2
	testVector.resize(2);

	// Print each element's id (should print 2 3 )
	for (int i = 0; i < testVector.size(); i++)
	{
		std::cout << testVector[i].elementId << std::endl;
	}

	// Add twenty new elements to the vector
	for (int i = 0; i < 20; i++)
	{
		testVector.push_back(TestElement());
	}

	std::cout << "Break" << std::endl; //**

	// Print each element's id
	for (int i = 0; i < testVector.size(); i++)
	{
		std::cout << testVector[i].elementId << std::endl;
	}

	// Check if the vector is currently empty
	bool isEmpty = testVector.empty();

	// Get the current capacity
	int capacity = testVector.capacity();

	// This function should remove the element at the given position
	testVector.remove(0);

	std::cout << "Break" << std::endl; //**

	// Print each element's id
	for (int i = 0; i < testVector.size(); i++)
	{
		std::cout << testVector[i].elementId << std::endl;
	}

	TestElement newElement;
	// This function should insert newElement at position 5 in the array
	testVector.insert(newElement, 5);

	std::cout << "Break" << std::endl; //**

	// Print each element's id **
	for (int i = 0; i < testVector.size(); i++)
	{
		std::cout << testVector[i].elementId << std::endl;
	}

	// Finally, clear the vector
	testVector.clear();

	return 0;
}
