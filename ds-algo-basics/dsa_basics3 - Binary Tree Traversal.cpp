/* Binary Tree, Tree traversal,
	DFS, BFS, Tree size
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	struct Node *left, *right;

	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

void dft_inorder(Node *n) {
	if (n == NULL) 
		return;

	dft_inorder(n->left);
	printf("%d ", n->data);
	dft_inorder(n->right);
}

void dft_preorder(Node *n) {
	if (n == NULL) 
		return;

	printf("%d ", n->data);
	dft_preorder(n->left);
	dft_preorder(n->right);
}

void dft_postorder(Node *n) {
	if (n == NULL) 
		return;

	dft_postorder(n->left);
	dft_postorder(n->right);
	printf("%d ", n->data);
}

// Breadth first traversal - using queue
void bft(Node *n) {
	list<Node *> que;
	que.push_back(n);

	while (que.empty() == false) {
		//visit the first element of queue
		auto fr = que.front();
		printf("%d ", fr->data);

		// add its children to the queue
		if (fr->left != NULL)
			que.push_back(fr->left);

		if (fr->right != NULL)
			que.push_back(fr->right);

		// pop the front element
		que.pop_front();
	}
}

int treeSize(Node *n) {
	if (n == NULL)
		return 0;

	return (1 + treeSize(n->left) + treeSize(n->right));
}

int main() {
	/* A binary tree is a tree data structure in which each node has at most two children, which are referred to as the left child and the right child.

	Properties: 
		-The maximum number of nodes at level = 2^(h)
		-Maximum number of nodes = 2^(h+1) – 1. Here h is height of a tree.
		-Binary Tree with N nodes, minimum possible height or the minimum number of levels is Log2(N+1)

	*/

	struct Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);

	/* Tree structure
               1
            /     \
           2       3
          / \     / \
         4  NULL NULL NULL
        / \
     NULL NULL
    */
	
	/*
	Tree Traversal
		Binary Tree can be traversed in two ways: 
		Depth First Traversal: 
			Inorder (Left-Root-Right), 
			Preorder (Root-Left-Right) and 
			Postorder (Left-Right-Root) 
		Breadth First Traversal: Level Order Traversal 
		Time Complexity of Tree Traversal: O(n)

		- In the case of binary search trees (BST), Inorder traversal gives nodes in non-decreasing order.
		- Preorder traversal is used to create a copy of the tree. Preorder traversal is also used to get prefix expression on an expression tree.
		- Postorder traversal is used to delete the tree.

	*/

	// Depth first traversal
	printf("Inorder: ");
	dft_inorder(root);
	printf("\n");

	printf("Preorder: ");
	dft_preorder(root);
	printf("\n");

	printf("Postorder: ");
	dft_postorder(root);
	printf("\n");

	// Breadth First Traversal
	struct Node *root2 = new Node(1);
	root2->left = new Node(2);
	root2->right = new Node(3);
	root2->left->left = new Node(4);
	root2->right->left = new Node(5);
	root2->right->right = new Node(6);

	printf("Breadth first traversal : ");
	bft(root2);
	printf("\n");

	// Size of tree
	printf("Size of tree1: %d\n", treeSize(root));
	printf("Size of tree2: %d\n", treeSize(root2));

	// Construct Tree from given Inorder and Preorder traversals
	


	return 0;
}