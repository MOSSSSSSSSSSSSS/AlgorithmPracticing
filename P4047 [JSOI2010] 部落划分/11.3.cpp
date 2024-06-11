

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 1e3 + 10;
double dist[N][N];
int n, k;
int p[N];
PII node[N];
double l = 0.0, r = 15e3;

int find(int x)
{
	if (p[x] != x)p[x] = find(p[x]);
	return p[x];
}
double getDist(int i, int j)
{
	return sqrt((node[i].first - node[j].first) * (node[i].first - node[j].first) + (node[i].second - node[j].second) * (node[i].second - node[j].second));
}
bool check(double mid)
{
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		p[i] = i;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (dist[i][j] < mid)
			{
				int fa = find(i), fb = find(j);
				if (fa != fb)p[fa] = fb;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		if (p[i] == i)
			cnt++;
	return cnt >= k;
}

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> node[i].first >> node[i].second;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = getDist(i, j);
	while (r - l >= 1e-4)
	{
		double mid = (l + r) / 2.0;
		if (check(mid))l = mid;
		else r = mid;
	}
	printf("%.2lf", l);

	return 0;
}