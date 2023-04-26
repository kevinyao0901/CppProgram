#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* prev;
};

Node* head = NULL;

Node* GetNewNode(int x)
{
	Node* n = new Node;
	n->data = x;
	n->prev = NULL;
	n->next = NULL;
	return n;
}

void InsertAtHead(int x)
{
	Node* n=GetNewNode(x);
	if (head == NULL)
	{
		head = n;
		return;
	}
	head->prev = n;
	n->next = head;
	head = n;
	
}

void del(int x)
{
	Node* flag = head;
	while (flag->next != NULL)
	{
		if ((flag->next)->data != x)
		{
			flag = flag->next;
		}
		else
		{
			break;
		}
	}
	flag = flag->next;
	if (flag->prev != NULL)
	{
		flag->prev->next = flag->next;
	}
	else
	{
		head = flag->next;
	}
	if (flag->next != NULL)
	{
		flag->next->prev = flag->prev;
	}
}

int find(int y)
{
	Node* flag = head;
	while (flag->next!=NULL)
	{
		flag = flag->next;
	}
	Node* tail=flag;
	while (tail->prev != NULL)
	{
		if (flag != NULL && flag->data != y )
		{
			flag = flag->prev;
		}
		else
		{
			break;
		}
	}
	if (flag == NULL || flag->next==NULL)
	{
		return -1;
	}
	return flag->next->data;
}

void print()
{
	Node* temp = head;
	if (temp == NULL)
	{
		return;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	while (temp != NULL)
	{
		cout << temp->data;
		if (temp->prev != NULL)
		{
			cout << " ";
		}
		temp = temp->prev;
	}
	cout << endl;
}

int main()
{
	int n = 0;
	cin >> n;
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		InsertAtHead(t);
	}
	print();
	cout << endl;
	int x = 0;
	cin >> x;
	del(x);
	print();
	cout << endl;
	int y=0;
	cin >> y;
	cout<<find(y);
}