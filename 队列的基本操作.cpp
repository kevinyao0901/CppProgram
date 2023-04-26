#include<bits/stdc++.h>

using namespace std;

struct Queue
{
	vector<int> v;

	
};

void Enqueue(Queue* q, int i)
{
	(q->v).push_back(i);
}
void Dequeue(Queue* q)
{
	(q->v).erase((q->v).begin());
}
void print(Queue* q)
{
	for (int i = 0; i < (q->v).size(); i++)
	{
		cout << (q->v)[i];
		if (i != (q->v).size() - 1)
		{
			cout << " ";
		}
	}
}


int main()
{
	int n = 0;
	cin >> n;
	Queue q;
	int tmp = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		Enqueue(&q,tmp);
	}
	print(&q);
	int r = 0;
	cin >> r;
	if (r > n)
	{
		return 0;
	}
	for (int i = 0; i < r; i++)
	{
		Dequeue(&q);
	}
	print(&q);
	return 0;
}



