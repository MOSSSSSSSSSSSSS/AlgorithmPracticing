

//  离散化是极其特殊的哈希方式，前面的离散化是保序的
// 
//   一般情况下哈希表复杂度都是O(1)
// 
//   哈希表的存储结构 两类：1.开放寻址法 2. 拉链法(按照当发生哈希冲突时处理的不同)
// 
// 拉链法：用一个1e5大小的一维数组，存储，如果有数映射到3，在下标为3处拉一个链（单链表）(多个单链表就是邻接表)，记录所有映射到3的数
// 
//   哈希表作用：将比较大的值域 映射到 比较小的范围 0到N，一般就是存入一个数，查找一个数
//   从-1e9到1e9可以通过哈希函数（如对1e5取模，对谁取模尽量是质数，离2的整次幂要远，这样可以减少哈希冲突）映射到0到1e5-1，也有可能两个不同的数，映射到同一个数，叫哈希冲突
// 
//负数取模结果是负数，数学上不管是负数还是正数，余数都是正，c++不是，如-10%3在数学上等于2，在cpp上的等于-1
//memset,memcpy在cstring里

//******************************************************************************************************
//模拟散列表，用拉链法写
#include<bits/stdc++.h>
using namespace std;

const int N = 100003;   //取模的数用的是大于数据总数的第一个质数
int h[N], e[N], ne[N], idx,n;

void insert(int x)
{
	int k = (x % N + N) % N;//+ N保证数为正（数据有负数）
	e[idx] = x;
	ne[idx] = h[k];
	h[k] = idx;
	idx++;
}

bool find(int x)
{
	int k = (x % N + N) % N;
	for (int i = h[k]; i != -1; i = ne[i])
		if (e[i] == x)
			return true;
	return false;
}

int main()
{
	for (int i = 0; i < N; i++)h[i] = -1;
	cin >> n;
	while (n--)
	{
		char a;
		int x;
		cin >> a >> x;
		if (a == 'I')
			insert(x);
		else
		{
			if (find(x))cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}

	return 0;
}
//模拟散列表，用开放寻址法写,只需一个数组，但数组长度一般要开到题目数据范围的两到三倍
//插入一个数就是先用哈希函数求出k，看k处有没有数，有就向后找，一直到找到
//查找一个数，就是先用哈希函数求出k，看k处是不是x，不是就挨个往后找
//删除一个数就是先用哈希函数求出k，看k处是不是x，不是就挨个往后找，找到后也不真删除而是用一个标记记录


//memset是按字节的所以下面这个题想赋值成0x3f3f3f3f，只需写0x3f，因为int有4个字节，赋了就是4个3f，就是0x3f3f3f3f
// memset常用的还要0，-1，因为0每位都是0，赋完还是0，-1每位都是1，赋完还是-1
//memset 不能处理 vector

#include<bits/stdc++.h>
using namespace std;

const int N = 200003,null = 0x3f3f3f3f; //取2倍数据范围，再取大于他的第一个质数   还要定义一个不再所给数据大小范围里的数，
//并把数组初始化为这个数，表示这个地方没数，如果都是0，不能表示这个地方没数，0也可能是插入进来的数，这时是有数的
//0x3f3f3f3f是一个略大于十亿的数，在一些题里常被设置为INF最大的数，INF最大的数一般不用INT_MAX，因为它太大，加个1都会溢出
int h[N],n;

int find(int x)//开放寻址法最核心的是find，如果有x，返回x在哪，没有x，返回x应该在哪
{
	int k = (x % N + N) % N;

	while (h[k] != null && h[k] != x)//不符合条件就一直往后找，是循环
	{
		k++;
		if (k == N)k = 0;// 说明最后一个也看完了，再从下标0开始看
	}

	return k;
}

int main()
{
	cin >> n;
	for (int i = 0; i < N; i++)h[i] = 0x3f3f3f3f;
	while (n--)
	{
		char a;
		int x;
		cin >> a >> x;
		int k = find(x);
		if (a == 'I')
			h[k] = x;
		else
		{
			if (h[k]==x)cout << "Yes" << endl;
			else if(h[k]==null) cout << "No" << endl;
		}
	}

	return 0;
}

//*********************************************************************************************
//字符串哈希
//讲的是一种特殊的字符串哈希方式：字符串前缀哈希法
//对于一个字符串，首先h[0] = 0，h[1]是前一个字符的哈希值，h[2]是前两个字符的哈希值，一直到整个字符串的长度
//求哈希值：看作是一个p进制的数，（p常取131或13331）再转换成十进制，非常大，所以再对q（2的64次方）取模，因为用ull存储会溢出就相当于对2的64次方取模，所以不用管
//可以求某个子段l到r的哈希值，先求出从第一个字符到第r个字符的哈希值，在求出第一个到l-1的哈希值，（类比十进制）
//子段的哈希值就是  h[r] - h[l-1]*p的r-l+1次方
//这样求出前一个h[n]就能求出后一个h[n+1] = h[n]*p+第n+1个字母(只要保证不是0就行，是多少无所谓)
//还要注意：A作为1而不能作为0，否则A，AA，AAA都是0，哈希冲突

//字符串哈希的作用kmp则不能做，作用非常牛逼，很多困难的题目可以用这个方法，       kmp可以求一个字符串的循环节，字符串哈希不行，其他的字符串哈希大约更厉害
//字符串哈希        比如可以   快速   比较 两个字符串 是不是相等，O(1)复杂度
#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
const int N = 100010,P = 13331;
ULL h[N], p[N];                     //   会频繁用到  p  的多少次方，先算出来
int n, m;
char str[N];

ULL get(int l, int r)
{
	return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
	cin.tie(0);
	cin >> n >> m >> str+1;
	p[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		p[i] = p[i - 1] * P;
		h[i] = h[i - 1] * P + str[i];
	}
	while (m--)
	{
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		if (get(l1, r1) == get(l2, r2))cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}
// 上一个是  字符串 前缀哈希法，把一个字符串 所有前缀的  哈希值 都保存起来了，如果只要求一个字符串的哈希值  可以用以下模板。
//  竞赛中 哈希方式 都是 找一个  进制数 找一个 模数，上下两种都是  自然溢出法（ULL），还有  单模数哈希，双模数哈希，1e18 大小级别质数作为模数的哈希

//  只求一个字符串的哈希值，不求它前缀的哈希值
#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
const int N = 10010, P = 131;
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

	cout << ans + 1;

	return 0;
}