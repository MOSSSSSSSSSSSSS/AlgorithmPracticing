

    100·Ö£º

#include<bits/stdc++.h>
using namespace std;

const int N = 110, M = 2010;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
bool st[N];
int cnt[N];
int S,t,n,m;

void add(int a, int b, int c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
bool spfa()
{
	memset(dist, 0x3f, sizeof dist);
	memset(st, 0, sizeof st);
	memset(cnt, 0, sizeof cnt);
	dist[S] = 0;
	queue<int> q;
	q.push(S);
	st[S] = true;
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
				if (cnt[j] == n + 2)return true;
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
		memset(h, -1, sizeof h);
		idx = 0;
		cin >> n >> m;
		S = n + 1;
		for (int i = 0; i <= n; i++)
			add(S, i, 0);
		for (int i = 1; i <= m; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			add(b, a - 1, -c), add(a - 1, b, c);
		}
		if (spfa())cout << "false" << endl;
		else cout << "true" << endl;
	}
	

	return 0;
}
       0·Ö£º
/*
#include<bits/stdc++.h>
using namespace std;

const int N = 110, M = 2010;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
bool st[N];
int cnt[N];
int S, t, n, m;

void add(int a, int b, int c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
bool spfa()
{
	memset(dist, 0x3f, sizeof dist);
	memset(st, 0, sizeof st);
	memset(cnt, 0, sizeof cnt);
	dist[S] = 0;
	queue<int> q;
	q.push(S);
	st[S] = true;
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
				if (cnt[j] == n + 1)return true;
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
		memset(h, -1, sizeof h);
		idx = 0;
		cin >> n >> m;
		S = 0;
		for (int i = 1; i <= n; i++)
			add(S, i, 0);
		for (int i = 1; i <= m; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			add(b, a - 1, -c), add(a - 1, b, c);
		}
		if (spfa())cout << "false" << endl;
		else cout << "true" << endl;
	}


	return 0;
}*/