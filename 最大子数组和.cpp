#include<bits/stdc++.h>
using namespace std;


int main()
{
	vector<int> v;
	int t = 0;
	while (cin >> t)
	{
		v.push_back(t);
	}
	int flag = 0;
	int MaxSum = v[0];
	int tmp = 0;
	for (int i = 0; i < v.size(); i++)
	{
		tmp = max(tmp + v[i], v[i]);
		MaxSum = max(MaxSum, tmp);
	}
	cout << MaxSum;
}

