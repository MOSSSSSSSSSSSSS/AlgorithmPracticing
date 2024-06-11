#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

const int N = 100010;
int head = -1, idx = 0, e[N], ne[N], m;

void add_to_head(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}

void remove(int k)
{
    ne[k] = ne[ne[k]];
}

void add(int k, int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

int main()
{
    scanf("%d", &m);
    while (m--)
    {
        char op;
        cin >> op;
        if (op == 'H')
        {
            int x;
            scanf("%d", &x);
            add_to_head(x);
        }
        else if (op == 'D')
        {
            int k;
            scanf("%d", &k);
            if (k)
            {
                remove(k - 1);
            }
            else
            {
                head = ne[head];
            }
        }
        else
        {
            int k, x;
            scanf("%d%d", &k, &x);
            add(k - 1, x);
        }
    }
    for (int i = head; i != -1; i = ne[i])cout << e[i] << ' ';

    return 0;
}10
H 9
I 1 1
D 1
D 0
H 6
I 3 6
I 4 5
I 4 5
I 3 4
D 6