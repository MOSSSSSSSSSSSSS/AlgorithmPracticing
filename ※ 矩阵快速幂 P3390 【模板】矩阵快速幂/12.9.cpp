
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int mod = 1e9 + 7,N = 110;
struct matrix {
	LL c[N][N];
	matrix() { memset(c, 0, sizeof c); };
}A,res;
LL n, k;

matrix operator* (const matrix& x, const matrix& y)
{
	matrix t;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				t.c[i][j] = (t.c[i][j] + x.c[i][k] * y.c[k][j]) % mod;
	return t;
}
void quickpow(LL k)
{
	for (int i = 1; i <= n; i++)res.c[i][i] = 1;
	while (k)
	{
		if (k & 1)res = res * A;
		k >>= 1;
		A = A * A;
	}
}

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> A.c[i][j];
	quickpow(k);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << res.c[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}