

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 10010, M = 1e6 + 10;
int n;
int h[N], e[M], ne[M], idx;
PII len_ver[N];
int din[N];
int dout[N];

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

void toposort()
{
	priority_queue<PII,vector<PII>,greater<PII>> q;
	for (int i = 1; i <= n; i++)
		if(!din[i])
			q.push(len_ver[i]);
	while (q.size())
	{
		PII t = q.top();
		q.pop();
		int ver = t.second, len = t.first;
		for (int i = h[ver]; ~i; i = ne[i])
		{
			int j = e[i];
			din[j]--;
			if (!din[j])
			{
				len_ver[j].first += len;
				q.push(len_ver[j]);
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		h[i] = -1;
	for (int i = 1; i <= n; i++)
	{
		cin >> len_ver[i].second >> len_ver[i].first;
		while (1)
		{
			int x;
			cin >> x;
			if (!x)break;
			add(x,i);
			din[i]++;
			dout[x]++;
		}
	}
	toposort();
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (!dout[i])
			ans = max(ans, len_ver[i].first);
	cout << ans;

	return 0;
}
