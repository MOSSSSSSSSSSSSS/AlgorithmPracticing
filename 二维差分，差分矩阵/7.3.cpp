
//通过画图更好理解，注意是一个个分散的点，界限分明，通过差分矩阵几个元素的加减（使用insert函数），使前缀和矩阵  要求的  一个子矩阵 所有元素都 加 上 c
//对于给出的原矩阵，即前缀和矩阵 ，求它的 差分 矩阵，我们可以先假设 原矩阵 全为0 ，则它的差分矩阵也一定全是0，然后因为可以 通过差分矩阵几个元素的加减（使用insert函数），使前缀和矩阵
//变成一个新的矩阵，所以我们可以 用 insert函数 对全是0的差分矩阵进行处理 ，使处理后差分矩阵的前缀和矩阵 从全为0 的前缀和矩阵 变成题目给出的矩阵，这时
//我们就得到了题目中给出矩阵的 差分矩阵
//具体处理全为0的差分矩阵的方法是：由于insert函数可以使前缀和矩阵 的一个子矩阵 都加 c，所以 当 x1 = x2 ，y1 = y2时 就相当于只改变前缀和矩阵中的一个元素的值
//这样一个一个改变，就使全为0的前缀和矩阵变成题目中给的矩阵

#include<iostream>
using namespace std;

const int N = 1010;
int n, m, q;
int a[N][N], b[N][N];

void insert(int x1, int y1, int x2, int y2, int c)
{
	b[x1][y1] += c;
	b[x1][y2 + 1] -= c;
	b[x2 + 1][y1] -= c;
	b[x2 + 1][y2 + 1] += c;
}

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			insert(i, j, i, j, a[i][j]);

	while (q--)
	{
		int x1, y1, x2, y2, c;
		scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
		insert(x1, y1, x2, y2, c);
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			printf("%d ", b[i][j]);
		cout << endl;
	}

	return 0;
}