
//    ������find����
//    ���鼯  �� �������ٵ�   1. ���������Ϻϲ�  2.  ѯ������Ԫ���Ƿ���һ�����ϵ���
// ���������Ϸֱ�洢�����У����ڵ�洢 �����ϵı��
//     ʱ�临�ӶȽ��� O��1��������һ������,���Կ�����һ��С��5�ĳ����ڣ�   ·��ѹ���Ż�����·���������ӽڵ�ֱ��ָ����ڵ㣬������һ���ڵ������ĸ����Ͽ���ֱ�ӵõ�,����һ���Ż�����ֵ�ϲ������Ż�Ч��������


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
//           ���鼯 �������� : 
//   ������ͨ���е������   
//  ��ͨͼ����һ�����ϣ�a��b֮����һ���߾��Ǽ��Ϻϲ���ѯ���Ƿ���һ����ͨ���о����Ƿ���ͬһ�������a������ͨ���е��������������Ԫ������
//  ��ǰ��һ����һ�ʾ����� ������Ԫ������
//  �󼯺�Ԫ�ظ���size��ʱ�򣬽���һ��size���飬ÿ�����ϵĸ��ڵ�Ϊ�±꣬�洢ÿ������Ԫ�ظ��� 
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