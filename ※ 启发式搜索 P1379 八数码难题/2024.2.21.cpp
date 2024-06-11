

//  A星是bfs的改进，定义起点s终点t，从起点开始的距离函数g(x)，到终点的距离函数h(x),估价函数f(x) = g(x)+h(x)
//  A星 每次从优先队列中取出一个f最小的元素，然后更新相邻的状态
//  八数码问题可以用a星求解
//h 函数可以定义为，不在应该在的位置的数字个数。容易发现 h 满足以上两个性质，此题可以使用 A* 算法求解。

//  用的是优先队列，估价函数值最小的在最前

#include<bits/stdc++.h>
using namespace std;
#define int long long

int s, e = 123804765;
int h(int x)
{
	int cnt = 0;
	for (int i = 0; i <= 8; i++)
		if ((x >> i) != (e >> i))
			cnt++;
	return cnt;
}
struct node {
	int num;
	int g;
	friend bool operator<(node a, node b)
	{
		return a.g + h(a.num) > b.g + h(b.num);
	}
};
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
priority_queue<node> q;
map<int, bool> mp;

signed main()
{
	cin >> s;
	if (s == e)
	{
		cout << 0;
		return 0;
	}
	mp[s] = true;
	q.push({ s,0});
	while (q.size())
	{
		node t = q.top();
		int g = t.g;
		q.pop();
		/*
		int num = t.num,pos;
		for (int i = 0; i <= 8; i++)
		{
			if (((num >> i) & 1) == 0)
			{
				pos = i + 1;
				break;
			}
		}
		int x, y;
		if (7 <= pos && pos <= 9)x = 1;
		else if (4 <= pos && pos <= 6)x = 2;
		else x = 3;
		if (pos == 7 || pos == 4 || pos == 1)y = 3;
		else if (pos == 8 || pos == 5 || pos == 2)y = 2;
		else y = 1;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 4 || nx <= 0 || ny >= 4 || ny <= 0)continue;
			int nnum = num - 
		}
		*/
		int pow = 1;
		for (; pow <= 1e8; pow *= 10)
			if (t.num / pow % 10 == 0)
				break;
		int a = pow * 10, b = pow / 10, c = pow / 1000, d = pow * 1000;
		if (pow == 1e8)
		{
			int bb = t.num / b % 10;
			int bbb = t.num - bb * b + bb * pow;
			if (!mp[bbb])mp[bbb] = true, q.push({bbb,g + 1});
			if (bbb == 123804765)
			{
				cout << g + 1;
				break;
			}
			int cc = t.num / c % 10;
			int ccc = t.num - cc * c + cc * pow;
			if (!mp[ccc])mp[ccc] = true, q.push({ccc,g + 1});
			if (ccc == 123804765)
			{
				cout << g + 1;
				break;
			}
		}
		else if (pow == 1e7)
		{
			int aa = t.num / a % 10;
			int aaa = t.num - aa * a + aa * pow;
			if (!mp[aaa])mp[aaa] = true, q.push({aaa,g+1});
			if (aaa == 123804765)
			{
				cout << g + 1;
				break;
			}
			int bb = t.num / b % 10;
			int bbb = t.num - bb * b + bb * pow;
			if (!mp[bbb])mp[bbb] = true, q.push({ bbb,g + 1 });
			if (bbb == 123804765)
			{
				cout << g + 1;
				break;
			}
			int cc = t.num / c % 10;
			int ccc = t.num - cc * c + cc * pow;
			if (!mp[ccc])mp[ccc] = true, q.push({ ccc,g + 1 });
			if (ccc == 123804765)
			{
				cout << g + 1;
				break;
			}
		}
		else if (pow == 1e6)
		{
			int aa = t.num / a % 10;
			int aaa = t.num - aa * a + aa * pow;
			if (!mp[aaa])mp[aaa] = true, q.push({ aaa,g + 1 });
			if (aaa == 123804765)
			{
				cout << g + 1;
				break;
			}
			int cc = t.num / c % 10;
			int ccc = t.num - cc * c + cc * pow;
			if (!mp[ccc])mp[ccc] = true, q.push({ ccc,g + 1 });
			if (ccc == 123804765)
			{
				cout << g + 1;
				break;
			}
		}
		else if (pow == 1e5)
		{
			int bb = t.num / b % 10;
			int bbb = t.num - bb * b + bb * pow;
			if (!mp[bbb])mp[bbb] = true, q.push({ bbb,g + 1 });
			if (bbb == 123804765)
			{
				cout << g + 1;
				break;
			}
			int cc = t.num / c % 10;
			int ccc = t.num - cc * c + cc * pow;
			if (!mp[ccc])mp[ccc] = true, q.push({ ccc,g + 1 });
			if (ccc == 123804765)
			{
				cout << g + 1;
				break;
			}
			int dd = t.num / d % 10;
			int ddd = t.num - dd * d + dd * pow;
			if (!mp[ddd])mp[ddd] = true, q.push({ddd,g+1});
			if (ddd == 123804765)
			{
				cout << g + 1;
				break;
			}
		}
		else if (pow == 1e4)
		{
			int aa = t.num / a % 10;
			int aaa = t.num - aa * a + aa * pow;
			if (!mp[aaa])mp[aaa] = true, q.push({ aaa,g + 1 });
			if (aaa == 123804765)
			{
				cout << g + 1;
				break;
			}
			int cc = t.num / c % 10;
			int ccc = t.num - cc * c + cc * pow;
			if (!mp[ccc])mp[ccc] = true, q.push({ ccc,g + 1 });
			if (ccc == 123804765)
			{
				cout << g + 1;
				break;
			}
			int bb = t.num / b % 10;
			int bbb = t.num - bb * b + bb * pow;
			if (!mp[bbb])mp[bbb] = true, q.push({ bbb,g + 1 });
			if (bbb == 123804765)
			{
				cout << g + 1;
				break;
			}
			int dd = t.num / d % 10;
			int ddd = t.num - dd * d + dd * pow;
			if (!mp[ddd])mp[ddd] = true, q.push({ ddd,g + 1 });
			if (ddd == 123804765)
			{
				cout << g + 1;
				break;
			}
		}
		else if (pow == 1e3)
		{
			int aa = t.num / a % 10;
			int aaa = t.num - aa * a + aa * pow;
			if (!mp[aaa])mp[aaa] = true, q.push({ aaa,g + 1 });
			if (aaa == 123804765)
			{
				cout << g + 1;
				break;
			}
			int dd = t.num / d % 10;
			int ddd = t.num - dd * d + dd * pow;
			if (!mp[ddd])mp[ddd] = true, q.push({ ddd,g + 1 });
			if (ddd == 123804765)
			{
				cout << g + 1;
				break;
			}
			int cc = t.num / c % 10;
			int ccc = t.num - cc * c + cc * pow;
			if (!mp[ccc])mp[ccc] = true, q.push({ ccc,g + 1});
			if (ccc == 123804765)
			{
				cout << g + 1;
				break;
			}
		}
		else if (pow == 1e2)
		{
			int bb = t.num / b % 10;
			int bbb = t.num - bb * b + bb * pow;
			if (!mp[bbb])mp[bbb] = true, q.push({ bbb,g + 1 });
			if (bbb == 123804765)
			{
				cout << g + 1;
				break;
			}
			int dd = t.num / d % 10;
			int ddd = t.num - dd * d + dd * pow;
			if (!mp[ddd])mp[ddd] = true, q.push({ ddd,g + 1  });
			if (ddd == 123804765)
			{
				cout << g + 1;
				break;
			}
		}
		else if (pow == 10)
		{
			int aa = t.num / a % 10;
			int aaa = t.num - aa * a + aa * pow;
			if (!mp[aaa])mp[aaa] = true, q.push({ aaa,g + 1  });
			if (aaa == 123804765)
			{
				cout << g + 1;
				break;
			}
			int bb = t.num / b % 10;
			int bbb = t.num - bb * b + bb * pow;
			if (!mp[bbb])mp[bbb] = true, q.push({ bbb,g + 1  });
			if (bbb == 123804765)
			{
				cout << g + 1;
				break;
			}
			int dd = t.num / d % 10;
			int ddd = t.num - dd * d + dd * pow;
			if (!mp[ddd])mp[ddd] = true, q.push({ ddd,g + 1  });
			if (ddd == 123804765)
			{
				cout << g + 1;
				break;
			}
		}
		else
		{
			int aa = t.num / a % 10;
			int aaa = t.num - aa * a + aa * pow;
			if (!mp[aaa])mp[aaa] = true, q.push({ aaa,g + 1 });
			if (aaa == 123804765)
			{
				cout << g + 1;
				break;
			}
			int dd = t.num / d % 10;
			int ddd = t.num - dd * d + dd * pow;
			if (!mp[ddd])mp[ddd] = true, q.push({ ddd,g + 1 });
			if (ddd == 123804765)
			{
				cout << g + 1;
				break;
			}
		}
	}

	return 0;
}