

#include<bits/stdc++.h>
#define _for(i,a,b) for(int i = (a);i<=(b);i++)
#define _rep(i,a,b) for(int i = (a);i<(b);i+=2)
#define mm memset
using namespace std;

typedef pair<int, int> PII;
const int N = 1010, M = 2010;
int n, m;
int h[N], e[M], ne[M], w[M],f[M], idx;
int dist[N];
bool st[N];
double ans;
int ans2;

double dijkstra(int limit)
{
	mm(dist, 0x3f, sizeof dist);
	mm(st, false, sizeof st);
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
			if (f[i] < limit)continue;
			int j = e[i];
			if (dist[j] > distance + w[i])
			{
				dist[j] = distance + w[i];
				heap.push({ dist[j],j });
			}
		}
	}
	double res = limit/(double)dist[n];
	return res;
}

void add(int a, int b, int c, int d)
{
	f[idx] = d;
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

int main()
{
	cin >> n >> m;
	mm(h, -1, sizeof h);
	_for(i, 1, m)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		add(a, b, c, d), add(b, a, c, d);
	}
	_rep(i, 0, idx)
	{
		double res = dijkstra(f[i]);
		ans = max(ans, res);
	}
	ans2 = ans * 1000000;
	cout << ans2;

	return 0;
}