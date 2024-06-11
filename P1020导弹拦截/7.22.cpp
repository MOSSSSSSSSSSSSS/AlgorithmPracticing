

//输入一般都是第一行是数据个数，第二行是所有数据，如果没有告诉数据一共多少个，直接给所有数据，又没有数据结束的标识（如输入一个0表示输入结束）
//此时应该用while(cin>>)读入

//这个题找的是  最长不上升子序列

//Dilworth Dilworth 定理：数列的最长不上升子序列的个数等于数列最长上升子序列的大小

#include<bits/stdc++.h>
using namespace std;

const int N = 100010;

vector<int> b,c;
int a[N],f[N],res,n = 1;

int main()
{
	ios::sync_with_stdio(false);   //提高cin速度
	while (cin >> a[n])n++;
	n--;   //此时n是一共有多少个输入的数据

	b.push_back(0);
	b.push_back(a[1]);
	f[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		int l = 0, r = b.size() - 1;
		while (l < r)
		{
			int mid = l + r + 1 >> 1;
			if (b[mid] >= a[i])l = mid;
			else r = mid - 1;
		}
		if (l == b.size() - 1)b.push_back(a[i]);        //    因为这个==写成了=，浪费好几小时
		else b[l + 1] = a[i];
		f[i] = l + 1;
	}

	for (int i = 1; i <= n; i++)res = max(res, f[i]);
	//for (int i = 1; i <= n; i++)cout << f[i] << ' ';           //  记得交上去的时候要删
	cout << endl << res << endl;

	c.push_back(0);
	c.push_back(a[1]);

	for (int i = 2; i <= n; i++)
	{
		int l =1, r = c.size();
		while (l < r)
		{
			int mid = l + r >> 1;
			if (c[mid] >= a[i])r = mid;
			else l = mid + 1;
		}
		if (l == c.size())c.push_back(a[i]);
		else c[l] = a[i];
		f[i] = l;
	}

	res = 0;
	for (int i = 1; i <= n; i++)res = max(res, f[i]);
	cout << res;


	return 0;
}
