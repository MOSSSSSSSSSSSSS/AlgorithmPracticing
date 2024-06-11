

//  单调队列优化多重背包

#include<bits/stdc++.h>
using namespace std;

const int N = 110,M = 4e4+10;
int n, W;
struct bao{
	int v, w, m;
}baos[N];
int dp[M];
int temp[M];
int q[M];

int main()
{
	cin >> n >> W;
	for (int i = 1; i <= n; i++)
		cin >> baos[i].v >> baos[i].w >> baos[i].m;
	for (int i = 1; i <= n; i++)
	{
		memcpy(temp, dp, sizeof dp);
		for (int j = 0; j < baos[i].w; j++)
		{
			int hh = 0, tt = -1;
			for (int k = j; k <= W; k += baos[i].w)
			{
				if (hh <= tt && q[hh] < k - baos[i].m * baos[i].w)hh++;
				if (hh <= tt)dp[k] = max(temp[k], temp[q[hh]] + (k - q[hh]) / baos[i].w * baos[i].v);
				while (hh <= tt && temp[k] >= temp[q[tt]]+(k-q[tt])/baos[i].w*baos[i].v)tt--;
				q[++tt] = k;
			}
		}
	}
	cout << dp[W];

	return 0;
}