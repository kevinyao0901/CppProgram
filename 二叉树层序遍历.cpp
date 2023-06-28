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


Node* Delete(Node* root, int x)
{
	if (root->data != x)
	{
		if (root->data >= x)
		{
			root->left = Delete(root->left, x);
			return root;
		}
		else
		{
			root->right = Delete(root->right, x);
			return root;
		}
	}
	if (root->left == NULL && root->right == NULL)
	{
		return NULL;
	}
	if ((root->left == NULL) || (root->right == NULL))
	{
		if (root->left == NULL)
		{
			return root->right;
		}
		else
		{
			return root->left;
		}
	}
	else
	{
		Node* Save;
		Save = FindMin(root->right);
		root->data = Save->data;
		root->right = Delete(root->right, root->data);
		return root;
	}
}

void BfsPrint(Node* root, int* cnt)
{
	while (!MyQueue.empty())
	{
		if (MyQueue.size() > 1)
		{
			cout << " " << (MyQueue.front())->data;
			(*cnt)++;
		}
		else
		{
			if (*cnt == 0)
			{
				cout << (MyQueue.front())->data;
				(*cnt)++;
			}
			else
			{
				cout << " " << (MyQueue.front())->data;
			}
		}
		if (root->left != NULL)
		{
			MyQueue.push(root->left);
		}
		if (root->right != NULL)
		{
			MyQueue.push(root->right);
		}
		MyQueue.pop();
		if (!MyQueue.empty())
		{
			BfsPrint(MyQueue.front(), cnt);
		}
	}
}

int main()
{
	Node* root = NULL;
	int tmp = 0;
	while(cin>>tmp)
	{
		root = Insert(root, tmp);
	}
	int save = 0;
	cnt = &save;
	MyQueue.push(root);
	BfsPrint(root, cnt);
}

