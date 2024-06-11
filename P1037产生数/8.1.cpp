

#include<bits/stdc++.h>
using namespace std;

int k, turn[10];
bool rule[10][10], check[10][10];
string num;
vector<int> ans;

vector<int> mul(vector<int> A, vector<int> B)
{
	vector<int> C(A.size() + B.size());

	for (int i = 0; i < A.size(); i++)
		for (int j = 0; j < B.size(); j++)
			C[i + j] += A[i] * B[j];

	for (int i = 0, t = 0; i < C.size() || t; i++)
	{
		t += C[i];
		if (i >= C.size()) C.push_back(t % 10);
		else C[i] = t % 10;
		t /= 10;
	}

	while (C.size() > 1 && !C.back()) C.pop_back();

	return C;
}

void dfs(int x,int num)
{
	for (int i = 1; i <= 9; i++)
	{
		if (rule[x][i] == 1&&check[num][i]==0)
		{
			check[num][i] = 1;
			dfs(i, num);
		}
	}
}

int main()
{
	ans.push_back(1);
	cin >> num >> k;
	for (int i = 1; i <= k; i++)
	{
		int x, y;
		cin >> x >> y;
		rule[x][y] = 1;
	}
	for (int i = 0; i <= 9; i++)
		check[i][i] = 1;
	for (int i = 0; i < 10; i++)
		dfs(i,i);
	for (int i = 0; i <= 9; i++)
		for (int j = 0; j <= 9; j++)
			if (check[i][j] == 1)
				turn[i]++;
	for (int i = 0; i < num.size(); i++)
	{
		vector<int> B;
		B.push_back(turn[num[i] - '0']);
		ans = mul(ans, B);
	}
	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i];

	return 0;
}