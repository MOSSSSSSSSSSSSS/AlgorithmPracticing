

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int mod = 1e9+7;
int n, x, y;
int cnt;

LL qmi(int a, int k)
{
	LL res = 1;
	while (k)
	{
		if (k & 1)res = res * a % mod;
		k >>= 1;
		a = (LL)a * a % mod;
	}
	return res;
}

int main()
{
	cin >> n >> x >> y;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a<x || b>y)continue;
		cnt++;
	}
	cout<<qmi(2, cnt)-1;

	return 0;
}