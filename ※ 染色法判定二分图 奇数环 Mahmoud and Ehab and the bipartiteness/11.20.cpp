
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int h[N], e[N*2], ne[N*2], idx;
int n;
int color[N];
int num1, num2;

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void dfs(int u, int c)
{
	color[u] = c;
	if (c == 1)num1++;
	else num2++;
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (!color[j])
			dfs(j, 3 - c);
	}
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n;
	for (int i = 1; i <= n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	dfs(1, 1);
	cout << (long long)num1 * num2 - n + 1;

	return 0;
}