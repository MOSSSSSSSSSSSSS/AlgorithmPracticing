

#include<bits/stdc++.h>
using namespace std;

const int N = 210;
int n, m;
double v[N], c[N],l,r;

bool check(double mid)
{
	double a[N],add = 0;
	for (int i = 1; i <= n; i++)
		a[i] = v[i] - mid * c[i];
	sort(a + 1, a + 1 + n);
	for (int i = n;i >= n - m + 1; i--)
		add += a[i];
	if (add >= 0)return true;//小或刚好
	else return false; //大
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
		double x = v[i] / c[i];
		r = max(r, x);
	}
	while (r - l > 1e-6)
	{
		double mid = (l + r) / 2.0;
		if (check(mid))l = mid;
		else r = mid;
	}
	printf("%.3lf", l);

	return 0;
}