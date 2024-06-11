



//  bfs �ǵ� �ѵ�push��ȥ
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, M = 4e5 + 10;
int h[N], e[M], ne[M],w[M], idx; int n, m;//˫�������
int d, st, ed, dist[N]; bool vis[N];
//d��ֱ����st����㣬ed���յ㣬dist�Ǿ��룬�ǵ����㣬vis��bfs����ʱ���Ƿ���ʣ��ǵ�����
int dist2[N];
int ans;

int bfs(int u)
{
	memset(dist, 0, sizeof dist);
	memset(vis, 0, sizeof vis);
	int node = 0;// ��¼������Զ�����ĸ���
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
	//��ʼ���ڽӱ�
	//�����������
	//�ӱ�
	st = bfs(1);ed = bfs(st);
	bfs2(ed);
	for (int i = 1; i <= n; i++)
		if (i != st && i != ed)
			ans = max(ans, min(dist[i], dist2[i]));
	//���������ղ�bfs������е㵽ed�ĳ��ȣ��ٴ�bfs2������е㵽st�ĳ��ȣ�
	//ö�����е㣬һ���㵽ed��st�ľ���Ľ�Сֵ��󣬼��Ǵ�����㡣
	cout << d +ans;

	return 0;
}