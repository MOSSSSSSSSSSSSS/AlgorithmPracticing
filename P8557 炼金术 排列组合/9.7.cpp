

//  ����¯�ĽǶȺ����룬Ҫѧ��ת���� �����ĽǶȡ�
//  �����n��������ÿ����������Ҫ��1��¯�����������ÿ����������C��k��1����һֱ�ӵ�C��k��k��
//  ����2��k�η�-1�֣����н������ǣ�2��k�η�-1����n�η�����Ҫȡģ����ȡģ�Ŀ�����
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