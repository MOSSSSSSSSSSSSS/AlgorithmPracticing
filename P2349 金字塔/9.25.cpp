

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 110, M = 4010,INF = 0x3f3f3f3f;
int n, m;
int h[N], e[M], ne[M], w[M],idx;
int dist[N];
bool st[N];
int pre[N];

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
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({ 0,1 });
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
			if (w[i] <= pre[ver])
			{
				if (dist[j] > distance + w[i])
				{
					pre[j] = pre[ver];
					dist[j] = distance + w[i];
					heap.push({ dist[j],j });
				}
			}
			else
			{
				int dis = distance - pre[ver];
				dis = dis + w[i] * 2;
				if (dist[j] > dis)
				{
					pre[j] = w[i];
					dist[j] = dis;
					heap.push({ dist[j],j });
				}
			}
		}
	}
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
		add(a, b, c), add(b, a, c);
	}
	dijkstra();
	cout << dist[n];

	return 0;
}