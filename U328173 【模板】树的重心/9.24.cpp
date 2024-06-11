
#include<bits/stdc++.h>
using namespace std;

const int N = 1000010,M = 2000010;
int n;
int h[N], e[M], ne[M], idx;
bool st[N];
int ans = N;
int a[N];

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

int dfs(int u)
{
	st[u] = true;
	int sum = 1,res = 0;
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (!st[j])
		{
			int s = dfs(j);
			sum += s;
			res = max(res, s);
		}
	}
	res = max(res, n - sum);
	a[u] = res;
	ans = min(ans, res);
	return sum;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		h[i] = -1;
	for (int i = 1; i <= n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	dfs(1);
	priority_queue<int, vector<int>, greater<int>> heap;
	for (int i = 1; i <= n; i++)
		if (a[i] == ans)
			heap.push(i);
	while (heap.size())
	{
		cout << heap.top() << ' ';
		heap.pop();
	}

	return 0;
}