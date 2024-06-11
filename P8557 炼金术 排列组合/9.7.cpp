

//  从熔炉的角度很难想，要学会转换成 金属的角度。
//  想造出n个金属，每个金属至少要从1个炉子里造出来，每个金属就有C（k，1），一直加到C（k，k）
//  等于2的k次方-1种，所有金属就是（2的k次方-1）的n次方，又要取模，用取模的快速幂
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int mod = 998244353;
int n, k;

int qmi(int n,int k)
{
	int res = 1;
	while (k)
	{
		if (k & 1)res = (LL)res * n % mod;
		k >>= 1;
		n = (LL)n * n % mod;
	}
	return res;
}

int main()
{
	cin >> n >> k;
	int res = qmi(2, k);
	res -= 1;
	int ans = qmi(res, n);
	cout << ans;

	return 0;
}