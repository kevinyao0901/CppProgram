#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	int temp = 0;
	vector<int>gas;
	vector<int>cost;
	int SumGas = 0;
	int SumCost = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		SumGas += temp;
		gas.push_back(temp);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		SumCost += temp;
		cost.push_back(temp);
	}
	if (SumCost > SumGas)
	{
		cout<< -1<< endl;
		return 0;
	}
	int start=0;
	int GasLeft = 0;
	for (int i = 0; i < gas.size(); i++)
	{
		GasLeft = GasLeft + gas[i] - cost[i];
		if (GasLeft < 0)
		{
			start = i + 1;
			GasLeft = 0;
		}
	}
	cout << start<<endl;
	return 0;
}