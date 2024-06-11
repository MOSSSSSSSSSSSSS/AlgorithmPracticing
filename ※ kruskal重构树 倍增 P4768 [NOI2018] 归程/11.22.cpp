

// kruskal重构树 若原图不连通 是个森林
/*
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")*/
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;
const int N = 200010,M = 400010;
struct node {
	int to, l,a;
};
struct edge {
	int a, b, w;
}edges[M];
vector<node> edge1[N];   // vector 存图
vector<int> edge2[2 * N];
int T, n, m,q,k,s;
int dist[N];
bool st[N];
int fa[N*2];
int mn_dist[2 * N];
int bzfa[2*N][20];   ///////////%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%   20 一般也超不了空间1
int v[2 * N];

int find(int x)
{
	if (fa[x] != x)fa[x] = find(fa[x]);
	return fa[x];
}
void dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	priority_queue<PII, vector<PII>, greater<PII> >heap;
	heap.push({ dist[1],1 });
	while (heap.size())
	{
		PII t = heap.top();
		heap.pop();
		int ver = t.second, distance = t.first;
		if (st[ver])continue;
		st[ver] = true;
		for (auto item : edge1[ver])
		{
			if (dist[item.to] > distance + item.l)
			{
				dist[item.to] = distance + item.l;
				heap.push({ dist[item.to],item.to });
			}
		}
	}
}
bool cmp(edge a, edge b)
{
	return a.w > b.w;
}
void kruskal()
{
	int cnt = 0;
	for (int i = 1; i <= 2 * n; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++)
	{
		int a = edges[i].a, b = edges[i].b, w = edges[i].w;
		int f1 = find(a), f2 = find(b);
		if (f1 != f2)
		{
			cnt++;
			v[cnt + n] = w;
			edge2[cnt + n].push_back(fa[f1]);
			edge2[cnt + n].push_back(fa[f2]);
			if (cnt + n == 5)cout << "$$$" << fa[f1] << ' ' << fa[f2] << endl;
			fa[f1] = fa[f2] = cnt + n;
			if (cnt == n - 1)return;
		}
	}
}
void dfs(int u)
{
	if (1 <= u && u <= n)
	{
		mn_dist[u] = dist[u];
		return;
	}
	for (auto item : edge2[u])
	{
		dfs(item);
		mn_dist[u] = min(mn_dist[u], mn_dist[item]);    //  min运算，mn_dist没初始化是0，要初始化正无穷%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	}
}
void bz(int u,int father)
{
	bzfa[u][0] = father;
	for (int i = 1; i < 20; i++)
		bzfa[u][i] = bzfa[bzfa[u][i - 1]][i - 1];
	for (auto item : edge2[u])
		bz(item,u);
}
int query(int x,int p)
{
	for (int i = 19; i >= 0; i--)
		if (v[bzfa[x][i]] > p)
			x = bzfa[x][i];
	return x;
}

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		for (int i = 1; i <= m; i++)
		{
			int u, v, l, a;
			cin >> u >> v >> l >> a;
			edge1[u].push_back({ v,l,a });
			edge1[v].push_back({ u,l,a });
			edges[i] = { u,v,a };
		}
		dijkstra();
		sort(edges + 1, edges + 1 + m, cmp);
		kruskal();
		memset(mn_dist, 0x3f, sizeof mn_dist);
		dfs(2*n-1);
		bz(2 * n - 1, 0);
		cin >> q >> k >> s;
		int lastans = 0;
		while (q--)
		{
			int v, p;
			cin >> v >> p;
			v = (v + k * lastans - 1) % n + 1;
			p = (p + k * lastans) % (s + 1);
			lastans = mn_dist[query(v, p)];
			cout << lastans << '\n';
		}
		memset(bzfa, 0, sizeof bzfa);
		memset(fa, 0, sizeof fa);
		memset(st, 0, sizeof st);
		memset(v ,0, sizeof v);
		memset(mn_dist, 0, sizeof mn_dist);
		for (int i = 1; i <= 2 * n;i++)
			edge2[i].clear();
		for (int i = 1; i <= n;i++)
			edge1[i].clear();
	}

	return 0;
}