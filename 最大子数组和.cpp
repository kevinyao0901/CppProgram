#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> v;
	int tmp = 0;
	while(1)
	{
		if (scanf("%d",&tmp) != EOF)
		{
			v.push_back(tmp);
		}
		else
		{
			break;
		}
	}
	tmp = 0;
	int max_sum = v[0];
	for (int i = 0; i < v.size(); i++)
	{
		tmp += v[i];
		max_sum = max(tmp, max_sum);
	}
 
	cout << max_sum;
}

/*
int max_subarr(vector<int>* nums, int size)
{
	int mid = size / 2;
	if (size == 1)
	{
		return (*nums)[0];
	}
	vector<int> lmax;
	for (int i = 0; i < mid; i++)
	{
		lmax.push_back((*nums)[i]);
	}
	vector<int> rmax;
	for (int j = mid; j < size; j++)
	{
		rmax.push_back((*nums)[j]);
	}
	int l_max = max_subarr(&lmax,mid);
	int r_max = max_subarr(&rmax,size-mid);

	int left_max = (*nums)[mid-1];
	int ltmp = 0;
	for (int i = mid - 1; i >= 0; i--)
	{
		ltmp += (*nums)[i];
		left_max = max(ltmp, left_max);
	}
	int right_max = (*nums)[mid];
	int rtmp = 0;
	for (int j = mid; j < size; j++)
	{
		rtmp += (*nums)[j];
		right_max = max(rtmp, right_max);
	}
	return max(max(l_max, r_max), left_max + right_max);
}

int main()
{
	vector<int> v;
	int tmp = 0;
	while(1)
	{
		if (scanf("%d",&tmp) != EOF)
		{
			v.push_back(tmp);
		}
		else
		{
			break;
		}
	}
	cout<<max_subarr(&v,v.size());
}
*/