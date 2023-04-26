#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* head = NULL;

void add(int x)
{
	Node* n = new Node;
	n->data = x;
	n->next = NULL;
	if (head != NULL)
	{
		n->next = head;
	}
	head = n;
}

void print()
{
	Node* flag = head;
	while (flag != NULL)
	{
		cout << flag->data;
		if (flag->next != NULL)
		{
			cout << " ";
		}
		flag = flag->next;
	}
}

int main()
{
	int length1, length2;
	cin >> length1;
	cin >> length2;
	int tmp = 0;
	for (int i = 0; i < length1; i++)
	{
		cin >> tmp;
		add(tmp);
	}
	Node* head1 = head;
	head = NULL;
	for (int i = 0; i < length2; i++)
	{
		cin >> tmp;
		add(tmp);
	}
	Node* head2 = head;
	head = NULL;
	while (head1 != NULL && head2 != NULL)
	{
		if (head1->data > head2->data)
		{
			add(head1->data);
			head1 = head1->next;
		}
		else 
		{
			add(head2->data);
			head2 = head2->next;
		}
	}
	while (head1 != NULL)
	{
		add(head1->data);
		head1 = head1->next;
	}
	while (head2 != NULL)
	{
		add(head2->data);
		head2 = head2->next;
	}
	print();
	return 0;
}