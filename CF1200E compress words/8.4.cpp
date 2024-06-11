


//  用哈希这种相对简单的算法做过了这道题，首先遇到的第一个困难是TLE，这是因为每次都计算哈希值，后来发现许多哈希值都可以通过前面算出来的哈希值一步计算出来，不用再通过Hash函数进入循环计算
//  用一个P数组记录P的各个次方的值，用上一次的值求下一次的值，解决了，哈希TLE的问题。
//  第二个问题是：题目卡了自然溢出法的哈希，这是可以改P，改mod，改成单模数或10的18次方级别的模数或双模数，这样就可以过。
//     改成单模数的改法：其他不变，ULL什么的也不用变，直接定义mod，再将Hash函数改成这样(ans * P + str[i])%mod;但这样还没完，所有与计算哈希值有关的都要加%mod，还有P的幂次的数组，用上一次哈希结果求
//     下一次哈希结果时，都要加上  %mod

//             以上做到，这题就过了

#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
const ULL P = 291143, N = 1000010,mod = 998244353;  //  mod:212370440130137957  ll  后面是long long 缩写       P:291143,131,13331
int n;
string str,s;
ULL p[N];

ULL Hash(string str)
{
	ULL ans = 0;
	for (int i = 0; i < str.size(); i++)
		ans = (ans * P + str[i])%mod;

	return ans;
}

int main()
{
	cin.tie(0);
	p[0] = 1;
	for (int i = 1; i < N; i++)p[i] = (p[i - 1] * P)%mod;
	cin >> n;
	cin >> str;
	for (int i = 1; i < n; i++)
	{
		cin >> s;
		int j = 1,m = 0;
		//while (Hash(str.substr(str.size() - j, j)) == Hash(s.substr(0, j)))j++;          //第一个串后缀和第二个串前缀相等，可能  ast ， ast，不一定第一个的最后一个就一定和第二个第一个相等

		ULL has1 = Hash(str.substr(str.size() - j, j));
		ULL has2 = Hash(s.substr(0, j));

		while (1)                //  注意str.size()返回值unsigned，但是要是负数才能退出循环，所以要把他准换成int，才能计算出负数从而退出循环
		{
			if (has1!=has2)
				j++;
			else
				m = j++;
			if ((int(str.size())-j>=0)&&(j-1<s.size()))
			{
				has1 = (has1 + str[str.size() - j] * p[j - 1])%mod;
				has2 = (has2 * P + s[j - 1])%mod;
			}
			else
				break;
		}
		str += s.substr(m);
	}

	cout << str;

	return 0;
}
