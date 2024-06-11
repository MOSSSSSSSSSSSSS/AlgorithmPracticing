

#include<bits/stdc++.h>
using namespace std;

const int N = 60, M = 1410,INF = 1e8;
int h[N], e[M], ne[M], w[M], idx;
int d[N], cur[N], q[N];
map<char, int> mp;
int n;

void add(int a, int b, int c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
bool bfs()
{
	int hh = 0, tt = -1;
	memset(d, -1, sizeof d);
	d[mp['A']] = 0, cur[mp['A']] = h[mp['A']], q[++tt] = mp['A'];
	while (hh <= tt)
	{
		//cout << "sb_zhang_jing";
		int t = q[hh++];
		for (int i = h[t]; ~i; i = ne[i])
		{
			int j = e[i];
			if (d[j] == -1 && w[i])
			{
				d[j] = d[t] + 1;
				cur[j] = h[j];
				q[++tt] = j;
				if (j == mp['Z'])return true;
			}
		}
	}
	return false;
}
int find(int u, int limit)
{
	if (u == mp['Z'])return limit;
	int flow = 0;
	for (int i = cur[u]; ~i&&flow<limit; i = ne[i])
	{
		//cout << "sb_zhang_jing";
		cur[u] = i;
		int j = e[i];
		if (d[j] == d[u] + 1 && w[i])
		{
			int t = find(j, min(w[i], limit - flow));/////////////////////////////////////////////////////////////////////////////////////////////
			if (!t)d[j] = -1;
			w[i] -= t, w[i ^ 1] += t, flow += t;
		}
	}
	return flow;
}
int dinic()
{
	int ans = 0, flow;
	while (bfs()) while (flow = find(mp['A'], INF)) ans += flow; 
	return ans;
}

int main()
{
	memset(h, -1, sizeof h);
	for (char i = 'A'; i <= 'Z'; i++)
		mp[i] = i - 'A';
	for (char i = 'a'; i <= 'z'; i++)
		mp[i] = i - 'a'+26;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		char a, b;
		int c;
		cin >> a >> b >> c;
		add(mp[a], mp[b], c), add(mp[b], mp[a], 0);
	}
	cout << dinic();

	return 0;
}
