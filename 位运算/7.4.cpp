

//��һ��   l + r >> 1   �ȼ���   ��l+r��/2
//�ڶ���   ��λ�� & �������������� �ڴ��в�����ʽ ��Ӧλ�� ���� ��Ϊ 1ʱ ����� 1�����������0
//������   �� һ���� ��������ʽ �� ��k������1����0   �� n >> k & 1  ����10�Ķ�������1010�����ҵ��������ǵ�0������1������2������3����Ҫ��� 1 ���Ǽ�����10 >> 1 & 1,10>>1�����101(������)��1��001��&������1
//���ĸ�   lowbit��x�����ض����������һ��1����1000111000������1000(2����)�����ʵ�֣�x&-x��-x�Ĳ�����xȡ����һ���������1000,   ����ʵ��ͳ��x��1�ĸ�����
//�����   c++������Ƹ�����ϵͳ���Զ��� ���λ �� 1
#include<iostream>
using namespace std;

int lowbit(int x)
{
	return x & -x;
}

int main()
{
	cout << (15 >> 1) << endl;

	cout << lowbit(10);

	return 0;
}

//����������1�ĸ�����
#include<iostream>
using namespace std;

int n;
int lowbit(int x)
{
	return x & -x;
}

int main()
{
	scanf("%d", &n);

	while (n--)
	{
		int x;
		scanf("%d", &x);

		int res = 0;
		while (x)
		{
			x -= lowbit(x);
			res++;
		}
		printf("%d ", res);
	}

	return 0;
}
#include<iostream>
using namespace std;

int lowbit(int x)
{
	return x & -x;
}

int main()
{

	int x;
	scanf("%d", &x);

	int res = 0;
	while (x)
	{
		x -= lowbit(x);
		res++;
	}
	printf("%d ", res);

	return 0;
}
