#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void swap(vector<int> ::iterator a, vector<int> ::iterator b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	int input;
	vector<int> arr;
	while(cin >> input)
	{
		arr.push_back(input);
	} ;
	/*for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
	}*/
	vector<int> ::iterator it = arr.begin();
	while (it != arr.end())
	{
		vector<int> ::iterator tag = it;
		while (tag > arr.begin())
		{
			if (*tag < *(tag-1))
			{
				swap(*tag, *(tag - 1));
			}
			tag--;
		}
		it++;
	}
	for_each(arr.begin(), arr.end(), [](int element)
		{
			cout << element <<" ";
		});

}