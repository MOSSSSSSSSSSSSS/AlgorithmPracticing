


#include<bits/stdc++.h>
using namespace std;

typedef pair<long long, int> PII;
const int N = 1e5 + 10, M = 2e5 + 10;
int h[N], e[M], ne[M], w[M], idx;
int n, m;
long long dist[N];
bool st[N];
int last[N];
vector<int> ans;

void add(int a, int b, int c)
{
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}
void dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	priority_queue<PII, vector<PII>, greater<PII> > heap;
	heap.push({ dist[1],1 });
	while (heap.size())
	{
		PII t = heap.top();
		heap.pop();
		int ver = t.second;
		long long distance = t.first;
		if (st[ver])continue;
		st[ver] = true;
		for (int i = h[ver]; ~i; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > distance + w[i])
			{
				dist[j] = distance + w[i];
				last[j] = ver;
				heap.push({ dist[j],j });
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
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}
	dijkstra();
	if (dist[n] == 0x3f3f3f3f3f3f3f3f)
	{
		cout << -1;
		return 0;
	}
	for (int i = n;; i = last[i])
	{
		ans.push_back(i);
		if (i == 1)break;
	}
	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] << ' ';

	return 0;
}