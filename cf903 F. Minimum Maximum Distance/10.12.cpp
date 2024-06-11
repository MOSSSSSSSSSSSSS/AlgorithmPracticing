

#include<iostream>
#include<vector>
using namespace std;

const int N = 2e5 + 10,INF = 1e8;
int t;
vector<int> a[N];
int dep[N], fa[N][20];
bool st[N];

void dfs(int u, int father,vector<int> a[N],int dep[N],int fa[N][20],bool st[])
{
	dep[u] = dep[father] + 1;
	st[u] = true;
	fa[u][0] = father;
	for (int i = 1; i < 20; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = 0; i < a[u].size(); i++)
	{
		int j = a[u][i];
		if (!st[j] && j != father)
			dfs(j, u,a,dep,fa,st);
	}
}
int lca(int u, int v,int dep[N],int fa[N][20])
{
	if (dep[u] < dep[v])swap(u, v);
	for (int i = 19; i >= 0; i--)
		if (dep[fa[u][i]] >= dep[v])
			u = fa[u][i];
	if (u == v)return v;
	for (int i = 19; i >= 0; i--)
		if (fa[u][i] != fa[v][i])
			u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}

int main()
{
	cin >> t;
	while (t--)
	{
		int n, k,ans = INF;
		vector<int> mark;
		cin >> n >> k;
		while (k--)
		{
			int x;
			cin >> x;
			mark.push_back(x);
		}
		for (int i = 1; i <= n - 1; i++)
		{
			int u, v;
			cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		dfs(1,0,a,dep,fa,st);
		for (int i = 1; i <= n; i++)
		{
			int res = 0;
			for (int j = 0; j < mark.size(); j++)
				res = max(res, dep[i] + dep[mark[j]] - 2 * dep[lca(i, mark[j],dep,fa)]);
			ans = min(ans, res);
		}
		cout << ans << endl;
		memset(dep, 0, sizeof dep);
		memset(fa, 0, sizeof fa);
		memset(st, false, sizeof st);
		for (int i = 0; i < N; i++)
			a[i].clear();
	}

	return 0;
}