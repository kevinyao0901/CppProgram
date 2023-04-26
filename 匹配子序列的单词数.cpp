#include<bits/stdc++.h>
using namespace std;

int Upper_bound(int* v,int size, int target)
{
	int low = 0;
	int high = size - 1;
	int result = -1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (v[mid] == target)
		{
			result = mid;
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
	if (result == -1)
	{
		return v[size - 1];
	}
	return v[result];
}

int main()
{
	string s;
	cin >> s;
	int n;
	cin >> n;
	vector<string> v;
	string tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}
	int c_index[26][5];
	memset(c_index,0, 26 * 5 * sizeof(int));
	int c_cnt[26];
	for (int i = 0; i < 26; i++)
	{
		c_cnt[i] = 0;
	}
	for (int i = 0; i < s.size(); i++)
	{
		c_index[s[i] - 'a'][c_cnt[s[i] - 'a']]=i;
		c_cnt[s[i] - 'a']++;
	}
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		int last_index = -1;
		int current_index = -1;
		bool Flag=true;
		for (int j = 0; j < v[i].size(); j++)
		{
			current_index =Upper_bound(c_index[v[i][j] - 'a'],c_cnt[v[i][j] - 'a'],last_index);
			if (current_index<=last_index)
			{
				Flag = false;
				break;
			}
			last_index = current_index;
		}
		if (Flag)
		{
			total += 1;
		}
	}
	cout<< total;
}