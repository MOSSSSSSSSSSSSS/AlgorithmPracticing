
#include<bits/stdc++.h>
using namespace std;

const int N = 110;
int A[N],n;
int avg;
int ans;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> A[i], avg += A[i];
	avg /= n;
	for (int i = 1; i < n; i++)
	{
		if (A[i] == avg)continue;
		A[i + 1] -= (avg - A[i]);
		ans++;
	}
	cout << ans;

	return 0;
}