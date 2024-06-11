

//  有向图欧拉路径，复杂度低


#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10,M = 2e5+10;
int n, m;
vector<int> a[N];
int din[N], dout[N];
int ans[M],cnt2;
int las[N];
int cnt1, start = 1;

void dfs(int u)
{
	for (int i = las[u]+1; i < a[u].size(); i = las[u] + 1)
	{
		las[u] = i;
		dfs(a[u][i]);
		ans[++cnt2] = a[u][i];
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		las[i] = -1;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		dout[u]++;
		din[v]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (din[i] != dout[i])
		{
			cnt1++;
			if (dout[i] - din[i] == 1)
				start = i;
		}
	}
	if (cnt1 != 0 && cnt1 != 2)
	{
		cout << "No";
		return 0;
	}
	for (int i = 1; i <= n; i++)
		sort(a[i].begin(), a[i].end());
	dfs(start);
	cout << start << ' ';
	for (int i = m; i >= 1; i--)
		cout << ans[i] << ' ';

	return 0;
}