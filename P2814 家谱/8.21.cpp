

//   在学并查集的时候，学的是数字的也就是编号，p[i] = i，例如 3的父节点是5，p[3] = 5，在这个题里也是用并查集，但是是一个个的人名，p[人名] = 人名，用人名做下标，就是
 

//     要用 map的映射  一个string到另一个 string，和map中的一些函数，注意map当数组用就行，第一个first是下标，第二个second是值


#include<bits/stdc++.h>
using namespace std;

const int N = 50010;
map <string, string> p;
string now;

string find(string name)            //  并查集路径压缩
{
	auto it = p.find(name);
	if (it!=p.end()&&p[name]!=name)p[name] = find(p[name]);
	else
	{
		p[name] = name;//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		return p[name];
	}    //   题中给的数据有可能前面出现一次但他是儿子，后面又出现一次是父亲，必须查找到最头上，再p[name] = name,而不是所有的父亲都p[name] = name，只有祖先才p[name] = name
	return p[name];
}

int main()
{
	while (1)
	{
		char flag;
		string name;
		cin >> flag;
		if (flag == '$')
			return 0;
		cin >> name;
		if (flag == '#')
		{
			now = name;
			//p[name] = name;
		}
		else if (flag == '+')
			p[name] = now;
		else if (flag == '?')
			cout << name << ' ' << find(name)<< endl;
	}

	return 0;
}//it->second it是迭代器p.find(name)返回迭代器