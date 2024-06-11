

//ÓÉO£¨n2£©±äÎªO£¨n£©

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

const int N = 100010;
int n, m, x;
int A[N], B[N];

int main()
{
	scanf("%d%d%d", &n, &m, &x);
	for (int i = 0; i < n; i++)scanf("%d", &A[i]);
	for (int i = 0; i < m; i++)scanf("%d", &B[i]);
	int i, j;
	for (i = 0, j = m - 1;;)
	{
		if (A[i] + B[j] > x)j--;
		else if (A[i] + B[j] == x)break;
		else i++;
	}
	cout << i << ' ' << j;

	return 0;
}