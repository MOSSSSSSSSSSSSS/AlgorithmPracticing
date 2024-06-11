

//  trie�� �������ٴ洢 �� ���� �ַ������� �����ݽṹ

#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int son[N][26], cnt[N], idx;//   ��һ����ά�����¼  �����ڵ���ӽڵ㣨��Ϊ�Ƕ�ʮ����СдӢ����ĸ���ӽڵ����26����  �洢���±꣬
//�ڶ��������¼  �Ը����ڵ��β�ĵ����ж��ٸ���idx��¼��ǰ����Ѿ��õ��±ꡣ
//�±���0���и��ڵ㣬�սڵ㣨���һ���ڵ�û���ӽڵ㣬��ô��ָ��սڵ㣩

void insert(char str[])
{
	int p = 0;//�Ӹ��ڵ�
	for (int i = 0; str[i]; i++)
	{
		int u = str[i] - 'a';
		if (!son[p][u])son[p][u] = ++idx;  //�൱�����һ���ӽڵ�
		p = son[p][u];
	}
	cnt[p]++;         //  p�����һ���ڵ���±꣬��ʾ�����һ���ڵ��β�ĵ���������1
}

int query(char str[])//       ��ѯ������ĳ�����ʳ��ֶ��ٴ�
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
//�������
// �Ȱ����е����洢���ֵ����У�����ÿһ����������ΪҪ������ʹ����������������������Ǹ���Ҫ������ÿ��λ�������෴����
//�����ֵ�������������������������������������Ľ��������ÿ�������������������ȡ���н�������ֵ��


//     ѭ����i���ڵ���0���ж�����   �ȼ���~i   ȡ��i
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

// AC�Զ���  �� �����ߺ�ת�Ʊ�  
// KMP�ǵ�ģʽ��ƥ�䣬AC�Զ����Ƕ�ģʽ��ƥ��
#include<bits/stdc++.h>
using namespace std;

const int N = 1000010;
int n;
string str;
int son[N][26], cnt[N], idx, ne[N];  //  ne�ǻ������յ�,son�����ߺ�ת�Ʊ��յ�

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
	/*int q[N], hh = 0, tt = -1;         //  BFS����ȥ��AC�Զ���
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
			if (v)ne[v] = son[ne[t]][i], q.push(v);  // �ǵ��ٰ��ӽڵ����
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
			ans += cnt[j], cnt[j] = -1;             //  ������ģʽ�����ظ�������˵��ֻҪ��Ų�һ�����Ͱ���һ�������ԾͿ��Եó�������ģʽ���г������ı����еĸ���
	}//   �����һ�������ִ�����Ҫȥ�� && ~cnt[j]��cnt[j] = -1; 
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