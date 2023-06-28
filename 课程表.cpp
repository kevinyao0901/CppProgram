#include<bits/stdc++.h>
using namespace std;

int main()
{
	int NumCourse = 0;
	cin >> NumCourse;
	int Course[10][10];
	int C=-1;
	int PreC = -1;
	int NumPreC = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Course[i][j] = -1;
		}
	}
	for (int i = 0; i < NumCourse; i++)
	{
		cin >> C >> NumPreC;
		for (int j = 0; j < NumPreC; j++)
		{
			cin >> PreC;
			Course[C][PreC] = PreC;
		}
		cout << "A";
	}

}
