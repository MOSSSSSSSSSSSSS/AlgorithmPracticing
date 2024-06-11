

#include<bits/stdc++.h>
using namespace std;

const int N = 110;
int n;
bool a[N][N];
bool b[N][N];

void floyd()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			b[i][j] = a[i][j];
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				b[i][j] |= (b[i][k] && b[k][j]);
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	floyd();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << b[i][j] << ' ';
		cout << endl;
	}

	return 0;
}