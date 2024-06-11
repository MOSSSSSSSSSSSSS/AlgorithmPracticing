#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

typedef long long ll;
const int N = 1000010;
int q[N], tmp[N], n;

ll merge_sort(int l, int r)
{
	if (l >= r)return 0;

	int mid = l + r >> 1;
	ll res = merge_sort(l, mid) + merge_sort(mid + 1, r);

	int k = 0, i = l, j = mid + 1;
	while (i <= mid && j <= r)
	{
		if (q[i] <= q[j])tmp[k++] = q[i++];
		else
		{
			tmp[k++] = q[j++];
			res += r - i + 1;
		}
	}
	while (i <= mid)tmp[k++] = q[i++];
	while (j <= r)tmp[k++] = q[j++];

	for (i = l, j = 0; i <= r; i++, j++)q[i] = tmp[j];
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &q[i]);
	
	printf("%d", merge_sort(0, n - 1));

	return 0;
}