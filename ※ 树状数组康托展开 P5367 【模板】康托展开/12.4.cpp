

//  树状数组优化康托展开，康托展开可以求一个排列在所有排列中的排名 
//  预处理 阶乘数组

/*
* 初始化长度为n（索引从1开始），值全为1 的序列P枚举排列的每一位，对值为 
pk的第k位：修改 Ppk=0求出 a=(n−k)!∑pk−1i=1Pi ，和式为序列P 区间[1,pk−1] 的元素和
把所有a 相加，最后加1 即为索引。时间复杂度为O(nlogn)
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int f[N];
int tr[N];
int mod = 998244353;
int n;
int a[N];
int ans;

int lowbit(int x)
{
	return x & (-x);
}
void pushup(int p)
{
	while (p < N)
	{
		tr[p] -= 1;
		p += lowbit(p);
	}
}
int sum(int p)
{
	int res = 0;
	while (p)
	{
		res += tr[p];
		p -= lowbit(p);
	}
	return res;
}

int main()
{
	cin >> n;
	f[0] = 1;
	for (int i = 1; i <= n; i++)
		f[i] = (long long)f[i - 1] * i % mod;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		tr[i] = lowbit(i);
	for (int i = 1; i <= n; i++)
	{
		pushup(a[i]);
		ans = ((long long)ans + (long long)f[n - i] * sum(a[i] - 1))%mod;      
	}
	cout << ans + 1;    //  最后加一是排名，注意求ans那里是加

	return 0;
}