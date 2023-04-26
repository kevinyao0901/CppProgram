#include<bits/stdc++.h>
using namespace std;

struct Hash_element
{
	int title;
	vector<int> index;
};


struct Hash
{
	vector<Hash_element> nums;
};

int main()
{
	int n,m,k;
	cin >> n >> m >> k;
	Hash hashtable;
	int tmp = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		int cnt = 0;
		for (int j = 0; j < hashtable.nums.size();j++)
		{
			if ((hashtable.nums[j]).title == tmp)
			{
				hashtable.nums[j].index.push_back(i);
				break;
			}
			cnt++;
		}
		if (cnt == hashtable.nums.size())
		{
			Hash_element NewHashElement;
			NewHashElement.title = tmp;
			NewHashElement.index.push_back(i);
			hashtable.nums.push_back(NewHashElement);
		}
	}
	for (int i = 0; i < m; i++)
	{
		cin >> tmp;
		for (int j = 0; j < hashtable.nums.size(); j++)
		{
			if ((hashtable.nums[j]).title == tmp)
			{
				hashtable.nums.erase(hashtable.nums.begin()+i);
				break;
			}
		}
	}
	for (int i = 0; i < k; i++)
	{
		cin >> tmp;
		int cnt = 0;
		for (int j = 0; j < hashtable.nums.size(); j++)
		{
			if ((hashtable.nums[j]).title == tmp)
			{
				cout<< (hashtable.nums[j]).index.size();
				if (i != k - 1)
				{
					cout << " ";
				}
				break;
			}
			cnt++;
		}
		if (cnt == hashtable.nums.size())
		{
			cout << 0;
			if (i != k - 1)
			{
				cout << " ";
			}
		}
	}
}