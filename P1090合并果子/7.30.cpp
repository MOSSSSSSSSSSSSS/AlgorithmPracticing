
#include<bits/stdc++.h>
using namespace std;

const int N = 10010,INF = 0x3f3f3f3f;
int fruit[N],s[N], n;
int dp[N][N];    //  合并从哪到哪需要的最小体力 dp[i][j] = dp[i][k]+dp[k+1][j]  +  合并最后两堆(  i<=k<=j-1  )

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;
		fruit[i] = num;
		s[i] = s[i - 1] + fruit[i];
		dp[i][i] = 0;    //    已经是一堆了，是0，不是num
	}

	for (int i = n; i >= 1; i--)
	{
		for (int j = i + 1; j <= n; j++)
		{
			for (int k = i; k <= j - 1; k++)
			{
				if(k==i)dp[i][j] = INF;
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]-s[i-1]+s[j]);
			}
		}
	}

	cout << dp[1][n];

	return 0;
}
//   合并石子只有300多的数据，但这个题有10000的数据，并且这个题%%%%%%%根本不能用石子合并区间DP做，因为石子合并只能合并相邻的两堆，果子合并可以合并任意的两堆，是贪心
//   区间DP是尝试出所有情况，这个题数据太多，需要一些规律
//   规律：不断地拿出最小的两个来，合成一个，放进去，直到合成为一堆，此时就是花费最小体力
//   所以可以用：小根堆
#include<bits/stdc++.h>
using namespace std;

const int N = 10010;
int n, heap[N], Size, res;

void down(int u)
{
	int t = u;
	if (2 * u <= Size && heap[2 * u] < heap[t])t = 2 * u;
	if (2 * u + 1 <= Size && heap[2 * u + 1] < heap[t])t = 2 * u + 1;
	if (t != u)
	{
		swap(heap[t], heap[u]);
		down(t);
	}
}

void up(int u)
{
	while (u / 2 && heap[u / 2] > heap[u])
	{
		swap(heap[u / 2], heap[u]);
		u /= 2;
	}
}

int main()
{
	cin >> n;
	Size = n;
	for (int i = 1; i <= n; i++)cin >> heap[i];
	for (int i = n / 2; i >= 1; i--)down(i);

	while (Size != 1)
	{
		int ans = 0;
		ans += heap[1];
		//swap(heap[1], heap[Size]);     也行
		heap[1] = heap[Size];
		Size--;
		down(1);
		ans += heap[1];
		//swap(heap[1], heap[Size]);
		heap[1] = heap[Size];
		Size--;
		down(1);
		heap[++Size] = ans;
		up(Size);            //   up和down的是 下标 。别写成ans
		res += ans;           //  注意res，ans有什么用
	}

	cout << res;

	return 0;
}