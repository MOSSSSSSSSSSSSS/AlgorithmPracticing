


#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
const int N = 1000010;
int n, k,hh, tt = -1, q[N];
ULL a[N];//   2��64�η����Ҷ��Ǵ��ڵ���1�ģ�ע��ULL

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		while (hh <= tt && a[q[tt]] <= a[i])tt--;
		q[++tt] = i;
		if (hh <= tt && q[hh] < i - k + 1)hh++;
		if (i >= k)cout << tt - hh + 1 << endl;       //  ������ɴ��ϰ���  ��������һ��˼·Ϲ����������
	}

	return 0;
}