

// ���ϲ���е��ֺͱ߲�֣��ֱ����������Ȩֵ�����Ӻͱ�Ȩֵ������
// ������� Ҫ�� u��v·���ϵ����е��Ȩ��1��o��lca��p��o�ĸ��ڵ� v[u]+1,v[v]+1,v[o]-1,v[p]-1 ��dfs����
// ����߲�� Ҫ�� u��v·���ϵ����б߱�Ȩ��1��o��lca��p��o�ĸ��ڵ� v[u]+1,v[v]+1,v[o]-1*2 ��dfs����

#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;
int n,a[N];
int h[N], e[N*2], ne[N*2], idx;
int v[N];
int dep[N], fa[N][20];

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void dfs1(int u,int father)
{
	dep[u] = dep[father] + 1;
	fa[u][0] = father;
	for (int i = 1; i < 20; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (j != father)dfs1(j, u);
	}
}
int lca(int a, int b)
{
	if (dep[a] < dep[b])swap(a, b);
	for (int i = 19; i >= 0; i--)
		if (dep[fa[a][i]] >= dep[b])
			a = fa[a][i];
	if (a == b)return a;
	for (int i = 19; i >= 0; i--)
		if (fa[a][i] != fa[b][i])
			a = fa[a][i], b = fa[b][i];
	return fa[a][0];
}
void dfs2(int u, int father)
{
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (j != father)
		{
			dfs2(j, u);
			v[u] += v[j];
		}
	}
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	dfs1(1, 0);
	for (int i = 1; i < n; i++)
	{
		int c = a[i], d = a[i + 1];
		int o = lca(c, d);
		int p = fa[o][0];
		v[c] += 1,v[d]+=1, v[o] -= 1, v[p] -= 1;
	}
	dfs2(1, 0);
	for (int i = 2; i <= n; i++)
		v[a[i]] -= 1;
	for (int i = 1; i <= n; i++)
		cout << v[i] << '\n';

	return 0;
}