

//  本来想的是  dist[1] = cnt;,走过没有坏的路，边权是-1，dist就-1，走过坏的路需要修复，边权+1，最后求最短路即可，但是有负权环，这个题没法做

// 之后发现一开始理解错题意了，就是边权为1找最短路，如果有多条，要影响最少的一条
// 要以 路径长度为第一关键字，路径上完好道路数量为第二关键字
/*
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
bool st[N];
int n, m,cnt;
int Prev[N],last;
map<pair<int,int>, int> mp;

void add(int a, int b,int c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void spfa()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = cnt;
	queue<int> q;
	q.push(1);
	st[1] = true;
	while (q.size())
	{
		int tt = q.front();
		q.pop();
		st[tt] = false;///////////////////////////////////////////////////////////////////////////////////////////
		for (int i = h[tt]; ~i; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[tt] + w[i])
			{
				Prev[j] = tt;
				dist[j] = dist[tt] + w[i];
				if (!st[j])
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
	if (n == 4)
	{
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		if (z == 1)
			add(x, y, -1), add(y, x, -1),cnt++;
		else
			add(x, y, 1), add(y, x, 1);
		mp[{x, y}] = mp[{y, x}] = z;
	}
	spfa();
	cout << dist[n]<<endl;
	last = n;
	for (int i = 1; i <= dist[n]; i++)
	{
		cout << last << ' ' << Prev[last] << ' ';
		if (mp[{last, Prev[last]}] == 1)cout << 0 << endl;
		else cout << 1 << endl;
		last = Prev[last];
	}

	return 0;
}*/
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 1e5 + 10, M = 2e5 + 10;
int h[N], e[M], ne[M], w[M],flag[M], idx;
int n, m, cnt;
int dist[N], num[N];
bool vis[N];
map<pair<int, int>, int> mp;
int Prev[N], last;

void add(int a, int b,int c)
{
	flag[idx] = c;
	w[idx] = 1;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0,num[1] = 0;
	priority_queue<PII, vector<PII>, greater<PII> >heap;
	heap.push({ dist[1],1 });
	while (heap.size())
	{
		PII t = heap.top();
		heap.pop();
		int ver = t.second, distance = t.first;
		if (vis[ver])continue;
		vis[ver] = true;
		for (int i = h[ver]; ~i; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > w[i] + distance)
			{
				Prev[j] = ver;
				num[j] = num[ver];
				if (flag[i] == 1)num[j]++;
				dist[j] = w[i] + distance;
				heap.push({ dist[j],j });
			}
			else if (dist[j] == w[i] + distance)
			{
				int res = num[ver];
				if (flag[i] == 1)res++;
				if (num[j] < res)
				{
					Prev[j] = ver;
					num[j] = res;
				}
			}
		}
	}
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z), add(y, x, z);
		if (z == 1)cnt++;
	}
	dijkstra();
	cout << dist[n] - 2*num[n] + cnt<< endl;
	last = n;
	for (;Prev[last];last = Prev[last])
		mp[{last, Prev[last]}] = mp[{ Prev[last],last}] = 1;
	for (int i = 0; i < idx; i += 2)
	{
		int a = e[i], b = e[i ^ 1];
		if (mp[{a, b}] == 1&&flag[i]==0)
		{
			cout << a << ' ' << b << ' ' << 1 << endl;
		}
		else if(mp[{a,b}]==0&&flag[i]==1)
		{
			cout << a << ' ' << b << ' ' << 0 << endl;
		}
	}

	return 0;
}