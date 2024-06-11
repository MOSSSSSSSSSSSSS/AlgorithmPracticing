//for(auto item :add)是遍历容器add中的所有元素，每一次循环都会将add中的一个元素赋值给变量item，使用auto系统自动判断其类型。
//如果是pair<int,int>的一个数组可以使用item.first,item.second


//模板，先排序，再去重，再映射
//当范围很大，但有用的数是少的，是稀疏的，其他的数对结果也没有影响，就可以将这几个稀疏的数 离散化处理 ，保序是说原来从小到大，映射后也从小到大
//#include<iostream>
//#include<vector>
//#include<algorithm>                                               reverse, sort，unique都是<algorithm>里的
//
//using namespace std;

//vector<int> alls;
//int find(int x)
//{
//	int l = 0, r = alls.size() - 1;
//	while (l < r)
//	{
//		int mid = l + r >> 1;
//		if (alls[mid] >= x) r = mid;
//		else l = mid + 1;
//	}
//
//	return r;//r是下标从0开始，r+1是下标从1开始，取决于题目需要
//}

//int main()
//{
//	sort(alls.begin(),alls.end());
//	alls.erase(unique(alls.begin(), alls.end()), alls.end());//unique是去重用的，重复的元素都放到了最后面，然后返回前面不含重复元素的最后的后一个位置的下标（？）再配合end，用erase消除掉后面留下的重复元素
//	//再用二分求一个数的映射，映射为它在数组中的下标，二分函数在上面

//}
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 300010;
int n, m;
vector<int> alls;//需要一个数组放需要离散化的所有数据,这个数组中的数据有序还要去重，通过这个数组和find，就是映射的方法
vector<PII> add,query;
int a[N], s[N];//将离散化后的从1开始（前缀和从1开始）的自然数，作为a数组的下标

int find(int x)
{
	int i = 0, j = alls.size() - 1;
	while (i < j)
	{
		int mid = i + j >> 1;
		if (alls[mid] >= x)j = mid;
		else i = mid + 1;
	}

	return i + 1;
}

int main()
{
	scanf("%d%d", &n,&m);
	while (n--)
	{
		int x, c;
		scanf("%d%d", &x, &c);
		add.push_back({ x,c });
		alls.push_back(x);
	}
	while (m--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		query.push_back({ l,r });
		alls.push_back(l);
		alls.push_back(r);
	}
	sort(alls.begin(), alls.end());
	alls.erase(unique(alls.begin(), alls.end()), alls.end());
	
	for (auto item : add)a[find(item.first)] += item.second;
	for (int i = 1; i < N; i++)s[i] = s[i - 1] + a[i];
	for (auto item : query)
	{
		int i = find(item.first), j = find(item.second);
		cout << s[j] - s[i - 1] << endl;
	}
}
//7.6第二次
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 300010;
typedef pair<int, int> PII;
vector <int> alls;
vector <PII> add, query;
int n, m;
int a[N], s[N];

int find(int x)
{
	int l = 0, r = alls.size() - 1;
	while (l < r)
	{
		int mid = l + r >> 1;
		if (alls[mid] >= x)r = mid;
		else l = mid + 1;
	}

	return r + 1;
}

int main()
{
	scanf("%d%d", &n, &m);
	while (n--)
	{
		int x, c;
		scanf("%d%d", &x, &c);
		alls.push_back(x);
		add.push_back({ x,c });
	}
	while (m--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		alls.push_back(l);
		alls.push_back(r);
		query.push_back({ l,r });
	}
	sort(alls.begin(), alls.end());
	alls.erase(unique(alls.begin(), alls.end()), alls.end());
	for (auto item : add)a[find(item.first)] += item.second;
	for (int i = 1; i < N; i++)s[i] = s[i - 1] + a[i];
	for (auto item : query)
	{
		int l = find(item.first), r = find(item.second);
		cout << s[r] - s[l - 1] << endl;
	}

	return 0;
}