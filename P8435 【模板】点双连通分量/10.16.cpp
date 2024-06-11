


//  单独一个点也是  点双联通分量  ，但如果有自环 h[a]就不是-1了，不能判断是不是一个孤立点，因此加边的时候 判断，自环不要加
#include<bits/stdc++.h>
using namespace std;

const int N = 500010, M = 4000010;
int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
int vdcc_cnt;
vector<int> vdcc[N];
int root;

bool cut[N];//  割点

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void tarjan(int u)
{
	int cnt = 0;
	if (u == root && h[u] == -1)
	{
		vdcc_cnt++;
		vdcc[vdcc_cnt].push_back(u);
		return;
	}
	dfn[u] = low[u] = ++timestamp;
	stk[++top] = u;
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (!dfn[j])
		{
			tarjan(j);
			low[u] = min(low[u], low[j]);
			if (low[j] >= dfn[u])
			{
				cnt++;
				if (u != root || cnt > 1)cut[u] = true;
				int y;
				vdcc_cnt++;
				do {						
					y = stk[top--];
					vdcc[vdcc_cnt].push_back(y);
				} while (y != j);
				vdcc[vdcc_cnt].push_back(u);
			}
		}
		else low[u] = min(low[u], dfn[j]);
	}
}

int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a == b)continue;
		add(a, b), add(b, a);
	}
	for (root = 1; root <= n; root++)
		if (!dfn[root])
			tarjan(root);
	cout << vdcc_cnt << endl;
	for (int i = 1; i <= vdcc_cnt; i++)
	{
		cout << vdcc[i].size() << ' ';
		for (auto item : vdcc[i])
			cout << item << ' ';
		cout << endl;
	}

	return 0;
}