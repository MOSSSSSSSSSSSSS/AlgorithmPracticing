

#include<bits/stdc++.h>
#define int long long
using namespace std;

typedef pair<int, int> PII;
const int N = 10010, M = 100010, INF = 0x3F3F3F3F; //  有时候表示极限的数不够大，就改成8个
int n, m, b;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
bool vis[N];
int fee[N];
int l = INF, r=-INF,temp;

bool check(int mid)
{
	for (int i = 1; i <= n; i++)
		dist[i] = INF, vis[i] = 0;
	dist[1] = 0;
	if (fee[1] > mid || fee[n] > mid)return false;
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({ 0,1 });
	while (heap.size())
	{
		PII t = heap.top();
		heap.pop();
		int ver = t.second, distance = t.first;
		if (vis[ver]||fee[ver] > mid)continue;
		vis[ver] = 1;
		for (int i = h[ver]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (fee[j] > mid)continue;
			if (dist[j] > distance + w[i])
			{
				dist[j] = distance + w[i];
				heap.push({ dist[j],j });
			}
		}
	}
	if (dist[n] <= b)return true;
	else return false;
}

void add(int a, int b, int c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

signed main()
{
	cin >> n >> m >> b;
	for (int i = 1; i <= n; i++)
		h[i] = -1;
	for (int i = 1; i <= n; i++)
	{
		cin >> fee[i];
		l = min(l, fee[i]);
		r = max(r, fee[i]);
	}
	temp = r;
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}
	while (l < r)
	{
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	if (l == temp)
	{
		if (check(l))cout << l;          //   注意二分，从最大值退出来有两种可能，可能答案是最大值，也可能无解，再判断一次
		else cout << "AFK";
	}
	else
		cout << l;

	return 0;
}