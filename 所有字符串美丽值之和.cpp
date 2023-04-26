#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int character[26];
	int total = 0;
	for (int i = 0; i < str.size(); i++)
	{
		for (int j = 2; j <= str.size()-i; j++)
		{
			string s;
			s = str.substr(i, j);
			for (int k = 0; k < 26; k++)
			{
				character[k] = 0;
			}
			int flag = 0;
			while (flag < s.size())
			{
				character[s[flag] - 'a']++;
				flag++;
			}
			int max = character[0], min = s.size();
			for (int m = 0; m < 26; m++)
			{
				if (character[m] > max)
				{
					max = character[m];
				}
				if (character[m] < min && character[m] != 0)
				{
					min = character[m];
				}
			}
			total+= max - min;
			/*if (max - min != 0)
			{
				cout << i << j;
				cout << s << endl;
			}*/
		}
	}
	cout << total;
}