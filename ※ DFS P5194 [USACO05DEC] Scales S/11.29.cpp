

//  题目中数据范围 1000，好像不能DFS，但是题目规定 至少大于等于前两项的和，类似斐波那契数列，所以能用的砝码大约40多个
//  因此数据范围缩小到40，可以用DFS

//  剪枝是下面注释的部分，一开始  没想到第二个剪枝而TLE， 
//  从大到小排序后满足(ans + w[i] <= C)的才递归，因此前面很多很大的砝码没有递归，不影响时间复杂度

#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
long long w[N],sum[N];
int n, C;
int ans,res;

bool cmp(int a, int b)
{
	return a > b;
}
void dfs(int u)
{
	/*if (ans + w[n] > C || u > n)  
	{
		res = max(res, ans);
		return;
	}
	if (ans + sum[u] <= C)
	{
		res = max((long long)res, ans+sum[u]);
		return;
	}*/
	for (int i = u; i <= n; i++)
	{
		if (ans + w[i] <= C)
		{
			ans += w[i];
			dfs(i + 1);
			ans -= w[i];
		}
	}
}
int main()
{
	cin >> n >> C;
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	sort(w + 1, w + 1 + n, cmp);
	sum[n] = w[n];
	for (int i = n - 1; i >= 1; i--)
		sum[i] = sum[i + 1] + w[i];
	dfs(1);
	cout << res;

	return 0;
}