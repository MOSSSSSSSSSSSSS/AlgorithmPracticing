
//  不要用insert在前面头上插值，会T的起飞

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, m;
int p[N];
vector<int> e[N];
vector<int> close;
vector<bool> ans;
bool is_close[N];
int sum = 0;              //   怎么判断全联通？不是每次都看一遍所有的，而是拿一个sum，每次增加一个点sum++，合并sum--，若sum==1则全联通

int find(int x)
{
	if (p[x] != x)p[x] = find(p[x]);
	return p[x];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		p[i] = i;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		e[u].push_back(v), e[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		close.push_back(a);
		is_close[a] = true;
	}
	for (int i = n - 1; i >= 0; i--)
	{
		bool flag = false;
		is_close[close[i]] = false;
		sum++;
		for (auto item : e[close[i]])
		{
			if (!is_close[item])
			{
				int fa = find(close[i]);
				int fb = find(item);
				if (fa != fb)p[fa] = fb,sum--;
			}
		}
		if (sum == 1)ans.push_back(true);
		else ans.push_back(false);
	}
	for (int i = ans.size()-1;i>=0;i--)
	{
		if (ans[i])cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}