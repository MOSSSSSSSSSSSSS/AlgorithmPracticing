
/*
���ǴӴ�С����ÿ��������������ķ���������ֵͬ����һ���ǡ�

���ȣ����е����ֵ��������м䣻

�������ǿ��ǵڶ����ֵ�����������x �Σ�������Ӧ����x+1 �ַ�ʽ������Щ����

����ԭ������[2],��������1����ô����[1,1,2],[1,2,1],[2,1,1],�����������һ�㡣

�Դ����ơ�

��˴𰸾��� �����ֵ�����ĳ��ִ���+1�ĳ˻���*/

#include<bits/stdc++.h>
using namespace std;

const int N = 100010,mod = 998244353;
int T;

int main()
{
    cin >> T;
    while (T--)
    {
        int n;
        int a[N], mx = -1;
        long long ans = 1;
        map<int, int> mp;                           //  ��¼�����и���Ԫ�س��ִ����������ܿ�  1e9��С �����飬��ʱ��map <int,int>mp��¼
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            mx = max(mx, a[i]);
            mp[a[i]]++;
        }
        for (auto item : mp)                   //����map�е�Ԫ��
        {
            if (item.first != mx)
            {
                ans = (ans * (item.second + 1)) % mod;             //   ע�⣺��Ȼȡ��ģ������ans * (item.second + 1)�ļ��������������ansҪ��long long
            }
        }
        cout << ans << endl;
    }

    return 0;
}