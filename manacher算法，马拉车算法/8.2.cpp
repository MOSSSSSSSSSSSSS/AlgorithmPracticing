

//   ��һ��  ���촮�������������Ĵ�������  a + 1 ����ԭ�����ٰ�ԭ�����˺�ÿ�����ַ�֮�����һ��ԭ���в�����ֵ��ַ� ����s + 1����s[0] = �������ڱ����߽磩����д����
//    ���İ뾶����� 7 ���ȵĻ��Ĵ����� 4 Ҫ�������ĵ��ַ�
//     ���ٺ��ӣ�ͬ��չKMP�㷨��ĺ���
//     ���Ӷ�O��n��

//         ȥ�������㷨

#include<bits/stdc++.h>
using namespace std;

const int N = 11000010;
char a[N],s[2*N];
int d[2 * N];
int ans;

void get_d(char s[], int n)
{
	for (int i = 2, l, r = 1; i <= n; i++)     // l,r������
	{
		if (i <= r)d[i] = min(d[r - i + l], r - i + 1);        //���ٺ������Ҵ�
		while (s[i - d[i]] == s[i + d[i]])d[i]++;//�����Ҵ�
		if (i + d[i] - 1 > r)l = i - d[i] + 1, r = i + d[i] - 1;//���º��ӣ����Ž��������ϲ���һ��������д�ں���
	}
}

int main()
{
	cin >> a + 1;
	int n = strlen(a + 1),k = 0;
	s[0] = '$'; s[++k] = '#';
	for (int i = 1; i <= n; i++)
	{
		s[++k] = a[i];
		s[++k] = '#';
	}
	n = k;

	d[1] = 1;
	get_d(s,n);

	for (int i = 1; i <= n; i++)ans = max(ans, d[i]);
	cout << ans - 1;                                   // ԭ������Ĵ��ĳ��ȵ��ڹ��촮���뾶-1

	return 0;
}
