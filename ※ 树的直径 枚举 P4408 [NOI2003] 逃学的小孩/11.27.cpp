



//  bfs 记得 把点push进去
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, M = 4e5 + 10;
int h[N], e[M], ne[M],w[M], idx; int n, m;//双向边两倍
int d, st, ed, dist[N]; bool vis[N];
//d是直径，st是起点，ed是终点，dist是距离，记得清零，vis是bfs遍历时的是否访问，记得清零
int dist2[N];
int ans;

int bfs(int u)
{
	memset(dist, 0, sizeof dist);
	memset(vis, 0, sizeof vis);
	int node = 0;// 记录距离最远的是哪个点
	queue<int> q;
	q.push(u), vis[u] = true;/////////////////////////////////////////////////////
	while (q.size())
	{
		int t = q.front();
		q.pop();
		for (int i = h[t]; ~i; i = ne[i])
		{
			int j = e[i];
			if (!vis[j])//////////////////////////////////////////////////////////
			{
				vis[j] = true;
				dist[j] = dist[t] + w[i];/////////////////////////////////////////
				if (dist[j] >= d)////////////////////////////////
				{
					d = dist[j];//////////////
					node = j;/////////////////
				}
				q.push(j);////////////////////////////////////////////////////////
			}
		}
	}
	return node;
}
void bfs2(int u)
{
	memset(vis, 0, sizeof vis);
	queue<int> q;
	q.push(u), dist2[u] = 0, vis[u] = true;
	while (q.size())
	{
		int t = q.front();
		q.pop();
		for (int i = h[t]; ~i; i = ne[i])
		{
			int j = e[i];
			if (!vis[j])
			{
				vis[j] = true;
				dist2[j] = dist2[t] + w[i];
				q.push(j);
			}
		}
	}
}

signed main()
{
	//初始化邻接表
	//输入点数边数
	//加边
	st = bfs(1);ed = bfs(st);
	bfs2(ed);
	for (int i = 1; i <= n; i++)
		if (i != st && i != ed)
			ans = max(ans, min(dist[i], dist2[i]));
	//这是树，刚才bfs求出所有点到ed的长度，再次bfs2求出所有点到st的长度，
	//枚举所有点，一个点到ed和st的距离的较小值最大，即是答案所求点。
	cout << d +ans;

	return 0;
}