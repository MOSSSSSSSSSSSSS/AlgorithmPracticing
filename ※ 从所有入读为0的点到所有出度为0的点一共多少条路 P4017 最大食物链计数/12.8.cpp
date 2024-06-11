
//  �����޻�ͼ �� ע��һ��������������������Ϊ0�ĵ㣬һ������Ϊ0�ĵ�һ����
//  �����������һ�����Ϊ0�ĵ㣬�����1��������һ�����Ϊ0�ĵ㣬������vis���飬�Ѳ���ȥ��
//  �������1��������˲�����vis���飬����������ظ���������TLE������ټ��仯����

#include<bits/stdc++.h>
using namespace std;

const int N = 5010, M = 500010,P = 80112002;
int h[N], e[M], ne[M], idx;
int n, m;
int din[N], dout[N];
set<int> chudu;
vector<int> rudu;
int num[N];
int ans;

void dfs(int u)
{
	int cnt = 0;
	if (chudu.count(u))
	{
		cnt = (cnt + 1)%P;
		num[u] = cnt;
		return;
	}
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if(num[j]==0)dfs(j);
		num[u] = (num[j] + num[u])%P;
	}
}

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
		din[b]++;
		dout[a]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (din[i] == 0)rudu.push_back(i);
		if (dout[i] == 0)chudu.insert(i);
	}
	for (auto node : rudu)
		dfs(node);
	for (auto node : rudu)
		ans = (ans + num[node]) % P;
	cout << ans;

	return 0;
}