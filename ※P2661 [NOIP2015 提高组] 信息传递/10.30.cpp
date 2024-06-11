

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10,INF = 1e8;
int p[N];
int dist[N];
int n;
int ans = INF;

int find(int x)
{
	if (p[x] != x)
	{
		int temp = p[x];
		p[x] = find(p[x]);
		dist[x] += dist[temp];
	}
	return p[x];
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		p[i] = i;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		int fa = find(i), fb = find(x);
		if (fa != fb)
		{
			dist[fa] ++;
			p[fa] = x;
		}
		else
		{
			int res = abs(dist[i] - dist[x]) + 1;
			ans = min(res, ans);
		}
	}
	cout << ans;

	return 0;
}