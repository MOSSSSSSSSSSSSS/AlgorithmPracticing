
//因为链表new操作浪费时间，所以用数组模拟可以提高速度
//单链表最常用的是邻接表，它常用来存储图和树，       邻接表 就是 一组 单链表，有head[0].....head[i]
//双链表常用来优化 

//用数组模拟链表叫静态链表，直接用数据结构叫动态链表


/////注意scanf读入   %c   时可以读入回车，空格，可能会把回车或空格赋值给变量，所以需要再格式控制串中加入空格回车，例如“%c ”，“%c\n”的方式使变量不被赋值成空格回车
/////下面的最后的例题就是用scanf不处理就出错，用cin不出错。




#include<bits/stdc++.h>
using namespace std;

const int N = 100010;

int head,e[N], ne[N],idx;//需要一个头节点，head是头节点指针，存储后面第一个节点的下标，头节点不存储值，只有一个指针，按照一共多少节点，定义两个多大的数组，分别存储一个节点的值和next指针（存储下一个节点的下标），节点编号从0开始。
//还需要一个idx指向当前的节点。

void init()//给链表初始化  单链表最一开始就是head指向空节点
{
	head = -1;//一开始只想空结点，空结点下标是-1；
	idx = 0;
}

void add_to_head(int x)//将x插到头节点和第一个节点之间
{
	e[idx] = x;
	ne[idx] = head;//等于head原来指向的
	head = idx;
	idx++;//已经用了这个编号的节点，当前可用的移到下一个；例如原来可用的编号为10，就将10移到了head和第一个节点（0）之间，下一个可用的是11，所以idx++
}

void add(int x,int k)//将x插到下标是k的点后面
{
	e[idx] = x;
	ne[idx] = ne[k];
	ne[k] = idx;
	idx++;
}

void remove(int k)//将下标是k的后面的节点删掉
{
	ne[k] = ne[ne[k]];//k直接跳过下一个节点，指针记录下下个节点的下标，注意节点下表是k，下一个节点下标不一定是k+1
}

int main()
{


	return 0;
}

//例题
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
    scanf("%d\n", &m);//需后面加个\n
    while (m--)
    {
        char op;
        scanf("%c", &op);
        if (op == 'H')
        {
            int x;
            scanf("%d\n", &x);//需后面加个\n     %d前面缓冲区有一个空格“ 6”可以不管，直接 %d
            add_to_head(x);
        }
        else if (op == 'D')
        {
            int k;
            scanf("%d\n", &k);//需后面加个\n
            if (k)
            {
                remove(k - 1);
            }
            else
            {
                head = ne[head];//             题目说k为0时删除头节点，实际上就是删掉第一个节点
            }
        }
        else
        {
            int k, x;
            scanf("%d%d\n", &k, &x);//需后面加个\n
            add(k - 1, x);
        }
    }
    for (int i = head; i != -1; i = ne[i])cout << e[i] << ' ';//  注意   打印单链表   是打印节点的值（value）    从head开始打印，通过它们指针存储的下一个的下标来寻找，
    //而不是从下标0开始再i++，要按照链表的顺序，链表中下标不一定是按照0，1，2，3，4，5，6的顺序，例如可以将下标为10的插入到头节点和下标为0的节点之间，
    //要先输出下标为10的值

    return 0;
}

