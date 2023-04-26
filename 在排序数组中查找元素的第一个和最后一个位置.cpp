#include<bits/stdc++.h>
using namespace std;

int Upper_bound(vector<int> v, int target)
{
	int low = 0;
	int high = v.size()-1;
	int result = -1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (v[mid] == target)
		{
			result= mid;
			low = mid + 1;
		}
		else if (v[mid] < target)
		{
			low = mid + 1;
		}
		else if (v[mid] > target)
		{
			high = mid - 1;
		}
	}
	return result;
}

int Lower_bound(vector<int> v, int target)
{
	int low = 0;
	int high = v.size() - 1;
	int result = -1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (v[mid] == target)
		{
			result = mid;
			high = mid - 1;
		}
		else if (v[mid] < target)
		{
			low = mid + 1;
		}
		else if (v[mid] > target)
		{
			high = mid - 1;
		}
	}
	return result;
}

vector<int> search_range(vector<int> v, int target)
{
	int ub = Upper_bound(v, target);
	int lb = Lower_bound(v, target);
	vector<int> ret;
	ret.push_back(lb);
	ret.push_back(ub);
	return ret;
}



int main()
{
	int n;
	cin >> n;
	int tmp;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}
	int target;
	cin >> target;
	for (int i = 0; i < 2; i++)
	{
		cout << search_range(v, target)[i]<<" ";
	}
	return 0;
}