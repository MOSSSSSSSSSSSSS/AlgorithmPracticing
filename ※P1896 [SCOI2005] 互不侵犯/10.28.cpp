

// ״ѹdp

#include<bits/stdc++.h>
using namespace std;

const int N = 10, M = 100, K = 1<<9;
long long f[N][M][K],n,m;
vector<int> ok[K];
vector<int> ojbk;
unsigned long long ans;

int count(int a)
{
	int cnt = 0;
	while (a)
	{
		a -= (a & ( -a));
		cnt++;
	}
	return cnt;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < 1 << n; i++)
		if (!((i << 1 | i >> 1) & i))
			ojbk.push_back(i);
	for (auto a : ojbk)
		for (int i = 0; i < 1 << n; i++)
			if (!((a | a << 1 | a >> 1) & i))
				ok[a].push_back(i);
	for (auto a : ojbk)
		f[1][count(a)][a] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 0; j <= m; j++)
			for (auto a : ojbk)
				for (auto b : ok[a])
					if(j-count(a)>=0)
						f[i][j][a] += f[i - 1][j - count(a)][b];
	for (auto a : ojbk)
		ans += f[n][m][a];
	cout << ans;

	return 0;
}