

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 500 * 500 + 10;
int p[N];
int n, m;
int h[510][510];
bool is[510][510];
int l = 0, r = 1e9;
vector<PII> biao;
int dx[2] = { 0,1 };
int dy[2] = { 1,0 };

int find(int x)
{
	if (p[x] != x)p[x] = find(p[x]);
	return p[x];
}
bool check(int mid)
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			p[(i - 1) * m + j] = (i - 1) * m + j;
	for(int i = 1;i<=n;i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				int x = i + dx[k], y = j + dy[k];
				if (x >= 1 && x <= n && y >= 1 && y <= m)
				{
					if (abs(h[x][y] - h[i][j]) <= mid)
					{
						int fa = find((x - 1) * m + y), fb = find((i - 1) * m + j);
						p[fa] = fb;
					}
				}
			}
		}
	}
	int wcnm = find((biao[0].first - 1) * m + biao[0].second);
	for (int i = 1; i < biao.size(); i++)
		if (find((biao[i].first - 1) * m + biao[i].second) != wcnm)
			return false;
	return true;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> h[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> is[i][j];
			if (is[i][j])
				biao.push_back({ i,j });
		}
	}
	while (l < r)
	{
		int mid = l + r >> 1;
		if (check(mid))r = mid;
		else l = mid + 1;
	}
	cout << l;

	return 0;
}