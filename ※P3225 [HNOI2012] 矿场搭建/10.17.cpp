

#include<bits/stdc++.h>
using namespace std;

const int M = 1010,N = 1010;
int dp;
int n,m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
int vdcc_cnt;
vector<int> vdcc[N];
bool cut[N];
int root;
int res;
unsigned long long ans = 1;

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
		res++;
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
	while (cin >> m, m)
	{
		dp++;
		memset(h, -1, sizeof h);
		memset(stk, 0, sizeof stk);
		memset(dfn, 0, sizeof dfn);
		memset(low, 0, sizeof low);
		memset(cut, 0, sizeof cut);
		for (int i = 1; i <= vdcc_cnt; i++)
			vdcc[i].clear();
		idx = timestamp =top=vdcc_cnt= res=n=0;
		ans = 1;
		for (int i = 1; i <= m; i++)
		{
			int a, b;
			cin >> a >> b;
			if (a == b)continue;
			n = max(n,max(a, b));
			add(a, b), add(b, a);
		}
		for (root = 1; root <= n; root++)
			if (!dfn[root])
				tarjan(root);
		for (int i = 1; i <= vdcc_cnt; i++)
		{
			int cnt = 0;
			for (auto item : vdcc[i])
				if (cut[item])cnt++;
			if (!cnt)res += 2,ans*= (vdcc[i].size()* (vdcc[i].size()-1))/2;
			else if (cnt == 1)res += 1,ans*= (vdcc[i].size() - 1);
		}
		cout << "Case "<<dp<<": " << res << ' ' << ans << endl;
	}

	return 0;
}