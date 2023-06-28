#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int> v1,vector<int>v2)
{
	return v1[1] < v2[1];
}

int main()
{
	int n = 0;
	cin >> n;
	vector<vector<int>> data;
	vector<int> v;
	int left=0,right=0;
	for (int i = 0; i < n; i++)
	{
		cin >>left>>right;
		v.push_back(left);
		v.push_back(right);
		data.push_back(v);
		v.clear();
	}
	sort(data.begin(), data.end(), cmp);
	int MaxLength = 1;
	int flag = data[0][1];
	for (int i = 1; i < n; i++)
	{
		if (flag <= data[i][0])
		{
			MaxLength++;
			flag = data[i][1];
		}
	}
	cout <<n-MaxLength;
}