

#include<bits/stdc++.h>
using namespace std;

const int N = 5510;
int n, m, idx;
int u[N], d[N], l[N], r[N];
int row[N], col[N];
int h[N];
int s[N];
int ans[N];

void init()
{
	for (int i = 0; i <= m; i++)
		u[i] = d[i] = i, l[i] = i - 1, r[i] = i + 1;
	l[0] = m, r[m] = 0, idx = m;
}
void link(int x, int y)
{
	row[++idx] = x, col[idx] = y, s[y]++;
	d[u[y]] = idx;
	u[idx] = u[y];
	d[idx] = y;
	u[y] = idx;
	if (h[x] == 0)h[x] = r[idx] = l[idx] = idx;
	else
	{
		l[idx] = l[h[x]];
		r[l[h[x]]] = idx;
		r[idx] = h[x];
		l[h[x]] = idx;
	}
}
void remove(int y)
{
	l[r[y]] = l[y], r[l[y]] = r[y];
	for (int i = d[y]; i != y; i = d[i])
		for (int j = r[i]; j != i; j = r[j])
			u[d[j]] = u[j], d[u[j]] = d[j], s[col[j]]--;
}
void resume(int y)
{
	l[r[y]] = y, r[l[y]] = y;
	for (int i = d[y]; i != y; i = d[i])
		for (int j = r[i]; j != i; j = r[j])
			d[u[j]] = j, u[d[j]] = j, s[col[j]]++;
}
bool dance(int dep)
{
	if (r[0] == 0)return true;
	int y = r[0];
	for (int i = r[0]; i != 0; i = r[i])if (s[y] > s[i])y = i;
	remove(y);
	for (int i = d[y]; i != y; i = d[i])
	{
		ans[dep] = row[i];
		for (int j = r[i]; j != i; j = r[j])remove(col[j]);
		if (dance(dep + 1))return true;
		for (int j = l[i]; j != i; j = l[j])resume(col[j]);/////////////////////////////////////////////////////////////////////////
	}
	resume(y);
	return false;
}

int main()
{
	cin >> n >> m;
	init();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int x;
			cin >> x;
			if (x == 1)link(i, j);
		}
	}
	if (!dance(0))cout << "No Solution!";
	else 
	{
		int i = 0;
		while (ans[i])cout << ans[i] << ' ',i++;
	}

	return 0;
}