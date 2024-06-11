

//  ��Ŀ�����ݷ�Χ 1000��������DFS��������Ŀ�涨 ���ٴ��ڵ���ǰ����ĺͣ�����쳲��������У��������õ������Լ40���
//  ������ݷ�Χ��С��40��������DFS

//  ��֦������ע�͵Ĳ��֣�һ��ʼ  û�뵽�ڶ�����֦��TLE�� 
//  �Ӵ�С���������(ans + w[i] <= C)�Ĳŵݹ飬���ǰ��ܶ�ܴ������û�еݹ飬��Ӱ��ʱ�临�Ӷ�

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