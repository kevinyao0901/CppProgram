//�ݹ�˷��� дһ���ݹ麯������ʹ��* ������� ʵ����������������ˡ�����ʹ�üӺš����š�λ�ƣ���Ҫ����һЩ��
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