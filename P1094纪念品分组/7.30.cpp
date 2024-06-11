
//  题意：尽量分组最少，每组价值不能超过上限，每组最多有两件
//  贪心：从小到大排列，l指向最左，r指向最右，如果最小加最大没超过上限就分为一组，l++,r--
//        如果超过上限，最大单独一组r--，最后如果剩一个，再分一组
#include<bits/stdc++.h>
using namespace std;

const int N = 30010;
int w, n;
int g[N],ans;

int main()
{
	cin >> w >> n;
	for (int i = 1; i <= n; i++)
		cin >> g[i];
	sort(g + 1, g + n + 1);          //  对 从 下标 1开始的n个排序  排完后第一个位置不变（没排它）

	int l = 1, r = n;
	while (l < r)
	{
		if (g[l] + g[r] <= w)
		{
			ans++;
			l++;
			r--;
		}
		else
		{
			ans++;
			r--;
		}
	}
	if (l == r)ans++;        //  可能是l>r了，也可能是等于了

	cout << ans;

	return 0;
}