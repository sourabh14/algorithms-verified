/* Heap, Heapsort, Priority queue
*/

#include <bits/stdc++.h>

using namespace std;

void displayVec(vector<int> v) {
	cout << "Vector: ";
    for (int i=0; i<v.size(); i++) {
    	cout << v[i] << " "; 
    }
    cout << endl;
}

int main() {
	/*
	A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

	HEAP - is a complete binary tree with the property that each node, except the root, is less than or equal to its parent. i.e.
		A[i] <= A[parent] - this is called max-heap.
		- largest element in a max-heap is the root.

	Operations - (read cormen pg 154-161)
		- Max-heapify: maintaining max-heap property at i - O(log-n)
		- Build-Max-Heap: building a max-heap from array - O(n)
		- Heapsort: O(n-log-n)

	Heapsort comparison with other sort
		Although QuickSort works better in practice, the advantage of HeapSort worst case upper bound of O(nLogn).MergeSort also has upper bound as O(nLogn) and works better in practice when compared to HeapSort. But MergeSort requires O(n) extra space

	Priority queue: in addition to heap, priority queue have another operation - increase or decrease the key
		- for decreasing the key - max-heapify operation
		- for increasing the key - increase-key operation - see pg 165 

	Application
		- heapsort
		- priority-queues
		- Order statistics: find the kth smallest (or largest) element in an array.
	*/

	vector<int> v1 = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
      
    // Converting vector into a heap
    make_heap(v1.begin(), v1.end());
    cout << "The maximum element of heap is : " << v1.front() << endl;
    displayVec(v1);

    // Inserting an element in heap
    cout << endl << "push 50" << endl;
    v1.push_back(50);
    push_heap(v1.begin(), v1.end());
    displayVec(v1);

    // Pop heap - element with the highest value is moved to (last-1).
    cout << endl << "pop heap" << endl;
    pop_heap(v1.begin(), v1.end());
    displayVec(v1);
    v1.pop_back();

    // heap sort
    cout << endl << "heap sort" << endl;
    sort_heap(v1.begin(), v1.end());
    displayVec(v1);

	/* BST 
		Binary Search Tree is a node-based binary tree data structure which has the following properties:
			- The left subtree of a node contains only nodes with keys lesser than the node’s key.
			- The right subtree of a node contains only nodes with keys greater than the node’s key.
			- The left and right subtree each must also be a binary search tree.

		Operations
			- Insertion - O(log-n)
			- Searching - O(log-n)
		- Inorder traversal of BST always produces sorted output.
	*/
	return 0;
}	
