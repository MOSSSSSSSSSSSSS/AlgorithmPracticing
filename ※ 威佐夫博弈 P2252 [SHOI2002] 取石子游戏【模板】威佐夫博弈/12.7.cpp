
#include<bits/stdc++.h>
using namespace std;

int main()
{
	double d = (sqrt(5) + 1) / 2.0;
	int a, b;
	cin >> a >> b;
	if (int(abs(a - b) * d) == min(a, b))cout << 0;
	else cout << 1;

	return 0;
}