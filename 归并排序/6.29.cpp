#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//�鲢�����Ӷ�һ����O��nlog2n�������ȶ��ģ���������ʱ���ȶ��ģ������Ը�Ϊ�ȶ��ģ�����������ʱ���ӶȻ��Ϊn��
//�鲢��������ȡ���������±��ֵ����Ϊ�������ߣ������߷ֱ�ݹ��������ս������Ѿ��ź��������ϲ�Ϊһ������
//���Ӷ�����ô��ģ�  һ����СΪn���������ձ���Ϊn����СΪһ�����飬һ����log2n�Σ�ÿ�εĸ��Ӷȶ���n����2����СΪn/2�����飩�������
const int N = 1000010;
int q[N], tmp[N];//�鲢������Ҫһ����ʱ����
int n;

void merge_sort(int q[],int l,int r)
{
	if (l >= r)return;//�鲢������ڵ��ڻ���ڵ��ڶ���

	int mid = l + r>>1;//l+r���Զ�
	merge_sort(q, l, mid);
	merge_sort(q, mid + 1, r);

	int k = 0, i = l, j = mid + 1;
	while (i <= mid&&j<=r)//ע��С�ڵ���,������û����ʱ,������&&
	{
		if (q[i] <= q[j])tmp[k++] = q[i++];//�ȶ�����
		else tmp[k++] = q[j++];
	}
	while (i <= mid)tmp[k++] = q[i++];
	while (j <= r)tmp[k++] = q[j++];

	for (i = l, j = 0; i <= r; i++, j++)q[i] = tmp[j];//���tmp�е����Ƶ�ԭ�����У�ע��i����l
}

int main()
{ 
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &q[i]);

	merge_sort(q, 0, n - 1);

	for (int i = 0; i < n; i++)printf("%d ", q[i]); 

	return 0;
}