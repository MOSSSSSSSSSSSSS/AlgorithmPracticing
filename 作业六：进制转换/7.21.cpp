
// to_chars��c++17�ĺ���
// puts����ַ��������ʱ������\0���Ϊ�س�
strtol��һ�����Ƶ��ַ���ת����ʮ���Ƶ�long
to_chars��һ��ʮ���Ƶ���ת����n���Ƶ��ַ���������Ӣ����ĸСд

#include<bits/stdc++.h>
using namespace std;

const int N = 40;
int n, m;
char str[N], ans[N];

int main()
{
	cin >> n >> str >> m;
	to_chars(ans, ans + N, strtol(str, NULL, n), m);
	for (int i = 0; ans[i]; i++)
		if (ans[i] >= 'a' && ans[i] <= 'z')
			ans[i] = ans[i] - 'a' + 'A';
	puts(ans);

	return 0;
}