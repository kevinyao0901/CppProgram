#include<bits/stdc++.h>
using namespace std;

struct Hash_element
{
	int title;
	int ShowUpTime;
};


struct Hash
{
	vector<Hash_element> nums;
};

bool cmp(Hash_element a,Hash_element b)
{
	return a.ShowUpTime > b.ShowUpTime;
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
	sort(v.begin(), v.end());
	Hash hashtable;
	int flag = 0;
	while (flag < v.size())
	{
		int cnt = 1;
		while (flag < v.size() - 1 && v[flag] == v[flag + 1])
		{
			flag++;
			cnt++;
		}
		Hash_element NewElement;
		NewElement.title = v[flag];
		NewElement.ShowUpTime = cnt;
		hashtable.nums.push_back(NewElement);
		flag++;
	}
	sort(hashtable.nums.begin(), hashtable.nums.end(), cmp);
	int k = 0;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cout << hashtable.nums[i].title;
		if (i != k - 1)
		{
			cout << " ";
		}
	}
	return 0;
}