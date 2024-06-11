
// 用来快速求 a的k次方模p的值，时间复杂度O(logk)。朴素算法需要循环时间复杂度O(k)
// 首先k可以用二进制表示例如k = （1110110）2，那么k就等于2的6次方+2的5次方+2的4次方+2的2次方+2
// 那么a的k次方就等于a的2的6次方*a的2的5次方*a的2的4次方*a的2的2次方*a的2次方
// a的k次方模p就等于（a的2的6次方模p*a的2的5次方模p*a的2的4次方模p*a的2的2次方模p*a的2次方模p）模p
// 所以快速幂就是先算出a的2的0次方模p一直到a的2的log2k（小数向下取整）次方模p

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
//作业
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