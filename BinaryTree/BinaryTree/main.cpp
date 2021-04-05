#include <iostream>
#include "BinaryTree.h"

int main()
{
	BinaryTree myTree;

	for (int i = 0; i < 5; i++)
		myTree.Insert(i);
	for (int i = 20; i < 25; i++)
		myTree.Insert(i - 2);

	int value = 3;
	bool contains = myTree.Contains(value);

	if (contains == true)
		std::cout << "Binary Tree contains " << value << "\n";
	else
		std::cout << "Binary Tree does not contain " << value << "\n";

	myTree.InOrderPrint();

	myTree.DeleteNodes();
}