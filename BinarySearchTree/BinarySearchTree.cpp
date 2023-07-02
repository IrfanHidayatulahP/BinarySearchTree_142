#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	string info;
	Node* leftchild;
	Node* rightchild;

	//constructor for the node class
	Node(string i, Node* l, Node* r) {
		info = i;
		leftchild = l;
		rightchild = r;
	}
};

class BinaryTree {
public:
	Node* ROOT;

	BinaryTree() {
		ROOT = NULL;													//Initializing ROOT to NULL
	}

	void insert(string element) {										//Insert a node in the binary search tree
		Node* newNode = new Node(element, NULL, NULL);					// Allocate memory for the new node
		newNode->info = element;										// Assign value to the data field of the new node
		newNode->leftchild = NULL;										// Make the left child of the new node point to NULL
		newNode->rightchild = NULL;										// Make the right child of the new node point to NULL
		
		Node* parent = NULL;
		Node* currentNode = NULL;
		search(element, parent, newNode);								// Locate the node which will be the parent of the node to be inserted

		if (parent == NULL) {												// if the parent is NULL (tree is empty)
			ROOT = newNode;												//mark the new node as ROOT
			return;
		}

		if (element < parent->info) {
			parent->leftchild = newNode;								//make the leftchild of the parent point to the new node
		}
		else if (element > parent->info) {								//if the value in the data field of the newnode is greater than that of the parent
			parent->rightchild = newNode;								//make the leftchild of the parent point to the new node
		}
	}


	void search(string element, Node*& parent, Node*& currentNode) {
		currentNode = ROOT;
		parent = NULL;
		while ((currentNode != NULL) && (currentNode->info != element)) {
			parent = currentNode;
			if (element < currentNode->info)
				currentNode = currentNode->leftchild;
			else
				currentNode = currentNode->rightchild;
		}
	}

	void inorder(Node* ptr) {
		if (ROOT == NULL) {
			cout << "Tree is Empty" << endl;
			return;
		}
		if (ptr != NULL) {
			inorder(ptr->leftchild);
			cout << ptr->info << "	";
			inorder(ptr->rightchild);
		}
	}

	void preorder(Node* ptr) {
		if (ROOT == NULL) {
			cout << "Tree is Empty" << endl;
			return;
		}
		if (ptr != NULL) {
			cout << ptr->info << " ";
			preorder(ptr->leftchild);
			preorder(ptr->rightchild);
		}
	}

	void postorder(Node* ptr) {
		if (ROOT == NULL) {
			cout << "Tree is Empty" << endl;
			return;
		}
		if (ptr != NULL) {
			postorder(ptr->leftchild);
			postorder(ptr->rightchild);
			cout << ptr->info << " ";
		}
	}
};


int main() {
	BinaryTree obj;
	while (true) {
		cout << "\nMenu" << endl;
		cout << "1. Implement insert operation" << endl;
		cout << "2. Perform inorder traversal" << endl;
		cout << "3. Perform preorder traversal" << endl;
		cout << "4. Perform postorder traversal" << endl;
		cout << "5. Exit" << endl;
		cout << "\nEnter your choice (1-5) : ";

		char ch;
		cin >> ch;
		cout << endl;

		switch (ch) {
		case '1': {
			cout << "Enter a word: ";
			string word;
			cin >> word;
			obj.insert(word);
			break;
		}
		case '2': {
			obj.inorder(obj.ROOT);
			break;
		}
		case '3': {
			obj.preorder(obj.ROOT);
			break;
		}
		case '4': {
			obj.postorder(obj.ROOT);
			break;
		}
		}
	}
}

