
//    核心是find函数
//    并查集  ： 用来快速地   1. 将两个集合合并  2.  询问两个元素是否在一个集合当中
// 将两个集合分别存储在树中，根节点存储 ：集合的编号
//     时间复杂度近乎 O（1），（不一定就是,可以控制在一个小于5的常量内）   路径压缩优化：将路径上所有子节点直接指向根节点，这样找一个节点属于哪个集合可以直接得到,还有一个优化：按值合并，但优化效果不明显


#include<bits/stdc++.h>
using namespace std;

const int N = 100010;

int n, m;
int p[N];

int find(int x)
{
	if (p[x] != x)p[x] = find(p[x]);
	return p[x];
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)p[i] = i;
	while (m--)
	{
		char a;
		int b, c;
		cin >> a >> b >> c;
		if (a == 'M')
			p[find(b)] = find(c);
		else
		{
			if (find(b) == find(c))cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}

	return 0;
}
//           并查集 其他功能 : 
//   例：连通块中点的数量   
//  连通图就是一个集合，a，b之间连一条线就是集合合并，询问是否在一个连通块中就是是否在同一个集合里，a所在连通块中点的数量，集合中元素数量
//  比前面一题多的一问就是求 集合中元素数量
//  求集合元素个数size的时候，建立一个size数组，每个集合的根节点为下标，存储每个集合元素个数 
#include<bits/stdc++.h>
using namespace std;

const int N = 100010;

int n, m;
int p[N],size[N];

int find(int x)
{
	if (p[x] != x)p[x] = find(p[x]);
	return p[x];
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		p[i] = i;
		size[i] = 1;
	}
	while (m--)
	{
		string c;
		int a, b;
		cin >> c;
		if (c == "C")
		{
			cin >> a >> b;
			if (find(a) != find(b))size[find(b)] += size[find(a)];
			p[find(a)] = find(b);
		}
		else if (c == "Q1")
		{
			cin >> a >> b;
			if (find(a) == find(b))cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		else
		{
			cin >> a;
			cout << size[find(a)] << endl;
		}
	}

	return 0;
}