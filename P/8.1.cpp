

//              注意：什么是sizeof函数，什么是size函数，想要求string中字符个数用的是  .size()，求某个类型所占字节大小，用  sizeof(int)
//                    此题没分清，浪费时间
//                    还要注意    string 的 size函数，大小不包括尾零，就是字符的数量


#include<bits/stdc++.h>
using namespace std;

const int N = 30;
int n;
char head;
string words[N];
int times[N];
int ans,res;

void dfs(int u)
{
	times[u]++;
	for (int i = 1; i <= n; i++)
	{
		int num = 0;
		for (int j = 1; j < min(words[u].size(), words[i].size()); j++)
		{
			if (words[u].substr(words[u].size() - j, j) == words[i].substr(0, j))                //   用substr  求  子串  要注意如果看第一个字母，不一样，不要退出循环，可能前两个是一样的
			{
				num = j;
				break;
			}
		}//    为什么break：也许你和我一样，和出题人对题意的理解不同。对于 abbb, bbbcde 两个相连，应该只合并一个 b，变 abbbbbcde；而非 3 个 b 都合并掉。 ，所以有了num的值就直接break
		if (num >= 1&&times[i]<2)
		{
			res += (words[i].size() - num);
			dfs(i);
			times[i]--;
			res -= (words[i].size() - num);
		}
	}

	ans = max(ans, res);                    //     找所有串时，每个串末尾 找不到单词了 都会经过这里，这里是每个串  最长的时候，要在这里  把ans  求最大
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> words[i];
	cin >> head;
	for (int i = 1; i <= n; i++)
	{
		if (words[i][0] == head)
		{
			res += words[i].size();
			dfs(i);
			res = 0;
			for (int i = 1; i <= n; i++)times[i] = 0;
		}
	}

	cout << ans;

	return 0;
}