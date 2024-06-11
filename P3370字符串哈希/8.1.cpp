

#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
const int N = 10010,P = 131;
int n;
string str;
ULL h[N];

ULL Hash(string str)
{
	ULL ans = 0;
	int n = str.size();
	for (int i = 0; i < n; i++)   //  共n个字符，从0到<n
		ans = ans * P + ULL(str[i]);    // 转换成ULL   //  直接往一个字符串里输入一个大数，最高位在下标0处

	return ans;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> str;
		h[i] = Hash(str);      //   各个字符串的哈希值存在数组里
	}

	sort(h + 1, h + 1 + n);
	int ans = 0;
	for (int i = 1; i < n; i++)
		if (h[i] != h[i + 1])ans++;

	cout << ans+1;

	return 0;
}