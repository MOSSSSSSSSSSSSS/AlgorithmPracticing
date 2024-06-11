

//   第一步  构造串，都构造成奇回文串，先往  a + 1 输入原串，再把原串两端和每两个字符之间添加一个原串中不会出现的字符 ，给s + 1串，s[0] = ￥，叫哨兵（边界）方便写代码
//    回文半径：如果 7 长度的回文串，是 4 要算上中心的字符
//     加速盒子：同拓展KMP算法里的盒子
//     复杂度O（n）

//         去看董晓算法

#include<bits/stdc++.h>
using namespace std;

const int N = 11000010;
char a[N],s[2*N];
int d[2 * N];
int ans;

void get_d(char s[], int n)
{
	for (int i = 2, l, r = 1; i <= n; i++)     // l,r闭区间
	{
		if (i <= r)d[i] = min(d[r - i + l], r - i + 1);        //加速盒子里找答案
		while (s[i - d[i]] == s[i + d[i]])d[i]++;//暴力找答案
		if (i + d[i] - 1 > r)l = i - d[i] + 1, r = i + d[i] - 1;//更新盒子，逗号将两个语句合并成一个，可以写在后面
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
	cout << ans - 1;                                   // 原串最长回文串的长度等于构造串最大半径-1

	return 0;
}
