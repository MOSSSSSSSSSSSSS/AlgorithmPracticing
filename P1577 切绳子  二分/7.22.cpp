

//      ע��   ����   ��Ϊ  ������  ����  ʱ���ں����ڲ� �ı������ֵ��ʵ�λ�ı�
//      ��Ϊ������һ�㣬�����˷�ʱ��


//   ֱ�ӶԴ𰸶��� 
//      ���Ƕ��ָ��������������е�������100���������100����������  ��mid���Զ���ʱ��midֱ����int���У�û��double��   ��Ϊ ������ ������ ��
//      if (sum >= k)return false;
//	    else return true;
//һ��ʼ������д�ģ�
//if (check(mid, k, sheng, n)) r = mid;
//		else l = mid + 1;
//�ʹ��ˣ�������ĳ�
//if (sum >= k)return true;
//	else return false;
//  ����ĳ�
//int mid = (l + r + 1) / 2;
//if (check(mid, k, sheng, n)) l = mid;
//else r = mid - 1;
//  �Ͷ���
//
#include<bits/stdc++.h>
using namespace std;

const int N = 10010;
int n, k;
int sheng[N], m;

bool check(int mid, int k, int sheng[], int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		int j = sheng[i];
		while (j - mid >= 0)
		{
			j -= mid;
			sum++;
		}
	}
	//l = mid
	if (sum >= k)return true;//  ����ʱ������Ҫ���ֵ���������������ķ����ƶ�
	else return false;
}

int main()
{
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		double a;
		cin >> a;
		sheng[i] = int(a * 100);
		m = max(m, sheng[i]);
	}
	int l = 0, r = m;
	while (r - l > 0.0001)           //   Ҫ��0.01��ֱ�Ӷ�2��0��0.0001
	{
		int mid = (l + r + 1) / 2;
		if (check(mid, k, sheng, n)) l = mid;
		else r = mid - 1;
	}
	printf("%.2f", r / 100.0);                //��100.0���ٱ�����λ���                 //  printf("%.2f"  �����������,����Ҫ��ֱ����ȥ

	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;

const int N = 10010;
int n, k;
double sheng[N],m;

bool check(double mid,int k,double sheng[],int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		double j = sheng[i];
		while (j-mid>=0)
		{
			j -= mid;
			sum++;
		}
	}
	//l = mid
	if (sum >= k)return false;//  ����ʱ������Ҫ���ֵ���������������ķ����ƶ�
	else return true;
}

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> sheng[i];
		m = max(m, sheng[i]);
	}
	double l = 0, r = m+3;
	while (r - l > 0.001)
	{
		double mid = (l + r) / 2.0;
		if(!mid)break;
		if (check(mid, k, sheng, n)) r = mid;
		else l = mid;
	}
	printf("%.2lf", ((l * 100)) / 100.0);                     //  printf("%.2f"  �����������,����Ҫ��ֱ����ȥ
	return 0;
}
*/