
// to_chars是c++17的函数
// puts输出字符串，输出时将最后的\0输出为回车
strtol将一个进制的字符串转换成十进制的long
to_chars将一个十进制的数转换成n进制的字符串，其中英文字母小写

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