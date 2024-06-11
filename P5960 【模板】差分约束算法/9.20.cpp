

#include<bits/stdc++.h>
using namespace std;

const int N = 5010, M = 10010,INF = 0x3f3f3f3f;  //Á½±¶±ß
int h[N], e[M], ne[M], w[M], idx;
int n, m;
int dist[N];
bool vis[N];
int cnt[N];
int q[N], hh, tt = -1;

bool spfa()
{
	for (int i = 1; i <= n; i++)
		dist[i] = INF;
	dist[0] = 0;
	q[++tt] = 0;
	vis[0] = 1;
	while (hh <= tt)
	{
		int x = q[hh++];
		vis[x] = 0;
		for (int i = h[x]; ~i; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[x] + w[i])
			{
				dist[j] = dist[x] + w[i];
				cnt[j] = cnt[x] + 1;
				if (cnt[j] >= n + 1)return true;
				if (!vis[j])
				{
					q[++tt] = j;
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
	for (int i = 0; i <= n; i++)
		h[i] = -1;
	for (int i = 1; i <= n; i++)
		add(0, i, 0);
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(b, a, c);
	}
	if (spfa())cout << "NO";
	else
	{
		for (int i = 1; i <= n; i++)
			cout << dist[i] << ' ';
	}

	return 0;
}