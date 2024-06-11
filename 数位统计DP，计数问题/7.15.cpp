
//  ��λDP�����������

//  ��A��B  ���䣨0<A,B<100000000��ע��AB֮���С��ϵû�У�  ĳ�������ֵĴ���  ��ǰ׺��˼�룬�� 1��A-1 �д����Ĵ���  ������1��B�д������ֵĴ��� �����������  ���� �Ĵ𰸡�
//  дһ������count��n��x����1��n��x���ֵĴ���
//  ����ʵ�֣��ֱ����x��ÿһλ�ϳ��ֵĴ���������������x���ֵĴ�����
//  ������x�ڵ���λ���ֵĴ�����abc d efg��������abc x efg ������һ�����ٸ��� ������ö��ǰ��λ �� 000 ��abc-1��d = x������λ���Դ�000��999
//  �ٿ�ǰ��λ��abc����������d<x��0�֣����d = x��efg���Դ� 000��efg��efg+1�֣����d>X ��1000��
//  ����������������� ����λ ����ʱ��û��ö��ǰ��λ�Ŀ��ܣ�ǰ��λû������ �� 0 ���ֵĴ���ʱ��ǰ��λҪ��001��ʼ������000

// **********************************************************************************************
#include<bits/stdc++.h>
using namespace std;

int a, b;

int get(vector<int> num, int l, int r)
{
	int res = 0;
	for (int i = r; i >= l; i--)
		res = res * 10 + num[i];        //��abc  a*100+b*10+c

	return res;
}

int power10(int n)
{
	int res = 1;
	for (int i = 0; i < n; i++)
		res *= 10;

	return res;
}

int count(int n, int x)
{
	if (!n)return 0;

	int res = 0;
	vector<int> num;
	while (n)                      //������һ�����ֿ���������
	{
		num.push_back(n % 10);
		n /= 10;
	}
	n = num.size() - 1; 
	for (int i = n; i >= 0; i--) 
	{
		if (i != n)
		{
			if (x)
				res += get(num, i + 1, n) * power10(i);
			else
				res += (get(num, i + 1, n) - 1) * power10(i);
		}
		if (x == num[i])res += get(num, 0, i - 1) + 1;
		else if (i == n && x < num[i] && x || i != n && x < num[i])res += power10(i);
	}

	return res;
}

int main()
{
	while (cin >> a >> b, a || b)
	{
		if (a > b)swap(a, b);

		for (int i = 0; i <= 9; i++)
			cout << count(b, i) - count(a - 1, i) << ' ';
		cout << endl;
	}

	return 0;
}