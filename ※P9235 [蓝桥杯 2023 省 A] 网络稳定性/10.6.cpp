


#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10, M = 5e4 + 10,INF = 1e8;
int p[N];
int n, m, q;
struct edge {
	int a, b, w;
}edges[M];
vector<int> ver;
int dep[N], fa[N][18];
int mn[N][18];
int h[N], e[M*2], ne[M*2], w[M*2], idx;
bool st[N];

bool cmp(edge a, edge b)
{
	if (a.w > b.w)return true;
	else return false;
}
int find(int x)
{
	if (p[x] != x)p[x] = find(p[x]);
	return p[x];
}
void add(int a, int b, int c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void dfs(int u, int father)
{
	dep[u] = dep[father] + 1;
	fa[u][0] = father;
	st[u] = true;
	for (int i = 1; i < 18; i++)
	{
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
		mn[u][i] = min(mn[u][i - 1], mn[fa[u][i - 1]][i - 1]);
	}
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (j != father&&!st[j])
		{
			mn[j][0] = w[i];
			dfs(j, u);
		}
	}
}
int lca(int x, int y)
{
	int ans = INF;
	if (dep[x] < dep[y])swap(x, y);
	for (int i = 17; i >= 0; i--)
	{
		if (dep[fa[x][i]] >= dep[y])
		{
			ans = min(ans, mn[x][i]);
			x = fa[x][i];
		}
	}
	if (x == y)return ans;
	for (int i = 17; i >= 0; i--)
	{
		if (fa[x][i] != fa[y][i])
		{
			ans = min(ans, mn[x][i]);
			ans = min(ans, mn[y][i]);
			x = fa[x][i], y = fa[y][i];
		}
	}
	ans = min(ans, mn[x][0]);
	ans = min(ans, mn[y][0]);
	return ans;
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 17; j++)
			mn[i][j] = INF;
	for (int i = 1; i <= n; i++)
		p[i] = i;
	for (int i=1; i <= m; i++)
		cin >> edges[i].a >> edges[i].b >> edges[i].w;
	cin >> q;
	sort(edges + 1, edges + 1 + m,cmp);
	int cnt = 0;
	for (int i = 1; i <= m; i++)
	{
		int a = edges[i].a, b = edges[i].b;
		a = find(a), b = find(b);
		if (a != b)
		{
			p[a] = b;
			cnt++;
			ver.push_back(i);
		}
		if (cnt == n - 1)break;
	}
	for (int i = 0; i < ver.size(); i++)
	{
		add(edges[ver[i]].a, edges[ver[i]].b, edges[ver[i]].w);
		add(edges[ver[i]].b, edges[ver[i]].a, edges[ver[i]].w);
	}
	for (int i = 1; i <= n; i++)
		if (p[i]==i)
			dfs(i, 0);
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		if (find(x) != find(y))cout << -1 << '\n';
		else cout << lca(x, y) << '\n';
	}

	return 0;
}