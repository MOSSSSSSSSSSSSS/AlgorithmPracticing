
//����C(n,m)%mod�������ö�ά����洢������ǣ����������a[i][j] = a[i-1][j-1]+a[i-1][j]  �����ܴܺ���ll

#include<iostream>
using namespace std;

typedef long long ll;

const ll N = 10010ll, M = 110ll,mod = 10007ll;

ll n, m,ans = 1ll;
ll yang_hui[N][M];

int main()
{
	cin >> n >> m;

	for (int i = 0; i <= n; i++)yang_hui[i][0] = 1ll;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j < i)yang_hui[i][j] = (yang_hui[i - 1][j - 1] + yang_hui[i - 1][j]) % mod;
			else yang_hui[i][j] = 1ll;
		}
	}//�и�i-1��j-1��������1��ʼѭ����Ϊ���±겻���ָ������Ͱ�j
	//��1��ʼ��j = 0��ֱ��ȫ��ֵΪ1
	//�������ֱ�Ӵ��±�0��ʼд������������һ��������Ҳ��C(0,0)
	//�Ȱ��������������������������ʱֱ����
	//ҲҪģmod������ᳬ��ll���и�������


	//(a + b) % p = (a % p + b % p) % p ��1��
	//(a - b) % p = (a % p - b % p) % p ��2��
	//(a * b) % p = (a % p * b % p) % p ��3�������������Ϊʲô����ȡģ��ԭ��
	//	a ^ b % p = ((a % p) ^ b) % p ��4��

	while (m--)
	{
		int t;
		cin >> t;
		ans = (ans * yang_hui[n][t])%mod;   // ˵���������ģmod��ֵ����  ÿ�μ���  ��ģһ�Σ�������
		n -= t;
	}

	cout << ans;

	return 0;
}
