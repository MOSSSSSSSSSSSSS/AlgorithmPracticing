

#include<bits/stdc++.h>
using namespace std;

const int N = 11260, M = 52510, INF = 1e8;
int p[15];
int h[N], e[M], ne[M], w[M], idx;
int d[N], cur[N], q[N];
int n, m, k,S,T;
struct ship {
	int human, stop, path[20];
}ships[25];

int find(int x)
{
	if (p[x] != x)p[x] = find(p[x]);
	return p[x];
}
void add(int a, int b, int c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
	//cout <<endl<<"%%%" << a << ' ' << S << ' ' << h[a] << ' ' << h[S] << "%%%" << endl;
}
int find(int u, int limit)
{
	if (u == T)return limit;
	int flow = 0;
	for (int i = cur[u]; ~i && flow < limit; i = ne[i])
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
	int hh = 0, tt = -1;
	memset(d, -1, sizeof d);
	q[++tt] = S, d[S] = 0, cur[S] = h[S];
	//cout <<endl<< "%%%" << h[S] << "%%%" << endl;
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
	// 地球是0，月球是n+1
int main()
{
	cin >> n >> m >> k;
	S = N - 1, T = N - 2;
	memset(h, -1, sizeof h);
	for (int i = 0; i <= n + 1; i++)
		p[i] = i;
	for (int i = 1; i <= m; i++)
	{
		cin >> ships[i].human >> ships[i].stop;
		for (int j = 1; j <= ships[i].stop; j++)
		{
			cin >> ships[i].path[j];
			if (ships[i].path[j] == -1)ships[i].path[j] = n + 1;
			if (j > 1)
			{
				int x = ships[i].path[j - 1], y = ships[i].path[j];
				if (find(x) != find(y))p[find(x)] = find(y);
			}
		}
		ships[i].path[0] = ships[i].path[ships[i].stop];
	}
	if (find(0) != find(n + 1))cout << 0;
	else
	{
		add(S, 0, k), add(0, S, 0);
		int day = 0, tot = 0;
		while (tot < k)
		{
			day++;
			add((n + 2) * day + n + 1, T, k), add(T, (n + 2) * day + n + 1, 0);
			for (int i = 0; i <= n; i++)
				add((n + 2) * (day - 1) + i, (n + 2) * day + i, INF), add((n + 2) * day + i, (n + 2) * (day - 1) + i, 0);
			for (int i = 1; i <= m; i++)
			{
				add((n + 2) * (day - 1) + ships[i].path[day % ships[i].stop], (n + 2) * day + ships[i].path[(day + 1) % ships[i].stop], ships[i].human);
				add((n + 2) * day + ships[i].path[(day + 1) % ships[i].stop], (n + 2) * (day - 1) + ships[i].path[day % ships[i].stop], 0);
			}
			tot += dinic();
		}
		cout << day;
	}

	return 0;
}