

#include<bits/stdc++.h>
using namespace std;

const int N = 1010,M = 10010,INF = 0x3f3f3f3f;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
bool vis[N];
int cnt[N];
int n, m;
int ans;

bool spfa(int x)
{
	for (int i = 1; i <= n; i++)
		dist[i] = INF,cnt[i] = 0;
	dist[x] = 0;
	queue<int> q;
	q.push(x);
	vis[x] = 1;
	while (q.size())
	{
		int t = q.front();
		q.pop();
		vis[t] = 0;
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				cnt[j] = cnt[t] + 1;
				if (cnt[j] >= n)return true;
				if (!vis[j])
				{
					q.push(j);
					vis[j] = 1;
				}
			}
		}
	}
	return false;
}

void add(int a, int b, int c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		h[i] = -1;
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, -c);
	}
	if (spfa(1))
	{
		cout << "Forever love";
		return 0;
	}
	else
		ans = dist[n];
	if (spfa(n))
		cout << "Forever love";
	else
	{
		ans = min(ans, dist[1]);
		cout << ans;
	}


	return 0;
}