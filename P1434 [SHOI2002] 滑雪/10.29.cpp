

#include<bits/stdc++.h>
using namespace std;

const int N = 110;
struct node {
	int h, x, y;
	friend bool operator <(node a, node b)
	{
		return a.h > b.h;
	}
};
priority_queue<node> heap;
int r, c;
int Map[N][N];
int sum[N][N];
int ans;

int main()
{
	cin >> r >> c;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			cin >> Map[i][j], heap.push({Map[i][j],i,j});
	while (heap.size())
	{
		node tt = heap.top();
		heap.pop();
		int i = tt.x, j = tt.y;
		if (i >= 1 && i <= r && j - 1 >= 1 && j - 1 <= c)
		{
			if (Map[i][j - 1] < Map[i][j])
			{
				sum[i][j] = max(sum[i][j], sum[i][j - 1] + 1);
			}
		}
		if (i >= 1 && i <= r && j + 1 >= 1 && j + 1 <= c)
		{
			if (Map[i][j + 1] < Map[i][j])
			{
				sum[i][j] = max(sum[i][j], sum[i][j + 1] + 1);
			}
		}
		if (i - 1 >= 1 && i - 1 <= r && j >= 1 && j <= c)
		{
			if (Map[i - 1][j] < Map[i][j])
			{
				sum[i][j] = max(sum[i][j], sum[i - 1][j] + 1);
			}
		}
		if (i + 1 >= 1 && i + 1 <= r && j >= 1 && j <= c)
		{
			if (Map[i + 1][j] < Map[i][j])
			{
				sum[i][j] = max(sum[i][j], sum[i + 1][j] + 1);
			}
		}
		if (!sum[i][j])sum[i][j] = 1;
		ans = max(sum[i][j], ans);
	}
	cout << ans;

	return 0;
}