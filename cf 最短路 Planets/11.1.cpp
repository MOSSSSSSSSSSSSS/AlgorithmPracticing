

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 1e5 + 10, M = 2e5 + 10,INF = 2e9;
int h[N], e[M], ne[M], w[M], idx;
int n, m;
int dist[N];
bool st[N];
map<int, int> mp[N];

void add(int a, int b, int c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void dijkstra()
{
	for (int i = 1; i <= n; i++)
		dist[i] = INF;
	dist[1] = 0;
	if (mp[1][dist[1]])dist[1] = mp[1][dist[1]];
	priority_queue<PII, vector<PII>, greater<PII> > heap;
	heap.push({ dist[1],1 });
	while (heap.size())
	{
		PII t = heap.top();
		heap.pop();
		int ver = t.second, distance = t.first;
		if (st[ver])continue;
		st[ver] = true;
		for (int i = h[ver]; ~i; i = ne[i])
		{
			int j = e[i];
			if (j != n)
			{
				int time = distance + w[i];
				if (mp[j][time])time = mp[j][time];
				if (dist[j] > time)
				{
					dist[j] = time;
					heap.push({ dist[j],j });
				}
			}
			else
			{
				if (dist[n] > distance + w[i])
				{
					dist[n] = distance + w[i];
					heap.push({ dist[n],n });
				}
			}
		}
	}
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		int last = -1;
		int cnt = 0;
		for (int j = 1; j <= k; j++)
		{
			int x;
			cin >> x;
			if (last != -1)
			{
				if (x - last > 1)
				{
					for (int q = 0; q <= cnt; q++)
					{
						mp[i][last-q] = last + 1;
					}
					cnt = 0;
				}
				else
				{
					cnt++;
				}
			}
			last = x;
			if (j == k)
			{
				for (int q = 0; q <= cnt; q++)
				{
					mp[i][last - q] = last + 1;
				}
			}
		}
	}
	dijkstra();
	if (dist[n] == INF)
	{
		cout << -1;
		return 0;
	}
	cout << dist[n];

	return 0;
}
