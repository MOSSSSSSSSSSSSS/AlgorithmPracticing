

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;///////////////////////////////////////////////////   别忘了加10，因为这个浪费半个下午！！！！
int h[N], e[N], ne[N], idx;
int n, m;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int id[N], scc_cnt;
vector<int> edge[N];
int MAX[N];
bool vis[N];

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void dfs(int u)
{
	for (auto item : edge[u])
	{
		if (!vis[item]) 
		{
			vis[item] = true;
			dfs(item);
		}
		MAX[u] = max(MAX[u], MAX[item]);
	}
}
void tarjan(int u)
{
	dfn[u] = low[u] = ++timestamp;
	stk[++top] = u, in_stk[u] = true;
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (!dfn[j])
		{
			tarjan(j);
			low[u] = min(low[u], low[j]);
		}
		else if (in_stk[j])
			low[u] = min(low[u], dfn[j]);
	}
	if (dfn[u] == low[u])
	{
		scc_cnt++;
		int y;
		do {
			y = stk[top--];
			in_stk[y] = false;
			id[y] = scc_cnt;
			MAX[scc_cnt] = max(MAX[scc_cnt], y);
		} while (y != u);
	}
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			tarjan(i);
	for (int i = 1; i <= n; i++)
	{
		for (int j = h[i]; ~j; j = ne[j])
		{
			int k = e[j];
			if (id[i] != id[k])
				edge[id[i]].push_back(id[k]);
		}
	}
	for (int i = 1;i<=scc_cnt;i++)
		if(!vis[i])
			dfs(i);
	for (int i = 1; i <= n; i++)
		cout<<MAX[id[i]]<<' ';

	return 0;
}
/*
#include <cstdio>
#include <cstring>
#include <iostream>

#define maxn 100010

using namespace std;

inline int read() {
	int op = 1, a = 0;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar()) if (c == '-') op = -1;
	for (; c >= '0' && c <= '9'; c = getchar()) a = a * 10 + c - '0';
	return op * a;
}

int n, m;

int cnt;
int head[maxn];
struct Edge {int from, to, nxt;} e[maxn];

inline void add_edge(int u, int v) {
	cnt++;
	e[cnt].to = v;
	e[cnt].from = u;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}

int r;//栈的右端点
int s[maxn];//数组来模拟栈
int num;//个数
int Time;
bool vis[maxn];
int belong[maxn];//一个点属于哪个强连通分量
int dfn[maxn], low[maxn];
int rep[maxn];//存储缩完点后每个点所代表的所有点中编号最大的

void Tarjan(int u) {
	dfn[u] = low[u] = ++Time;
	vis[u] = 1;
	s[++r] = u;
	int R = r;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (!dfn[v]) {
			Tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (vis[v]) low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u]) {
		num++;
		for (int i = R; i <= r; i++) {
			vis[s[i]] = 0;
			belong[s[i]] = num;
			rep[num] = max(rep[num], s[i]);
			//记录强连通分量中编号最大的点（的编号）
		}
		r = R - 1;
	}
}

//重新建图
void rebuild() {
	cnt = 0;
	memset(head, 0, sizeof head);
	for (int i = 1; i <= m; i++) {
		int x = e[i].from, y = e[i].to;
		if (belong[x] == belong[y]) continue;
		add_edge(belong[x], belong[y]);
	}
}

int ans[maxn];

void dfs(int u) {
	if (ans[u]) return;
	ans[u] = rep[u];
	//必定能到这个强连通分量中的点
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		dfs(v);
		ans[u] = max(ans[u], ans[v]);
		//和上一句的位置不能颠倒
	}
}

int main() {
	n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		int x = read(), y = read();
		add_edge(x, y);
	}
	for (int i = 1; i <= n; i++) if (!dfn[i]) Tarjan(i);
	rebuild();
	for (int i = 1; i <= num; i++) if (!ans[i]) dfs(i);
	for (int i = 1; i <= n; i++) cout << ans[belong[i]] << ' ';
	//一个点的答案都直接输出对应的强连通分量能到的编号最大的点
	return 0;
}*/