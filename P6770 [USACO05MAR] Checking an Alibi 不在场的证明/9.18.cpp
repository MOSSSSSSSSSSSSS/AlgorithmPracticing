

#include<bits/stdc++.h>
using namespace std;

const int N = 510, M = 2010,INF = 0x3f3f3f3f;
int f, p, c, m;
int h[N], e[M], ne[M], t[M], idx;
int dist[N];
int pos[N];
bool vis[N];
vector<int> ans;

void add(int a, int b, int c)
{
	t[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

void spfa()
{
	for (int i = 1; i <= f; i++)
		dist[i] = INF;
	dist[1] = 0;
	queue<int> q;
	q.push(1);
	vis[1] = 1;
	while (q.size())
	{
		int tt = q.front();
		q.pop();
		vis[tt] = 0;
		for (int i = h[tt]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[tt] + t[i])
			{
				dist[j] = dist[tt] + t[i];
				if (!vis[j])
				{
					q.push(j);
					vis[j] = 1;
				}
			}
		}
	}
}

int main()
{
	cin >> f >> p >> c >> m;
	for (int i = 1; i <= f; i++)
		h[i] = -1;
	for (int i = 1; i <= p; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}
	for (int i = 1; i <= c; i++)
		cin >> pos[i];
	spfa();
	for (int i = 1; i <= c; i++)
		if (dist[pos[i]] <= m)
			ans.push_back(i);
	sort(ans.begin(),ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;

	return 0;
}