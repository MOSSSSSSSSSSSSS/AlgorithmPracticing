

//  dfs��һ���ص���  ���ݷ�Χ��С����Ϊʱ�临�Ӷȴ�

#include<bits/stdc++.h>
using namespace std;

const int N = 30;
int n, k,cnt,res,ans;
int a[N];

void dfs(int k,int now)
{
	if (k == cnt)
	{
		for (int i = 2; i < res; i++)     //  �ж��������ұ� 2�� n-1
			if (res % i == 0)
				return;
		ans++;
	}

	for (int i = now + 1; i <= n; i++)
	{
		res += a[i];
		cnt++;
		dfs(k, i);
		cnt--;
		res -= a[i];
	}
}

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	dfs(k,0);
	cout << ans;

	return 0;
}