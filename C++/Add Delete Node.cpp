// Github Username : rprithvi653
// Aim : To add and delete a node in linked list
// Date : 11/10/2022


#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node *next;
};

class LinkedList
{
	Node *head = NULL;

public:
	void insertAtHead(int value)
	{
		Node *node = new Node;
		node->value = value;

		if (head == NULL)
		{
			node->next = NULL;
		}
		else
		{
			node->next = head;
		}
		head = node;
	}

	void displayList()
	{
		Node *flag = head;
		while (flag != NULL)
		{
			cout << "->" << flag->value;
			flag = flag->next;
		}
		cout << endl;
	}

	void deleteNode(Node *nodeBefore)
	{
		Node *temp;
		temp = nodeBefore->next;
		nodeBefore->next = temp->next;
		delete temp;
	}

	void deleteHeadNode(){
		Node *temp;
		temp = head;
		head = head->next;
		delete temp;
	}

	void deleteNodeWithValue(int value)
	{
		Node *nodeBefore = head;

		if (nodeBefore->value == value)
		{
			deleteHeadNode();
		}
		else
		{
			while (nodeBefore->next->value != value)
			{
				nodeBefore = nodeBefore->next;
				if (nodeBefore->next == NULL)
				{
					break;
				}
			}

			if (nodeBefore->next == NULL)
			{
				cout << "Node not found" << endl;
			}
			else
			{
				deleteNode(nodeBefore);
			}
		}
	}
};

int main()
{
	int choice, value;
	LinkedList linkedList;

	while (1)
	{
		int exit = 0;
		cout << "Enter 1 to insert, 2 to display, 3 to delete and -1 to exit :" << endl;
		cin >> choice;

		switch (choice)
		{
		case -1:
			exit = 1;
			break;
		case 1:
			cout << "Enter a value :" << endl;
			cin >> value;
			linkedList.insertAtHead(value);
			break;
		case 2:
			linkedList.displayList();
			break;
		case 3:
			cout << "Enter a value to delete :" << endl;
			cin >> value;
			linkedList.deleteNodeWithValue(value);
			break;
		}

		if (exit == 1)
		{
			break;
		}
	}
	return 0;
}
