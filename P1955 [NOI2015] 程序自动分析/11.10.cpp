

#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
typedef pair<int, int> PII;
int t;
vector<PII> eq;
vector<PII> neq;
int p[2*N];
map<int, int> mp;
int cnt;

int find(int x)
{
	if (p[x] != x)p[x] = find(p[x]);
	return p[x];
}

int main()
{
	cin >> t;
	while (t--)
	{
		int n;
		bool flag = false;
		cin >> n;
		for (int i = 1; i <= 2 * n; i++)p[i] = i;
		while (n--)
		{
			int op,a,b;
			cin >>a>>b>>op;
			if (!mp[a])mp[a] = ++cnt;
			if (!mp[b])mp[b] = ++cnt;
			if (op == 0)neq.push_back({ mp[a], mp[b] });
			else eq.push_back({ mp[a],mp[b] });
		}
		for (auto item : eq)
		{
			int a = item.first, b = item.second;
			int fa = find(a), fb = find(b);
			if (fa != fb)p[fa] = fb;
		}
		for (auto item : neq)
		{
			int a = item.first, b = item.second;
			int fa = find(a), fb = find(b);
			if (fa == fb)
			{
				cout << "NO" << endl;
				flag = true;
				break;
			}
		}
		if (!flag)cout << "YES" << endl;
		eq.clear();
		neq.clear();
		cnt = 0;
		mp.clear();
	}

	return 0;
}