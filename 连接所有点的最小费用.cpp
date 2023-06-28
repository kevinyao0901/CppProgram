#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	vector<vector<int>> matrix;
	vector<int> line;
	vector<vector<int>> points;
	vector<int> point;
	int x = 0,y=0;
	for (int i = 0; i < n; i++)
	{
		cin >> x>>y;
		point.push_back(x);
		point.push_back(y);
		points.push_back(point);
		point.clear();
	}
	int Mdistance = 0;
	vector<int> MinDisSet;
	int MinElement = INT_MAX;
	int MinX = 0;
	int MinY = 0;
	vector<vector<int>> MinPath;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Mdistance = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
			line.push_back(Mdistance);
		}
		matrix.push_back(line);
		line.clear();
	}
	vector<vector<int>> Union;
	for (int i = 0; i< n; i++)
	{
		line.push_back(i);
		Union.push_back(line);
		line.clear();
	}
	int k = 0;
	while(k<n-1)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				if (matrix[i][j] < MinElement && matrix[i][j] != 0)
				{
					MinElement = matrix[i][j];
					MinX = i;
					MinY = j;
				}
			}
		}
		matrix[MinX][MinY] = INT_MAX;
		int Uniontag = 0;
		for (int m = 0; m < Union.size(); m++)
		{
			if (find(Union[m].begin(), Union[m].end(), MinX) != Union[m].end() && find(Union[m].begin(), Union[m].end(), MinY) != Union[m].end())
			{
				Uniontag=1;
				matrix[MinX][MinY] = INT_MAX;
				MinElement = INT_MAX;
				break;
			}
		}
		if (Uniontag == 1)
		{
			continue;
		}
		else
		{
			int U1 = 0,U2=0;
			for (int m = 0; m < Union.size(); m++)
			{
				if (find(Union[m].begin(), Union[m].end(), MinX) != Union[m].end())
				{
					U1 = m;
				}
				if (find(Union[m].begin(), Union[m].end(), MinY) != Union[m].end())
				{
					U2 = m;
				}
			}
			vector<int> UnionResult(Union[U1].size()+ Union[U2].size());
			merge(Union[U1].begin(), Union[U1].end(), Union[U2].begin(), Union[U2].end(), UnionResult.begin());
			Union[U1] = UnionResult;
			Union.erase(Union.begin() + U2);
		}
		MinDisSet.push_back(MinElement);
		MinElement = INT_MAX;
		k++;
	}
	//sort(MinDisSet.begin(), MinDisSet.end());
	int MinTotal = 0;
	for (int i = 0; i < n - 1; i++)
	{
		MinTotal += MinDisSet[i];
	}
	cout << MinTotal;
	return 0;
}