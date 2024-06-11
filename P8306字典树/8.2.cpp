

#include<bits/stdc++.h>
using namespace std;

const int N = 3000010;
int T,n,q;                     //   注意：多组数据的，又用了全局变量，一定要注意上一组不要影响下一组
string s;                     //    可以直接不定义成全局，或每组完后再初始化一遍，，，int son[N][62] = {0}, cnt[N] = {0}, idx = 0;这样整个二维数组都是0
int son[N][62], idx, cnt[N];//     定义成全局  需要  清零(注意不要到N，要到idx)，耗时。定义成局部，需要耗空间

void init()
{
	for (int i = 0; i <= idx; i++)                   //   根节点不存储，但插了很多东西很多分支(存在son[0][u]中)，要从 0 开始清空
	{
		cnt[i] = 0;
		for (int j = 0; j < 62; j++)
			son[i][j] = 0;
	}
	idx = 0;
}

void insert(string s)
{
	int p = 0;
	for (int i = 0; i < s.size(); i++)
	{
		int u;
		if (s[i] >= 'a' && s[i] <= 'z')u = s[i] - 71;
		else if (s[i] >= 'A' && s[i] <= 'Z')u = s[i] - 'A';
		else if (s[i] >= '0' && s[i] <= '9')u = s[i] + 4;
		if (!son[p][u])son[p][u] = ++idx;
		p = son[p][u];
		cnt[p]++;                //   注意：本题是找有多少个串的前缀是询问串的，所以cnt不再记录以那个字母结尾的串的数量，而是每经过一个都要记录，并且根节点是不存储的%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	}
	
}

int query(string t)
{
	int p = 0;
	for (int i = 0; i < t.size(); i++)
	{
		int u;
		if (s[i] >= 'a' && s[i] <= 'z')u = s[i] - 71;
		else if (s[i] >= 'A' && s[i] <= 'Z')u = s[i] - 'A';
		else if (s[i] >= '0' && s[i] <= '9')u = s[i] + 4;
		if (!son[p][u])return 0;
		p = son[p][u];
	}
	return p;
}

/*void total(int p)
{
	ans += cnt[p];
	for (int i = 0; i < 62; i++)
		if (son[p][i])
			total(son[p][i]);                          //  一开始是用的这种方法，cnt记录以那个字母结尾的串的数量。但太慢了
*/

int main()
{
	cin.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> n >> q;
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			insert(s);
		}
		for (int i = 0; i < q; i++)
		{
			cin >> s;
			int p = query(s);
			if (p)cout << cnt[p] << endl;
			else cout << 0 << endl;
		}
		init();
	}

	return 0;
}