#include<bits/stdc++.h>
using namespace std;
int n = 0;

int PathCount(vector<vector<int>> matrix,vector<int> target,int cnt)
{
	vector<int> t;
	for (int i = 0; i < target.size(); i++)
	{
		for (int j = 0; j < n-1; j++)
		{
			if (matrix[target[i]][j] == 1)
			{
				if (j == 0)
				{
					cnt += 1;
				}
				else
				{
					t.push_back(j);
				}
			}
		}
		if (t.size() > 0)
		{
			cnt = PathCount(matrix, t, cnt);
		}
		t.clear();
	}
	return cnt;
}

int main()
{
	cin >> n;
	vector<vector<int>> matrix;
	vector<int> line;
	int tmp = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> tmp;
			line.push_back(tmp);
		}
		matrix.push_back(line);
		line.clear();
	}
	vector<vector<int>> Tmatrix;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			line.push_back(matrix[j][i]);
		}
		Tmatrix.push_back(line);
		line.clear();
	}
	matrix = Tmatrix;
	vector<int> target;
	vector<int> path;
	for (int i = 0; i < n; i++)
	{
		if (matrix[n - 1][i] == 1)
		{
			target.push_back(i);
		}
	}
	int cnt = 0;
	cnt = PathCount(matrix, target, cnt);
	if (matrix[n-1][0] == 1)
	{
		cnt++;
	}
	cout << cnt;
}