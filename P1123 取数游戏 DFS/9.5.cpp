

//  两个需要注意的点
//1.一个点被选中就是check[x][y] = 1，看一个点能不能被选，是看一个点周围有没有check为1的，如果没有可以被选
//  而不是：一个点被选中就是周围所有的点都check[x][y] = 1，一个点选中后又删除，会导致周围所有的点check又变为0，但是它周围的点的周围的点如果有1，它周围的点是不能变为0的，所以这种方法会出现错误
//2.dfs中的两重循环要从目前找的点后面的点里找，如果每次都全找一遍会超时，同一个答案会算好几遍
//例如 同一个答案可能从前往后找了一遍，又从第二个找第一个找第三个找第四个找一遍，又从后往前找一遍。


#include<bits/stdc++.h>
using namespace std;

const int N = 15;
int t, n, m;
int num[N][N],ans;
bool check[N][N];
int dx[9] = { 1,1,0,-1,-1,-1,0,1 ,0 };
int dy[9] = { 0,-1,-1,-1,0,1,1,1 ,0 };

bool judge(int x, int y)
{
	for (int i = 0; i < 9; i++)
		if (x + dx[i] >= 1 && x + dx[i] <= n && y + dy[i] >= 1 && y + dy[i] <= m&& check[x + dx[i]][y + dy[i]])
			return false;
	return true;
}

void dfs(int x,int y,int add)
{
	add += num[x][y];
	check[x][y] = 1;

	for (int i = x; i <= n; i++)
	{
		int j;
		if (i == x)
			j = y + 2;
		else
			j = 1;
		for (; j <= m; j++)
		{
			if (judge(i,j))
			{
				dfs(i,j,add);
				check[i][j] = 0;
			}
		}
	}

	ans = max(ans, add);
}

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> num[i][j];
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				dfs(i, j, 0);
				check[i][j] = 0;
			}
		}
		cout << ans << endl;
		ans = 0;
	}

	return 0;
}