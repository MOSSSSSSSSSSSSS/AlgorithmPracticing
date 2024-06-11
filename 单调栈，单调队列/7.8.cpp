

//单调栈，单调队列在题中的应用，题会给一个序列，让你找到  每  一个数  左边离它最近且小于它的数，或（右边离它最近且大于它等等）可以暴力做出来，也可以单调栈进行优化
// 每  一个数  左边离它最近且小于它的数   有一个性质，这个数左边如果有a3>=a5，（a3在a5前）a3永远不可能是结果，所以可以去掉a3，所以这个数左边严格单调递增
//单调队列，经典用来优化问题：滑动窗口里的n个数中最大数和最小数。   滑动窗口可以用队列来维护。

#include<iostream>
using namespace std;

const int N = 100010;

int n;
int stk[N], tt;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)    //    假定是严格单调增的，后面实现单调
    {
        int x;
        cin >> x;
        while (tt && stk[tt] >= x)tt--;
        if (tt)cout << stk[tt] << ' ';
        else cout << -1 << ' ';
        stk[++tt] = x;
    }

    return 0;
}
//加cin.tie(0)也可以提升速度
//*****************************************************************************************************************
//滑动窗口的最小值最大值              要通过样例模拟一遍过程才能懂
#include<bits/stdc++.h>
using namespace std;

const int N = 1000010;
int n, k,hh,tt = -1;
int a[N],q[N];     //  队列里存的是下标

int main()
{
    cin >> n>>k;
    for (int i = 1; i <= n; i++)scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++)
    {
        if (hh <= tt && i - k + 1 > q[hh])hh++;
        while (hh <= tt && a[q[tt]] >= a[i])tt--;
        q[++tt] = i;
        if (i - k >= 0)printf("%d ", a[q[hh]]);
    }
    cout << endl;
    hh = 0, tt = -1;//   初始化队列
    for (int i = 1; i <= n; i++)
    {
        if (hh <= tt && i - k + 1 > q[hh])hh++;
        while (hh <= tt && a[q[tt]] <= a[i])tt--;
        q[++tt] = i;
        if(i-k>=0)printf("%d ", a[q[hh]]);
    }

    return 0;
}