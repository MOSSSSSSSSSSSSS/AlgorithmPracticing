
//  ���⣺�����������٣�ÿ���ֵ���ܳ������ޣ�ÿ�����������
//  ̰�ģ���С�������У�lָ������rָ�����ң������С�����û�������޾ͷ�Ϊһ�飬l++,r--
//        ����������ޣ���󵥶�һ��r--��������ʣһ�����ٷ�һ��
#include<bits/stdc++.h>
using namespace std;

const int N = 30010;
int w, n;
int g[N],ans;

int main()
{
	cin >> w >> n;
	for (int i = 1; i <= n; i++)
		cin >> g[i];
	sort(g + 1, g + n + 1);          //  �� �� �±� 1��ʼ��n������  ������һ��λ�ò��䣨û������

	int l = 1, r = n;
	while (l < r)
	{
		if (g[l] + g[r] <= w)
		{
			ans++;
			l++;
			r--;
		}
		else
		{
			ans++;
			r--;
		}
	}
	if (l == r)ans++;        //  ������l>r�ˣ�Ҳ�����ǵ�����

	cout << ans;

	return 0;
}