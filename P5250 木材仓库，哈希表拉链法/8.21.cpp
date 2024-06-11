

//   ��ϣ����ǲ���һ������û�У�����һ����
//   ������ɾ��һ����������ǰ���ֱ��ָ������

//�ڴ�С��������������У�
//lower_bound( begin,end,num)���������beginλ�õ�end-1λ�ö��ֲ��ҵ�һ�����ڻ����num�����֣��ҵ����ظ����ֵĵ�ַ,�������򷵻�end��ͨ�����صĵ�ַ��ȥ��ʼ��ַbegin,�õ��ҵ������������е��±ꡣ
//upper_bound( begin,end,num)���������beginλ�õ�end-1λ�ö��ֲ��ҵ�һ������num�����֣��ҵ����ظ����ֵĵ�ַ���������򷵻�end,ͨ�����صĵ�ַ��ȥ��ʼ��ַbegin,�õ��ҵ������������е��±ꡣ




//  ��Ŀ��Ҫ���ҵ�����Ϊx�ģ����û�о�����x����ĳ��ȵģ�����ϣ��O��1��������ģ��ù�ϣ���������������鷳��

//     ƽ���������Ӷ�O��logn����������ģ���ƽ���������ֲ������á�



/*����hash���ѯ���죬���ݿ�Ϊʲô����hash��

�����뵽���������棬һ����ƽ�������������ԣ���һ������hash����������⡣

������ʲô�ã�

�������ݿ�����1���������ݣ���100����id>xxx����������Ҫ����һ�����������У�ȡ����100��id>xxx�����ݡ�����ƽ����������ģ�ֻҪ�ҵ�xxx����������Ϳ���˳�����ϣ��õ����еĴ���xxx���û���������hash����ֻ�ܰ�ÿ�����ݶ��ó����ȶ�һ�顣

hash�������������ʲô��

���ǳ�����hash��ʵ�֣��ǻ�������ʵ�ֵģ������������hash��ͻ����������Ĺ̶���С�����ǲŷ������hash���㡣���ǵ���������ȥ��ʱ��ÿ��hashͰ�ڵ�Ԫ�ػ�Խ��Խ�࣬��ȻӰ�쵽��ѯ������һ�㶼���ڴﵽ�ٽ�ֵ��ʱ�򣬽������ݡ���һƬ����Ŀռ䣬Ȼ��Ѿ����������¿ռ��У����������Ҫ��hash��������һ��Ļ�����hash��ʱ��ɱ��ǳ��ߡ�

���Ծ���������hash��

�����ǿ��ԡ�ǰ��������֪����Ҫ��������ݴ����ʲô��Χ�������Ļ��Ϳ����ڳ�ʼ��hash���ʱ��ָ����С�����Ƕ������ݿ�����Ӧ�ã�����û�취ȷ�����׻�Ŷ������ݽ�ȥ��*/




#include<bits/stdc++.h>
using namespace std;

const int N = 100003;
int h[N], e[N], ne[N], idx,n,m,backup[N]; //   m��̬ά��ľ������
bool check[N];        //  e�е�Ԫ�ز��������е�Ԫ�أ��еı�ɾ���е�û��ɾ����Ϊɾ������ֻ�Ƕ���ne������check��¼ĳ��������û�б�ɾ

void insert(int len)
{
	int k = (len % N + N) % N;
	e[idx] = len;
	ne[idx] = h[k];
	h[k] = idx++;
}

bool find(int len)
{
	int k = (len % N + N) % N;
	for (int i = h[k]; i != -1; i = ne[i])
		if (e[i] == len)
			return true;
	return false;
}

void del(int len)
{
	int k = (len % N + N) % N;
	int i = h[k];
	if (e[i] == len)
	{
		check[i] = 1;
		h[k] = ne[i];
		return;
	}
	for (int i = h[k];; i = ne[i])
	{
		int j = ne[i];
		if (e[j] == len)
		{
			check[j] = 1;
			ne[i] = ne[j];
			return;
		}
	}
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < N; i++)h[i] = -1;
	cin >> n;
	while (n--)
	{
		char flag;
		int len;
		cin >> flag >> len;
		if (flag == '1')
		{
			if (find(len))cout << "Already Exist" << endl;
			else
			{
				insert(len);
				m++;
			}
		}
		else
		{
			if (m)
			{
				if (find(len))
				{
					del(len);
					m--;
					cout << len << endl;
				}
				else
				{
					int j = 0;
					for (int i = 0; i < idx; i++)
						if(check[i]==0)
							backup[j++] = e[i];
					if (m == 1)
					{
						del(backup[0]);
						m--;
						cout << backup[0] << endl;
					}
					else
					{
						sort(backup, backup + m);
						int t = upper_bound(backup, backup + m, len) - backup;
						if (t == m)
						{
							del(backup[m - 1]);
							cout << backup[m - 1] << endl;
							m--;
						}
						else
						{
							if (t == 0)
							{
								del(backup[0]);
								m--;
								cout << backup[0] << endl;
							}
							else
							{
								if (backup[t] - len < len - backup[t - 1])        //    ����������,������һ����ʱ��Ҫ����
								{
									del(backup[t]);
									m--;
									cout << backup[t] << endl;
								}
								else
								{
									del(backup[t - 1]);
									m--;
									cout << backup[t - 1] << endl;
								}
							}
						}
					}
				}
			}
			else
				cout << "Empty" << endl;
		}
	}

	return 0;
}