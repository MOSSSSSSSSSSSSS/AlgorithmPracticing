

//  给定  普通 二叉树  的前序后序遍历，中序遍历不确定，
//  中序遍历的种类的个数取决于 二叉树中 只有一个儿子的节点的个数 2的n次方
//  给你前序和后序序列，怎么找只有一个儿子的节点？
//  前序AB，后序BA，那么A只有一个儿子
#include<bits/stdc++.h>
using namespace std;

string qian, hou;
unsigned long long cnt;

int main()
{
	cin >> qian >> hou;
	for (int i = 0; i < qian.size() - 1; i++)
	{
		for (int j = 1; j < hou.size(); j++)
		{
			if (qian[i] == hou[j] && qian[i + 1] == hou[j - 1])cnt++;
		}
	}
	cout << (1 << cnt);

	return 0;
}