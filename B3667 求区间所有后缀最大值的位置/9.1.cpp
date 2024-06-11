


#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
const int N = 1000010;
int n, k,hh, tt = -1, q[N];
ULL a[N];//   2的64次方，且都是大于等于1的，注意ULL

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
		if (i >= k)cout << tt - hh + 1 << endl;       //  这个题躺床上按照  单调队列一般思路瞎想就想出来了
	}

	return 0;
}