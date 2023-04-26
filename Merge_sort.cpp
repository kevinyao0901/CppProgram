#include<bits/stdc++.h>
using namespace std;

vector<int> v;

void Merge(vector<int>* v, int left, int mid,int right)
{
	vector<int> l;
	for (int i = left; i <= mid; i++)
	{
		l.push_back((*v)[i]);
	}
	l.push_back(INT_MAX);
	vector<int> r;
	for (int i = mid+1; i <=right; i++)
	{
		r.push_back((*v)[i]);
	}
	r.push_back(INT_MAX);
	int i = 0, j = 0;
	for (int m = left; m <= right; m++)
	{
		if (l[i] < r[j])
		{
			(*v)[m] = l[i];
			i++;
		}
		else
		{
			(*v)[m] = r[j];
			j++;
		}
	}
}

void Merge_sort(vector<int>* v, int left,int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		Merge_sort(v, left, mid);
		Merge_sort(v, mid + 1, right);
		Merge(v, left, mid, right);
	}
}

void print(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}

int main()
{
	int n = 0;
	cin >> n;
	int tmp = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}
	Merge_sort(&v,0,n-1);
	print(v);
	return 0;
}