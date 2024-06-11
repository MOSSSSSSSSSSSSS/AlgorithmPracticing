

//���ɣ����ϵ��ó���С�����������ϳ�һ�����Ž�ȥ��ֱ���ϳ�Ϊһ�ѣ���ʱ���ǻ�����С�������ͺϲ�����һ��̰��˼·

#include<bits/stdc++.h>
using namespace std;

const int N = 20010;
int n;
int wood[N];
unsigned long long ans;

void down(int u)
{
	int t = u;
	if (2 * u <= n && wood[2 * u] < wood[u])t = 2 * u;
	if (2 * u + 1 <= n && wood[2 * u + 1] < wood[t])t = 2 * u + 1;
	if (t != u)
	{
		swap(wood[t], wood[u]);
		down(t);
	}
}

void up(int u)
{
	while (u / 2 && wood[u / 2] > wood[u])
	{
		swap(wood[u / 2], wood[u]);
		u /= 2;
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> wood[i];
	for (int i = n / 2; i; i--)
		down(i);
	while (n>1)
	{
		int tmp = 0;
		tmp += wood[1];
		wood[1] = wood[n];
		n--;
		down(1);
		tmp += wood[1];
		wood[1] = wood[n];
		n--;
		down(1);
		wood[++n] = tmp;
		up(n);
		ans += tmp;
	}
	cout << ans;

	return 0;
}