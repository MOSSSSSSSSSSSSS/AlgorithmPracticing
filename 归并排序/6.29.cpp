#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//归并排序复杂度一定是O（nlog2n），是稳定的，快速排序时不稳定的，但可以改为稳定的，快速排序有时复杂度会变为n方
//归并排序是先取数组中心下标的值，分为左右两边，对两边分别递归排序，最终将两个已经排好序的数组合并为一个数组
//复杂度是怎么算的？  一个大小为n的数组最终被分为n个大小为一的数组，一共分log2n次，每次的复杂度都是n（如2个大小为n/2的数组），再相乘
const int N = 1000010;
int q[N], tmp[N];//归并排序需要一个临时数组
int n;

void merge_sort(int q[],int l,int r)
{
	if (l >= r)return;//归并排序大于等于或等于等于都行

	int mid = l + r>>1;//l+r除以二
	merge_sort(q, l, mid);
	merge_sort(q, mid + 1, r);

	int k = 0, i = l, j = mid + 1;
	while (i <= mid&&j<=r)//注意小于等于,两个都没超出时,所以用&&
	{
		if (q[i] <= q[j])tmp[k++] = q[i++];//稳定排序
		else tmp[k++] = q[j++];
	}
	while (i <= mid)tmp[k++] = q[i++];
	while (j <= r)tmp[k++] = q[j++];

	for (i = l, j = 0; i <= r; i++, j++)q[i] = tmp[j];//最后将tmp中的数移到原数组中，注意i等于l
}

int main()
{ 
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &q[i]);

	merge_sort(q, 0, n - 1);

	for (int i = 0; i < n; i++)printf("%d ", q[i]); 

	return 0;
}