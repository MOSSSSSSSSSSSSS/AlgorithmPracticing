

//���Ͳ��鼯

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
	}//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  ������仰�����鼯һ��Ҫע�⣬���鼯���ϲ��������ϣ��鿴����Ԫ���Ƿ���ͬһ������
	for (int i = 0; i < m; i++)          //   ���鼯һ���ǳ���Ҫע��ĵ㣺�ϲ��������ʱ�����ж����������Ƿ��Ѿ���ͬһ�����������ھͲ��ùܣ�����ϲ����������Ͼ�û��ͷ�ڵ��ˣ�����p[x] = x���ĵ㣩�ݹ麯����һֱִ���ˣ����ڲźϲ�
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