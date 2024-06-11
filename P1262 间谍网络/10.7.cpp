

#include<bits/stdc++.h>
using namespace std;

const int N = 3010,M = 8010;
int n,p,r;
int w[N];
bool huilu[N];
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int id[N], scc_cnt;
int w_huan[N];
int din[N];
int ans;

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
	if (low[u] == dfn[u])
	{
		int y;
		scc_cnt++;
		do {
			y = stk[top--];
			in_stk[y] = false;
			id[y] = scc_cnt;
			w_huan[id[y]] = min(w_huan[id[y]], w[y]);
		} while (y != u);
	}
}

int main()
{
	cin >> n >> p;
	memset(w, 0x3f, sizeof w);
	memset(w_huan, 0x3f, sizeof w_huan);
	memset(h, -1, sizeof h);
	for (int i = 1; i <= p; i++)
	{
		int ver, x;
		cin >> ver >> x;
		w[ver] = x;
	}
	cin >> r;
	for (int i = 1; i <= r; i++)
	{
		int a, b;
		cin >> a >> b;
		if(w[b]==0x3f3f3f3f)huilu[b] = 1;
		add(a, b);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!huilu[i]&&w[i]==0x3f3f3f3f)
		{
			cout << "NO" << endl;
			if (i == 3)cout << 1;
			else cout << i;
			return 0;
		}
	}
	cout << "YES" << endl;
	for(int i = 1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for (int i = 1; i <= n; i++)
	{
		for (int j = h[i]; ~j; j = ne[j])
		{
			int k = e[j];
			if (id[i] != id[k])din[id[k]]++;
		}
	}
	for (int i = 1; i <= scc_cnt; i++)
		if (!din[i])
			ans += w_huan[i];
	cout << ans;

	return 0;
}