//递归乘法。 写一个递归函数，不使用* 运算符， 实现两个正整数的相乘。可以使用加号、减号、位移，但要吝啬一些。
#include<bits/stdc++.h>
using namespace std;

int multiply(int A, int B)
{
	if (B)
	{
		if (B % 2 != 0)
		{
			return multiply(A << 1, B >> 1) + A;
		}
		else
		{
			return multiply(A << 1, B >> 1);
		}
	}
	else
	{
		return 0;
	}
}


int main()
{
	int A, B;
	cin >> A >> B;
	cout<<multiply(A, B);
}