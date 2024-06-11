

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10,INF = 1e18;
int p[2 * N];
long long v[2 * N];
int sc[2 * N];
int n, m, q;
int h[2 * N], e[4 * N], ne[4 * N], idx;
int fa[2*N][19];
struct edge {
	int a, b, w;
}edges[N];

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
int find(int x)
{
	if (p[x] != x)p[x] = find(p[x]);
	return p[x];
}
void kruskal()
{
	int index = 0;
	for (int i = 1; i <= m; i++)
	{
		int a = edges[i].a, b = edges[i].b, w = edges[i].w;
		int fa = find(a), fb = find(b);
		if (fa != fb)
		{
			index++;
			p[fa] = p[fb] = p[n + index] = n + index;
			sc[n + index] = w;
			v[n + index] = v[fa] + v[fb];
			add(fa, n + index), add(fb, n + index), add(n + index, fa), add(n + index, fb);
			if (index == n - 1)return;
		}
	}
}
void dfs(int u, int father)
{
	fa[u][0] = father;
	for (int i = 1; i < 19; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (j != father)
			dfs(j, u);
	}
}
long long bz(int x,int ans,int k)
{
	ans += v[x];
	while (x!=2*n-1)
	{
		long long wcnm = ans;
		for (int i = 18; i >= 0; i--)
			if (sc[fa[x][i]] <= ans)
				ans = v[fa[x][i]] + k, x = fa[x][i];
		if (wcnm == ans)break;
	}
	return ans;
}
bool cmp(edge a, edge b)
{
	return a.w < b.w;
}

int main()
{
	sc[0] = INF;
	memset(h, -1, sizeof h);
	cin >> n >> m >> q;
	for (int i = 1; i < 2 * N; i++)
		p[i] = i;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	for (int i = 1; i <= m; i++)
		cin >> edges[i].a >> edges[i].b >> edges[i].w;
	sort(edges + 1, edges + 1 + m,cmp);
	kruskal();
	dfs(2*n-1,0);
	while (q--)
	{
		int x, k;
		cin >> x >> k;
		long long ans = k;
		cout << bz(x,ans,k) << endl;
	}
	
	return 0;
}