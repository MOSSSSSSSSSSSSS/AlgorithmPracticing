
#include<bits/stdc++.h>
using namespace std;

const int N = 1050000,M = 25,K = 110;
int n, m, k;
int f[N];
struct bao {
	int tot;
}baos[K];

int main()
{
	memset(f, 0x3f, sizeof f);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			int x;
			cin >> x;
			baos[i].tot |= (1 << (x - 1));
		}
		f[baos[i].tot] = 1;
	}
	for (int i = 0; i < 1 << m; i++)
	{
		if (f[i] != 0x3f3f3f3f)
		{
			for (int j = 1; j <= n; j++)
			{
				f[i | baos[j].tot] = min(f[i | baos[j].tot], f[i] + 1);
			}
		}
	}
	if (f[(1 << m) - 1] == 0x3f3f3f3f)cout << -1;
	else cout << f[(1 << m) - 1];
	return 0;
}