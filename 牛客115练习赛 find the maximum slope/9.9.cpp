

#include<bits/stdc++.h>
using namespace std;

const int N = 500010;
int n, q;
double sum[N], a[N];

void insert(int l, int r, int d)
{
    a[l] += d;
    a[r + 1] -= d;
}

int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> sum[i];
    for (int i = 1; i <= n; i++)
        insert(i, i, sum[i]);
    double l = N, r = -N;
    int t1, t2, t;
    for (int i = 2; i <= n; i++)
    {
        if (l > a[i])
        {
            l = a[i];
            t1 = i;
        }
        if (r < a[i])
        {
            r = a[i];
            t2 = i;
        }
    }
    double L;
    if (fabs(l) > fabs(r))
    {
        L = fabs(l);
        t = t1;
    }
    else
    {
        L = fabs(r);
        t = t2;
    }
    printf("%.6lf\n", L);
    while (q--)
    {
        int l2, r2, x;
        cin >> l2 >> r2 >> x;
        insert(l2, r2, x);
        if (l2 != t && r2 + 1 != t)
        {
            if (L < fabs(a[l2]) && l2 != 1)
            {
                L = fabs(a[l2]);
                t = l2;
            }
            if (L < fabs(a[r2 + 1]))
            {
                L = fabs(a[r2 + 1]);
                t = r2 + 1;
            }
        }
        else
        {
            double l = N, r = -N;
            int t1, t2;
            for (int i = 2; i <= n; i++)
            {
                if (l > a[i])
                {
                    l = a[i];
                    t1 = i;
                }
                if (r < a[i])
                {
                    r = a[i];
                    t2 = i;
                }
            }
            if (fabs(l) > fabs(r))
            {
                L = fabs(l);
                t = t1;
            }
            else
            {
                L = fabs(r);
                t = t2;
            }
        }
        printf("%.6lf\n", L);
    }

    return 0;
}