

#include<bits/stdc++.h>
using namespace std;
struct road
{
    int u;
    int v;
    int c1;
    int c2;
    int ver;
}roads[20005];
int st[20005];
int fa[20005];
int d[20005];
int n, k, m, mn = 0;
bool cmp1(road x, road y)
{
    return x.c1 < y.c1;
}
bool cmp2(road x, road y)
{
    return x.c2 < y.c2;
}
int find(int x)
{
    if (fa[x] != x)fa[x] = find(fa[x]);
    return fa[x];
}
void kruskal1()
{
    int cnt = 0;
    for (int i = 1; i <= m - 1; i++)
    {
        int f1 = find(roads[i].u), f2 = find(roads[i].v),w = roads[i].c1,ver = roads[i].ver;
        if (f1 != f2)
        {
            st[ver] = true;
            d[ver] = 1;
            cnt++;
            fa[f1] = f2;
            mn = max(mn, w);
            if (cnt == k)return;
        }
    }
}
void kruskal2()
{

    int cnt = 0;
    for (int i = 1; i <= m - 1; i++)
    {
        int f1 = find(roads[i].u), f2 = find(roads[i].v), w = roads[i].c2, ver = roads[i].ver;
        if (f1 != f2)
        {
            st[ver] = true;
            d[ver] = 2;
            cnt++;
            fa[f1] = f2;
            mn = max(mn, w);
            if (cnt == n - 1 - k)return;
        }
    }
}
int main()
{
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= m - 1; i++)
        cin >> roads[i].u >> roads[i].v >> roads[i].c1 >> roads[i].c2,roads[i].ver = i;
    sort(roads + 1, roads + m, cmp1);
    kruskal1();
    sort(roads + 1, roads + m, cmp2);
    kruskal2();
    cout << mn << '\n';
    for (int i = 1; i <= m - 1; i++)
        if (st[i])
            cout << i << ' ' << d[i] << '\n';
    return 0;
}
