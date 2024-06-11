


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
		cout << q[i];                        //并不能直接把q里的输出，并不是，试GFEDBCA，应是BC，输出AC

	return 0;
}*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1000010;
map<int, int>Prev;              //  直接拿一个数组记就行，记录每个数前面一个是谁，
//具体就是先从q中长度最长的找到最后一个，再Prev找完这个最长序列从后往前每找一个放到ans数组里（因为需要从后往前输出），再从后往前输出
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