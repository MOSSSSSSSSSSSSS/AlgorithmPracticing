
/*
定一个字符串 S,以及一个模式串 P，所有字符串中只包含大小写英文字母以及阿拉伯数字。

模式串 P在字符串 S中多次作为子串出现。

求出模式串 P在字符串 S 中所有出现的位置的起始下标

*/

//是i和j+1判断是否相等
//ne[1]一定是0，因为j = 1时j+1和i不想等，j = ne[j] = 0，再看j+1和i

//            注意题目中说下标从0开始，而我习惯都从1开始，输出下标的时候要-1

//时间复杂度        O(n)

/*“对于字符串 
S 的前 i 个字符构成的子串，既是它的后缀又是它的前缀的字符串中（它本身除外），最长的长度记作next[i]。”*/
#include<bits/stdc++.h>
using namespace std;


const int M = 1000010, N = 100010;

int n, m,ne[N];                         //  ne[i] 指的是 P串中 第 i+1个和S串第j个不匹配，第i个匹配，于是P串向后移，移到什么情况：ne[i]到原来i的位置  
char s[M], p[N];

int main()
{
	cin >> n >> p + 1 >> m >> s + 1;

	for (int i = 2, j = 0; i <= n; i++)         //求next（ne）数组  ne[1] = 0 所以求的时候，i从2开始j从0
	{
		while (j && p[i] != p[j + 1])j = ne[j];                //   注意判断条件还有个  j&&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		if (p[i] == p[j + 1])j++;
		ne[i] = j;
	}

	for (int i = 1, j = 0; i <= m; i++)
	{
		while (j && s[i] != p[j + 1])j = ne[j];          //   当 j 没有退回到一开始，并且出现不匹配。一直j = ne[j]直到退回起点，或出现匹配
		if (s[i] == p[j + 1])j++;                        //   匹配了，j++，i++
		if (j == n) // 匹配成功
		{
			cout << i - n << ' ';
			j = ne[j];                    //    继续往后匹配
		}
	}

	return 0;
}
// 拓展KMP算法，z函数  

//  可以  #define int long long,, #define MAX 50000前面的代表后面的东西  ，但要注意  int main()改成  signed main()

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