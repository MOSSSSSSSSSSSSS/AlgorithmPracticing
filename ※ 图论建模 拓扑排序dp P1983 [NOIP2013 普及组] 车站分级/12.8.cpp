

// 图论建模是，级别小的车站向级别大的车站连边，通过拓扑序dp

//  理论上有5e5条边，但是根据输入数据建边有重边，超过5e5条边，因此re，需要判重数组have


#include<bits/stdc++.h>
using namespace std;

const int N = 1010, M = 5e5 + 10;
int h[N], e[M], ne[M], idx;
int n, m;
bool vis[N];
int din[N];
int ans;
int rk[N];
vector<int> pass;
bool have[N][N];

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void topodp()
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (din[i] == 0)
			q.push(i),rk[i] = 1;
	ans = 1;
	while (q.size())
	{
		int t = q.front();
		q.pop();
		for (int i = h[t]; ~i; i = ne[i])
		{
			int j = e[i];
			din[j]--;
			rk[j] = max(rk[j], rk[t] + 1);
			if (din[j] == 0)
			{
				ans = max(ans, rk[j]);
				q.push(j);
			}
		}
	}
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int s,st,ed;
		pass.clear();
		memset(vis, false, sizeof vis);
		cin >> s;
		for (int j = 1; j <= s; j++)
		{
			int a;
			cin >> a;
			pass.push_back(a);
			vis[a] = true;
			if (j == 1)st = a;
			if (j == s)ed = a;
		}
		for (int j = st; j <= ed; j++)
			if (!vis[j])
				for (auto p : pass)
				{
					if (have[j][p])continue;
					add(j, p), din[p]++,have[j][p] = true;
				}
	}
	topodp();
	cout << ans;

	return 0;
}