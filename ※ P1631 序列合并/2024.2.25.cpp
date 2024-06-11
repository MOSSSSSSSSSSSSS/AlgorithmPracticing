
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int n;
int a[N], b[N];
map<pair<int,int>, bool> mp;
struct node {
	int i, j;
	friend bool operator<(node c, node d)
	{
		return a[c.i] + b[c.j] > a[d.i] + b[d.j];
	}
};
priority_queue<node> q;
vector<int> ans;

signed main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= n; i++)cin >> b[i];
	q.push({ 1,1 });
	mp[{1, 1}] = true;
	while (ans.size() < n)
	{
		node t = q.top();
		q.pop();
		ans.push_back(a[t.i] + b[t.j]);
		if (mp[{t.i + 1, t.j }] == false)q.push({ t.i + 1,t.j }), mp[{t.i + 1, t.j }] = true;
		if(mp[{t.i, t.j + 1 }] == false)q.push({ t.i,t.j + 1 }), mp[{t.i, t.j + 1}] = true;
	}
	for (int i = 0; i < n; i++)cout << ans[i] << ' ';

	return 0;
}