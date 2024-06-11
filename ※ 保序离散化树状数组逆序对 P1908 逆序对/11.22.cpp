

//  树状数组以权值为下标，而权值1e9，所以需要离散化，并且保序


#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
vector<int> alls;
int a[N],b[N],tr[N];
int n;
unsigned long long ans;

int fnd(int x)
{
	auto idx = lower_bound(alls.begin(), alls.end(), x) - alls.begin();
	return idx + 1;
}
int lb(int p)
{
	return p & (-p);
}
void pushup(int p)
{
	while (p < N)
	{
		tr[p] += 1;
		p += lb(p);
	}
}
int sum(int p)
{
	int res = 0;
	while (p)
	{
		res += tr[p];
		p -= lb(p);
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		alls.push_back(a[i]);
	}
	alls.erase(unique(alls.begin(), alls.end()), alls.end());
	sort(alls.begin(), alls.end());
	for (int i = 1; i <= n; i++)
		b[i] = fnd(a[i]);
	for (int i = n; i >= 1; i--)
	{
		ans += sum(b[i] - 1);
		pushup(b[i]);
	}
	cout << ans;

	return 0;
}