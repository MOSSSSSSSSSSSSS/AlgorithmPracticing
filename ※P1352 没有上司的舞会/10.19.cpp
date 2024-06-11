

#include<bits/stdc++.h>
using namespace std;

const int N = 6e3 + 10, M = 6e3 + 10;
int n;
int h[N], e[M], ne[M], idx;
int ha[N];
int f[N][2];
int din[N];
int boss;

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void dp(int u)
{
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		dp(j);
		f[u][0] += max(f[j][0], f[j][1]);
		f[u][1] += f[j][0];
	}
}

int main()
{
	cin >> n;
	memset(h, -1, sizeof h);
	for (int i = 1; i <= n; i++)
		cin >> ha[i],f[i][1] = ha[i];
	for (int i = 1; i <= n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		add(b, a);
		din[a]++;
	}
	for (int i = 1; i <= n; i++)
		if (!din[i])
		{
			boss = i;
			break;
		}
	dp(boss);
	cout << (f[boss][0] > f[boss][1] ? f[boss][0] : f[boss][1]);

	return 0;
}