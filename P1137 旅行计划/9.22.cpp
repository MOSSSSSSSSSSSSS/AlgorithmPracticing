

#include<bits/stdc++.h>
using namespace std;

const int N = 100010, M = 200010;
int n, m;
int h[N], e[M], ne[M], idx;
int ans[N];
int d[N];

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

void toposort()
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (!d[i])
			q.push(i), ans[i] = 1;
	while (q.size())
	{
		int t = q.front();
		q.pop();
		for (int i = h[t]; ~i; i = ne[i])
		{
			int j = e[i];
			ans[j] = ans[t] + 1;
			d[j]--;
			if (!d[j])
				q.push(j);
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		h[i] = -1;
	for (int i = 1; i <= m; i++)
	{
		int a,b;
		cin >> a >> b;
		add(a, b);
		d[b]++;
	}
	toposort();
	for (int i = 1; i <= n; i++)
		cout << ans[i] << endl;

	return 0;
}