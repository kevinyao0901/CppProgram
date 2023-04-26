#include<bits/stdc++.h>
using namespace std;

int Upper_bound(vector<int>* v,int start,int end,int target)
{
	int mid = start + (end - start) / 2;
	int result = -1;
	while (start <= end)
	{
		mid = start + (end - start) / 2;
		if ((*v)[mid] == target)
		{
			result = mid;
			start = mid + 1;
		}
		else if ((*v)[mid] < target)
		{
			start = mid+1;
		}
		else if((*v)[mid] > target)
		{
			end = mid - 1;
		}
	}
	return result;
}

int Lower_bound(vector<int>* v,int start,int end,int target)
{
	int mid = start + (end - start) / 2;
	int result = -1;
	while (start <= end)
	{
		mid = start + (end - start) / 2;
		if ((*v)[mid] == target)
		{
			result = mid;
			end = mid - 1;
		}
		else if ((*v)[mid] < target)
		{
			start = mid + 1;
		}
		else if((*v)[mid] > target)
		{
			end = mid - 1;
		}
	}
	return result;
}

int u_bound(vector<int>* v, int start, int end, int target)
{
	int mid = start + (end - start) / 2;
	while (start<end)
	{
		mid = start + (end - start) / 2;
		if ((*v)[mid] <= target)
		{
			start = mid + 1;
		}
		else
		{
			end = mid;
		}
	}
	return start;
}


int l_bound(vector<int>* v, int start, int end, int target)
{
	int mid = start + (end - start) / 2;
	while (start < end)
	{
		mid = start + (end - start) / 2;
		if ((*v)[mid] < target)
		{
			start = mid + 1;
		}
		else
		{
			end = mid;
		}
	}
	return start;
}

int find_count(vector<int>* v, int start, int end, int target)
{
	int ub = Upper_bound(v, start, end, target);
	if (ub == -1)
	{
		return -1;
	}
	int lb = Lower_bound(v, start, end, target);
	return ub - lb + 1;
}


//l_bound 返回数组中第一个不小于目标值的元素的iterator，（第一个 >= target的数）
//u_bound 返回数组中第一个大于目标值的元素的iterator， （第一个 > target的数）

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
	int target = 0;
	cin >> target;
	cout << endl;
	cout<<Upper_bound(&v,0,v.size()-1,target)<<endl;
	cout << u_bound(&v, 0, v.size() - 1, target) << endl;
	cout << "std upper_bound:" << upper_bound(v.begin(), v.end(), target) - v.begin()<<endl;
	cout << Lower_bound(&v, 0, v.size() - 1, target)<<endl;
	cout << l_bound(&v, 0, v.size() - 1, target) << endl;
	cout << "std lower_bound:" << lower_bound(v.begin(), v.end(), target)-v.begin() << endl;
	cout << "final_count:" << find_count(&v, 0, v.size() - 1, target);
	/*头文件：#include<algorithm>
	upper_bound(begin, end, num)：从数组的begin位置到end - 1位置二分查找第一个大于num的数字，
	找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin, 得到找到数字在数组中的下标。
	lower_bound(begin, end, num)：从数组的begin位置到end - 1位置二分查找第一个大于或等于num的数字，
	找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin, 得到找到数字在数组中的下标。*/

}