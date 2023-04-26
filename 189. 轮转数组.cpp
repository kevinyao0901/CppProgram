//https://www.bilibili.com/video/BV1Fh41197XF?p=6&vd_source=78fdacb8c389c051e9b03a8d8cc10381
//仅仅是类似leetcode.189但不是同一道题
#include<bits/stdc++.h>
using namespace std;

int rotate(vector<int>* nums) {
	int low = 0;
	int high = nums->size()-1;
	int n = nums->size();
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if ((*nums)[low] <= (*nums)[high])
		{
			return low;
		}
		int next = (mid + 1) % n;
		int prev = (mid + n - 1) % n;
		if ((*nums)[mid] <= (*nums)[prev] && (*nums)[mid] <= (*nums)[next])
		{
			return mid;
		}
		else if ((*nums)[mid] >= (*nums)[high])
		{
			low= mid+1;
		}
		else if ((*nums)[mid] <= (*nums)[low])
		{
			high = mid - 1;
		}
	}
	return -1;
}


int main()
{
	int n = 0;
	cin >> n;
	int tmp = 0;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}
	cout<<rotate(&v);
	return 0;
}
