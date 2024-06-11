

//  需要两颗线段树，一个 子节点可以到达父节点叫入树，一个父节点可以到达子节点叫出树，线段树的树边的权值是0，只起辅助作用
//  建好后使用堆优化dijkstra

#include<bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 4e5 + 10,M = 3e6+10,K = 2e5;
int h[N], e[M], ne[M], w[M], idx;
int n, q, s;
struct node {
	int l, r;
}tr[N];
int leaf[N / 2];
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r;
	if (l == r)
	{
		leaf[l] = u;
		return;
	}
	add(u, u << 1, 0), add(u, u << 1 | 1, 0);
	add((u << 1) + K, u + K, 0), add((u << 1 | 1) + K, u + K, 0);
	int mid = l + r >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}
void modify(int u, int l, int r, int v, int w,int op)
{
	if (l <= tr[u].l && tr[u].r <= r)
	{
		if (op == 2)add(leaf[v] + K, u, w);
		else add(u + K, leaf[v], w);
		return;
	}
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)modify(u << 1, l, r, v, w, op);
	if (r >= mid + 1)modify(u << 1 | 1, l, r, v, w, op);
}
void dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	dist[leaf[s]] = 0;
	priority_queue<PII, vector<PII>, greater<PII> >heap;
	heap.push({ dist[leaf[s]],leaf[s]});
	while (heap.size())
	{
		PII t = heap.top();
		heap.pop();
		int ver = t.second, distance = t.first;
		if (st[ver])continue;
		st[ver] = true;
		for (int i = h[ver]; ~i; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > distance + w[i])
			{
				dist[j] = distance + w[i];
				heap.push({ dist[j],j });
			}
		}
	}
}

signed main()
{
	memset(h, -1, sizeof h);
	cin >> n >> q >> s;                                                      //   s也是叶节点，leaf是编号//////////////////////////////////////////////////////////////////////////////////////////
	build(1, 1, n);
	for (int i = 1; i <= n; i++)
		add(leaf[i], leaf[i] + K, 0), add(leaf[i] + K, leaf[i], 0);
	while (q--)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			int v, u, w;
			cin >> v >> u >> w;
			add(leaf[v], leaf[u], w);
		}
		else
		{
			int v, l, r, w;
			cin >> v >> l >> r >> w;
			modify(1, l, r, v, w, op);
		}
	}
	dijkstra();
	for (int i = 1; i <= n; i++)
	{
		int x = dist[leaf[i]];
		if (x == 0x3f3f3f3f3f3f3f3f)cout << -1 << ' ';
		else cout << x << ' ';
	}

	return 0;
}

