

#include<bits/stdc++.h>
using namespace std;

const int N = 20010, M = 200010;
int h[N], e[M], ne[M],idx;
int dfn[N], low[N],timestamp;
int n, m;
int root;
vector<int> ans;

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

void tarjan(int u)
{
	dfn[u] = low[u] = ++timestamp;
	int cnt = 0;
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (!dfn[j])
		{
			tarjan(j);
			low[u] = min(low[u], low[j]);
			if (low[j] >= dfn[u])
				cnt++;
		}
		else
			low[u] = min(low[u], dfn[j]);
	}
	if (u != root && cnt)ans.push_back(u);
	else if (u == root && cnt > 1)ans.push_back(u);
}

int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	for (root = 1; root <= n; root++)
		if (!dfn[root])
			tarjan(root);
	cout << ans.size() << endl;
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';

	return 0;
}