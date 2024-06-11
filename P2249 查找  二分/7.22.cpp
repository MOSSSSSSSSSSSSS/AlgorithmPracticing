#include<bits/stdc++.h>
using namespace std;

const int N = 1000010;

int n, m;
int a[N];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)scanf("%d", &a[i]);

	while (m--)
	{
		int q;
		scanf("%d", &q);
		int l = 1, r = n;
		while (l < r)
		{
			int mid = l + r >> 1;
			if (a[mid] >= q)r = mid;
			else l = mid + 1;
		}
		if (a[l] != q)cout << -1 << ' ';
		else cout << l << ' ';
	}

	return 0;
}