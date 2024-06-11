


#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
const int N =1000010, P = 131;
ULL hash_ming[N], hash_mi[N];
int ne_ming[N], ne_mi[N],tmp[N];
int len_ming, len_mi;
string str;

ULL Hash(string str)
{
	ULL ans = 0;
	for (int i = 0; i < str.size(); i++)
		ans = ans * P + str[i];
	return ans;
}

int main()
{
	for (int i = 1;; i++)
	{
		cin >> str;
		if (str == "$")
		{
			len_ming = i - 1;
			break;
		}
		else
			hash_ming[i] = Hash(str);
	}
	for (int i = 1;; i++)
	{
		cin >> str;
		if (str == "$")
		{
			len_mi = i - 1;
			break;
		}
		else
			hash_mi[i] = Hash(str);
	}
	for (int i = 2, j = 0; i <= len_mi; i++)
	{
		while (j && hash_mi[i] != hash_mi[j + 1])j = ne_mi[j];
		if (hash_mi[i] == hash_mi[j + 1])j++;
		ne_mi[i] = j;
	}
	for (int i = 1; i + len_mi - 1 <= len_ming; i++)
	{
		for (int j = i; j <= i + len_mi - 1; j++)
			tmp[j - i + 1] = hash_ming[j];
		for (int j = 2, k = 0; j <= len_mi; j++)
		{
			while (k && tmp[j] != tmp[k + 1])k = ne_ming[k];
			if (tmp[j] == tmp[k + 1])k++;
			ne_ming[j] = k;
		}
		int j = 1;
		for (; j <= len_mi; j++)
			if (ne_ming[j] != ne_mi[j])
				break;
		if (j == len_mi + 1)
		{
			cout << i;
			return 0;
		}
	}

	return 0;
}