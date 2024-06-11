


#include<bits/stdc++.h>
using namespace std;

int T;
inline long long read() {
	long long s = 0, w = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	return s * w;
}

int main()
{
	T = read();
	while (T--)
	{
		long long n, p;
		n = read(), p = read();
		if (p == 1)
		{
			printf("0\n");
			continue;
		}
		long long ans = n;
		for (int i = 1;n;n = n/p,i++)
		{
			if (i & 1)ans -= n / p;
			else ans += n / p;
		}
		printf("%lld\n", ans);
	}

	return 0;
}