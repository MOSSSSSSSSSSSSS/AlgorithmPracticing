


//   ���kmp�������ַ�����ϣ����������һ��ֻ��kmp�����������ַ�����ѭ���ڣ�����Ҫ�ҵ��ַ�����len
//   �����ne���� , len-ne[len]��������Сѭ���ڵĳ��ȣ��ӵ�һ����ĸ��ʼ������Сѭ���ڡ�
//   ���len��len-ne[len]����������˵��������ȫ����Сѭ������ɵ��ַ���
//   �������������˵�����������������bcabcabcab����Сѭ������bca������Ҫ��������ĸ

#include<bits/stdc++.h>
using namespace std;

const int N = 1000010;
int len;
char str[N];
int ne[N];

int main()
{
	cin >> len >> str+1;
	for (int i = 2, j = 0; i <= len; i++)
	{
		while (j && str[i] != str[j + 1])j = ne[j];
		if (str[i] == str[j + 1])j++;
		ne[i] = j;
	}

	cout << len - ne[len];

	return 0;
}