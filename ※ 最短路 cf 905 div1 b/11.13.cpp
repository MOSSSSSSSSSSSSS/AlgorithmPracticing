

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 2e5+10,INF = 0x3f3f3f3f;
int n, t, k;
map<pair<int, int>, int> mp; int cnt;
vector<int> tim[N];
vector<int> edge[N];
int dist[N];
bool st[N];
vector<int> travel[N];

int get_tim(int u,int v,int num)
{
	int m = INF;
	for (auto history : tim[mp[{u,v}]])
	{
		auto ptr = lower_bound(travel[history].begin(), travel[history].end(), num);
		if (ptr == travel[history].end())continue;
		m = min(m, *ptr - num + 1);
	}
	return m;
}
 
void dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 1;
	priority_queue<PII, vector<PII>, greater<PII> > heap;
	heap.push({ dist[1],1 });
	while (heap.size())
	{
		PII t = heap.top();
		heap.pop();
		int ver = t.second, distance = t.first;
		if (st[ver])continue;
		st[ver] = true;
		for (auto item : edge[ver])
		{
			int wcnm = get_tim(ver,item,dist[ver]);
			if (dist[item] > dist[ver] + wcnm)
			{
				dist[item] = dist[ver] + wcnm;
				heap.push({ dist[item],item });
			}
		}
	}
}
int main()
{
	cin >> n >> t;
	for (int i = 1; i <= t; i++)
	{
		int m;
		cin >> m;
		for (int j = 1; j <= m; j++)
		{
			int u, v;
			cin >> u >> v;
			if (!mp[{u, v}])mp[{u, v}] = mp[{v, u}] = ++cnt;
			tim[mp[{u,v}]].push_back(i);
			edge[u].push_back(v), edge[v].push_back(u);
		}
	}
	cin >> k;
	for (int i = 1; i <= k; i++)
	{
		int x;
		cin >> x;
		travel[x].push_back(i);
	}
	dijkstra();
	if (dist[n] == INF)cout << -1;
	else cout << dist[n] - 1;

	return 0;
}