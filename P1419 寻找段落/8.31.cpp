


//   �� �����Ե�һ����Χ�����������������ֵ����Сֵ֮��ģ���������¿��Կ���
//   ���ִ�
//   ������ַ������£����mid����a����ÿ������ȥmid��������з������ⳤ�ȵ������ں͵����ֵ����0��˵���������ģ����ɸ���
#include<bits/stdc++.h>
using namespace std;

const int N = 100010,INF = 0x3f3f3f3f;
int n, s, t;
double l = INF, r = -INF;
double a[N],sum[N];
int q[N];

bool check(double mid)
{
	int hh = 0, tt = -1;
	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + a[i] - mid;
	}
	for (int i = s; i <= n; i++)                            ////////////////////////////
	{                                                       ////////////////////////////
		while (hh <= tt && sum[q[tt]] >= sum[i-s])tt--;    //////////////////////////////
		q[++tt] = i - s;                                       //////////////////////////////
		while (hh <= tt && q[hh] < i - t)hh++;             //////////////////////////////
		if (hh <= tt && sum[i] - sum[q[hh]] > 0)return 1;
	}
	return 0;
}

int main()
{
	cin >> n >> s >> t;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		l = min(l, a[i]);
		r = max(r, a[i]);
	}
	while (fabs(l-r)>1e-5)
	{
		double mid = (l + r ) /2.0;
		if (!check(mid))r = mid;
		else l = mid;
	}
	printf("%.3lf", l);

	return 0;
}