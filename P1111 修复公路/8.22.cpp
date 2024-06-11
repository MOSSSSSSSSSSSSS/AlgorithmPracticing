

#include<bits/stdc++.h>
using namespace std;

const int N = 1010,M = 100010;
struct road {
	int x, y, t;
}roads[M];
int n, m,t;
int p[N];

bool cmp(road a,road b)
{
	if (a.t < b.t)return true;
	else return false;
}

int find(int x)
{
	if (p[x] != x)p[x] = find(p[x]);
	return p[x];
}

bool check()
{
	for (int i = 2; i <= n; i++)
		if (find(1) != find(i))
			return false;
	return true;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)p[i] = i;
	for (int i = 1; i <= m; i++)
	{
		int x, y, t;
		cin >> x >> y >> t;
		roads[i].x = x;
		roads[i].y = y;
		roads[i].t = t;
	}
	sort(roads + 1, roads + m + 1, cmp);
	t = roads[1].t;
	for (int i = 1; i <= m; i++)
	{
		if (roads[i].t == t)             //   一次把t的路都修了
		{
			if (find(roads[i].x) != find(roads[i].y)) //  并查集，已经在一个集合的就不用再合并
			{
				p[find(roads[i].x)] = roads[i].y;
			}
		}
		else
		{
			if (check())
			{
				cout << t;
				return 0;
			}
			else
			{
				t = roads[i].t;
				i--;
			}
		}
	}
	if (check())
	{
		cout << t;
		return 0;
	}
	else
	{
		cout << -1;
		return 0;
	}
}