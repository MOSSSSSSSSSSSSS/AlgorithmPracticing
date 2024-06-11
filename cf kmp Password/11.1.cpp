

#include<bits/stdc++.h>
using namespace std;

const int N = 1000010;
char str[N];
int ne[N];
int len;
int Max;
int ans;

int main()
{
	cin >> str + 1;
	len = strlen(str + 1);
	for (int i = 2, j = 0; str[i]; i++)
	{
		while (j && str[i] != str[j + 1])j = ne[j];
		if (str[i] == str[j + 1])j++;
		ne[i] = j;
		if (i >= 2 && i <= len - 1)
		{
			Max = max(ne[i],Max);
		}
	}
	if (!ne[len])
	{
		cout << "Just a legend";
		return 0;
	}
	for (int i = ne[len];i; i = ne[i])
	{
		if (Max < i)continue;
		for (int j = 2; j <= len - 1; j++)
		{
			if (ne[j] == i)
			{
				ans = i;
				break;
			}
		}
		break;
	}
	if (!ans)
	{
		cout << "Just a legend";
		return 0;
	}
	for (int i = 1; i <= ans; i++)
		cout << str[i];

	return 0;
}