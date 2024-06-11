

#include<bits/stdc++.h>
using namespace std;

const int N = 110;
int n, m;
int g[N][N];
int ans;

void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                g[i][j] |= (g[i][k] && g[k][j]);
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a][b] = 1;
    }
    floyd();
    for (int i = 1; i <= n; i++)
    {
        bool flag = true;
        for (int j = 1; j <= n; j++)
        {
            if (j != i)
            {
                if (!g[i][j] && !g[j][i])
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag)ans++;
    }
    cout << ans;
    return 0;
}