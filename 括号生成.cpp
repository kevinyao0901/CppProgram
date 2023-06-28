#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n = 0;
	cin >> n;
	vector<vector<string>> s;
	vector<string> s1;
	vector<string> s2;
	s1.push_back("");
	s2.push_back("()");
	s.push_back(s1);
	s.push_back(s2);
	int index = n;
	int cnt = 1;
	n--;
	while (n > 0)
	{
		string NextString;
		vector<string> NextStringSet;
		int k = 0;
		while(k<=cnt)
		{
			for (int i = 0; i < s[k].size(); i++)
			{
				for (int j = 0; j < s[cnt-k].size(); j++)
				{
					NextString = "(" + s[k][i] + ")" + s[cnt - k][j];
					NextStringSet.push_back(NextString);
				}
			}
			k++;
		}
		s.push_back(NextStringSet);
		NextStringSet.clear();
		cnt++;
		n--;
	}
	cout << s[index].size();
}

