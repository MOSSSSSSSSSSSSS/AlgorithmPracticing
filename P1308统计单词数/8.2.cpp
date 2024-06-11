


//    cin>>string  到空格为止，空格不读入
//    getline(cin,string) 到回车结束，输入一行,但是，读的是第二行输入的字符串，而上一行用的cin，
//    剩一个回车，所以得先把回车读了  ,  getchar,scanf(%c)都能读回车


#include<bits/stdc++.h>
using namespace std;

const int N = 1000010,P = 131;
typedef unsigned long long ULL;
ULL ht, h0;
string str;
int sum,pos;

ULL Hash(string str)
{
	ULL ans = 0;
	int n = str.size();
	for (int i = 0; i < n; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;              //     题目说不区分大小写
		ans = ans * P + str[i];
	}

	return ans;
}

int main()
{
	cin >> str;
	h0 = Hash(str);
	getchar();
	getline(cin, str);
	int i = 0;
	while (str[i]==' ')
		i++;
	for (int j = i+1;j<str.size(); j++)
	{
		if (str[j] == ' ')
		{
			ht = Hash(str.substr(i, j - i));
			if (h0 == ht)
			{
				sum++;
				if (sum == 1)pos = i;
			}
			while (str[j] == ' ')
				j++;
			i = j;
		}
	}
	ht = Hash(str.substr(i, str.size() - i));
	if (h0 == ht)
	{
		sum++;
		if (sum == 1)pos = i;
	}
	
	if (sum) cout << sum << ' ' << pos;
	else cout << -1;

	return 0;
}