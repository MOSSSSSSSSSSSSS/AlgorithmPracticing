

            //  ��Ŀ�����ݷ�Χ1e9̫�󣬿���������������ֻ��Ҫ֪����Щ������ʯ�Ӿ��У����Կ�����ɢ����yxc����ɢ��������Щ��ĵ�����������
        //    ��������������±��ʾĳ�������ٽ�һ�������飬�±����ĳ����ת������±꣬�����洢����

//  ������õ������㣬������ɢ��
//���Է��ֵ�s<tʱ�� s��tһ�����غϣ������Ժ��ÿ���㶼���Ե�� ��������ֻ�轫ÿ����ʯͷ���� s��t �ľ�������s��t�Ϳ�����
#include<bits/stdc++.h>
using namespace std;

const int N = 105 * 90,M = 110,INF = 0x3f3f3f3f;
int l, s, t, m;
int bridge[N],stone[M],backup[M];
int dp[N];
int ans = INF;

int main()
{
    cin >> l >> s >> t >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> stone[i];
        backup[i] = stone[i];
    }
    sort(stone + 1, stone + m+1);
    sort(backup + 1, backup + m + 1);
    if (s == t)
    {
        int cnt = 0;
        for (int i = 1; i <= m; i++)
            if (stone[i] % s == 0)
                cnt++;
        cout << cnt;
        return 0;
    }
    for (int i = 1; i <= m; i++)
    {
        if (stone[i] - backup[i - 1] > s * t)
            stone[i] = stone[i - 1] + s * t;
        else
            stone[i] = stone[i - 1] + stone[i] - backup[i - 1];
        bridge[stone[i]] = 1;
    }
    if (l - backup[m] > s * t)
        l = stone[m] + s * t;                   //  21��38��%%%%%ѹ��·��%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    else
        l = stone[m] + l - backup[m];
    for (int i = 0; i <= l-1+t; i++)            //  ��ʼ������ֵ��ע���յ�����
        dp[i] = INF;
    dp[0] = 0;
    for (int i = 1; i <= l - 1 + t; i++)
    {
        /*for (int j = i - s; j >= 0 && j >= i - t; j--)
            dp[i] = min(dp[i], dp[j]);
        if (bridge[i] == 1)
            dp[i]++;*/
        for (int j = i - s; j >= 0 && j >= i - t; j--)
        {
            if (bridge[i] == 1)
                dp[i] = min(dp[i], dp[j]+1);
            else
                dp[i] = min(dp[i], dp[j]);
        }
    }
    for (int i = l; i <= l - 1 + t; i++)
        ans = min(ans, dp[i]);

    cout << ans;

    return 0;
}
