#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//ʱ�临�Ӷ�O��nlogn��
const int N = 1e6+10;//���鿪�ı���Ҫ�Ĵ�10
int q[N];
int n;//һ�����ٸ���
 
void quick_sort(int q[],int l,int r)
{
	if (l >= r)return;//��ֻ��һ������û����ʱֱ��return

	int x = q[l], i = l - 1, j = r + 1;//����ָ��//x��ȡ�÷ֽ�㣬����ȡ��߽磬�ұ߽磬���ֵ���м�ֵ��ȡ��߽�ʱ ����ݹ� ֻ����quick_sort(q, l, j)��quick_sort(q, j+1, r)��ȡ�ұ߽�ʱֻ����quick_sort(q, l, i-1)��quick_sort(q, i, r)
	//Ϊʲô��j��j+1��i-1��i ����Ϊ�κ�ʱ�̣�i����ߣ�������i������С�ڵ���x������j���ұߣ�������j�����Ǵ��ڵ���x������i�������Ǵ��ڵ���x������j��������С�ڵ���x����
	//��ʱȡ���ұ߽���ܳ�ʱ����ʱ����ȡ�м�ֵq[��i+j��/2]�����ֵ
	//i��jһ��ʼ��Ҫ��һ��ƫ����i = l - 1��j = r + 1����Ϊ��ֱ����ѭ��
	//����һ�ַ����������������飬a�����зű�xС�ڵ��ڵ�����b�����зű�x���ڵ��ڵ������ٰ�a������b�����ŵ�p������
	while (i < j)//ע��i < j
	{
		do i++; while (q[i] < x);//ע����С��
		do j--; while (q[j] > x);//ע���Ǵ���
		if (i < j)swap(q[i], q[j]);//������������ֻ��i < jʱ������i > jʱ���ܽ���
	}
	//�ֽ�㴦������һ������x��x���ܳ�������ֵĵط�
	quick_sort(q, l, j);
	quick_sort(q, j + 1, r);
}

int main()
{
	scanf("%d", &n);//�κ��������cin����
	for (int i = 0; i < n; i++)scanf("%d", &q[i]);//��������ֻ��һ��������ֱ��д����

	quick_sort(q, 0, n - 1);//���������飬0��n-1

	for (int i = 0; i < n; i++)printf("%d ", q[i]);
}