

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
	for (int i = 0; i < n; i++)   //  ��n���ַ�����0��<n
		ans = ans * P + ULL(str[i]);    // ת����ULL   //  ֱ����һ���ַ���������һ�����������λ���±�0��

	return ans;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> str;
		h[i] = Hash(str);      //   �����ַ����Ĺ�ϣֵ����������
	}

	sort(h + 1, h + 1 + n);
	int ans = 0;
	for (int i = 1; i < n; i++)
		if (h[i] != h[i + 1])ans++;

	cout << ans+1;

	return 0;
}