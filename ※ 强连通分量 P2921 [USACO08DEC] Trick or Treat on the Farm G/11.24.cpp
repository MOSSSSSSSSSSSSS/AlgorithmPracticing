

//  求的是环的大小，有向图中求了强连通分量了就是有向无环图了，可以通过求强连通分量求环的大小

#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int n;
int h[N], e[N], ne[N], idx;
int dfn[N], low[N], timestamp;
int id[N], siz[N],scc;
int stk[N], top;
bool in_stk[N];
int dist[N];

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
			low[u] = min(low[u], dfn[j]);
	}
	if (dfn[u] == low[u])
	{
		scc++;
		int y;
		do {
			y = stk[top--];
			in_stk[y] = false;
			id[y] = scc;
			siz[scc]++;
		} while (y != u);
	}
}
int dfs(int u)
{
	int i = e[h[u]];
	if (siz[id[i]] == 1)
	{
		if (e[h[i]] == i)
		{
			dist[u] = 2;
			return dist[u];
		}
		else
		{
			if (dist[i])
			{
				dist[u] = 1 + dist[i];
				return dist[u];
			}
			else
			{
				dist[u] = 1 + dfs(i);
				return dist[u];
			}
		}
	}
	else
	{
		dist[u] = 1 + siz[id[i]];
		return dist[u];
	}
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int next;
		cin >> next;
		add(i, next);
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			tarjan(i);
	for (int i = 1; i <= n; i++)
	{
		if (siz[id[i]] == 1)
		{
			if (e[h[i]] == i)
			{
				cout << 1 << '\n';
			}
			else
			{
				if (dist[i])cout << dist[i] << '\n';
				else
				{
					dfs(i);
					cout << dist[i] << '\n';
				}
			}
		}
		else
		{
			cout << siz[id[i]] << '\n';
		}
	}

	return 0;
}