
//˫ָ���㷨����ĳ�ַ���������ָ�벻���ݣ�ǰ׺��

#include<bits/stdc++.h>
using namespace std;

const int N = 1000010;

int m;
int s[N];

int main()
{
	cin >> m;
	int l = 1, r = 2;

	for (int i = 1; i <= (m + 1 >> 1); i++)    //m+1>>1  ���Զ����ü�����
		s[i] = s[i - 1] + i;  //         ��ǰ׺�����飬��  m+1>>1

	while (l < r&&r<=m+1>>1)     //  ʹ��   ˫ָ���㷨  ��i<j  ��Ҫע�� j <= m+1>>1
	{
		if (s[r] - s[l - 1] > m)l++;              //���С��  r++
		else if (s[r] - s[l - 1] < m)r++;         //�������   l++ 
		else//                                   ֻ��++�Ĳ���
		{
			cout << l << ' ' << r << endl;
			l++;       //��l++����һ�����
		}
	}

	return 0;

}