

#include<bits/stdc++.h>
using namespace std;

const int N = 2010,M = 6010,INF = 0x3f3f3f3f;
int t;
int head[N], e[M], ne[M], w[M], idx;
int dist[N], cnt[N];
bool st[N];

void init(int n)
{
	for (int i = 1; i <= n; i++)
		cnt[i] = st[i] = 0;
	for (int i = 0; i <= idx; i++)
		e[i] = ne[i] = w[i] = 0;
	idx = 0;
}

void add(int x,int y,int z)
{
	e[idx] = y;
	ne[idx] = head[x];
	w[idx] = z;
	head[x] = idx++;
}

bool spfa(int n)
{
	for (int i = 2; i <= n; i++)dist[i] = INF;
	queue<int> q;
	q.push(1);
	st[1] = true;
	while (q.size())
	{
		int t = q.front();
		q.pop();
		st[t] = false;
		for (int i = head[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				cnt[j] = cnt[t] + 1;
				if (cnt[j] >= n)return true;

				if (!st[j])
				{
					q.push(j);
					st[j] = true;
				}
			}
		}
	}

	return false;
}

int main()
{
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)head[i] = -1;
		for (int i = 1; i <= m; i++)
		{
			int x, y, z;
			cin >> x >> y >> z;
			if (z >= 0) add(x, y, z), add(y, x, z);
			else add(x, y, z);
		}
		if (spfa(n)) cout << "YES" << endl;
		else cout << "NO" << endl;
		init(n);
	}

	return 0;
}