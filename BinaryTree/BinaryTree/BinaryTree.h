#pragma once

class BinaryTree
{
public:

	// Constructor
	BinaryTree();

	// Remember to properly delete any allocated memory
	~BinaryTree();

	// Insert a new node into the tree
	void Insert(int aValue);
	
	// Check if the tree contains the given value
	bool Contains(int aValue);

	// Print all of the elements in the Binary Tree, in order
	void InOrderPrint();
	
	// Delete all nodes in a binary tree
	void DeleteNodes();


private:

	struct BTreeNode
	{
		BTreeNode *left;
		BTreeNode *right;
		int value;
	};

	// private helper function for InOrderPrint
	void InOrderPrint(BTreeNode* node);

	BTreeNode *mRoot;
	int size;
};