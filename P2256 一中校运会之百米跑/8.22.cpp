

//典型并查集

#include<bits/stdc++.h>
using namespace std;

map<string, string> groups;
int n, m, query;
string name1, name2;

string find(string name)
{
	if (groups[name] != name)groups[name] = find(groups[name]);
	return groups[name];
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> name1;
		groups[name1] = name1;
	}//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  下面这句话，并查集一定要注意，并查集：合并两个集合；查看两个元素是否在同一集合中
	for (int i = 0; i < m; i++)          //   并查集一个非常需要注意的点：合并两个点的时候，先判断这两个点是否已经在同一个集合里，如果在就不用管（如果合并了整个集合就没有头节点了（满足p[x] = x）的点）递归函数就一直执行了，不在才合并
	{
		cin >> name1 >> name2;
		if(find(name1) != find(name2))
			groups[find(name2)] = name1;
	}
	cin >> query;
	while (query--)
	{
		cin >> name1 >> name2;
		if (find(name1) == find(name2))cout << "Yes." << endl;
		else cout << "No." << endl;
	}

	return 0;
}