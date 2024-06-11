

#include<bits/stdc++.h>
using namespace std;

const int N = 5010, M = 15010,INF = 0x3f3f3f3f;
int n, m;
int h[N], e[M], ne[M],w[M], idx;
int dist[N];
int cnt[N];
bool st[N];

void add(int a, int b,int c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

bool spfa()
{
	for (int i = 0; i <= n; i++)
		dist[i] = INF;
	dist[0] = 0;
	queue<int> q;
	q.push(0);
	st[0] = true;
	while (q.size())
	{
		int t = q.front();
		q.pop();
		st[t] = false;
		for (int i = h[t]; ~i; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				cnt[j] = cnt[t] + 1;
				if (cnt[j] >= n + 1)return true;
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
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		h[i] = -1;
	for (int i = 1; i <= n; i++)
		add(0, i, 0);
	for (int i = 1; i <= m; i++)
	{
		int flag, a, b;
		cin >> flag >> a >> b;
		if (flag == 1)
		{
			int c;
			cin >> c;
			add(a, b, -c);
		}
		else if (flag == 2)
		{
			int c;
			cin >> c;
			add(b, a, c);
		}
		else
			add(a, b, 0), add(b, a, 0);
	}
	if (spfa())cout << "No";
	else cout << "Yes";

	return 0;
}