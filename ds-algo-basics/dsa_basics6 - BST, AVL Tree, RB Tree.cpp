/* 
	Binary Search Tree, AVL Trees, Red black tree
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	/* BST
		-The left "subtree" (i.e. every node of left subtree) of a node contains only nodes with keys less than or equal to the node’s key.
		-The right subtree of a node contains only nodes with keys greater than or equal to the node’s key.
		-The left and right subtree each must also be a binary search tree. 

	Application
		- operations like search, minimum and maximum can be done fast.
		- inorder in a bst gives sorted list

	Operations - O(log-n) - the time complexity will depend on whether tree is balanced or not. if it is skewed then it may take more time - see cormen pg 290
		- search
		- Minimum/ Maximum
		- Successor/ Predecessor
		- Insertion
			A new key is always inserted at the leaf. We start searching a key from the root until we hit a leaf node. Once a leaf node is found, the new node is added as a child of the leaf node. 
		- Deletion - three cases
			1. Node to be deleted is the leaf: Simply remove from the tree. 
			2. Node to be deleted has only one child: Copy the child to the node and delete the child 
			3. Node to be deleted has two children: Find inorder successor of the node. Copy contents of the inorder successor to the node and delete the inorder successor. Note that inorder predecessor can also be used. 

	BST vs Hash Tables
		Advantages of hash table: supports following operations in Θ(1) time. 1) Search 2) Insert 3) Delete
		Advantages of BST
			-We can get all keys in sorted order by just doing Inorder Traversal of BST. This is not a natural operation in Hash Tables
			-Doing order statistics, finding closest lower and greater elements, doing range queries are easy to do with BSTs. Like sorting, these operations are not a natural operation with Hash Tables.
			-BSTs are easy to implement compared to hashing, we can easily implement our own customized BST. 
	*/

	/* AVL Trees
		AVL tree is a self-balancing Binary Search Tree (BST) where the difference between heights of left and right subtrees cannot be more than one for all nodes.
		operations that can be performed to re-balance a BST without violating the BST property (keys(left) < key(root) < keys(right)). 
			1) Left Rotation 
			2) Right Rotation

		They are strictly height balanced trees.

		Insertion
			1) Perform standard BST insert for w. 
			2) Starting from w, travel up and find the first unbalanced node. Let z be the first unbalanced node, y be the child of z that comes on the path from w to z and x be the grandchild of z that comes on the path from w to z. 
			3) Re-balance the tree by performing appropriate rotations on the subtree rooted with z. There can be 4 possible cases that needs to be handled as x, y and z can be arranged in 4 ways. Following are the possible 4 arrangements: 
				a) y is left child of z and x is left child of y (Left Left Case) 
				b) y is left child of z and x is right child of y (Left Right Case) 
				c) y is right child of z and x is right child of y (Right Right Case) 
				d) y is right child of z and x is left child of y (Right Left Case)

		https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
	*/
				

	/* Red Black Trees
		A red-black tree is a kind of self-balancing binary search tree where each node has an extra bit, and that bit is often interpreted as the colour (red or black). These colours are used to ensure that the tree remains balanced during insertions and deletions.

		It is roughly height balanced tree. AVL tree is strictly height balance tree

		Why Red-Black Trees?
			Most of the BST operations (e.g., search, max, min, insert, delete.. etc) take O(h) time where h is the height of the BST. The cost of these operations may become O(n) for a skewed Binary tree. 
			If we make sure that the height of the tree remains O(log n) after every insertion and deletion, then we can guarantee an upper bound of O(log n) for all these operations. The height of a Red-Black tree is always O(log n) where n is the number of nodes in the tree. 
	
		Property of RBT: 
			-Every node has a colour either red or black.
			-The root of the tree is always black.
			-There are no two adjacent red nodes (A red node cannot have a red parent or red child).
			-Every path from a node (including root) to any of its descendants NULL nodes has the same number of black nodes.

		Insertion: https://youtu.be/qA02XWRTBdw?list=PLdo5W4Nhv31bbKJzrsKfMpo_grxuLl8LU

		Application:
			-Most of the self-balancing BST library functions like map and set in C++ (OR TreeSet and TreeMap in Java) use Red-Black Tree.
			-It is used to implement CPU Scheduling Linux. Completely Fair Scheduler uses it.

		AVL Tree vs RBT
			The AVL trees are more balanced compared to Red-Black Trees, but they may cause more rotations during insertion and deletion. So if your application involves many frequent insertions and deletions, then Red Black trees should be preferred. 
			AVL trees are subset of RBT. If we color AVL trees acc to rules, it will be a RBT.
	*/



	return 0;
}