

//  trie树 用来快速存储 和 查找 字符串集合 的数据结构

#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int son[N][26], cnt[N], idx;//   第一个二维数组记录  各个节点的子节点（因为是二十六个小写英文字母，子节点最多26个）  存储的下标，
//第二个数组记录  以各个节点结尾的单词有多少个，idx记录当前最后已经用的下标。
//下标是0的有根节点，空节点（如果一个节点没有子节点，那么它指向空节点）

void insert(char str[])
{
	int p = 0;//从根节点
	for (int i = 0; str[i]; i++)
	{
		int u = str[i] - 'a';
		if (!son[p][u])son[p][u] = ++idx;  //相当于伸出一个子节点
		p = son[p][u];
	}
	cnt[p]++;         //  p是最后一个节点的下标，表示以最后一个节点结尾的单词数量加1
}

int query(char str[])//       查询操作，某个单词出现多少次
{
	int p = 0;
	for (int i = 0; str[i]; i++)
	{
		int u = str[i] - 'a';
		if (!son[p][u])return 0;
		p = son[p][u];
	}

	return cnt[p];
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		char x, str[N];
		cin >> x >> str;
		if (x == 'I')
			insert(str);
		else
			cout<<query(str)<<endl;
	}

	return 0;
}
//****************************************************************************************************************
//最大异或对
// 先把所有的数存储在字典树中，对于每一个数，（因为要尽可能使结果最大，所以与这个数异或的那个数要尽可能每个位都与他相反），
//就在字典树中找与此数异或结果尽可能最大的数，求出它的结果，对于每个数都进行这个操作，取所有结果的最大值。


//     循环里i大于等于0的判断条件   等价于~i   取反i
#include<bits/stdc++.h>
using namespace std;

const int N = 100010,M = 3100010;

int n;
int a[N];
int son[M][2], idx;
int res;

void insert(int x)
{
	int p = 0;
	for (int i = 30; ~i; i--)
	{
		int u = x >> i & 1;
		if (!son[p][u])son[p][u] = ++idx;
		p = son[p][u];
	}
}

int query(int x)
{
	int res = 0;
	int p = 0;
	for (int i = 30; ~i; i--)
	{
		int u = x >> i & 1;
		if (son[p][!u])
		{
			res += 1 << i;
			p = son[p][!u];
		}
		else
			p = son[p][u];
	}

	return res;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)scanf("%d", &a[i]);

	for (int i = 1; i <= n; i++)insert(a[i]);

	for (int i = 1; i <= n; i++)res = max(res, query(a[i]));

	cout << res;

	return 0;
}

// AC自动机  有 回跳边和转移边  
// KMP是单模式串匹配，AC自动机是多模式串匹配
#include<bits/stdc++.h>
using namespace std;

const int N = 1000010;
int n;
string str;
int son[N][26], cnt[N], idx, ne[N];  //  ne是回跳边终点,son是树边和转移边终点

void insert(string str)
{
	int p = 0;
	for (int i = 0; i < str.size(); i++)
	{
		int u = str[i] - 'a';
		if (!son[p][u])son[p][u] = ++idx;
		p = son[p][u];
	}
	cnt[p]++;
}

void build()
{
	/*int q[N], hh = 0, tt = -1;         //  BFS队列去建AC自动机
	for (int i = 0; i < 26; i++)
		if (son[0][i])q[++tt] = son[0][i];
	while (hh <= tt)
	{
		int t = q[hh++];
		for (int i = 0; i < 26; i++)
		{
			int v = son[t][i];
			if (v)ne[v] = son[ne[t]][i], q[++tt] = v;
			else son[t][i] = son[ne[t]][i];
		}
	}
	*/
	queue<int> q;
	for (int i = 0; i < 26; i++)
		if (son[0][i])q.push(son[0][i]);
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		for (int i = 0; i < 26; i++)
		{
			int v = son[t][i];
			if (v)ne[v] = son[ne[t]][i], q.push(v);  // 记得再把子节点入队
			else son[t][i] = son[ne[t]][i];
		}
	}
}

int query(string str)
{
	int ans = 0;
	for (int k = 0, i = 0; k < str.size(); k++)
	{
		i = son[i][str[k] - 'a'];
		for (int j = i; j && ~cnt[j]; j = ne[j])
			ans += cnt[j], cnt[j] = -1;             //  可能有模式串有重复但题中说了只要序号不一样，就按不一样，所以就可以得出，所有模式串中出现在文本串中的个数
	}//   如果求一个串出现次数就要去掉 && ~cnt[j]和cnt[j] = -1; 
	return ans;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> str;
		insert(str);
	}
	build();

	cin >> str;
	cout << query(str);

	return 0;
}