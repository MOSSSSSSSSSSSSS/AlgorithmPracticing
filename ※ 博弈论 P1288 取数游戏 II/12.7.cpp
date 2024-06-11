

// 由于两边都非常聪明，因此每个人一定都会取光所有边权，如果不取光，没有获胜可能

#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	int cnt = 0;
	for (auto item : v)
	{
		if (item == 0)break;
		else cnt++;
	}
	if (cnt % 2 != 0) {
		cout << "YES" << '\n'; return 0;
	}
	reverse(v.begin(), v.end());
	cnt = 0;
	for (auto item : v)
	{
		if (item == 0)break;
		else cnt++;
	}
	if (cnt % 2 != 0) cout << "YES" << '\n';
	else cout << "NO";

	return 0;
}