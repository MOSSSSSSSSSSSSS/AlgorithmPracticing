


//   许多kmp都可以字符串哈希做，但是有一种只能kmp做，就是找字符串的循环节，假设要找的字符串长len
//   求出的ne数组 , len-ne[len]，就是最小循环节的长度，从第一个字母开始就是最小循环节。
//   如果len对len-ne[len]可以整除，说明就是完全由最小循环节组成的字符串
//   如果不能整除，说明可能是这种情况：bcabcabcab，最小循环节是bca，但需要补几个字母

#include<bits/stdc++.h>
using namespace std;

const int N = 1000010;
int len;
char str[N];
int ne[N];

int main()
{
	cin >> len >> str+1;
	for (int i = 2, j = 0; i <= len; i++)
	{
		while (j && str[i] != str[j + 1])j = ne[j];
		if (str[i] == str[j + 1])j++;
		ne[i] = j;
	}

	cout << len - ne[len];

	return 0;
}