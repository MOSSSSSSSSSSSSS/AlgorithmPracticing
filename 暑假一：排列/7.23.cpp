
#include<bits/stdc++.h>
using namespace std;

int n,now,resmin = 1e9,resmax;
vector<int> num;

int main()
{
	cin >> n;
	if (n == 2)resmax = 4;
	for (int i = 1; i <= n; i++)num.push_back(i);
	do {
		int A, U = 0, D = 0;
		int l = 0, r = 1,i = l;
		while (i<n-1)
		{
			for (;i<n-1; i++)
			{
				now = num[i];
				if (num[r] > now)r++;
				else
				{
					if (r - l != 1)
						U += r - l;
					l = r;
					i = l;
					r++;
					break;
				}
			}
		}
		if (r - l != 1)
			U += r - l;
		l = 0, r = 1,i = l;
		while (i<n-1)
		{
			for (; i < n-1; i++)
			{
				now = num[i];
				if (num[r] < now)r++;
				else
				{
					if (r - l != 1)
						D += (r - l) * 2;
					l = r;
					i = l;
					r++;
					break;
				}
			}
		}
		if (r - l != 1)
			D += (r - l) * 2;
		A = U + D;
		resmin = min(resmin, A);
		resmax = max(resmax, A);
	} while (next_permutation(num.begin()+1, num.end()));
	cout << resmin << endl;
	cout << resmax << endl;

	return 0;
}