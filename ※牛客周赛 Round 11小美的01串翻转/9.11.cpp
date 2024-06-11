

#include<bits/stdc++.h>
using namespace std;

const int N = 2010;
char str[N];
long long ans;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> str;
    for (int i = 0; i < strlen(str); i++)
    {
        int ans1 = 0, ans2 = 0;
        for (int j = i; j < strlen(str); j++)
        {
            if (j % 2 != 0)
            {
                if (str[j] == '0')ans1++;
                else ans2++;
            }
            else
            {
                if (str[j] == '0')ans2++;
                else ans1++;
            }
            ans += min(ans1, ans2);
        }
    }
    cout << ans;
    return 0;
}