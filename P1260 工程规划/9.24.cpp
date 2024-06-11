

#include<bits/stdc++.h>
using namespace std;

const int N = 1010, M = 10010,INF = 0x3f3f3f3f;
int n, m;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
bool vis[N];
int cnt[N];

bool spfa()
{
	for (int i = 1; i <= n; i++)
		dist[i] = -INF;
	dist[0] = 0;
	queue<int> q;
	q.push(0);
	vis[0] = true;
	while (q.size())
	{
		int t = q.front();
		q.pop();
		vis[t] = false;
		for (int i = h[t]; ~i; i = ne[i])
		{
			int j = e[i];
			if (dist[j] < dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				cnt[j] = cnt[t] + 1;
				if (cnt[j] >= n + 1)return true;
				if (!vis[j])
				{
					q.push(j);
					vis[j] = true;
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
		add(a, b, -c);
	}
	if (spfa())cout << "NO SOLUTION";
	else
	{
		for (int i = 1; i <= n; i++)
			cout << dist[i] << endl;
	}

	return 0;
}