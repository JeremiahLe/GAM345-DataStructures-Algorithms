// BinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BinaryTree.h"
#include <string.h>

using namespace std;

BinaryTree::BinaryTree() {
	BTreeNode *node = new BTreeNode;
	mRoot = node;
	node->value = 10;
	node->left = nullptr;
	node->right = nullptr;
	size++;
}

void BinaryTree::DeleteNodes() {

	BTreeNode *current = mRoot;

	while (1) {
		if (current != NULL) {
			current = current->left; // go down left
			if (current == NULL)
				delete current; // delete last
			else
			{
				current = current->right; // go down right
				if (current == NULL)
					delete current; // delete last
			}
		}
		else {
			delete current; // delete mRoot
			delete mRoot;
			return; 
		}
	}
}

BinaryTree::~BinaryTree() {
	DeleteNodes();
}

void BinaryTree::Insert(int aValue) {

	BTreeNode *tempNode = new BTreeNode;
	BTreeNode *current;
	BTreeNode *parent;

	tempNode->value = aValue;
	tempNode->left = NULL;
	tempNode->right = NULL;

	// starting with empty tree
	if (mRoot == NULL) {
		mRoot = tempNode;
	}
	else {
		current = mRoot;
		parent = NULL;

		while (1) {
			parent = current;

			if (aValue < parent->value) {
				current = current->left; // go down left tree

				if (current == NULL) {
					parent->left = tempNode;
					size++; // end of left tree
					return;
				}
			}  
			else {
				current = current->right; // go down right tree

				if (current == NULL) {
					parent->right = tempNode; 
					size++; // end of right tree
					return;
				}
			}
		}
	}
}

bool BinaryTree::Contains(int aValue) {

	BTreeNode *current = mRoot;

	while (current->value != aValue) {

		if (current != NULL) {

			if (current->value > aValue) {
				current = current->left; // Search left tree
			}  
			else {
				current = current->right; // else, Search right tree
			}

			// Value not found
			if (current == NULL) {
				return false;
			}
		}
	}

	return true; // value found
}

void BinaryTree::InOrderPrint() {

	BTreeNode *node = mRoot; // start with root node
	InOrderPrint(node); // call helper function

}

void BinaryTree::InOrderPrint(BTreeNode* node) {
	
	// base case
	if (node == NULL)
		return;

	InOrderPrint(node->left); // print all left nodes

	if (node != NULL) {
		printf("%d ", node->value); // if the node is not empty, print value
	}

	InOrderPrint(node->right); // move on to right nodes
		
}
