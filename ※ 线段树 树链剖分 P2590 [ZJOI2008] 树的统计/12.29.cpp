

#include<bits/stdc++.h>
using namespace std;
#define ls u<<1
#define rs u<<1|1
const int N = 3e4 + 10,INF = 1e8;
int n, q, w[N];
vector<int> edge[N];
int dep[N], fa[N], sz[N], son[N];
int top[N], id[N], nw[N],idx;
struct node {
	int l, r, sum, mx;
}tr[4*N];

void dfs1(int u, int father)
{
	fa[u] = father, dep[u] = dep[father] + 1, sz[u] = 1;
	for (auto item : edge[u])
	{
		if (item != father)
		{
			dfs1(item, u);
			sz[u] += sz[item];
			if (sz[item] > sz[son[u]])son[u] = item;
		}
	}
}
void dfs2(int u, int father)
{
	top[u] = father,id[u] = ++idx,nw[idx] = w[u];
	if (!son[u])return;
	dfs2(son[u], father);
	for (auto item : edge[u])
		if (item != fa[u] && item != son[u])/////////////////  不是不等于father，是不等于u的father
			dfs2(item, item);
}
void pushup(int u)
{
	tr[u].mx = max(tr[ls].mx, tr[rs].mx);
	tr[u].sum = tr[ls].sum + tr[rs].sum;
}
void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r;
	if (l == r)
	{
		tr[u].mx = tr[u].sum = nw[l];
		return;
	}
	int mid = l + r >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	pushup(u);
}
void modify(int u, int p, int x)
{
	if (tr[u].l == tr[u].r && tr[u].l == p)
	{
		tr[u].mx = tr[u].sum = x;
		return;
	}
	int mid = tr[u].l + tr[u].r >> 1;
	if (p <= mid)modify(ls, p, x);
	else if (p >= mid + 1)modify(rs, p, x);
	pushup(u);
}
int query1(int u,int l,int r)
{
	int mx = -INF;
	if (l<=tr[u].l&&tr[u].r<=r)
	{
		return tr[u].mx;
	}
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)mx = max(mx, query1(ls, l, r));
	if (r >= mid + 1)mx = max(mx, query1(rs, l, r));
	return mx;
}
int query_1(int u, int v)
{
	int res = -INF;
	while (top[u] != top[v])
	{
		if (dep[top[u]] < dep[top[v]])swap(u, v);
		res = max(res,query1(1, id[top[u]], id[u]));
		u = fa[top[u]];
	}
	if (dep[u] < dep[v])swap(u, v);
	res = max(res,query1(1, id[v], id[u]));
	return res;
}
int query2(int u, int l, int r)
{
	int mx = 0;
	if (l <= tr[u].l && tr[u].r <= r)
	{
		return tr[u].sum;
	}
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)mx += query2(ls, l, r);
	if (r >= mid + 1)mx += query2(rs, l, r);
	return mx;
}
int query_2(int u, int v)
{
	int res = 0;
	while (top[u] != top[v])
	{
		if (dep[top[u]] < dep[top[v]])swap(u, v);
		res += query2(1, id[top[u]], id[u]);
		u = fa[top[u]];
	}
	if (dep[u] < dep[v])swap(u, v);
	res += query2(1, id[v], id[u]);
	return res;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)cin >> w[i];
	dfs1(1, 0);
	dfs2(1, 1);
	build(1, 1, n);
	cin >> q;
	while (q--)
	{
		string op;
		int u, v;
		cin >> op >> u >> v;
		if (op == "CHANGE")modify(1, id[u], v);
		else if (op == "QMAX")cout << query_1(u, v) << '\n';
		else cout << query_2(u, v) << '\n';
	}

	return 0;
}
/*
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
#define N 100007
#define INF 10000000
using namespace std;
int n,cnt,num,Q;
int val[N],head[N];
int f[N],dep[N],size[N],son[N];	//Dfs1处理 父亲，深度，大小，重儿子
int top[N],id[N],rk[N];	//Dfs2处理 链顶，Dfs序新编号 ，新编号对应原编号
struct Edge {
	int next,to;
}edge[N<<1];
struct Segment_Tree
{
	int sum[N<<2] ,maxv[N<<2];
	inline int ls(int p) {return p<<1;}
	inline int rs(int p) {return p<<1|1;}
	void push_up(int p) {
		sum[p] = sum[ls(p)] + sum[rs(p)];
		maxv[p] = max(maxv[ls(p)],maxv[rs(p)]);
	}
	void build(int p,int l,int r)
	{
		if(l==r) {sum[p]=maxv[p]=val[rk[l]]; return ;}
		int mid = (l+r)>>1;
		build(ls(p),l,mid);
		build(rs(p),mid+1,r);
		push_up(p);
	}
	int Querysum(int ql,int qr,int p,int l,int r)
	{
		if(ql<=l && r<=qr) return sum[p];
		int res=0 ,mid=(l+r)>>1;
		if(ql<=mid) res += Querysum(ql,qr,ls(p),l,mid);
		if(qr>mid) res += Querysum(ql,qr,rs(p),mid+1,r);
		return res;
	}
	int Querymax(int ql,int qr,int p,int l,int r)
	{
		if(ql<=l && r<=qr) return maxv[p];
		int Max=-INF ,mid=(l+r)>>1;
		if(ql<=mid) Max = max(Max,Querymax(ql,qr,ls(p),l,mid));
		if(qr>mid) Max = max(Max,Querymax(ql,qr,rs(p),mid+1,r));
		return Max;
	}
	void update(int p,int l,int r,int q,int v)
	{
		int mid = (l+r)>>1;
		if(l==r) {sum[p] = maxv[p] = v; return ;}
		if(q<=mid) update(ls(p),l,mid,q,v);
		else update(rs(p),mid+1,r,q,v);
		push_up(p);
	}
}tree;
int qsum(int x,int y)
{
	int res = 0;
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x,y);
		res += tree.Querysum(id[top[x]],id[x],1,1,n);
		x = f[top[x]];
	}
	if(dep[x] > dep[y]) swap(x,y);
	return res += tree.Querysum(id[x],id[y],1,1,n);
}
int qmax(int x,int y)
{
	int res = -INF;
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x,y);
		res = max(res,tree.Querymax(id[top[x]],id[x],1,1,n));
		x = f[top[x]];
	}
	if(dep[x] > dep[y]) swap(x,y);
	return res = max(res,tree.Querymax(id[x],id[y],1,1,n));
}