
//ǰ׺�ͣ������������дӵ�l������r�����ĺͣ�1<=l<=r<=n��������a1��a2������������an��
//����ǰ׺������s0 = 0
//����Ҫ������ʱ�����ÿ����Ͷ�ѭ��һ�Σ�ÿ�ζ���O��n�����Ӷȣ�����������ǰ׺�����飬ÿ��ֻ��Ҫ����S��r�� - S��l - 1����ÿ�ζ���O��1�����Ӷ�

//����  ios::sync_with_stdio(false);   ����ʹcin�ٶȱ�죬������ʹ��scanf��


#include<iostream>
using namespace std;

const int N = 100010;
int n, m, a[N], s[N];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)s[i] = s[i - 1] + a[i];

	while (m--)//��m��ѯ��
	{
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%d\n", s[r] - s[l - 1]);
	}

	return 0;
}