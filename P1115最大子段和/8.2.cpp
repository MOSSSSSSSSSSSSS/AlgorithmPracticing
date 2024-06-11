


//   这题不是区间DP，区间Dp就是枚举所有情况，太慢
//    通过维护一个序列，当序列和加上一下个数的和大于下一个数，就把这个数放进来，小于就直接
//     把下一个数作为新序列，等于也是，每次都用ans = max(ans,当前)


#include<bits/stdc++.h>
using namespace std;

const int N = 200010,INF = 1e9;
int n, a[N],sum;
int ans = -INF;
vector<int> now;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];

	now.push_back(a[1]);
	sum = a[1];
	ans = a[1];
	for (int i = 2; i <= n; i++)
	{
		if (sum + a[i] <= a[i])
		{
			now.clear();
			now.push_back(a[i]);
			sum = a[i];
		}
		else
		{
			now.push_back(a[i]);
			sum += a[i];
		}
		ans = max(ans, sum);
	}

	cout << ans;

	return 0;
}