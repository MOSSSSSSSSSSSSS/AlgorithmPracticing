

//  无向图欧拉路径，无优化

#include<bits/stdc++.h>
using namespace std;

const int N = 510,M = 2500;
int m;
int d[N];
int s1,s2;
int ans[M],cnt;
vector<int> a[N];

void dfs(int u)
{
	for (int i = 0; i < a[u].size(); i++)
	{
		if (!a[u][i])continue;
		int t = a[u][i];
		a[u][i] = 0;
		for (int j = 0; j < a[t].size(); j++)
		{
			if (a[t][j] == u)
			{
				a[t][j] = 0;
				break;
			}
		}
		dfs(t);
		ans[++cnt] = t;
	}
}

int main()
{
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
		d[u]++, d[v]++;
	}
	for (int i = 1; i <= 500; i++)
		sort(a[i].begin(), a[i].end());
	for (int i = 1; i <= 500; i++)
	{
		if (d[i] & 1)
		{
			if (!s1)
				s1 = i;
			else
				s2 = i;
		}
	}
	s1 = ((s1 < s2) ? s1 : s2);
	if (!s1) s1 = 1;
	dfs(s1);
	cout << s1 << endl;
	for (int i = m; i >= 1; i--)
		cout << ans[i] << endl;

	return 0;
}