#include<bits/stdc++.h>
using namespace std;

bool cmp(const vector<double>& a, const vector<double>& b)
{
	return a[1] < b[1];
}

int main()
{
	int n = 0,m=0;
	cin >> n;
	cin >> m;
	vector<double> line;
	vector<vector<double>> matrix;
	//cout << typeid(&cmp).name()<<endl;
	priority_queue<vector<double>, vector<vector<double>>, decltype(&cmp)> q(cmp);
	for (int i = 0; i < n; i++)
	{
		line.push_back(0);
	}
	for (int i = 0; i < n; i++)
	{
		matrix.push_back(line);
	}
	int x = 0, y = 0;
	double weight = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> weight;
		matrix[x][y] = weight;
		matrix[y][x] = weight;
	}
	int s = 0, e = 0;
	cin >> s >> e;
	vector<double> Element;
	vector<int> flag;
	for (int i = 0; i < n; i++)
	{
		flag.push_back(0);
	}
	Element.push_back(s);
	Element.push_back(1);
	q.push(Element);
	Element.clear();
	double aws = 0;
	while (q.top()[0] != e)
	{
		for (int i = 0; i < n; i++)
		{
			if (matrix[q.top()[0]][i] != 0 && flag[i] != 1)
			{
				Element.push_back(i);
				Element.push_back(q.top()[1] * (matrix[q.top()[0]][i]));
				q.push(Element);
				Element.clear();
			}
		}
		q.pop();
		if (q.empty())
		{
			cout<<0;
			return 0;
		}
		flag[q.top()[0]] = 1;
	}
	cout<<q.top()[1];
	return 0;
}