


#include<bits/stdc++.h>
using namespace std;

int n;
string str;
vector<int> now;

bool cmp(vector<int> tot,vector<int> now)
{
	if (tot.size() > now.size())return true;
	else if (tot.size() < now.size())return false;
	else
	{
		for (int i = tot.size() - 1; i >= 0; i--)
		{
			if (tot[i] > now[i])
				return true;
			else if(tot[i] < now[i])
				return false;
		}
		return true;
	}
}
vector<int> mul(vector<int> newborn,int b)
{
	vector<int> C;
	int t = 0;
	for (int i = 0; i < newborn.size(); i++)
	{
		t += newborn[i] * b;
		C.push_back(t % 10);
		t /= 10;
	}
	if (t)C.push_back(t);
	while (C.size() > 1 && C.back() == 0)C.pop_back();
	return C;
}
vector<int> add(vector<int> A, vector<int> B)
{
	vector<int> C;
	int t = 0;
	for (int i = 0; i < A.size() || i < B.size(); i++)
	{
		if (i < A.size())t += A[i];
		if (i < B.size())t += B[i];
		C.push_back(t % 10);
		t /= 10;
	}
	if (t)C.push_back(1);
	return C;
}
bool check(int mid)
{
	vector<int> newborn;
	vector<int> old;
	vector<int> tot;
	old.push_back(0);
	while (mid)
	{
		newborn.push_back(mid % 10);
		mid /= 10;
	}
	for (int i = 1; i <= n; i++)
	{
		old = add(newborn, old);
		newborn = mul(newborn, 2);
		if (newborn[0] != 0)
			newborn[0] -= 1;
		else
			newborn[1] -= 1, newborn[0] = 9;
	}
	tot = add(newborn, old);
	if (cmp(tot, now)) return true;  // tot大于等于
	else return false;
}

int main()
{
	cin >> n >> str;
	for (int i = str.size() - 1; i >= 0; i--)
		now.push_back(str[i] - '0');
	int l = 1, r = 100;
	while (l < r)
	{
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l;

	return 0;
}