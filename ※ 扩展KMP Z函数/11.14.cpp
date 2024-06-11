
//  z函数 ： z[i]表示以i开头的后缀序列与整个序列的lcp
//  lcp : 最长公共前缀

//  求一个序列与它本身的z函数
//  求a序列b序列的z函数   只需要把b和a接起来，再求z函数
#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e7 + 10;
char a[N],b[N];
int z[N], p[N];
int ans1, ans2;

void get_z(int len)
{
	z[1] = len;
	for (int i = 2, l, r = 0; i <= len; i++)
	{
		if (i <= r)z[i] = min(z[i-l+1],r-i+1 );
		while (b[1 + z[i]] == b[i + z[i]])z[i]++;
		if (i + z[i] - 1 > r)l = i, r = i + z[i] - 1;
	}
}
void get_p(int len,int le)
{
	for (int i = 1, l, r = -1; i <= len; i++)
	{
		if (i <= r)p[i] = min(z[i-l+1], r - i + 1);
		while (1+p[i]<=le&&i+p[i]<=len && b[1 + p[i]] == a[i + p[i]])p[i]++;/////////////////////////////////////////////////////////////////////////////////////////
		if (i + p[i] - 1 > r)l = i, r = i + p[i] - 1;
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> a + 1 >> b + 1;
	int len1 = strlen(b + 1);
	int len2 = strlen(a + 1);
	get_z(len1);
	for (int i = 1; i <= len1; i++)
		ans1 ^= (i * (z[i] + 1));
	get_p(len2,len1);
	for (int i = 1; i <= len2; i++)
		ans2 ^= (i * (p[i] + 1));
	cout << ans1 << '\n' << ans2;

	return 0;
}
/*

#include<bits/stdc++.h>
#define int long long                    //注意这个数量，要开long long，并且要小心其他如果有int类型，，小心在计算过程中溢出，不容易发现这种错误，直接全定义成long long
using namespace std;

const int N = 20000010;
string a, b;
int z[N], p[N];

void get_z()
{
	z[0] = b.size();
	for (int i = 1, l, r = 0; i < b.size(); i++)       //  r取值保证不进入第一个if，先暴力找一个,第三个if，r会有值
	{
		if (i <= r)z[i] = min(z[i - l], r - i + 1);  //   注意  a，b都是从下标0开始，z也是从0开始，和董晓算法从一开始不一样，这里浪费2小时
		while (b[i + z[i]] == b[z[i]])z[i]++;
		if (i + z[i] - 1 > r)l = i, r = i + z[i] - 1;
	}
}

void get_p()
{
	for (int i = 0, l, r = -1; i < a.size(); i++)      //  r取值保证不进入第一个if，先暴力找一个,第三个if，r会有值
	{
		if (i <= r)p[i] = min(z[i - l], r - i + 1);          //   注意  a，b都是从下标0开始，z也是从0开始，和董晓算法从一开始不一样，这里浪费2小时
		while (i + p[i] < a.size() && p[i] < b.size() && b[p[i]] == a[i + p[i]])p[i]++;//前面两个条件是下标不越界
		if (i + p[i] - 1 > r)l = i, r = i + p[i] - 1;
	}
}

signed main()
{
	cin.tie(0);
	cin >> a >> b;

	get_z();
	get_p();

	int ans = 0;
	for (int i = 1; i <= b.size(); i++)
		ans ^= i * (z[i - 1] + 1);
	cout << ans << endl;
	ans = 0;
	for (int i = 1; i <= a.size(); i++)
		ans ^= i * (p[i - 1] + 1);
	cout << ans;

	return 0;
}
*/