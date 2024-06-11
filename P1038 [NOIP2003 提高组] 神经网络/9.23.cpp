

//  我觉得第一个没看标签题解做出来的提高普及加，一次ac

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 110,M = 10010;
int n, p;
PII c_u[N];
int dout[N],din[N];
int h[N], e[M], ne[M], w[M], idx;

void add(int a, int b, int c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

void toposort()
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (!din[i])
			q.push(i);
	while (q.size())
	{
		int t = q.front();
		q.pop();
		if (c_u[t].first <= 0)continue;
		for (int i = h[t]; ~i; i = ne[i])
		{
			int j = e[i];
			c_u[j].first += (w[i] * c_u[t].first);
			din[j]--;
			if (!din[j])
			{
				q.push(j);
				c_u[j].first -= c_u[j].second;
			}
		}
	}
}

int main()
{
	cin >> n >> p;
	for (int i = 1; i <= n; i++)
		h[i] = -1;
	for (int i = 1; i <= n; i++)
		cin >> c_u[i].first >> c_u[i].second;
	for (int i = 1; i <= p; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
		din[b]++;
		dout[a]++;
	}
	toposort();
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (!dout[i] && c_u[i].first > 0)
			cnt++, cout << i << ' ' << c_u[i].first << endl;
	if (!cnt)cout << "NULL";


	return 0;
}