#include<bits/stdc++.h>
using namespace std;

int* cnt;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

queue<Node*> MyQueue;

Node* GetNewNode(int x)
{
	Node* NewNode = new Node;
	NewNode->data = x;
	NewNode->left = NULL;
	NewNode->right = NULL;
	return NewNode;
}


Node* Insert(Node* root, int x)
{
	if (root == NULL)
	{
		Node* NewNode = GetNewNode(x);
		root = NewNode;
	}
	else
	{
		if (root->data >= x)
		{
			root->left = Insert(root->left, x);
		}
		else
		{
			root->right = Insert(root->right, x);
		}
	}
	return root;
}

Node* FindMin(Node* root)
{
	while (root->left != NULL)
	{
		root = root->left;
	}
	return root;
}

void PreOrderPrint(Node* root, int num, int* cnt)
{
	if (root != NULL)
	{
		if (*cnt <= num - 1)
		{
			cout << root->data << " ";
			(*cnt)++;
		}
		else
		{
			cout << root->data;
		}
		PreOrderPrint(root->left, num, cnt);
		PreOrderPrint(root->right, num, cnt);
	}
}


Node* BuildTree(vector<int>& InOrder, vector<int>& PostOrder, Node* root)
{
	if (PostOrder.size()==0)
	{
		return NULL;
	}
	int RootValue = PostOrder.back();
	root = GetNewNode(RootValue);
	if (PostOrder.size() == 1)
	{
		return root;
	}
	int index=0;
	while(index<InOrder.size())
	{
		if (InOrder[index] == RootValue)
		{
			break;
		}
		index++;
	}
	vector<int> LeftInOrder(InOrder.begin(), InOrder.begin() + index);
	vector<int> RightInOrder(InOrder.begin() + index+1,InOrder.end());

	PostOrder.resize(PostOrder.size() - 1);
	vector<int> LeftPostOrder(PostOrder.begin(), PostOrder.begin() + LeftInOrder.size());
	vector<int> RightPostOrder(PostOrder.begin() + LeftInOrder.size(), PostOrder.end());

	root->left = BuildTree(LeftInOrder, LeftPostOrder, root);
	root->right = BuildTree(RightInOrder, RightPostOrder, root);

	return root;
}



int main()
{
	int n = 0;
	cin >> n;
	vector<int> InOrder;
	vector<int> PostOrder;
	Node* root = NULL;
	int tmp = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		InOrder.push_back(tmp);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		PostOrder.push_back(tmp);
	}
	root=BuildTree(InOrder, PostOrder, root);
	int save = 0;
	cnt = &save;
	PreOrderPrint(root,n,cnt);
	return 0;
}