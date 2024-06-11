

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 110, M = 10010;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
bool st[N];
bool destroy[M]; // ÄÄÌõ±ß»µÁË
int n, m, d, A, B;

void add(int a, int b, int c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	dist[A] = 0;
	priority_queue < PII, vector<PII>, greater<PII>> heap;
	heap.push({ 0,A });
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
			if (destroy[i])
			{
				if (dist[j] > distance + w[i])
				{
					dist[j] = distance + w[i];
					heap.push({ dist[j],j });
				}
			}
			else
			{
				if (dist[j] > distance)
				{
					dist[j] = distance;
					heap.push({ dist[j],j });
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}
	cin >> d;
	for (int i = 1; i <= d; i++)
	{
		int a, b;
		cin >> a >> b;
		for (int j = 0; j < idx; j+=2)
			if (e[j] == a && e[j ^ 1] == b || e[j] == b && e[j ^ 1] == a)
				destroy[j] = destroy[j ^ 1] = true;
	}
	cin >> A >> B;
	dijkstra();
	cout << dist[B];

	return 0;
}