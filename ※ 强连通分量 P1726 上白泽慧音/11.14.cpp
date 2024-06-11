

#include<bits/stdc++.h>
using namespace std;

const int N = 5e3 + 10, M = 1e5 + 10;
int h[N], e[M], ne[M], idx;
int n, m;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int id[N], scc_cnt;
priority_queue<int, vector<int>, greater<int> >village[N];   //  结合题意，可以  优先队列%%%%%%%%%%%
int MAX,ver;

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
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
			village[scc_cnt].push(y);
		} while (y != u);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b, t;
		cin >> a >> b >> t;
		if (t == 1)add(a, b);
		else add(a, b), add(b, a);
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			tarjan(i);
	for (int i = 1; i <= scc_cnt; i++)
	{
		if (village[i].size() > MAX)
		{
			MAX = village[i].size();
			ver = i;
		}
		else if (village[i].size() == MAX)
		{
			if (village[i].top() < village[ver].top())
				ver = i;
		}
	}
	cout << MAX << endl;
	while (village[ver].size())
	{
		cout << village[ver].top()<<' ';
		village[ver].pop();
	}

	return 0;
}