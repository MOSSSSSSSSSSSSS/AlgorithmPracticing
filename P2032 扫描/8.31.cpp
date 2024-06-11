

#include<bits/stdc++.h>
using namespace std;

const int N = 2000010;
int num[N],n,k;
int q[N], hh, tt = -1;

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> num[i];
	for (int i = 1; i <= n; i++)
	{
		if (hh <= tt && i - k + 1 > q[hh])hh++;
		while (hh <= tt && num[q[tt]] <= num[i])tt--;
		q[++tt] = i;
		if (i >= k)cout << num[q[hh]] << endl;
	}

	return  0;
}