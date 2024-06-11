

#include<bits/stdc++.h>
using namespace std;

const int N = 4010, M = 25000;
int h[N], e[M], ne[M], idx;
int match[N];
bool st[N];
int n, m;
map<string, int> ma;

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

bool Find(int x)
{
	for (int i = h[x]; ~i; i = ne[i])
	{
		int j = e[i];
		if (!st[j])
		{
			st[j] = 1;
			if (!match[j] || Find(match[j]))
			{
				match[j] = x;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		h[i] = -1;
	for (int i = 1; i <= n; i++)
	{
		string nv, nan;cv
		cin >> nv >> nan;
		ma[nv] = i;
		ma[nan] = i;
	}
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		string nv, nan;
		cin >> nv >> nan;
		add(ma[nan], ma[nv]);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			st[j] = 0,match[j] = j;
		match[i] = 0;
		if (Find(i))
			cout << "Unsafe" << endl;
		else
			cout << "Safe" << endl;
	}

	return 0;
}