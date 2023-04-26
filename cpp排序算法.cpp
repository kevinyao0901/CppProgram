#include<bits/stdc++.h>
using namespace std;

void print(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}

vector<int> v;

//Selection_sort
void Selection_sort(vector<int>* v)
{
	for (int i = 0; i < v->size()-1; i++)
	{
		int j = i+1;
		while (j > 0 && (*v)[j] < (*v)[j - 1])
		{
			swap((*v)[j], (*v)[j - 1]);
			j--;
		}
	}
}

//Bubble_sort
void Bubble_sort(vector<int>* v)
{
	for (int i = 0; i < v->size(); i++)
	{
		int flag = 0;
		for (int j = 0; j < v->size() - i-1; j++)
		{
			if ((*v)[j] > (*v)[j + 1])
			{
				swap((*v)[j], (*v)[j+1]);
				flag++;
			}
		}
		if (flag == 0)
		{
			return;
		}
	}
}

//Insert_Sort
void Insert_sort(vector<int>* v)
{
	if (v->size() == 1)
	{
		return;
	}
	for (int i = 0; i < v->size(); i++)
	{
		int min = (*v)[i];
		int min_index = i;
		for (int j = i + 1; j < v->size(); j++)
		{
			if ((*v)[j] < min)
			{
				min = (*v)[j];
				min_index = j;
			}
		}
		swap((*v)[i], (*v)[min_index]);
	}
}

//Merge_sort
void Merge(vector<int>* v, int left, int mid, int right)
{
	vector<int> left_arr;
	for (int i = left; i <= mid; i++)
	{
		left_arr.push_back((*v)[i]);
	}
	left_arr.push_back(INT_MAX);
	vector<int> right_arr;
	for (int i = mid+1; i <= right; i++)
	{
		right_arr.push_back((*v)[i]);
	}
	right_arr.push_back(INT_MAX);
	int i = 0, j = 0;
	for(int m=left;m<=right;m++)
	{
		if (left_arr[i] < right_arr[j])
		{
			(*v)[m] = left_arr[i];
			i++;
		}
		else
		{
			(*v)[m] = right_arr[j];
			j++;
		}
	}
}

void Merge_sort(vector<int>* v,int left,int right)
{
	if (left<right)
	{
		int mid = (left + right) / 2;
		Merge_sort(v, left, mid);
		Merge_sort(v, mid + 1, right);
		Merge(v, left, mid, right);
	}
}


//Quick_sort
void Quick_sort(vector<int>* v,int start,int end)
{
	if (start < end)
	{
		int pivot = (*v)[end];
		int divide = start;
		int p = start;
		while (p < end)
		{
			if ((*v)[p] < pivot)
			{
				swap((*v)[p], (*v)[divide]);
				divide++;
			}
			p++;
		}
		swap((*v)[divide], (*v)[end]);
		Quick_sort(v, start, divide - 1);
		Quick_sort(v, divide + 1, end);
	}
}

int main()
{
	int n;
	cin >> n;
	int tmp = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}
	//Selection_sort(&v);
	//Insert_sort(&v);
	//Bubble_sort(&v);
	Merge_sort(&v, 0, n - 1);
	//Quick_sort(&v, 0, n - 1);
	print(v);
}