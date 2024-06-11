


#include<bits/stdc++.h>
using namespace std;

const int N = 1000010;
int n, m;
int sum[N],a[N];
int l[N], r[N], c[N];          //  ���붼��¼������������һ��һ��while(m--)����¼���ٶ���

void insert(int l, int r, int c)
{
	a[l] -= c;            //   ע��-=��+=˳�򣬱������д+=���������⣬�Ǽ�С�ģ�
	a[r + 1] += c;           //   ע��%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%5
}  //%%%%%%%%%%%%%%%%%%%%%%%%%%%% ��ò������ʱ�����������+=���±ߵ���-=
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%555
bool check(int mid)
{
	for (int i = 1; i <= n; i++)
		a[i] = 0;
	for (int i = 1; i <= n; i++)
		insert(i, i, -sum[i]);           //   ������һ�����������飬a[]Ҫ�Ǵ����ж���0��ʼ������ǰһ���Ȱ���ǰ�е�ȫ������
	for (int i = 1; i <= mid; i++)
		insert(l[i], r[i], c[i]);
	for (int i = 1; i <= n; i++)
	{
		a[i] = a[i - 1] + a[i];
		if (a[i] < 0)return 0;
	}
	return 1;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> sum[i];
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> c[i] >> l[i] >> r[i];
	}
	int left = 1, right = m;
	while (left < right)
	{
		int mid = left + right >> 1;    
		if (!check(mid))right = mid;          
		else left = mid + 1;
	}
	if (left < m)
	{
		cout << -1 << endl << left;
	}
	else                              //   ע�⻹��һ������ǲ�ȱ���ҵ������ģ��һ�¾�֪����ʵmid = mʱ��ֱ���˳��ģ����Բ���ȷ��  m ����ȱ��ȱ����Ҫ������ж�
	{
		if (check(m))cout << 0;
		else cout << -1 << endl << m;
	}

	return 0;
}