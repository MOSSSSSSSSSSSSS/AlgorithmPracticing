
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, M = 4e5 + 10;
int n, m;
int h[N], e[M], ne[M], idx;  // 左手偶数
int ans[N];
bool in1[N];
vector<int> bian;
bool ban[M];

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	memset(ans, -1, sizeof ans);
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		add(i, a), add(i, b);
	}
	for (int i = 0; i <= m - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		bian.push_back(x * 2 - 3 + y);
		ban[x * 2 - 3 + y] = true;
	}
	in1[1] = true;
	for (int i = 0; i < idx; i++)
	{
		if (!ban[i])
		{
			int x = (i + 2) / 2;
			if (e[i] != -1)
			{
				int y = e[i];
				if (x != y)p[x] = y;
			}
			else continue;
		}
	}
	for (int i = 1; i <= n; i++)if (p[i] != p[1])ans[i] = m - 1;
	for (int i = m - 1; i >= 0; i--)
	{
		int x = bian[i];
		int y = find((x + 2) / 2);
		if (e[x] != -1)
		{
			int z = find(e[x]);
			if (y != z)p[y] = z;
		}
		else continue;
		for (int j = 1; j <= n; j++)if (p[j] != p[1])ans[j] = i + 1;
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << endl;

	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 2e5 + 10, M = 4e5 + 10;
int n, m;
int h[N], e[M], ne[M], idx;  // 左手偶数
int p[N];
PII drop[M];
bool bian[M];
int ans[N];
int find(int x)
{
	if (p[x] != x)find(p[x]);
	return p[x];
}
void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	memset(h, -1, sizeof h);
	memset(ans, -1, sizeof ans);
	for (int i = 1; i <= n; i++)p[i] = i;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		add(i, a), add(i, b);
	}
	for (int i = 0; i <= m - 1; i++)
	{
		cin >> drop[i].first >> drop[i].second;
		bian[drop[i].first * 2 - 3 + drop[i].second] = true;
	}
	for (int i = 0; i < idx; i++)
	{
		if (!bian[i])
		{
			int x = find((i + 2)/2);
			if (e[i] != -1)
			{
				int y = find(e[i]);
				if (x != y)p[x] = y;
			}
			else continue;
		}
	}
	for (int i = 1; i <= n; i++)if (p[i] != p[1])ans[i] = m - 1;
	for (int i = m - 1; i >= 0; i--)
	{
		int x = find((drop[i].first * 2 - 3 + drop[i].second + 2)/2);
		if (e[drop[i].first * 2 - 3 + drop[i].second] != -1)
		{
			int y = find(e[drop[i].first * 2 - 3 + drop[i].second]);
			if (x != y)p[x] = y;
		}
		else continue;
		for (int j = 1; j <= n; j++)if (p[j] != p[1])ans[j] = i-1;
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << endl;

	return 0;
}*/
/*
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 2e5 + 10, M = 4e5 + 10;
int n, m;
int h[N], e[M], ne[M], idx;  // 左手偶数
int p[N];
int ans[N];
vector<int> bian;
bool ban[M];

int find(int x)
{
	if (p[x] != x)find(p[x]);
	return p[x];
}
void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	memset(h, -1, sizeof h);
	memset(ans, -1, sizeof ans);
	for (int i = 1; i <= n; i++)p[i] = i;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		add(i, a), add(i, b);
	}
	for (int i = 0; i <= m - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		bian.push_back(x * 2 - 3 + y);
		ban[x * 2 - 3 + y] = true;
	}
	for (int i = 0; i < idx; i++)
	{
		if (!ban[i])
		{
			int x = find((i + 2)/2);
			if (e[i] != -1)
			{
				int y = find(e[i]); 
				if (x != y)p[x] = y;
			}
			else continue;
		}
	}
	for (int i = 1; i <= n; i++)if (p[i] != p[1])ans[i] = m - 1;
	for (int i = m - 1; i >= 0; i--)
	{
		int x = bian[i];
		int y = find((x+2)/2);
		if (e[x] != -1)
		{
			int z = find(e[x]);
			if (y != z)p[y] = z;
		}
		else continue;
		for (int j = 1;j<=n ; j++)if (p[j] != p[1])ans[j] = i + 1;
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << endl;

	return 0;
}*/