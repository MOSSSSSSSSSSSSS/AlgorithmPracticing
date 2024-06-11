#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//时间复杂度O（n）
const int N = 1000010;
int q[N];
int n, k;

int quick_select(int l, int r, int k)
{
	if (l == r)return q[l];//要找的数一直在递归的数组里，当数组只剩下一个时，就是要找的数。

	int x = q[l], i = l - 1, j = r + 1;
	while(i < j)
	{
		while (q[++i] < x);
		while (q[--j] > x);
		if (i < j)swap(q[i], q[j]);
	}
	int sl = j - l + 1;
	if (sl >= k)return quick_select(l, j, k);

	return quick_select(j + 1, r, k - sl);
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)scanf("%d", &q[i]);
	printf("%d", quick_select(0, n - 1, k));
}