
#include<bits/stdc++.h>
using namespace std;

const int N = 60, INF = 1e8;
int f[N][N];
string color;

int main()
{
	cin >> color;
	for (int i = 1; i <= color.size(); i++)
		for (int j = 1; j <= color.size(); j++)
			f[i][j] = INF;
	for (int i = 1; i <= color.size(); i++)f[i][i] = 1;
	for (int len = 2; len <= color.size(); len++)
	{
		for (int l = 1; l + len - 1 <= color.size(); l++)
		{
			int r = l + len - 1;
			if (color[r - 1] == color[l - 1])
				f[l][r] = min(f[l + 1][r], f[l][r - 1]);
			else
				for (int k = l; k < r; k++)
					f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r]);
		}
	}
	cout << f[1][color.size()];

	return 0;
}