

#include<bits/stdc++.h>
using namespace std;

const int N = 1000;

int n;
int a[N];

int main()
{
	a[0] = 6, a[1] = 2, a[2] = 5, a[3] = 5, a[4] = 4, a[5] = 5, a[6] = 6, a[7] = 3, a[8] = 7, a[9] = 6;
	for (int i = 1; i <= 9; i++)
		for (int j = 0; j <= 9; j++)
			a[i * 10 + j] = a[i] + a[j];
	for (int i = 1; i <= 9; i++)
		for (int j = 0; j <= 9; j++)
			for (int k = 0; k <= 9; k++)
				a[i * 100 + j * 10 + k] = a[i] + a[j] + a[k];
	
	cin >> n;
	n -= 4;
	int res = 0;
	for (int i = 0; i <= 999; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (i + j < 1000)
			{
				if (a[i] + a[j] + a[i + j] == n && i == j)res++;
				else if (a[i] + a[j] + a[i + j] == n && i != j)res += 2;
			}
		}
	}
	cout << res;

	return 0;
}