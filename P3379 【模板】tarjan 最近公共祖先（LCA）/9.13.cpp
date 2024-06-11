

//离线算法 tarjan求LCA，n+m线性时间复杂度

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 500010;
vector<int> e[N];
vector<PII> query[N];
int ans[N], fa[N];
bool vis[N];
int n, m, s;

int find(int x)
{
	if (fa[x] != x)fa[x] = find(fa[x]);
	return fa[x];
}

void tarjan(int u)
{
	vis[u] = 1;
	for (auto v : e[u])
	{
		if (!vis[v])
		{
			tarjan(v);
			fa[v] = u;
		}
	}
	for (auto q : query[u])
		if (vis[q.first])ans[q.second] = find(q.first);
}

int main()
{
	cin >> n >> m >> s;
	for (int i = 1; i <= n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		e[x].push_back(y), e[y].push_back(x);
	}
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		query[a].push_back({ b,i });
		query[b].push_back({ a,i });
	}
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	tarjan(s);
	for (int i = 1; i <= m; i++)
		cout << ans[i] << endl;

	return 0;
}

