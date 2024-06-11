

#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const int N = 1000010, mod = 100003;
int head[N], ne[4 * N], e[4 * N], idx;      //   双向的边，一个顶俩      ，邻接表存储树和图
int n, m;
int dist[N], ans[N];

void add(int x, int y)
{
	e[idx] = y;
	ne[idx] = head[x];
	head[x] = idx++;
}

void bfs()
{
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		for (int i = head[t]; i != -1; i = ne[i])
		{
			int v = e[i];
			if (v != t)
			{
				if (dist[v] == -1)
				{
					dist[v] = dist[t] + 1;
					q.push(v);
				}
				else
					if (dist[v] < dist[t] + 1)
						continue;
				ans[v] = (ans[v] + ans[t]) % mod;                    //%%%%%%%%%%%%%%%%%%%%%%%%%%%%自己写的算法拿样例模拟一遍就知道哪里出错了%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
				// 一开始写的 加1，每一个都挨个加1，要得到最终结果用时太长，可以通过看他是由哪个点过来的，那么它的最短路数量+=过来的那个点的最短路数量，这样就快多了
			}                                                        //  有时候MLE不一定是空间的问题，也可能是算法不好的问题
		}
	}
}

int main()
{
	freopen("D:\\P1144_4.in", "r", stdin);          //  输入重定向,交的时候记得注释了，否则全TLE

	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)dist[i] = head[i] = -1;
	ans[1] = 1;
	dist[1] = 0;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		add(x, y);
		add(y, x);
	}

	bfs();
	for (int i = 1; i <= n; i++)
		cout << ans[i] % mod << endl;

	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;

const int N = 1000010,mod = 100003,INF = 1e9;
int head[N], ne[4 * N], e[4 * N], idx;
int n, m;
int dist[N],ans[N];

void add(int x, int y)
{
	e[idx] = y;
	ne[idx] = head[x];
	head[x] = idx++;
}

void bfs()
{
	//int q[N], hh = 0, tt = -1;
	queue<int> q;                  //   用手写的队列，说占用空间太多，考虑将一部分移到堆
	//q[++tt] = 1;
	q.push(1);
	while (hh <= tt*!q.empty())
	{
		//int t = q[hh++];
		int t = q.front();
		q.pop();
		for (int i = head[t]; i != -1; i = ne[i])
		{
			int v = e[i];
			if (v != t   && (dist[v] == -1 || v == x)  )
			{
				if ((dist[x] != INF) && v == x)
				{
					if (dist[x] == dist[t] + 1)
						ans[x] = (ans[x]+1)%mod;
					else
					{
						while (!q.empty())q.pop();
						break;
					}
				}
				else if(v==x&&dist[x]==INF)
				{
					dist[x] = dist[t] + 1;
					ans[x] = (ans[x] + 1) % mod;
				}
				else
				{
					if(dist[v]==INF)
						dist[v] = dist[t] + 1;
					else
						if (dist[v] < dist[t] + 1)
							continue;
					//q[++tt] = v;
					q.push(v);
				}

				if (dist[v] == INF)
					dist[v] = dist[t] + 1;
				else
					if (dist[v] < dist[t] + 1)
						continue;
				ans[v] = (ans[v] + 1) % mod;
				q.push(v);
			}
		}
	}
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int j = 1; j <= n; j++)head[j] = -1;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		add(x, y);
		add(y, x);
	}
	ans[1] = 1;
	for (int j = 2; j <= n; j++)dist[j] = INF;
	dist[1] = 0;
	//for (int i = 2; i <= n; i++)
		bfs();
	for (int i = 1; i <= n; i++)
		cout << ans[i] << endl;

	return 0;
}
*/