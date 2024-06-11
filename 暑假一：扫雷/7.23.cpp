

#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
int n, a[N], b[N];

bool check()
{
    for (int i = 2; i <= n + 1; i++)
    {
        b[i] = a[i - 1] - b[i - 1] - b[i - 2];
        if (b[i] < 0||b[i]>1)return false;
    }
    return !b[n + 1];
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)  cin >> a[i];

    int ans = 0;
    if (check()) ans++;

    b[1] = 1;
    if (check()) ans++;
    cout << ans << endl;
    return 0;
}
