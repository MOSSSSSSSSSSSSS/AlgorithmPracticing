
#include<bits/stdc++.h>
using namespace std;

const int N = 110, M = 550;
int n, W,sw;
struct good {
	int w, p;
}goods[N];
int dp[M];
int MIN = 1e8;

int main()
{
	cin >> n >> W;
	for (int i = 1; i <= n; i++)
	{
		cin >> goods[i].w >> goods[i].p;
		MIN = min(MIN, goods[i].w);
	}
	MIN--;
	for (int i = 1; i <= n; i++)
		goods[i].w -= MIN,sw+=goods[i].w;
	for (int i = 1; i <= n; i++)
		for (int j = sw; j >= goods[i].w; j--)
			for(int k = )
	cout << dp[W];

	return 0;
}