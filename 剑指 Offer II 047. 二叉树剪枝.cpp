#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* GetNewNode(int x)
{
	Node* NewNode = new Node;
	NewNode->data = x;
	NewNode->left = NULL;
	NewNode->right = NULL;
	return NewNode;
}

int TreeMinHeight(Node* root)
{
	int cnt = 0;
	while (root != 0)
	{
		root = root->right;
		cnt++;
	}
	return cnt;
}


Node* Insert(Node* root, queue<int> MyQueue)
{
	if(MyQueue.size() != 0)
	{
		Node* NewNode = GetNewNode(MyQueue.front());
		if (root == NULL)
		{
			root = NewNode;
			MyQueue.pop();
		}
		else
		{
			if (root->left == NULL)
			{
				root->left = NewNode;
				MyQueue.pop();
			}
			else if (root->right == NULL)
			{
				root->right = NewNode;
				MyQueue.pop();
			}
			else
			{
				if (TreeMinHeight(root->left) <= TreeMinHeight(root->right) && root->left->data!=-1)
				{
					root->left = Insert(root->left, MyQueue);
				}
				else
				{
					root->right = Insert(root->right, MyQueue);
				}
			}
		}
	}
	return root;
}

int TreeAllZreo(Node* root)
{
	if (root->data != -1 && root!=NULL)
	{
		if (root->data == 1)
		{
			return 0;
		}
		int left = 1, right = 1;
		if (root->left != NULL)
		{
			left = TreeAllZreo(root->left);
		}
		if (root->right != NULL)
		{
			right = TreeAllZreo(root->right);
		}
		return (left & right);
	}
}

Node* Cute(Node* root)
{
	if (TreeAllZreo(root))
	{
		return NULL;
	}
	if (root->left != NULL && root->left->data != -1)
	{
		root->left=Cute(root->left);
	}
	if (root->right != NULL && root->right->data != -1)
	{
		root->right=Cute(root->right);
	}
	return root;
}


Node* CuteTree(Node* root)
{
	if (root->left == NULL && root->right == NULL)
	{
		if (root->data == 1)
		{
			return root;
		}
		else
		{
			return NULL;
		}
	}
	if (root != NULL)
	{
		root->left=Cute(root->left);
		root->right=Cute(root->right);
	}
}



void InOrderPrint(Node* root)
{
	if (root != NULL)
	{
		InOrderPrint(root->left);
		cout << root->data << " ";
		InOrderPrint(root->right);
	}
}



int main()
{
	int n = 0;
	cin >> n;
	queue<int> MyQueue;
	int tmp = 0;
	int i = 0;
	while(i<n)
	{
		cin >> tmp;
		if (tmp != -1)
		{
			i++;
		}
		MyQueue.push(tmp);
	}
	Node* root = NULL;
	while (MyQueue.size() != 0)
	{
		root = Insert(root, MyQueue);
		MyQueue.pop();
	}
	InOrderPrint(root);
	cout << endl;

	CuteTree(root);
	InOrderPrint(root);
}