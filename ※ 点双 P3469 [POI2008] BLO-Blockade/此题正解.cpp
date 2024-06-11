
#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 100010, M = 1000010;
int n, m;
int h[N], e[M], ne[M], idx;
set<int> cut;
int dfn[N], low[N], timestamp;
int root;
int ans[N];

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
int tarjan(int u)
{
	int cnt = 0, tot = 1, sum = 0;
	dfn[u] = low[u] = ++timestamp;
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (!dfn[j])
		{
			int res = tarjan(j);
			tot += res;
			low[u] = min(low[u], low[j]);
			if (low[j] >= dfn[u])
			{
				cnt++;
				sum += res;
				ans[u] += res * (n - res);
				if (u != root || cnt > 1)cut.insert(u);                      //  是放到set里所以有重复的也去掉了
			}
		}
		else low[u] = min(low[u], dfn[j]);
	}
	if (cut.count(u))
	{
		ans[u] += (n - sum - 1) * (sum + 1) + (n - 1);
	}

	return tot;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	for (root = 1; root <= n; root++)
		if (!dfn[root])
			tarjan(root);
	for (int i = 1; i <= n; i++)
	{
		if (cut.count(i))cout << ans[i] << '\n';
		else cout << 2 * (n - 1) << '\n';
	}
	return 0;
}