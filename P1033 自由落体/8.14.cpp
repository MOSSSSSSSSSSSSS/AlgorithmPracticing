

#include<bits/stdc++.h>
using namespace std;

double h, s, v, l, k;
int n, ans;

int main()
{
	cin >> h >> s >> v >> l >> k >> n;
	double t1 = sqrt((h - k-0.0001) / 5.0);
	double x1 = s -l- (v * t1), x2 = x1 + l;
	int x11,x22;
	if (x1 >= n - 1||x2<0)
	{
		cout << 0;
		return 0;
	}
	if (x2 > n - 1)
		x22 = n - 1;
	else
		x22 = x2;
	if (x1 < 0)
		x11 = 0;
	else
		x11 = x1 + 1;
	ans += (x22 - x11+1);

	cout << ans;
	return 0;
}