#include<iostream>
using namespace std;

const int N = 100010;
int n, m;
int a[N], b[N];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)scanf("%d", &a[i]);
	for (int i = 0; i < m; i++)scanf("%d", &b[i]);

	int j = -1,i;
	for (i = 0; i < n; i++)
	{
		for (j ++ ;j<m;)
		{
			if (a[i] == b[j])break;
			else j++;
		}
		if (j == m)break;
	}
	if (i == n)cout << "Yes";
	else cout << "No";

	return 0;
}