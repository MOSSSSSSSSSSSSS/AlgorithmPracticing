
/*
��һ���ַ��� S,�Լ�һ��ģʽ�� P�������ַ�����ֻ������СдӢ����ĸ�Լ����������֡�

ģʽ�� P���ַ��� S�ж����Ϊ�Ӵ����֡�

���ģʽ�� P���ַ��� S �����г��ֵ�λ�õ���ʼ�±�

*/

//��i��j+1�ж��Ƿ����
//ne[1]һ����0����Ϊj = 1ʱj+1��i����ȣ�j = ne[j] = 0���ٿ�j+1��i

//            ע����Ŀ��˵�±��0��ʼ������ϰ�߶���1��ʼ������±��ʱ��Ҫ-1

//ʱ�临�Ӷ�        O(n)

/*�������ַ��� 
S ��ǰ i ���ַ����ɵ��Ӵ����������ĺ�׺��������ǰ׺���ַ����У���������⣩����ĳ��ȼ���next[i]����*/
#include<bits/stdc++.h>
using namespace std;


const int M = 1000010, N = 100010;

int n, m,ne[N];                         //  ne[i] ָ���� P���� �� i+1����S����j����ƥ�䣬��i��ƥ�䣬����P������ƣ��Ƶ�ʲô�����ne[i]��ԭ��i��λ��  
char s[M], p[N];

int main()
{
	cin >> n >> p + 1 >> m >> s + 1;

	for (int i = 2, j = 0; i <= n; i++)         //��next��ne������  ne[1] = 0 �������ʱ��i��2��ʼj��0
	{
		while (j && p[i] != p[j + 1])j = ne[j];                //   ע���ж��������и�  j&&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		if (p[i] == p[j + 1])j++;
		ne[i] = j;
	}

	for (int i = 1, j = 0; i <= m; i++)
	{
		while (j && s[i] != p[j + 1])j = ne[j];          //   �� j û���˻ص�һ��ʼ�����ҳ��ֲ�ƥ�䡣һֱj = ne[j]ֱ���˻���㣬�����ƥ��
		if (s[i] == p[j + 1])j++;                        //   ƥ���ˣ�j++��i++
		if (j == n) // ƥ��ɹ�
		{
			cout << i - n << ' ';
			j = ne[j];                    //    ��������ƥ��
		}
	}

	return 0;
}
// ��չKMP�㷨��z����  

//  ����  #define int long long,, #define MAX 50000ǰ��Ĵ������Ķ���  ����Ҫע��  int main()�ĳ�  signed main()

#include<bits/stdc++.h>
#define int long long                    //ע�����������Ҫ��long long������ҪС�����������int���ͣ���С���ڼ������������������׷������ִ���ֱ��ȫ�����long long
using namespace std;

const int N = 20000010;
string a, b;
int z[N], p[N];

void get_z()
{
	z[0] = b.size();
	for (int i = 1, l, r = 0; i < b.size(); i++)       //  rȡֵ��֤�������һ��if���ȱ�����һ��,������if��r����ֵ
	{
		if (i <= r)z[i] = min(z[i - l], r - i + 1);  //   ע��  a��b���Ǵ��±�0��ʼ��zҲ�Ǵ�0��ʼ���Ͷ����㷨��һ��ʼ��һ���������˷�2Сʱ
		while (b[i + z[i]] == b[z[i]])z[i]++;
		if (i + z[i] - 1 > r)l = i, r = i + z[i] - 1;
	}
}

void get_p()
{
	for (int i = 0, l, r = -1; i < a.size(); i++)      //  rȡֵ��֤�������һ��if���ȱ�����һ��,������if��r����ֵ
	{
		if (i <= r)p[i] = min(z[i - l], r - i + 1);          //   ע��  a��b���Ǵ��±�0��ʼ��zҲ�Ǵ�0��ʼ���Ͷ����㷨��һ��ʼ��һ���������˷�2Сʱ
		while (i + p[i] < a.size() && p[i] < b.size() && b[p[i]] == a[i + p[i]])p[i]++;//ǰ�������������±겻Խ��
		if (i + p[i] - 1 > r)l = i, r = i + p[i] - 1;
	}
}

signed main()
{
	cin.tie(0);
	cin >> a >> b;

	get_z();
	get_p();

	int ans = 0;
	for (int i = 1; i <= b.size(); i++)
		ans ^= i * (z[i - 1] + 1);
	cout << ans << endl;
	ans = 0;
	for (int i = 1; i <= a.size(); i++)
		ans ^= i * (p[i - 1] + 1);
	cout << ans;

	return 0;
}