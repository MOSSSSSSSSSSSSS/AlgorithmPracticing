

//  对 一个点 有限制：拆点 入点和出点
// 浮点数比较有误差，eps = 1e-8
// 遍历每个点去做汇点，图要还原
// 多次询问，也要清零。

#include<bits/stdc++.h>
using namespace std;
#define mm memset

typedef pair<int, int> PII;
const int N = 210, M = 20410,INF = 1e8;
int h[N], e[M], ne[M], w[M], idx;
int d[N], cur[N], q[N];
int t, n, S,T,tot,cnt;
PII node[N];
double D,eps = 1e-8;  // 浮点数比较有误差

void add(int a, int b, int c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
bool check(int a, int b)
{
	PII x = node[a], y = node[b];
	int dx = x.first - y.first, dy = x.second - y.second;
	return dx * dx + dy * dy < D * D + eps;
}
bool bfs()
{
	int hh = 0, tt = -1;
	mm(d, -1, sizeof d);
	q[++tt] = S, d[S] = 0, cur[S] = h[S];
	while (hh <= tt)
	{
		int t = q[hh++];
		for (int i = h[t]; ~i; i = ne[i])
		{
			int j = e[i];
			if (d[j] == -1 && w[i])
			{
				d[j] = d[t] + 1;
				cur[j] = h[j];
				q[++tt] = j;
				if (j == T)return true;
			}
		}
	}
	return false;
}
int find(int u, int limit)
{
	if (u == T)return limit;
	int flow = 0;
	for (int i = cur[u]; ~i&&flow<limit; i = ne[i])
	{
		cur[u] = i;
		int j = e[i];
		if (d[j] == d[u] + 1 && w[i])
		{
			int t = find(j, min(w[i], limit - flow));
			if (!t)d[j] = -1;
			w[i] -= t, w[i ^ 1] += t, flow += t;
		}
	}
	return flow;
}
int dinic()
{
	int ans = 0, flow;
	while (bfs())while (flow = find(S, INF))ans += flow;
	return ans;
}

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> D;
		S = 2*n;
		mm(h, -1, sizeof h);
		vector<int> ans;
		idx =tot=cnt= 0;
		for (int i = 0; i < n; i++)
		{
			int num, jump;
			cin >> node[i].first >> node[i].second >> num >> jump;
			tot += num;
			add(S, i, num), add(i, S, 0);
			add(i, n + i, jump), add(n + i, i, 0);
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (i != j && check(i, j))
					add(i + n, j, INF), add(j, i + n, 0);
		for (int i = 0; i < n; i++)
		{
			T = i;
			if (dinic() == tot)
			{
				cnt++;
				ans.push_back(i);
			}
			for (int j = 0; j < idx; j += 2)
			{
				w[j] += w[j ^ 1];
				w[j ^ 1] = 0;
			}
		}
		for (int i = 0; i + 1 < ans.size(); i++)
			cout << ans[i] << ' ';
		if(ans.size()>0)cout << ans[ans.size() - 1];
		if (!cnt)cout << -1 << endl;
		else cout << endl;
	}

	return 0;
}