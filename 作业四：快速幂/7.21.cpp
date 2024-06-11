
// ���������� a��k�η�ģp��ֵ��ʱ�临�Ӷ�O(logk)�������㷨��Ҫѭ��ʱ�临�Ӷ�O(k)
// ����k�����ö����Ʊ�ʾ����k = ��1110110��2����ôk�͵���2��6�η�+2��5�η�+2��4�η�+2��2�η�+2
// ��ôa��k�η��͵���a��2��6�η�*a��2��5�η�*a��2��4�η�*a��2��2�η�*a��2�η�
// a��k�η�ģp�͵��ڣ�a��2��6�η�ģp*a��2��5�η�ģp*a��2��4�η�ģp*a��2��2�η�ģp*a��2�η�ģp��ģp
// ���Կ����ݾ��������a��2��0�η�ģpһֱ��a��2��log2k��С������ȡ�����η�ģp

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int qmi(int a, int k, int p)
{
	int res = 1;
	while (k)
	{
		if (k & 1)res = (LL)res * a % p;
		k >>= 1;
		a = (LL)a * a % p;
	}

	return res;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int a, k, p;
		scanf("%d%d%d", &a, &k, &p);
		printf("%d\n", qmi(a, k, p));
	}

	return 0;
}
//***************************************************************************
//��ҵ
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
int qmi(int a, int b, int p)
{
	int res = 1;
	while (b)
	{
		if (b & 1)res = (LL)res * a % p;
		b >>= 1;
		a = (LL)a * a % p;
	}

	return res;
}

int main()
{
	int a, b, p;
	cin >> a >> b >> p;
	cout << a << '^' << b << ' ' << "mod" << ' ' << p << '=' << qmi(a, b, p);

	return 0;
}