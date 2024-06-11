
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 100010, M = 300010, INF = 0x3f3f3f3f;
int h[N], e[M], ne[M], w[M], idx;
LL dist[N];
bool vis[N];
int cnt[N];
int q[N], hh, tt = -1;     //  假溢出，或TLE改用栈
int n, k;

void add(int a, int b, int c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

bool spfa()
{
	for (int i = 1; i <= n; i++)
		dist[i] = INF;
	dist[0] = 0;
	q[++tt] = 0;
	vis[0] = 1;
	while (hh <= tt)
	{
		int x = q[hh++];
		vis[x] = 0;
		for (int i = h[x]; ~i; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[x] + w[i])
			{
				dist[j] = dist[x] + w[i];
				cnt[j] = cnt[x] + 1;
				if (cnt[j] >= n + 1)return true;
				if (!vis[j])
				{
					q[++tt] = j;
					vis[j] = 1;
				}
			}
		}
	}
	return false;
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i <= n; i++)
		h[i] = -1;
	for (int i = 1; i <= n; i++)
		add(0, i, -1);
	for (int i = 1; i <= k; i++)
	{
		int x, a, b;
		scanf("%d%d%d",&x, &a, &b);
		if (x == 1)
			add(b, a, 0), add(a, b, 0);
		else if (x == 2)
			add(a, b, -1);
		else if (x == 3)
			add(b, a, 0);
		else if (x == 4)
			add(b, a, -1);
		else
			add(a, b, 0);
	}
	if (spfa())cout << -1;
	else
	{
		LL res = 0;
		for (int i = 1; i <= n; i++)
			res += ( - dist[i]);
		cout << res;
	}

	return 0;
}

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 100010, M = 300010, INF = 0x3f3f3f3f;
int h[N], e[M], ne[M], w[M], idx;
LL dist[N];
bool vis[N];
int cnt[N];
int q[N], hh, tt = 1;     //  假溢出，或TLE改用栈
int n, k;

void add(int a, int b, int c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

bool spfa()
{
	memset(dist, -0x3f, sizeof dist);
	dist[0] = 0;
	q[0] = 0;
	vis[0] = 1;
	while (hh != tt)
	{
		int x = q[--tt];
		vis[x] = 0;
		for (int i = h[x]; ~i; i = ne[i])
		{
			int j = e[i];
			if (dist[j] < dist[x] + w[i])
			{
				dist[j] = dist[x] + w[i];
				cnt[j] = cnt[x] + 1;
				if (cnt[j] >= n + 1)return true;
				if (!vis[j])
				{
					q[tt++] = j;
					vis[j] = 1;
				}
			}
		}
	}
	return false;
}

int main()
{
	scanf("%d%d", &n, &k);
	memset(h, -1, sizeof h);
	for (int i = 1; i <= n; i++)
		add(0, i, 1);
	for (int i = 1; i <= k; i++)
	{
		int x, a, b;
		scanf("%d%d%d", &x, &a, &b);
		if (x == 1)
			add(b, a, 0), add(a, b, 0);
		else if (x == 2)
			add(a, b, 1);
		else if (x == 3)
			add(b, a, 0);
		else if (x == 4)
			add(b, a, 1);
		else
			add(a, b, 0);
	}
	if (spfa())cout << -1;
	else
	{
		LL res = 0;
		for (int i = 1; i <= n; i++)
			res += dist[i];
		printf("%lld", res);
	}

	return 0;
}