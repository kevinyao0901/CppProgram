#include<bits/stdc++.h>
using namespace std;

void print(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}

void sort_find(vector<int> &v, int left, int right,int target)
{
	if (left < right)
	{
		int pivot = v[right];
		int i = left, j = left;
		while (j < right)
		{
			if (v[j] < pivot)
			{
				swap(v[i], v[j]);
				i++;
			}
			j++;
		}
		swap(v[i], v[right]);
		if (target > i)
		{
			sort_find(v, left, i - 1, target);
		}
		if (target < i)
		{
			sort_find(v, i + 1, right, target);
		}
		if (target == i)
		{
			return;
		}
	}
}


int main()
{
	vector<int> v;
	int tmp = 0;
	int n = 0;
	while(scanf("%d",&tmp)>0)
	{
		v.push_back(tmp);
	}
	n = v[v.size() - 1];
	v.pop_back();
	sort_find(v,0,v.size()-1,n);
	print(v);
	cout << endl<<v[v.size()-n];
}