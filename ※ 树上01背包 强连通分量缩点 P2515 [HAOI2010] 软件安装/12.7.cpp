

// 根据题意，一个软件只有一个依赖软件，因此缩点后的有向无环图是一个森林，再来个超级源点，连成一个树
// 按树上01背包dp即可

#include<bits/stdc++.h>
using namespace std;

const int N = 110,M = 510;
int h[N], e[N], ne[N], idx;
int n, m;
int w[N], v[N];

int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int id[N], scc;
vector<int> edge[N];
int W[N], V[N];
int din[N];

int f[N][M];  // i号点为根的子树中用不超过j的空间的最大

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void tarjan(int u)
{
	dfn[u] = low[u] = ++timestamp;
	stk[++top] = u, in_stk[u] = true;
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (!dfn[j])
		{
			tarjan(j);
			low[u] = min(low[u], low[j]);
		}
		else if (in_stk[j])
			low[u] = min(dfn[j], low[u]);
	}
	if (low[u] == dfn[u])
	{
		int y;
		scc++;
		do {
			y = stk[top--];
			in_stk[y] = false;
			id[y] = scc;
			W[scc] += w[y];
			V[scc] += v[y];
		} while (y != u);
	}
}
void dfs(int u)
{
	for (int i = 0; i < edge[u].size(); i++)
		dfs(edge[u][i]);
	for (int i = 0; i<edge[u].size(); i++)
		for (int j = m - W[u]; j >= 0; j--)
			for (int k = 0; k <= j; k++)
				f[u][j+W[u]] = max(f[u][j+W[u]], f[u][j +W[u] - k] + f[edge[u][i]][k]);
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (x == 0)continue;
		add(x, i);
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			tarjan(i);
	for (int i = 1; i <= n; i++)
	{
		for (int j = h[i]; ~j; j = ne[j])
		{
			int k = e[j];
			if (id[i] != id[k])
				edge[id[i]].push_back(id[k]),din[id[k]]++;
		}
	}
	for (int i = 1; i <= scc; i++)
	{
		for (int j = W[i]; j <= m; j++)
			f[i][j] = V[i];
		if (din[i]==0)
			edge[0].push_back(i);
	}
	
	dfs(0);
	cout << f[0][m];

	return 0;
}