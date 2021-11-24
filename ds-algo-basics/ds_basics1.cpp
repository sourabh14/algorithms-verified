/* Stacks, Queue, Linked List
*/

#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int> v) {
	printf("vector: ");
	for (int i=0; i<v.size(); i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}

void printList(list <int> l) {
	printf("list: ");
	for(auto it= l.begin(); it!= l.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

int main() {
	// list - doubly linked list
	list<int> l1;

	/* STACK 
		-LIFO
		-Implementation through list
		-Applications: 
			-Check for Balanced Brackets in an expression
			-Infix to Postfix
			-tree traversal
			-recursion
	*/
	printf("\nStack Implementation \n");

	// push
	for (int i=0; i<10; i++) {
		l1.push_back(i);
	}
	printList(l1);

	// top of stack
	printf("top of stack: %d\n", l1.back());

	// pop
	printf("pop\n");
	l1.pop_back();
	printList(l1);

	printf("pop\n");
	l1.pop_back();
	printList(l1);

	printf("pop\n");
	l1.pop_back();
	printList(l1);

	// QUEUE Implementation

	list<int> l2;
	printf("\nQueue Implementation \n");

	// enqueue
	for (int i=0; i<10; i++) {
		l2.push_back(i);
	}
	printList(l2);

	// head of queue
	printf("head of queue: %d\n", l2.front());
	// tail of queue
	printf("tail of queue: %d\n", l2.back());

	// dequeue
	printf("dequeue\n");
	l2.pop_front();
	printList(l2);

	printf("dequeue\n");
	l2.pop_front();
	printList(l2);

	printf("dequeue\n");
	l2.pop_front();
	printList(l2);

	return 0;
}
