
//注意是一个个的数，界限分明

#include<iostream>
using namespace std;

const int N = 1010;
int n, m, q, a[N][N], s[N][N];

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];//求一个矩阵的前缀和矩阵，这是放在另一个二维数组中，也可以用覆盖原二维数组的方法
	while (q--)
	{
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%d\n", s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);//有了前缀和矩阵可以求，子矩阵的和
	}


	return 0;
}