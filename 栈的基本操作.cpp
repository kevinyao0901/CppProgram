#include<bits/stdc++.h>
using namespace std;

struct MyNode
{
	int data;
	MyNode* next;
};

MyNode* head = NULL;

void AddNode(int i)
{
	MyNode* NewNode = new MyNode;
	NewNode->data = i;
	NewNode->next = head;
	head= NewNode;
}

void MyPop()
{
	head = head->next;
}

void Print()
{
	MyNode* flag = head;
	if (flag == NULL)
	{
		return;
	}
	while (flag != NULL)
	{
		cout << flag->data<<" ";
		flag = flag->next;
	}
}

void ReverseLinkNode()
{
	MyNode* currentelement=head;
	MyNode* preelement=NULL;
	MyNode* nextelement;
	while (currentelement != NULL)
	{
		nextelement = currentelement->next;
		currentelement->next = preelement;
		preelement = currentelement;
		currentelement=nextelement;
	}
	head = preelement;
}


int main()
{
	int n;
	cin >> n;
	int tmp = 0;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
		AddNode(v[i]);
	}
	int x = 0;
	cin >> x;
	if (x > n)
	{
		x = n;
	}
	for (int i = 0; i < x; i++)
	{
		MyPop();
	}
	ReverseLinkNode();
	Print();
}