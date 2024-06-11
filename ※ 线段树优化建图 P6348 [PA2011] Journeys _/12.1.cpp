
								   
// 线段树优化建图 点向区间连边，区间向点连边，如上一个例题，区间向区间连边 空间复杂度是m（logn方），若连的是双向边建两个虚点，就可以优化成
// 2mlogn，不能建一个虚点，否则原本a，b区间向c，d区间连双向边，a，b区间也会向a，b区间连边。 
// 建好两个虚点后，找a，b的，连完边，再找c，d的连完边。注意是每次新建边的时候都新建两个虚点，m1e5，所以虚点2e5个
// 若一个区间向另一个区间连单向边 建一个虚点。 
						 
					  
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;                         
const int N = 4e6 + 10 + 2e5, M = 1.1e7+10, K = 2e6;
int n, m, p;
int h[N], e[M], ne[M], w[M], idx;
struct node {
	int l, r;
}tr[N];
int leaf[N / 4];
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
	tr[u].l = l, tr[u].r = r;             //   只用 出树的有 l 和 r就行了，划分区间的时候也是在出树上看 
	//add(u, u + K, 0);                           上面和下面的 连边 任选一个就行
	if (l == r)
	{
		add(u, u + K, 0), add(u + K, u, 0);
		leaf[l] = u;
		return;
	}
	int mid = l + r >> 1;
	add(u, u << 1, 0), add(u, u << 1 | 1, 0);
	add((u << 1) + K, u + K, 0), add((u << 1 | 1) + K, u + K, 0);
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}
/*void modify(int u1, int u2, int a, int b, int c, int d)
{
	if (a <= tr[u1].l && tr[u1].r <= b && c <= tr[u2].l && tr[u2].r <= d)
	{
		add(u1 + K, u2, 1), add(u2 + K, u1, 1);
		return;
	}
	int mid = tr[u1].l + tr[u1].r >> 1;
	if (a <= mid)modify(u1 << 1, u2, a, b, c, d);
	if (b >= mid + 1)modify(u1 << 1 | 1, u2, a, b, c, d);
	int mid2 = tr[u2].l + tr[u2].r >> 1;
	if (c <= mid2)modify(u1, u2 << 1, a, b, c, d);
	if (d >= mid2 + 1)modify(u1, u2 << 1 | 1, a, b, c, d);
}*/
void modify(int u, int a, int b,int xu1,int xu2)
{
	if (a <= tr[u].l && tr[u].r <= b)
	{
		add(u + K, xu1, 1);
		add(xu2, u, 0);
		return;
	}
	int mid = tr[u].l + tr[u].r >> 1;
	if (a <= mid)modify(u << 1, a, b, xu1, xu2);
	if (b >= mid + 1)modify(u << 1 | 1, a, b, xu1, xu2);
}
void modify2(int u, int c, int d, int xu1, int xu2)
{
	if (c <= tr[u].l && tr[u].r <= d)
	{
		add(u + K, xu2, 1);                                
		add(xu1, u, 0);
		return;
	}
	int mid = tr[u].l + tr[u].r >> 1;                          
	if (c <= mid)modify2(u << 1, c, d, xu1, xu2);
	if (d >= mid + 1)modify2(u << 1 | 1, c, d, xu1, xu2);
}
void dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	dist[leaf[p]] = 0;                                     
	priority_queue<PII, vector<PII>, greater<PII> >heap;
	heap.push({ dist[leaf[p]],leaf[p] });
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

int main()
{
	memset(h, -1, sizeof h);                         
	cin >> n >> m >> p;                                           
	build(1, 1, n);       
	while (m--)                                        //  因为这里调了一天，因为最后m等于0，虚点的编号是N，刚好超了。
	{                                                  //  我以为只要能进来 m就大于0，实际上 后置的--是先用原先的值判断，再减1，进到循环里面来是减完后的值，判断是减前的值
		int a, b, c, d;
		int xu1 = N - m - 1, xu2 = N - m - 1 -1e5;
		cin >> a >> b >> c >> d;
		modify(1, a, b,xu1,xu2);
		modify2(1, c, d, xu1, xu2);
	}
	dijkstra();
	for (int i = 1; i <= n; i++)
	{
		cout << dist[leaf[i]] << '\n';
	}

	return 0;
}