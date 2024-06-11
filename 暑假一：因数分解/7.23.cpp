
#include<bits/stdc++.h>
using namespace std;

int n,m;

int main()
{
	cin >> n;
	m = sqrt(n)+1;
	for (int i = 2; i <= m; i++)
		if (n % i == 0)cout << n / i;

	return 0;
}