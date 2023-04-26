#include<bits/stdc++.h>
using namespace std;

vector<int> diffWaysToCompute(string expression)
{
	vector<int> ret;
	if (isdigit(expression[0]) && expression.size()==1)
	{
		ret.push_back(expression[0]-'0');
		return ret;
	}
	for (int i = 0; i < expression.size(); i++)
	{
		if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
		{
			vector<int> left;
			vector<int> right;
			left = diffWaysToCompute(expression.substr(0, i));
			right = diffWaysToCompute(expression.substr(i + 1, expression.size() - i));

			for (int j = 0; j < left.size(); j++)
			{
				for (int k = 0; k < right.size(); k++)
				{
					if (expression[i] == '+')
					{
						ret.push_back(left[j] + right[k]);
					}
					else if (expression[i] == '-')
					{
						ret.push_back(left[j] - right[k]);
					}
					else if (expression[i] == '*')
					{
						ret.push_back(left[j] * right[k]);
					}
				}
			}
		}
	}
	return ret;
}

void print(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}

int main()
{
	string s;
	cin >> s;
	print(diffWaysToCompute(s));
	return 0;
}