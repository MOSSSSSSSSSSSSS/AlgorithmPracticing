

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 810, M = 2910,INF = 0x3f3f3f3f;
int n, p, c;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
int num[N];
bool st[N];
int ans = INF;

void add(int a, int b, int c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

void dijkstra(int x)
{
	for (int i = 1; i <= p; i++)
		dist[i] = INF, st[i] = false;
	dist[x] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({ 0,x });
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
			if (dist[j] > distance + w[i])
			{
				dist[j] = distance + w[i];
				heap.push({ dist[j],j });
			}
		}
	}
}

int main()
{
	cin >> n >> p >> c;
	for (int i = 1; i <= p; i++)
		h[i] = -1;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		num[x]++;
	}
	for (int i = 1; i <= c; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}
	for (int i = 1; i <= p; i++)
	{
		dijkstra(i);
		int res = 0;
		for (int j = 1; j <= p; j++)
			res += (num[j] * dist[j]);
		if (res < 0)continue;
		ans = min(ans, res);           //   溢出出现负数，这个点不可能是答案（有其他点到不了），不要用这点的负数去更新答案
	}
	cout << ans;

	return 0;
}