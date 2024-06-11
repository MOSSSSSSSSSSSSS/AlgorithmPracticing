#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll exgcd(ll a, ll b, ll& x, ll& y)// 拓欧
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}
ll inv(ll a, ll p)
{
    ll x, y;
    if (exgcd(a, p, x, y) != 1) // 无解的情形
        return -1;
    return (x % p + p) % p;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << inv(a, b);

    return 0;
}