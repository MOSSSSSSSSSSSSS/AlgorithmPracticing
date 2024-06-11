#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//时间复杂度O（nlogn）
const int N = 1e6+10;//数组开的比需要的大10
int q[N];
int n;//一共多少个数
 
void quick_sort(int q[],int l,int r)
{
	if (l >= r)return;//当只有一个数或没有数时直接return

	int x = q[l], i = l - 1, j = r + 1;//两个指针//x是取得分界点，可以取左边界，右边界，随机值，中间值，取左边界时 下面递归 只能是quick_sort(q, l, j)和quick_sort(q, j+1, r)，取右边界时只能是quick_sort(q, l, i-1)和quick_sort(q, i, r)
	//为什么是j，j+1或i-1，i ？因为任何时刻，i的左边（不包括i）都是小于等于x的数，j的右边（不包括j）都是大于等于x的数，i处的数是大于等于x的数，j处的数是小于等于x的数
	//有时取左右边界可能超时，这时可以取中间值q[（i+j）/2]或随机值
	//i和j一开始需要有一个偏移量i = l - 1，j = r + 1，因为是直到型循环
	//还有一种方法可以用两个数组，a【】中放比x小于等于的数，b【】中放比x大于等于的数，再把a【】，b【】放到p【】中
	while (i < j)//注意i < j
	{
		do i++; while (q[i] < x);//注意是小于
		do j--; while (q[j] > x);//注意是大于
		if (i < j)swap(q[i], q[j]);//交换有条件，只有i < j时交换，i > j时不能交换
	}
	//分界点处的数不一定等于x，x可能出现在奇怪的地方
	quick_sort(q, l, j);
	quick_sort(q, j + 1, r);
}

int main()
{
	scanf("%d", &n);//任何情况都比cin更快
	for (int i = 0; i < n; i++)scanf("%d", &q[i]);//大括号里只有一个语句可以直接写后面

	quick_sort(q, 0, n - 1);//参数，数组，0，n-1

	for (int i = 0; i < n; i++)printf("%d ", q[i]);
}