
//双指针算法，用某种方法让两个指针不回溯，前缀和

#include<bits/stdc++.h>
using namespace std;

const int N = 1000010;

int m;
int s[N];

int main()
{
	cin >> m;
	int l = 1, r = 2;

	for (int i = 1; i <= (m + 1 >> 1); i++)    //m+1>>1  除以二不用加括号
		s[i] = s[i - 1] + i;  //         求前缀和数组，求到  m+1>>1

	while (l < r&&r<=m+1>>1)     //  使用   双指针算法  ，i<j  还要注意 j <= m+1>>1
	{
		if (s[r] - s[l - 1] > m)l++;              //如果小于  r++
		else if (s[r] - s[l - 1] < m)r++;         //如果大于   l++ 
		else//                                   只有++的操作
		{
			cout << l << ' ' << r << endl;
			l++;       //再l++看下一种情况
		}
	}

	return 0;

}