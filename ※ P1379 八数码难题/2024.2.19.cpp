

#include<bits/stdc++.h>
using namespace std;
#define int long long

int now;
queue<int> q;
map<int, int> mp;

signed main()
{
	cin >> now;
	q.push(now);
	mp[now] = 1;
	while (q.size())
	{
		int t = q.front();
		q.pop();
		int pow = 1;
		for (; pow <= 1e8; pow*=10)
			if (t / pow % 10 == 0)
				break;
		int a = pow * 10, b = pow / 10, c = pow / 1000, d = pow * 1000;
		if (pow == 1e8)
		{
			int bb = t / b % 10;
			int bbb = t - bb * b + bb * pow;
			if (!mp[bbb])mp[bbb] = mp[t] + 1, q.push(bbb);
			if (bbb == 123804765)break;
			int cc = t / c % 10;
			int ccc = t - cc * c + cc * pow;
			if (!mp[ccc])mp[ccc] = mp[t] + 1, q.push(ccc);
			if (ccc == 123804765)break;
		}
		else if (pow == 1e7)
		{
			int aa = t / a % 10;
			int aaa = t - aa * a + aa * pow;
			if (!mp[aaa])mp[aaa] = mp[t] + 1, q.push(aaa);
			if (aaa == 123804765)break;
			int bb = t / b % 10;
			int bbb = t - bb * b + bb * pow;
			if (!mp[bbb])mp[bbb] = mp[t] + 1, q.push(bbb);
			if (bbb == 123804765)break;
			int cc = t / c % 10;
			int ccc = t - cc * c + cc * pow;
			if (!mp[ccc])mp[ccc] = mp[t] + 1, q.push(ccc);
			if (ccc == 123804765)break;
		}
		else if (pow == 1e6)
		{
			int aa = t / a % 10;
			int aaa = t - aa * a + aa * pow;
			if (!mp[aaa])mp[aaa] = mp[t] + 1, q.push(aaa);
			if (aaa == 123804765)break;
			int cc = t / c % 10;
			int ccc = t - cc * c + cc * pow;
			if (!mp[ccc])mp[ccc] = mp[t] + 1, q.push(ccc);
			if (ccc == 123804765)break;
		}
		else if (pow == 1e5)
		{
			int bb = t / b % 10;
			int bbb = t - bb * b + bb * pow;
			if (!mp[bbb])mp[bbb] = mp[t] + 1, q.push(bbb);
			if (bbb == 123804765)break;
			int cc = t / c % 10;
			int ccc = t - cc * c + cc * pow;
			if (!mp[ccc])mp[ccc] = mp[t] + 1, q.push(ccc);
			if (ccc == 123804765)break;
			int dd = t / d % 10;
			int ddd = t - dd * d + dd * pow;
			if (!mp[ddd])mp[ddd] = mp[t] + 1, q.push(ddd);
			if (ddd == 123804765)break;
		}
		else if (pow == 1e4)
		{
			int aa = t / a % 10;
			int aaa = t - aa * a + aa * pow;
			if (!mp[aaa])mp[aaa] = mp[t] + 1, q.push(aaa);
			if (aaa == 123804765)break;
			int cc = t / c % 10;
			int ccc = t - cc * c + cc * pow;
			if (!mp[ccc])mp[ccc] = mp[t] + 1, q.push(ccc);
			if (ccc == 123804765)break;
			int bb = t / b % 10;
			int bbb = t - bb * b + bb * pow;
			if (!mp[bbb])mp[bbb] = mp[t] + 1, q.push(bbb);
			if (bbb == 123804765)break;
			int dd = t / d % 10;
			int ddd = t - dd * d + dd * pow;
			if (!mp[ddd])mp[ddd] = mp[t] + 1, q.push(ddd);
			if (ddd == 123804765)break;
		}
		else if (pow == 1e3)
		{
			int aa = t / a % 10;
			int aaa = t - aa * a + aa * pow;
			if (!mp[aaa])mp[aaa] = mp[t] + 1, q.push(aaa);
			if (aaa == 123804765)break;
			int dd = t / d % 10;
			int ddd = t - dd * d + dd * pow;
			if (!mp[ddd])mp[ddd] = mp[t] + 1, q.push(ddd);
			if (ddd == 123804765)break;
			int cc = t / c % 10;
			int ccc = t - cc * c + cc * pow;
			if (!mp[ccc])mp[ccc] = mp[t] + 1, q.push(ccc);
			if (ccc == 123804765)break;
		}
		else if (pow == 1e2)
		{
			int bb = t / b % 10;
			int bbb = t - bb * b + bb * pow;
			if (!mp[bbb])mp[bbb] = mp[t] + 1, q.push(bbb);
			if (bbb == 123804765)break;
			int dd = t / d % 10;
			int ddd = t - dd * d + dd * pow;
			if (!mp[ddd])mp[ddd] = mp[t] + 1, q.push(ddd);
			if (ddd == 123804765)break;
		}
		else if (pow == 10)
		{
			int aa = t / a % 10;
			int aaa = t - aa * a + aa * pow;
			if (!mp[aaa])mp[aaa] = mp[t] + 1, q.push(aaa);
			if (aaa == 123804765)break;
			int bb = t / b % 10;
			int bbb = t - bb * b + bb * pow;
			if (!mp[bbb])mp[bbb] = mp[t] + 1, q.push(bbb);
			if (bbb == 123804765)break;
			int dd = t / d % 10;
			int ddd = t - dd * d + dd * pow;
			if (!mp[ddd])mp[ddd] = mp[t] + 1, q.push(ddd);
			if (ddd == 123804765)break;
		}
		else
		{
			int aa = t / a % 10;
			int aaa = t - aa * a + aa * pow;
			if (!mp[aaa])mp[aaa] = mp[t] + 1, q.push(aaa);
			if (aaa == 123804765)break;
			int dd = t / d % 10;
			int ddd = t - dd * d + dd * pow;
			if (!mp[ddd])mp[ddd] = mp[t] + 1, q.push(ddd);
			if (ddd == 123804765)break;
		}
	}
	cout << mp[123804765] - 1;
	
	return 0;
}
