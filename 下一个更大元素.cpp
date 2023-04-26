#include<iostream>
#include<vector>
using namespace std;

struct Stack
{
	vector<int> v;

	void push(int i)
	{
		v.push_back(i);
	}

	int pop()
	{
		int ret = *(v.end() - 1);
		v.pop_back();
		return ret;
	}
	
	int show()
	{
		return *(v.end()-1);
	}
};


int main()
{
	vector<vector<int>> m;
	Stack s;
	int n1, n2;
	cin >> n1 >> n2;
	vector<int> nums1, nums2;
	int tmp = 0;
	for (int i = 0; i < n1; i++)
	{
		cin >> tmp;
		nums1.push_back(tmp);
	}
	for (int i = 0; i < n2; i++)
	{
		cin >> tmp;
		nums2.push_back(tmp);
	}
	int ret = 0;
	vector<int> element;
	for (int i = 0; i< n2; i++)
	{
		while ((s.v).size() != 0)
		{
			if (nums2[i] > s.show())
			{
				ret = s.pop();
				element.push_back(ret);
				element.push_back(nums2[i]);
				m.push_back(element);
				element.clear();
			}
			else
			{
				break;
			}
		}
		s.push(nums2[i]);
	}

	while ((s.v).size() > 0)
	{
		ret = s.pop();
		element.push_back(ret);
		element.push_back(-1);
		m.push_back(element);
		element.clear();
	}
	vector<int> aws;
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			if (m[j][0] == nums1[i])
			{
				aws.push_back(m[j][1]);
				break;
			}
		}
	}
	for (int i = 0; i < n1; i++)
	{
		cout << aws[i];
		if (i != n1 - 1)
		{
			cout << " ";
		}
	}
	return 0;
}