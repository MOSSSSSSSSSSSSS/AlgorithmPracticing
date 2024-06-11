
//差分数组相当于原数组，前缀和数组是前n项和数组
//如果想让前缀和数组从 l 到 r 项都加一个数 c ，可以将 它的 差分数组 在 l项 加上一个c ，在 r+1项 减去一个 c
//注意从  1  下标 开始。
#include<iostream>
using namespace std;

const int N = 100010;
int n, m;
int a[N], b[N];

void insert(int l, int r, int c)//初始化差分矩阵，即找到所给矩阵的差分矩阵，和后面给差分矩阵l处+c，r+1处减c操作是一样的，用一个函数
{
	b[l] += c;
	b[r + 1] -= c;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)scanf("%d", &a[i]);

	for (int i = 1; i <= n; i++)insert(i, i, a[i]);

	while (m--)
	{
		int l, r, c;
		scanf("%d%d%d", &l, &r, &c);
		insert(l, r, c);
	}

	for (int i = 1; i <= n; i++)b[i] += b[i - 1];

	for (int i = 1; i <= n; i++)printf("%d ", b[i]);

	return 0;
}