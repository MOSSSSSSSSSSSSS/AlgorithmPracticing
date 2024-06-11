

#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int h[2 * N], e[2 * N], ne[2 * N], idx;
int n, m;
int dfn[2*N], low[2*N], timestamp;
int stk[2*N], top;
bool in_stk[2*N];
int id[2*N], scc;

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
		} while (y != u);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--, c--;
		add(2 * a + !b, 2 * c + d);
		add(2 * c + !d, 2 * a + b);
	}
	for (int i = 0; i <= 2 * n - 1; i++)
		if (!dfn[i])
			tarjan(i);
	for(int i = 0;i<=n-1;i++)
		if (id[2 * i] == id[2 * i + 1])
		{
			cout << "IMPOSSIBLE";
			return 0;
		}
	cout << "POSSIBLE" << '\n';
	for (int i = 0; i <= n - 1; i++)
	{
		if (id[2 * i] < id[2 * i + 1])
			cout << 0 << ' ';
		else
			cout << 1 << ' ';
	}

	return 0;
}
