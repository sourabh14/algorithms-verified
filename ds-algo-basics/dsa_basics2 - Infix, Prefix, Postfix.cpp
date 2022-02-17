/* Infix, Postfix, Prefix
*/

#include <bits/stdc++.h>

using namespace std;

bool is_operand(char c) {
	if ((c >= 'a') && (c <= 'z'))
		return true;
	else 
		return false;
}

int prec(char c) {
	switch(c) {
		case '^' : return 3;
		break;
		case '/' : return 2;
		break;
		case '*' : return 2;
		break;
		case '+' : return 1;
		break;
		case '-' : return 1;
		break;
	}
}

void infix_to_postfix(string exp) {
	int i;
	char ch;
	list<char> st;
	for (i=0; i<exp.length(); i++) {
		ch = exp[i];

		// if ch is operand
		if (is_operand(ch))
			cout << ch;

		else if (ch == '(') {
			st.push_back(ch);
		}

		else if (ch == ')') {
			while (st.back() != '(') {
				cout << st.back();
				st.pop_back();
			}
			st.pop_back();
		}

		else {
			// if stack is empty OR precedence of ch > top of stack OR top of stack is '('
			if (st.empty()) {
				st.push_back(ch);
			}
			else if (st.back() == '(') {
				st.push_back(ch);
			}
			else if (prec(ch) > prec(st.back())) {
				st.push_back(ch);
			}
			else {
				while ((!st.empty()) && (prec(ch) <= prec(st.back()))) {
					cout << st.back();
					st.pop_back();
				}
				st.push_back(ch);
			}
		}

	}

	// pop the remaining elements
	while (!st.empty()) {
		cout << st.back();
		st.pop_back();
	}
}

int main() {
	/* Infix, Postfix, Prefix
		-Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
		-Postfix expression: The expression of the form a b op.
	
		Why postfix?
			-The compiler scans the expression either from left to right or from right to left. 
			The repeated scanning makes it very in-efficient. It is better to convert the expression to postfix(or prefix) form before evaluation.

		Infix to Postfix
			-Scan the infix expression from left to right. 
			-If the scanned character is an operand, output it. 
			-Else, 
			      1 If the precedence of the scanned operator is greater than the precedence of the operator in the stack (or the stack is empty or the stack contains a ‘(‘ ), push it. 
			      2 Else, Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator. After doing that Push the scanned operator to the stack. (If you encounter parenthesis while popping then stop there and push the scanned operator in the stack.) 
			-If the scanned character is an ‘(‘, push it to the stack. 
			-If the scanned character is an ‘)’, pop the stack and output it until a ‘(‘ is encountered, and discard both the parenthesis. 
			-Repeat steps 2-6 until infix expression is scanned. 
			-Print the output 
			-Pop and output from the stack until it is not empty.
	*/

	string ex2 = "a+b*c+d";
	string ex3 = "(a+b)*(c+d)";
	string ex4 = "a*b+c*d";
	string ex5 = "a+b+c+d";
	infix_to_postfix(ex2);
	cout << endl;
	infix_to_postfix(ex3);
	cout << endl;
	infix_to_postfix(ex4);
	cout << endl;
	infix_to_postfix(ex5);
	cout << endl;

	/* Expression tree: The expression tree is a binary tree in which each internal node corresponds to the operator and each leaf node corresponds to the operand
		-Inorder traversal of expression tree produces infix version
	*/

	return 0;
}