

// �������߶��ǳ����������ÿ����һ������ȡ�����б�Ȩ�������ȡ�⣬û�л�ʤ����

#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	int cnt = 0;
	for (auto item : v)
	{
		if (item == 0)break;
		else cnt++;
	}
	if (cnt % 2 != 0) {
		cout << "YES" << '\n'; return 0;
	}
	reverse(v.begin(), v.end());
	cnt = 0;
	for (auto item : v)
	{
		if (item == 0)break;
		else cnt++;
	}
	if (cnt % 2 != 0) cout << "YES" << '\n';
	else cout << "NO";

	return 0;
}