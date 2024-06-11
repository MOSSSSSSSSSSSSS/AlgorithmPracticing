
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, M = 4e5 + 10,P = 10007;
int n, v[N];
int h[N], e[M], ne[M], idx;
int tot;
int MAX = 0;

void add(int u, int v)
{
	e[idx] = v;
	ne[idx] = h[u];
	h[u] = idx++;
}
void dfs(int u, int f, int g)
{
	int sonsum = 0;
	int sum = 0;
	int m1 = 0, m2 = 0;
	if (g) { tot = (tot + v[g] * v[u] * 2) % P; MAX = max(MAX, v[g] * v[u]); }
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (j != f)
		{
			dfs(j, u, f);
			sonsum = (sonsum + v[j])%P;
			sum = (sum + v[j] * v[j]) % P;
			if (v[j] > m1)
			{
				m2 = m1, m1 = v[j];
			}
			else if (v[j] > m2)
			{
				m2 = v[j];
			}
		}
	}
	tot = (tot + sonsum * sonsum - sum) % P;
	MAX = max(MAX, m1 * m2);
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n;
	for (int i = 1; i <= n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		add(u, v), add(v, u);
	}
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	dfs(1, 0, 0);
	cout <<MAX<<' ' << tot;

	return 0;
}