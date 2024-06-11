

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, M = 1e6 + 10,INF = 1e9;
int n, m;
int p[N];
int h[3*N], e[4*M], ne[4*M], w[4*M], idx;
int dist[3 * N];
bool st[3 * N];
int ans;

void add(int a, int b, int c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
int spfa()
{
	for (int i = 1; i <= 3*n; i++)dist[i] = -INF;         //  求最短路是极大值，这里球的最长路
	dist[1] = 0;
	queue<int> q;
	q.push(1);
	st[1] = true;
	while (q.size())
	{
		int t = q.front();
		q.pop();
		st[t] = false;          //  弹出了，不在队列里了
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (dist[j] < dist[t] + w[i])   //如果应该更新
			{
				dist[j] = dist[t] + w[i];
				if (!st[j])                //  如果没在队列，在就不用管
				{
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
}
int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
		add(i, i + n, -p[i]);
		add(i + n, i + 2 * n, p[i]);
	}
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		if (z == 1)
		{
			add(x, y, 0);
			add(x + n, y + n, 0);
			add(x + 2 * n, y + 2 * n, 0);
		}
		else
		{
			add(x, y, 0);
			add(x + n, y + n, 0);
			add(x + 2 * n, y + 2 * n, 0);
			add(y, x, 0);
			add(y + n, x + n, 0);
			add(y + 2 * n, x + 2 * n, 0);
		}
	}
	spfa();
	cout << (ans > dist[3*n]?ans:dist[3*n]);

	return 0;
}