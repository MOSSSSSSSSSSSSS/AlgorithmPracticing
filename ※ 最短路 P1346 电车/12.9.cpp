
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 110, M = 10010;
int h[N], e[M], ne[M],w[M], idx;
int n, A, B;
int dist[N];
bool st[N];
void add(int a, int b, int c)
{
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}
void dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	dist[A] = 0;
	priority_queue<PII, vector<PII>, greater<PII> >heap;
	heap.push({ dist[A], A });
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
	memset(h, -1, sizeof h);
	cin >> n >> A >> B;
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			int x;
			cin >> x;
			if (j == 1)add(i,x,0);
			else add(i,x,1);
		}
	}
	dijkstra();
	if (dist[B] == 0x3f3f3f3f)cout << -1;
	else cout << dist[B];

	return 0;
}