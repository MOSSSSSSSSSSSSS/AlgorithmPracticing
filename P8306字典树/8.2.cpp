

#include<bits/stdc++.h>
using namespace std;

const int N = 3000010;
int T,n,q;                     //   ע�⣺�������ݵģ�������ȫ�ֱ�����һ��Ҫע����һ�鲻ҪӰ����һ��
string s;                     //    ����ֱ�Ӳ������ȫ�֣���ÿ������ٳ�ʼ��һ�飬����int son[N][62] = {0}, cnt[N] = {0}, idx = 0;����������ά���鶼��0
int son[N][62], idx, cnt[N];//     �����ȫ��  ��Ҫ  ����(ע�ⲻҪ��N��Ҫ��idx)����ʱ������ɾֲ�����Ҫ�Ŀռ�

void init()
{
	for (int i = 0; i <= idx; i++)                   //   ���ڵ㲻�洢�������˺ܶණ���ܶ��֧(����son[0][u]��)��Ҫ�� 0 ��ʼ���
	{
		cnt[i] = 0;
		for (int j = 0; j < 62; j++)
			son[i][j] = 0;
	}
	idx = 0;
}

void insert(string s)
{
	int p = 0;
	for (int i = 0; i < s.size(); i++)
	{
		int u;
		if (s[i] >= 'a' && s[i] <= 'z')u = s[i] - 71;
		else if (s[i] >= 'A' && s[i] <= 'Z')u = s[i] - 'A';
		else if (s[i] >= '0' && s[i] <= '9')u = s[i] + 4;
		if (!son[p][u])son[p][u] = ++idx;
		p = son[p][u];
		cnt[p]++;                //   ע�⣺���������ж��ٸ�����ǰ׺��ѯ�ʴ��ģ�����cnt���ټ�¼���Ǹ���ĸ��β�Ĵ�������������ÿ����һ����Ҫ��¼�����Ҹ��ڵ��ǲ��洢��%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	}
	
}

int query(string t)
{
	int p = 0;
	for (int i = 0; i < t.size(); i++)
	{
		int u;
		if (s[i] >= 'a' && s[i] <= 'z')u = s[i] - 71;
		else if (s[i] >= 'A' && s[i] <= 'Z')u = s[i] - 'A';
		else if (s[i] >= '0' && s[i] <= '9')u = s[i] + 4;
		if (!son[p][u])return 0;
		p = son[p][u];
	}
	return p;
}

/*void total(int p)
{
	ans += cnt[p];
	for (int i = 0; i < 62; i++)
		if (son[p][i])
			total(son[p][i]);                          //  һ��ʼ���õ����ַ�����cnt��¼���Ǹ���ĸ��β�Ĵ�����������̫����
*/

int main()
{
	cin.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> n >> q;
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			insert(s);
		}
		for (int i = 0; i < q; i++)
		{
			cin >> s;
			int p = query(s);
			if (p)cout << cnt[p] << endl;
			else cout << 0 << endl;
		}
		init();
	}

	return 0;
}