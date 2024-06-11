

//  匈牙利算法超时，可以尝试建图变成最大流用dinic算法，还超时，可以考虑时间复杂度太高，建图方式优化
//  这题是用数学性质优化建图，用dinic算法最大流

#include<bits/stdc++.h>
using namespace std;

const int N = 510,M = 666000,K = 2000010,INF = 1e9;
int t,n,m;
int red[N], blue[N];
map<int, int> prime_ver;
int tot;
int d[M],cur[M],q[M];
int h[M], e[K], ne[K], w[K], idx;
int S, T;

void add(int a, int b, int c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void get_primes1(int ver,int x)
{
	for (int i = 2; i <= x / i; i++)
	{
		if (x % i == 0)
		{
			if (prime_ver[i])
				add(ver, prime_ver[i],1),add(prime_ver[i],ver,0);
			else
			{
				tot++;
				prime_ver[i] = m + tot;
				add(ver, prime_ver[i], 1), add(prime_ver[i], ver, 0);
			}
			
			while (x % i == 0)x /= i;
		}
	}
	if (x > 1)
	{
		if (prime_ver[x])
			add(ver, prime_ver[x], 1), add(prime_ver[x], ver, 0);
		else
		{
			tot++;
			prime_ver[x] = m + tot;
			add(ver, prime_ver[x], 1), add(prime_ver[x], ver, 0);
		}
	}
}
void get_primes2(int ver, int x)
{
	for (int i = 2; i <= x / i; i++)
	{
		if (x % i == 0)
		{
			if (prime_ver[i])
				add(prime_ver[i], ver, 1), add( ver, prime_ver[i], 0);
			else
			{
				tot++;
				prime_ver[i] = m + tot;
				add(prime_ver[i], ver, 1), add(ver, prime_ver[i], 0);
			}

			while (x % i == 0)x /= i;
		}
	}
	if (x > 1)
	{
		if (prime_ver[x])
			add(prime_ver[x], ver, 1), add(ver, prime_ver[x], 0);
		else
		{
			tot++;
			prime_ver[x] = m + tot;
			add(prime_ver[x], ver, 1), add(ver, prime_ver[x], 0);
		}
	}
}
int find(int u, int limit)
{
	if (u == T)return limit;
	int flow = 0;
	for (int i = cur[u]; ~i&&flow<limit; i = ne[i])
	{
		cur[u] = i;
		int j = e[i];
		if (d[j] == d[u] + 1 && w[i])
		{
			int t = find(j, min(w[i], limit - flow));
			if (!t)d[j] = -1;
			w[i] -= t, w[i ^ 1] += t, flow += t;
		}
	}
	return flow;
}
bool bfs()
{
	memset(d, -1, sizeof d);
	int hh = 0, tt = -1;
	q[++tt] = S, d[S] = 0, cur[S] = h[S];
	while (hh <= tt)
	{
		int t = q[hh++];
		for (int i = h[t]; ~i; i = ne[i])
		{
			int j = e[i];
			if (d[j] == -1 && w[i])
			{
				d[j] = d[t] + 1;
				cur[j] = h[j];
				q[++tt] = j;
				if (j == T)return true;
			}
		}
	}
	return false;
}
int dinic()
{
	int ans = 0, flow;
	while (bfs())while (flow = find(S, INF))ans += flow;
	return ans;
}

int main()
{
	cin >> t;
	while (t--)
	{
		memset(h, -1, sizeof h);
		idx = tot = 0;
		prime_ver.clear();
		cin >> m >> n;
		S = 0; 
		for (int i = 1; i <= m; i++)
			add(S, i, 1), add(i, S, 0);
		for (int i = 1; i <= m; i++)
			cin >> blue[i],get_primes1(i,blue[i]);
		for (int i = 1; i <= n; i++)
			cin >> red[i], get_primes2(2000+m+i,red[i]);
		T = 2000 + m + n + 1;
		for (int i = 1; i <= n; i++)
			add(2000+m+i, T, 1), add(T, 2000+m+i, 0);
		cout << dinic() << '\n';
	}

	return 0;
}