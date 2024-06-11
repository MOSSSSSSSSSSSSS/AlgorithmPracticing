

#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int n, sum, d[N];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> d[i];
	for (int i = 1; i <= n; i++)if (d[i] > d[i - 1])sum += d[i] - d[i - 1];
	cout << sum;

	return 0;
}