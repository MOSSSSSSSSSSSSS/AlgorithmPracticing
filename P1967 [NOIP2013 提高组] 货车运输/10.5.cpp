

#include<bits/stdc++.h>
using namespace std;

const int N = 10010, M = 50010,INF = 1e8;
int n, m, q;
int p[N];
struct edge {
	int a, b, w;
}edges[M];
vector<int> ver;
int h[N], e[M*2], ne[M*2], w[M*2], idx;
int dep[N], fa[N][15];
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
	for (int i = 1; i < 15; i++)
		fa[u][i] = fa[fa[u][i-1]][i-1];
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (j != father && !st[j])
			dfs(j, u);
	}
}
int lca(int x,int y)
{
	int tempx = x, tempy = y,ans = INF,t;
	if (dep[x] < dep[y])swap(x, y);
	for (int i = 14; i >= 0; i--)
		if (dep[fa[x][i]] >= dep[y])
			x = fa[x][i];
	if (x == y)t = y;
	else
	{
		for (int i = 14; i >= 0; i--)
			if (fa[x][i] != fa[y][i])
				x = fa[x][i], y = fa[y][i];
		t = fa[x][0];
	}
	while (tempx != t)
	{
		for (int i = h[tempx]; ~i; i = ne[i])
		{
			int j = e[i];
			if (j == fa[tempx][0])
			{
				ans = min(ans, w[i]);
				tempx = fa[tempx][0];
				break;
			}
		}
	}
	while (tempy != t)
	{
		for (int i = h[tempy]; ~i; i = ne[i])
		{
			int j = e[i];
			if (j == fa[tempy][0])
			{
				ans = min(ans, w[i]);
				tempy = fa[tempy][0];
				break;
			}
		}
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		p[i] = i;
	for (int i = 1; i <= m; i++)
		cin >> edges[i].a >> edges[i].b >> edges[i].w;
	sort(edges + 1, edges + m + 1, cmp);
	int cnt = 0;
	for (int i = 1; i <= m; i++)
	{
		int a = edges[i].a, b = edges[i].b, w = edges[i].w;
		a = find(a), b = find(b);
		if (a != b)
		{
			p[a] = b;
			cnt++;
			ver.push_back(i);
		}
		if (cnt == n - 1)break;
	}
	for (int i = 1; i <= ver.size(); i++)
	{
		int a = edges[ver[i]].a, b = edges[ver[i]].b, c = edges[ver[i]].w;
		add(a, b, c);
		add(b, a, c);
	}
	for (int i = 1; i <= n; i++)
		if (p[i] == i)
			dfs(i, 0);
	cin >> q;
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		if (find(x) != find(y))
			cout << -1 << '\n';
		else
			cout << lca(x, y) << '\n';
	}

	return 0;
}