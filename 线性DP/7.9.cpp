

//动态规划 是 暴力搜索 的 优化。

//求复杂度，状态数*每个状态计算时复杂度，如数字三角形，O（n2）*O（1）
//数字三角形  状态表示：f（i，j）存储从起点到i，j所有路径中能有的最大值
#include<iostream>
using namespace std;

const int N = 510, INF = 1e9;       //定义  INF = 1e9；用来初始化，如果不初始化乘  -INF   就会保持为 0 ，这样当a[N]中有负数时，两个比较取最大值就会取不是负数的那个，
//但是所取的并不可能从那里过来，也就是不存在那种情况。所以要避免取到那种情况，所以要赋值为一个很小的值。
int n, a[N][N], f[N][N], res;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
			cin >> a[i][j];
	}

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= i+1; j++)    //每次计算时 只用到 i-1行 第j 和j-1 列的数，所以初始化到i+1即可，也可以到n
			f[i][j] = -INF;
	}

	f[1][1] = a[1][1];//赋完值后再给 1，1赋值，并且下面循环i从2开始

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)        
			f[i][j] = max(f[i - 1][j - 1] + a[i][j], f[i - 1][j] + a[i][j]);  //f存的是最大值，用max函数，先写出来
		//   用从1开始的写出来，再看边界。
	}

	res = -INF;    //要给res赋为很小的值，否则如果答案应该是负数，但res保持为0，最后res就得不到正确答案，依然是0

	for (int k = 1; k <= n; k++)res = max(res, f[n][k]);

	cout << res;

	return 0;
}

//  7.21做完作业三有感：只需要考虑状态转移方程求f[i][j]需要前面哪些值，再看如何初始化能把正确的值求出来，就如何初始化
//  然后再注意考虑负数的情况

//***********************************************************************************************************************
//最长单调递增子序列 题与 上一题思路相似，状态表示：使用一个一维数组，第i个位置f[i]存储 以 a[i]这个数  为终点的  所有递增子序列 中 最长的长度
//有了状态表示，下一步是找状态转移方程：思路是，划分集合，这个状态前一个状态（i-1）是什么，怎么通过前一个状态得到 这个状态i
//它的所有可能序列中   前一个数，  是它之前所有严格小于它的数都有可能从第1个数，2，3，4，....第i - 1个数
// ，同时它也可能是第一个数，前面没数，这是他前面所有情况，
//假设它某个  可能序列中  倒数第二个数是  a[j]  那么 f[i] = f[j] + 1
#include<bits/stdc++.h>
using namespace std;

const int N = 1010;

int n, res;
int a[N], f[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		f[i] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
			if (a[i] > a[j]) f[i] = max(f[i], f[j] + 1);    //先写出来再看一下该补充什么（初始化之类的问题）（条件的问题）
	}

	for (int i = 1; i <= n; i++)res = max(res, f[i]);

	cout << res;

	return 0;

}
//记录最长子序列
#include<bits/stdc++.h>
using namespace std;

const int N = 1010;

