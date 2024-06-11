


/*#include<bits/stdc++.h>
using namespace std;

const int N = 1000010;
string str;
string names[N];
vector<string> q;

int main()
{
	cin >> str;
	int idx = 0;
	for (int i = 0;str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			names[idx] += str[i];
		else
			names[++idx] += str[i];
	}
	q.push_back("0");
	q.push_back(names[1]);
	for (int i = 2; i <= idx; i++)
	{
		int l = 1, r = q.size();
		while (l < r)
		{
			int mid = l + r >> 1;
			if (q[mid] >= names[i])r = mid;
			else l = mid + 1;
		}
		if (l == q.size())
			q.push_back(names[i]);
		else
			q[l] = names[i];
	}
	for (int i = 1; i <= q.size()-1; i++)
		cout << q[i];                        //������ֱ�Ӱ�q�������������ǣ���GFEDBCA��Ӧ��BC�����AC

	return 0;
}*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1000010;
map<int, int>Prev;              //  ֱ����һ������Ǿ��У���¼ÿ����ǰ��һ����˭��
//��������ȴ�q�г�������ҵ����һ������Prev�����������дӺ���ǰÿ��һ���ŵ�ans�������Ϊ��Ҫ�Ӻ���ǰ��������ٴӺ���ǰ���
string str;
string names[N];
vector<string> ans;
vector<int> q;

int main()
{
	cin >> str;
	int idx = 0;
	for (int i = 0;str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			names[idx] += str[i];
		else
			names[++idx] += str[i];
	}
	q.push_back(0);
	q.push_back(1);
	for (int i = 2; i <= idx; i++)
	{
		int l = 1, r = q.size();
		while (l < r)
		{
			int mid = l + r >> 1;
			if (names[q[mid]] >= names[i])r = mid;
			else l = mid + 1;
		}
		if (l == q.size())
		{
			Prev[i] = q[q.size() - 1];
			q.push_back(i);
		}
		else
		{
			Prev[i] = q[l-1];
			q[l] = i;
		}
	}
	for (int i = q[q.size() - 1]; ; i = Prev[i])
	{
		ans.push_back(names[i]);
		if (!Prev[i])break;
	}
	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i];

	return 0;
}