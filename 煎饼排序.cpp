#include<bits/stdc++.h>
using namespace std;

void print(vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i]<<" ";
	}
}


int MaxoftheArr(vector<int> v,int len)
{
	int flag = 0;
	int Max = 0;
	int max_index = 0;
	while (flag<len)
	{
		if (v[flag] > Max)
		{
			Max = v[flag];
			max_index = flag;
		}
		flag++;
	}
	return max_index+1;
}

void Pancakesort(vector<int>& v,vector<int> &ret,int len)
{
	if (len > 1)
	{
		int index = MaxoftheArr(v,len);
		if (index != 1 && index != v.size())
		{
			ret.push_back(index);
			reverse(v.begin(), v.begin() + index);
		}
		if (index != v.size())
		{
			ret.push_back(len);
			reverse(v.begin(), v.end());
		}
		len--;
		return Pancakesort(v, ret, len);
	}
}


int main()
{
	vector<int> v;
	vector<int> ret;
	int tmp = 0;
	while (scanf("%d", &tmp) > 0)
	{
		v.push_back(tmp);
	}
	int len = v.size();
	int cnt = 0;
	for (int i = 0; i < v.size()-1; i++)
	{
		if (v[i] < v[i + 1])
		{
			cnt++;
		}
	}
	if (cnt == v.size() - 1)
	{
		return 0;
	}
	Pancakesort(v, ret, len);
	print(ret);
	return 0;
}