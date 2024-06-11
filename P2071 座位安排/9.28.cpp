

#include<bits/stdc++.h>
using namespace std;

const int N = 4010,M = 20010;
int n;
int h[N], e[M], ne[M], idx;
int match[N];
bool st[N];
int ans;

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

bool Find(int u)
{
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (!st[j])
		{
			st[j] = true;
			if (!match[j] || Find(match[j]))
			{
				match[j] = u;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= 2 * n; i++)
		h[i] = -1;
	for (int i = 1; i <= 2 * n; i++)
	{
		int s1, s2;
		cin >> s1 >> s2;
		add(i, s1), add(i, s1 + n), add(i, s2), add(i, s2 + n);
	}
	for (int i = 1; i <= 2 * n; i++)
	{
		for (int j = 1; j <= 2 * n; j++)
			st[j] = false;
		if (Find(i))
			ans++;
	}
	cout << ans;

	return 0;
}