int n, res;
int a[N], f[N],b[N];   //用b这个数组b[i]存储以某个数（下标i）结尾的最长序列的倒数第二个数的下标

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		f[i] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
			if (a[i] > a[j])
			{
				if (f[j] + 1 > f[i])//先写出来再看一下该补充什么（初始化之类的问题）（条件的问题）
				{
					f[i] = f[j] + 1;
					b[i] = j;
				}
			}
	}
	int k;
	for (int i = 1; i <= n; i++)
	{
		if (res < f[i])
		{
			res = f[i];
			k = i;
		}
	}

	for (int i = 0; i < res; i++)  //一共res个数，每次循环输出一个，再更新下标
	{
		cout << a[k] << ' ';
		k = b[k];
	}
	cout << res;

	return 0;

}
//时间优化，在最长上升子序列2中，一共N = 1e5,复杂度n方，1e10超过规定时间1s内最大进行运算的次数
//在一个要求的数x前面，以前的方法是枚举前面所有数，复杂度是n，现在可以看以前面所有数结尾的序列根据长度分为不同长度的序列，对于长度相同的序列
//取结尾数最小的一个，可以证明随着长度的增加，结尾的最小的数也在增加，因此可以使用二分的方法找以x结尾的最长上升子序列，找到后找下一个，需要更新状态
//只需要把刚才找到的以x结尾的最长上升子序列的长度处的最小值更新为x
#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int n,res;
int a[N], b[N];  //  b是dp数组
vector<int> q;  // q是二分用的

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%d", &a[i]);
	                              //写好后模拟一开始几个数据，看需要如何初始化
	q.push_back(0);               //****先假定****是按照所想逻辑执行，这样除了第一步，每一步都是按照所想逻辑进行，再初始化为所想逻辑，第一步也就可以按照所想逻辑进行
	q.push_back(a[1]);
	b[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		int l = 1, r = q.size();   // *****要找的是什么(二分找到的是什么)，出现的范围是什么（闭区间）****
		while (l < r)
		{
			int mid = l + r >> 1;
			if (q[mid] >= a[i])r = mid;
			else l = mid + 1;
		}
		if (l == q.size())q.push_back(a[i]); // ****有可能取到 q.size()****
		else q[l] = a[i];
		b[i] = l;
	}

	for (int i = 1; i <= n; i++)res = max(res, b[i]);
	cout << res;

	return 0;
}
//第二次写  7.21
#include<bits/stdc++.h>
using namespace std;

const int N = 100010;

int n,res;
int a[N];
int f[N];
vector<int> b;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)scanf("%d", &a[i]);

	b.push_back(0);
	b.push_back(a[1]);
	f[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		int l =1, r = b.size();
		while (l < r)
		{
			int mid = l + r >> 1;
			if (b[mid] >= a[i])r = mid;
			else l = mid + 1;
		}
		if (l == b.size()) b.push_back(a[i]);
		else b[l] = a[i];
		f[i] = l;
	}

	for (int i = 1; i <= n; i++)res = max(res, f[i]);

	cout << res;

	return 0;
}

//**********************************************************************************************
//最长公共子序列：有两个给定序列，这种题一般  状态表示是二维，f[i][j]，是所有满足是第一个序列前i个元素的子序列同时也是
//第二个序列前j个元素的子序列的 最长长度
//状态转移方程：状态划分：将f[i][j]分为几种情况（不重不漏），一共四种：公共子序列以a[i],b[j]结尾，公共子序列不以a[i]结尾以b[j]结尾，公共子序列以a[i]结尾不以b[j]结尾
//公共子序列不以a[i], b[j]结尾，即11，01，10，00四种情况，f[i][j]就是四种情况的最大值，对于00，可以用f[i][j] = f[i-1][j-1](a序列前i-1个，b序列前j-1个的最长公共子序列长度)
//对于11，f[i][j] = f[i-1][j-1] + 1，对于01，f[i][j] 是不等于 f[i-1][j]的，因为，虽然对于前面下标没问题，但对于后面下标f[i][j]一定以b[j]结尾
//f[i-1][j]指的是  以b序列中  b[j]之前（包括b[j]）的元素 结尾的公共子序列，从集合角度上，01，f[i][j]属于f[i-1][j]属于f[i][j]。由于#####求的是f[i][j]的最大值，所以划分的四个部分间可以有重合######
//同理对于10可以用f[i][j-1]，所以求出f[i][j-1]，f[i-1][j]，f[i-1][j-1] + 1， f[i-1][j-1]最大值，就是f[i][j]最大值，由于f[i-1][j-1]即包含在f[i][j-1]
//又包含在f[i-1][j]中，所以可以用f[i][j-1]，f[i-1][j]，f[i-1][j-1] + 1三个的最大值
#include<bits/stdc++.h>
using namespace std;

const int N = 1010;

int n, m;
char A[N], B[N];
int f[N][N];

