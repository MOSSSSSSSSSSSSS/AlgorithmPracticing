
//一种是像归并排序的 两个序列 用两个指针  一种是像快速排序 一个 序列 用 两个指针

//用来优化，把O(n2)优化成O（n）
//题目满足某种性质，使得i从0到n，而j不用每个循环都从0到n走一遍，j只用从0到n走一遍，j不回去
//此题j就不用回去，j只需要往后走或不动

//暴力做法：通过枚举所有连续子序列，找出最长的且不重复的。子序列包括起点终点，通过两重循环枚举所有。
#include<iostream>
using namespace std;

const int N = 100010;
int n, res;
int q[N],s[N];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &q[i]);

	for (int i = 0, j = 0; i < n; i++)
	{
		s[q[i]]++;
		while (s[q[i]] > 1)
		{
			s[q[j]]--;
			j++;
		}
		res = max(res, i - j + 1);
	}
	
	printf("%d", res);

	return 0;
}