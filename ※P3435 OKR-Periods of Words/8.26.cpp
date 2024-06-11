

#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1000010;
int len;
char str[N];
int ans;
int ne[N];

int max_cycle(int end)
{
	int ans = 0;
	for (int i = ne[end]; i; i = ne[i])
	{
		int j = ne[i];
		if (j == 0)
		{
			ans = end - i;
			ne[end] = i;   //   23�м��仯�����ⲻ��Ҫ���ظ�%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		} //                     ʵ�����������С����ȵ�ǰ��׺����kmp����һ�����һ����С
	}
	return ans;
}

signed main()
{
	cin >> len >> str + 1;
	for (int i = 2, j = 0; i <= len; i++)
	{
		while (str[i] != str[j + 1] && j)j = ne[j];
		if (str[i] == str[j + 1])j++;
		ne[i] = j;
	}
	for (int i = 1; i <= len; i++)
		ans += max_cycle(i);
	cout << ans;

	return 0;
}