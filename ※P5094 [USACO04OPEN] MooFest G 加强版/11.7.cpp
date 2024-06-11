

#include<bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 5e4 + 10;
int tr[N], tr2[N];
int n;
PII cow[N];
int ans,tot;

int lowbit(int x)
{
	return (x & (-x));
}
int query(int tr[],int p)
{
	int res = 0;
	while (p)
	{
		res += tr[p];
		p -= lowbit(p);
	}
	return res;
}
void add(int tr[], int x, int k)
{
	while (x < N)
	{
		tr[x] += k;
		x += lowbit(x);
	}
}

signed main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> cow[i].first >> cow[i].second;
	sort(cow + 1, cow + 1 + n);
	for (int i = 1; i <= n; i++)
	{
		int num = query(tr, cow[i].second);
		int sum = query(tr2, cow[i].second);
		ans += (cow[i].second * num - sum) * cow[i].first;
		ans += ((tot-sum) - cow[i].second * (i-1-num)) * cow[i].first;
		add(tr, cow[i].second, 1);
		add(tr2, cow[i].second, cow[i].second);
		tot += cow[i].second;
	}
	cout << ans;

	return 0;
}