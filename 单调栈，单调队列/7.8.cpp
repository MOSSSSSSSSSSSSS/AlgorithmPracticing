

//����ջ���������������е�Ӧ�ã�����һ�����У������ҵ�  ÿ  һ����  ������������С�������������ұ���������Ҵ������ȵȣ����Ա�����������Ҳ���Ե���ջ�����Ż�
// ÿ  һ����  ������������С��������   ��һ�����ʣ��������������a3>=a5����a3��a5ǰ��a3��Զ�������ǽ�������Կ���ȥ��a3���������������ϸ񵥵�����
//�������У����������Ż����⣺�����������n���������������С����   �������ڿ����ö�����ά����

#include<iostream>
using namespace std;

const int N = 100010;

int n;
int stk[N], tt;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)    //    �ٶ����ϸ񵥵����ģ�����ʵ�ֵ���
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
//��cin.tie(0)Ҳ���������ٶ�
//*****************************************************************************************************************
//�������ڵ���Сֵ���ֵ              Ҫͨ������ģ��һ����̲��ܶ�
#include<bits/stdc++.h>
using namespace std;

const int N = 1000010;
int n, k,hh,tt = -1;
int a[N],q[N];     //  �����������±�

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
    hh = 0, tt = -1;//   ��ʼ������
    for (int i = 1; i <= n; i++)
    {
        if (hh <= tt && i - k + 1 > q[hh])hh++;
        while (hh <= tt && a[q[tt]] <= a[i])tt--;
        q[++tt] = i;
        if(i-k>=0)printf("%d ", a[q[hh]]);
    }

    return 0;
}