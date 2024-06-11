
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 8e4 + 10, M = 2 * N;
int h[N], e[M], ne[M], w[M], idx;
int n;
int dist[N];
bool vis[N];
int la, lb;
int cnt = 1;

void add(int a, int b, int c)
{
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}
void dijkstra()
{
	priority_queue<PII, vector<PII>, greater<PII> > heap;
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	heap.push({ dist[1],1 });
	while (heap.size())
	{
		PII t = heap.top();
		heap.pop();
		int ver = t.second, distance = t.first;
		if (vis[ver])continue;
		vis[ver] = true;
		for (int i = h[ver]; ~i; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > distance + w[i])
			{
				dist[j] = distance + w[i];
				heap.push({ dist[j],j });
			}
		}
	}
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		cnt += 2;
		int len = abs(la - lb);
		if (i == 1)add(1, cnt - 1, a - 1), add(1, cnt, b - 1);
		else add(cnt - 3, cnt - 1, abs(lb - a)+1+len), add(cnt - 3,cnt, abs(lb - b) + 1+len),
		   	 add(cnt - 2, cnt - 1, abs(la - a) + 1 + len), add(cnt - 2,cnt, abs(la - b) + 1+len);
		la = a, lb = b;
	}
	cnt++; add(cnt - 2, cnt, n - la), add(cnt - 1, cnt, n + lb - 2*la);
	dijkstra();
	cout << dist[cnt];

	return 0;
}