int main()
{
	scanf("%d%d", &n, &m);
	scanf("%s", A + 1);       //输入是字符串%s，如果用字符数组存储，不是从下标0开始要从1开始，并且不需要&，因此是A + 1
	scanf("%s", B + 1);
	//输入完后，（状态初始化），再计算所有状态，即给储存状态的 数组赋值，最后输出

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			f[i][j] = max(f[i][j - 1], f[i - 1][j]);
			if (A[i] == B[j])f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);  //f[i - 1][j - 1] + 1
			//这种情况不一定存在，只有当A[i] == B[j]时可以有这种情况，故要有判断条件
			//写出状态转移方程后通过模拟几个数，发现边界值如果不初始化也正确，所以不用给f[][]初始化
		}
	}

	cout << f[n][m];

	return 0;
}
//****************************************************************************************************************
//最短编辑距离
//f[i][j]存储的是把第一个字符串前i个元素变得和第二个字符串前j个元素相同的所有方案中，的最少步骤
//状态转移方程：{首先，可以证明，如果有一个方案有最小步骤，那么这些步骤的顺序可以任意
//i如果小于j，最后一步一定是在最后插入一个数，即操作二 f[i][j] = f[i][j-1]+1
//i如果大于j，最后一步是在最后删一个数，操作一 f[i][j] = f[i-1][j]+1
//i如果等于j，最后一步是把最后一个数变得和j的最后一个数相同，f[i][j] = f[i-1][j-1]（最后一个本来就相同）或f[i-1][j-1]+1}
// 每一个状态f[i][j]上一步都是由某个状态通过三种操作之一作用在最后一个（i）个元素上得来的
// f[i][j] = 三种可能中最小的 min(f[i][j-1]+1,f[i-1][j]+1,f[i-1][j-1]或f[i-1][j-1]+1)
//二维状态n方个，每个状态是O(1)所以是n方
#include<bits/stdc++.h>
using namespace std;

const int N = 1010;

int n,m;
char a[N], b[N];//  是字符串char  ,注意 输入字符 时最好用 cin , scanf 读 回车 和 空格
int f[N][N];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];
	cin >> m;
	for (int i = 1; i <= m; i++)cin >> b[i];

	for (int i = 1; i <= m; i++)f[0][i] = i;         //   每次求一个状态，需要左边，左上，上边的状态
	for (int i = 1; i <= n; i++)f[i][0] = i;         //   0行和0列，按照所表示状态的含义初始化

	//for (int i = 1; i <= n; i++)
	//{
	//	for (int j = 1; j <= m; j++)
	//	{
	//		if (i < j)f[i][j] = f[i][j - 1] + 1;
	//		else if (i > j)f[i][j] = f[i - 1][j] + 1;
	//		else if (i == j && a[i] == b[j])f[i][j] = f[i - 1][j - 1];
	//		else f[i][j] = f[i - 1][j - 1] + 1;
	//	}
	//}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
			if (a[i] == b[j])f[i][j] = min(f[i][j], f[i - 1][j - 1]);
			else f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
		}
	}

	cout << f[n][m];

	return 0;
}
//*********************************************************************************************************
//编辑距离                                                                                                                                                                                                                                                                                                                                                                                                
#include<bits/stdc++.h>
using namespace std;

const int N = 15, M = 1010;

int n, m;
char a[M][N];
int f[M][M];

int edit_distance(char a[],char query[],int f[M][M])
{
	for (int i = 1; i <= strlen(a+1);i++)
	{
		for (int j = 1; j <= strlen(query + 1); j++)
		{
			f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
			if (a[i] == b[j]) f[i][j] = min(f[i][j], f[i - 1][j - 1]);
			else  f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
		}
	}

	return f[strlen(a + 1)][strlen(query + 1)];
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)scanf("%s", a[i] + 1);//输入字符串，并且起始是下标1处

	for (int i = 1; i <= N; i++)f[0][i] = i;
	for (int i = 1; i <= N; i++)f[i][0] = i;

	while (m--)
	{
		char query[N], int limit, int ans = 0;  //字符串形式输入，有为零，可以用strlen看长度
		scanf("%s %d", query + 1, &limit);
		for (int i = 1; i <= n; i++)
			if (edit_distance(a[i], query, f) <= limit)ans++;
		cout << ans << endl;
	}
	return 0;
}


