

//  ����  ��ͨ ������  ��ǰ�������������������ȷ����
//  �������������ĸ���ȡ���� �������� ֻ��һ�����ӵĽڵ�ĸ��� 2��n�η�
//  ����ǰ��ͺ������У���ô��ֻ��һ�����ӵĽڵ㣿
//  ǰ��AB������BA����ôAֻ��һ������
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