

//���ֲ�һ����  ������һ�����е�  ����¿���ʹ�ã���������������������⣬Ҳ�����ö��֣���ʱ����Ҫд   check����  if(check)  r = mid;else  l = mid + 1(�ٸ�����)
//������ʱ��ģ���ᵽ�������Բ�Ҫ��֪��check������ʲô��

#include<bits/stdc++.h>
using namespace std;

const int N = 510;

int m, k,l,r = 1e9;
int a[N], L[N], R[N];

bool check(int sum)
{
	int s = 0, cnt = 1;
	R[cnt] = m;
	for (int i = m; i >= 1; i--)
	{
		if (s + a[i] <= sum)s += a[i];
		else
		{
			L[cnt] = i + 1;
			cnt++;
			R[cnt] = i;
			s = a[i];
		}
	}
	L[cnt] = 1;

	if (cnt<=k)return true;
	else return false;
}

int main()
{
	cin >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &a[i]);
		l = max(l, a[i]);
	}

	while (l < r)
	{
		int mid = l + r >> 1;
		if (check(mid))r = mid;
		else l = mid + 1;
	}

	check(l);
	for (int i = k; i >= 1; i--)
		cout << L[i] << ' ' << R[i] << endl;
	

	return 0;
}