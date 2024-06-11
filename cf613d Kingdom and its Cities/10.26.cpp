

//  建虚树，树形dp，树链剖分求lca

#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int n, q;
vector<int> edge[N];
int siz[N];
int dep[N], fa[N], stk[N], top, son[N], ttop[N], sz[N];
int dfn[N], timestamp;
int k;
vector<int> city;
int ans;
void dfs0(int u, int father)
{
	dep[u] = dep[father] + 1, fa[u] = father;
	sz[u] = 1;
	for (auto item : edge[u])
	{
		if (item != father)
		{
			dfs0(item, u);
			sz[u] += sz[item];
			if (sz[item] > sz[son[u]])son[u] = item;
		}
	}
}
void dfs1(int u, int t)
{
	ttop[u] = t;
	if (!son[u])return;
	dfs1(son[u], t);
	for (auto item : edge[u])
	{
		if (item != son[u] && item != fa[u])
		{
			dfs1(item, item);
		}
	}
}
int lca(int u, int v)
{
	while (ttop[u] != ttop[v])
	{
		if (dep[ttop[u]] < dep[ttop[v]])swap(u, v);
		u = fa[ttop[u]];
	}
	return dep[u] < dep[v] ? u : v;
}
bool cmp(int x, int y)
{
	return dfn[x] < dfn[y];
}
void dfs2(int u)
{
	if (siz[u])
	{
		for (auto item:edge[u])
		{
			dfs2(item);
			if (siz[item])ans++, siz[item] = 0;
		}
	}
	else
	{
		for (auto item : edge[u])
		{
			dfs2(item);
			if (siz[item])siz[u] += siz[item], siz[item] = 0;
		}
		if (siz[u] > 1)ans++, siz[u] = 0;
	}
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
	dfs0(1, 0);
	dfs1(1, 1);
	cin >> q;
	while (q--)
	{
		for (int i = 1; i <= n; i++)
			edge[i].clear();
		city.clear();
		ans = top = 0;
		bool flag = false;
		cin >> k;
		for (int i = 1; i <= k; i++)
		{
			int x;
			cin >> x;
			city.push_back(x);
			siz[x] = 1;
		}
		for (int i = 1; i <= n; i++)
		{
			if (siz[fa[i]] && siz[i])
			{
				cout << -1 << endl;
				flag = true;
				break;
			}
		}
		if (flag)continue;
		sort(city.begin(), city.end(), cmp);
		stk[++top] = 1;
		if (city[0] != 1)stk[++top] = city[0];
		for (int i = 2; i <= k; i++)
		{
			int l = lca(city[i - 1], stk[top]);
			while (top > 1 && dep[stk[top - 1]] >= dep[l])
				edge[stk[top - 1]].push_back( stk[top]), top--;
			if (l != stk[top])edge[l].push_back(stk[top]), stk[top] = l;
			stk[++top] = city[i - 1];
		}
		while (top > 1)
			edge[stk[top - 1]].push_back(stk[top]), top--;
		dfs2(1);
		cout << ans << endl;
		for(int i = 1;i<=)
	}

	return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int n, q;
vector<int> edge[N];
int h[N], e[N], ne[N], idx;
int siz[N];
int dep[N], fa[N], stk[N], top,son[N],ttop[N],sz[N];
int dfn[N], timestamp;
int k;
vector<int> city;
int ans;
void dfs0(int u, int father)
{
	dep[u] = dep[father] + 1, fa[u] = father;
	sz[u] = 1;
	for (auto item : edge[u])
	{
		if (item != father)
		{
			dfs0(item, u);
			sz[u] += sz[item];
			if (sz[item] > sz[son[u]])son[u] = item;
		}
	}
}
void dfs1(int u,int t)
{
	ttop[u] = t;
	if (!son[u])return;
	dfs1(son[u], t);
	for (auto item : edge[u])
	{
		if (item != son[u] && item != fa[u])
		{
			dfs1(item, item);
		}
	}
}
int lca(int u, int v)
{
	while (ttop[u] != ttop[v])
	{
		if (dep[ttop[u]] < dep[ttop[v]])swap(u, v);
		u = fa[ttop[u]];
	}
	return dep[u] < dep[v] ? u : v;
}
bool cmp(int x, int y)
{
	return dfn[x] < dfn[y];
}
void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void dfs2(int u)
{
	if (siz[u])
	{
		for (int i = h[u]; ~i; i = ne[i])
		{
			int j = e[i];
			dfs2(j);
			if (siz[j])ans++, siz[j] = 0;
		}
	}
	else
	{
		for (int i = h[u]; ~i; i = ne[i])
		{
			int j = e[i];
			dfs2(j);
			if (siz[j])siz[u] += siz[j], siz[j] = 0;
		}
		if (siz[u] > 1)ans++, siz[u] = 0;
	}
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
	dfs0(1, 0);
	dfs1(1, 1);
	cin >> q;
	while (q--)
	{
		memset(h, -1, sizeof h);
		memset(siz, 0, sizeof siz);
		city.clear();
		idx = ans = top = 0;
		bool flag = false;
		cin >> k;
		for (int i = 1; i <= k; i++)
		{
			int x;
			cin >> x;
			city.push_back(x);
			siz[x] = 1;
		}
		for (int i = 1; i <= n; i++)
		{
			if (siz[fa[i]] && siz[i])
			{
				cout << -1 << endl;
				flag = true;
				break;
			}
		}
		if (flag)continue;
		sort(city.begin(), city.end(), cmp);
		stk[++top] = 1;
		if (city[0] != 1)stk[++top] = city[0];
		for (int i = 2; i <= k; i++)
		{
			int l = lca(city[i - 1], stk[top]);
			while (top > 1 && dep[stk[top - 1]] >= dep[l])
				add(stk[top - 1], stk[top]), top--;
			if (l != stk[top])add(l, stk[top]), stk[top] = l;
			stk[++top] = city[i - 1];
		}
		while (top > 1)
			add(stk[top - 1], stk[top]), top--;
		dfs2(1);
		cout << ans << endl;
	}

	return 0;
}*/
/*
#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int n,q;
vector<int> edge[N];
int h[N], e[N], ne[N], idx;
int siz[N];
int dep[N], fa[N][20], stk[N], top;
int dfn[N], timestamp;
int k;
vector<int> city;
int ans;
void dfs(int u, int father)
{
	fa[u][0] = father, dep[u] = dep[father] + 1;
	dfn[u] = ++timestamp;
	for (int i = 1; i < 20; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (auto item : edge[u])
		if (item != father)
			dfs(item, u);
}
int lca(int u, int v)
{
	if (dep[u] < dep[v])swap(u, v);
	for (int i = 19; i >= 0; i--)
		if (dep[fa[u][i]] >= dep[v])
			u = fa[u][i];
	if (u == v)return v;
	for (int i = 19; i >= 0; i--)
		if (fa[u][i] != fa[v][i])
			u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}
bool cmp(int x, int y)
{
	return dfn[x] < dfn[y];
}
void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void dfs2(int u)
{
	if (siz[u])
	{
		for (int i = h[u]; ~i; i = ne[i])
		{
			int j = e[i];
			dfs2(j);
			if (siz[j])ans++,siz[j] = 0;
		}
	}
	else
	{
		for (int i = h[u]; ~i; i = ne[i])
		{
			int j = e[i];
			dfs2(j);
			if (siz[j])siz[u]+=siz[j], siz[j] = 0;
		}
		if (siz[u] > 1)ans++,siz[u] = 0;;
	}
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
	dfs(1, 0);
	cin >> q;
	while (q--)
	{
		memset(h, -1, sizeof h);
		memset(siz, 0, sizeof siz);
		city.clear();
		idx = ans = top = 0;
		bool flag = false;
		cin >> k;
		for (int i = 1; i <= k; i++)
		{
			int x;
			cin >> x;
			city.push_back(x);
			siz[x] = 1;
		}
		for (int i = 1; i <= n; i++)
		{
			if (siz[fa[i][0]] && siz[i])
			{
				cout << -1 << endl;
				flag = true;
				break;
			}
		}
		if (flag)continue;
		sort(city.begin(), city.end(),cmp);
		stk[++top] = 1;
		if (city[0] != 1)stk[++top] = city[0];
		for (int i = 2; i <= k; i++)
		{
			int l = lca(city[i - 1], stk[top]);
			while (top > 1 && dep[stk[top - 1]] >= dep[l])
				add(stk[top - 1], stk[top]), top--;
			if (l != stk[top])add(l, stk[top]), stk[top] = l;
			stk[++top] = city[i - 1];
		}
		while(top>1)
			add(stk[top - 1], stk[top]), top--;
		dfs2(1);
		cout << ans << endl;
	}

	return 0;
}
*/