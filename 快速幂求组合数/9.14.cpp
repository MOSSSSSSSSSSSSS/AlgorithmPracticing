

//  P是一个大于m和n的大质数   时间复杂度 O（nlogP）

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 100010, P = 1e9 + 7;
LL q,f[N], g[N];

LL qmi(int a, int k)
{
	LL res = 1;
	while (k)
	{
		if (k & 1)res = (LL)res * a % P;
		k >>= 1;
		a = (LL)a * a % P;
	}
	return res;
}

void init()
{
	f[0] = g[0] = 1;
	for (int i = 1; i < N; i++)
	{
		f[i] = f[i - 1] * i % P;
		g[i] = g[i - 1] * qmi(i, P - 2) % P;
	}
}

int main()
{
	cin >> q;
	while (q--)
	{
		int n, m;
		cin >> n >> m;
		cout << f[n] * g[n - m] % P * g[m] % P << endl;
	}

	return 0;
}
