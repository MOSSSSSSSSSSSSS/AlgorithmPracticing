

#include<bits/stdc++.h>
using namespace std;

const int N = 200010, M = 1e6 + 10;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int A, B;
int n;
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
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (!dfn[j])
		{
			tarjan(j);
			low[u] = min(low[u], low[j]);
			if (low[j] >= dfn[u] && dfn[B] >= dfn[j]&&u!=A)
				ans.push_back(u);
		}
		else low[u] = min(low[u], dfn[j]);
	}
}

int main()
{
	cin >> n;
	memset(h, -1, sizeof h);
	int a, b;
	while (cin >> a >> b, a && b)
		add(a, b), add(b, a);
	cin >> A >> B;
	tarjan(A);
	if (!ans.size())
	{
		cout << "No solution";
		return 0;
	}
	sort(ans.begin(), ans.end());
	cout << ans[0];

	return 0;
}