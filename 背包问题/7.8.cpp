

//c++���һ��1e7��1e8�μ�һ�ڴ����㣬1e9��10��
// 
//�������⣬����dp������dp��������dp����λͳ��dp��״̬ѹ��dp������dp�����仯����
// 
//�������⣬��һ������ΪV�ı�������N����Ʒ��ÿ����Ʒ�����Vi�ͼ�ֵ��Ȩ�أ�Wi        ʹ������װ���µ������ ��ֵ���        һ��˼·���ά��һά�Ż�
//01�������⣺ÿ����Ʒ ���ֻ����һ�Σ� ���Խ� 0 1��������
//��ȫ�������⣺ÿ����Ʒ �� ���� �������������޴�
//���ر������⣺ÿ����Ʒ �� ���ĸ��� �������� ���ĸ����� �������ذ� �� �Ż��棬�Ż����� ���ر��� ������Ż���ʽ
//���鱳�����⣺�ж�����Ʒ��ÿ��ֻ��ѡһ��

//***************************************************************************************************
//01��������
//״̬��ʾ��f��i��j����ʾ��ǰi����Ʒ��j��ʾ������ǰʣ��������f��i��j���洢����������ȡ������ ��ֵ���ֵ
//״̬ת�ƣ������ò��õ�i����Ʒ��f��i��j�� =max( f��i-1��j��, f��i-1��j-Vi�� + Wi  )
//һ��ʼ�Ƕ�ά�ģ���һά�Ż��ռ��С
#include<iostream>
using namespace std;

const int N = 1010;

int n, V;
int v[N], w[N];
int f[N][N];

int main()
{
	cin >> n >> V;
	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];//   �����1��ʼ����һ����Ʒ����n����Ʒ
	//��ʼ��״̬��i = 0�Ǵ洢ֵΪ0��j = 0�Ǵ洢ֵΪ0
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			if (j >= v[i])f[i][j] = max(f[i - 1][j],f[i - 1][j - v[i]] + w[i]);//ע��f��i-1��j-Vi���е�j-Vi��j�Ǵ�1��ʼ���п����Ǹ�����Ҫ���⣬�������
			//f(i,j)�����ֿ��ܣ��û��ã�Ҫѡ�� ��ֵ����
			else f[i][j] = f[i - 1][j];
		}
	}
	cout << f[n][V];

	return 0;
}
//***********************************************************************************************
//01�����Ż���������ÿһ��r��ʱ��ֻ�õ�r - 1����һ���ֵ��   ������ȥ��r���ά�ȣ��������ٴ���
//������󲢲��ǵȼ۵ģ���������״̬ת�Ʒ��̣������˵����ÿһ��i��ѭ���������������´������Ҹ�ֵ��
// ��Ϊf[j] = max(f[j], f[j - v[i]] + w[i])�����i���j�Ⱥ��ұ�f[j]��i-1��ģ�
//����j��С����ѭ����f[j - v[i]]�Ѿ��ǵ�i��ģ�����Ҫi-1��ģ������ٸĳ�j�Ӵ�Сѭ��
#include<iostream>
using namespace std;

const int N = 1010;

int n, V;
int v[N], w[N];
int f[N];

int main()
{
	cin >> n >> V;
	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
	for (int i = 1; i <= n; i++)
		for (int j = V; j >= v[i]; j--)
			f[j] = max(f[j], f[j - v[i]] + w[i]);
	cout << f[V];//��������ǵ�i = n�Ľ����ֻ�����������V��

	return 0;
}
/*#include<iostream>
using namespace std;

const int N = 1010;

int n, V;
int v[N], w[N];
int f[N];

int main()
{
	cin >> n >> V;
	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
	for (int i = 1; i <= n; i++)
		for (int j = v[i]; j <= V; j++)
		{
			f[j] = max(f[j], f[j - v[i]] + w[i]);
		}
	cout << f[V];

	return 0;
}*/
//*************************************************************************************************
//��ȫ��������
//���ؽⷨ :01���������ǿ���i���û��ü���0����1������ȫ���������ǿ���i������0����������1����������2����һֱ������װ���¡�
#include<iostream>
using namespace std;

const int N = 1010;

int n, V;
int v[N], w[N];
int f[N][N];

int main()
{
	cin >> n >> V;
	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= V; j++)
			for (int k = 0; k * v[i] <= j; k++)//j�ǵ�ǰ����������V
				f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + w[i] * k);//ȡ��������������ֵ
	cout << f[n][V];

	return 0;
}
//ʱ���Ż�
#include<iostream>
using namespace std;

const int N = 1010;

int n, V;
int v[N], w[N];
int f[N][N];

int main()
{
	cin >> n >> V;
	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= V; j++)
		{
			if (j >= v[i])
			{
				f[i][j] = max(f[i - 1][j], f[i][j - v[i]] + w[i]);//Ϊʲô�����Ż���������ʽ��д��f[i][j] = max(��0������1������������һֱ�������k��)���ʽ
				//��д����f[i][j- v[i]] = max(��0������1������������k-1������Ϊ����v[i]��)���Է��֣�f[i][j]������0���ģ�ʣ�µĶ���f[i][j-v]�Ⱥ��ұ߲�һ��w
				//����f[i][j-v]�����ֵ+w����  f[i][j]�Ⱥ��ұ�ʣ�µ����ֵ.��
			}
			else
			{
				f[i][j] = f[i - 1][j];
			}
		}
	cout << f[n][V];

	return 0;
}
//ʱ���Ż��Ļ����Ͽռ��Ż��������Ƶ�����״̬ת�Ʒ���ֻ�� 01������һ���𣬿ռ��Ż���ֻ�еڶ���ѭ����˳�����Ż����01������ͬ��
#include<iostream>
using namespace std;

const int N = 1010;

int n, V;
int v[N], w[N];
int f[N];

int main()
{
	cin >> n >> V;
	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
	for (int i = 1; i <= n; i++)
		for (int j = v[i]; j <= V; j++)
		{
			f[j] = max(f[j], f[j - v[i]] + w[i]);
		}
	cout << f[V];

	return 0;
}
//*************************************************************************************************
//���ر�������
//����
#include<iostream>
using namespace std;

const int N = 1010;

int n, V;
int v[N], w[N],s[N];//s�ǵ�n����Ʒ�ж��ٸ�
int f[N][N];

int main()
{
	cin >> n >> V;
	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i]>>s[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= V; j++)
			for (int k = 0; k * v[i] <= j&&k<=s[i]; k++)//����������һ��������Ҳ���У�k�����ܳ���s[i]��Ҳ�����õĳ�����������
				f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + w[i] * k);//ȡ��������������ֵ
	cout << f[n][V];

	return 0;
}
//���ط������Ӷ�O(N*V*S)�������s��
//ʱ���Ż� 
//���ȣ���k���㱳������������j����j-v���ܴ洢��k����ȫ���洢�ģ��ٴγ���ʹ����ȫ�����Ż��������ᷢ������f[i][j-v] = max(������������k����k-1)
//���f[i][j] = max()�����г���0����Ĳ��֣�����һ���֪����һ������е����ֵ�������Ƴ�ȥ�������һ�������е����ֵ�����������������k���㱳������������j����j-v���ܴ洢��k����ȫ���洢�ģ�
//����ĳһ��������������У������ٿ�k��������������ܰ� ��ȫ�����ķ����Ż�
//��Ҫʹ�ã������ƣ��������ķ���ת����01�����������Ż���
//����һ����Ʒ��s���������Էֳ������飬��һ��1�����ڶ���2����������4����������8��......ֱ��������2��n�����ٷ֣���ֱ�ӽ�ʣ����ٷ�һ��
//������Щ�飬ÿ��ѡ���û��ã��Ϳ��԰���0����s�������ȫ����������֤���ٶ�̬�滮һ�Ͽ�¼��1��28��16��
//������Щ�����һ������Ʒ����01����һ����Ҫôֻ��1����Ҫô����
//�����ַ����Ż���ʱ�临�Ӷ�O(N*log2s*V)��01������N*V��������N��ÿ���ֳ�log2s�飬һ��N*log2s�飬��1023ǡ�÷ֳ�10�飬1024�͵�11�����1023С��900Ҳ����10��2047Ҳ��11�飩
#include<iostream>
using namespace std;

const int N = 23000, M = 2010;//��������ж��ٸ��������*2000*   log2 2000�����11�����11000    ��11000���  11010���Զ� 

int n, m;
int v[N], w[N];
int f[M];//ֱ����һά����V������

int main()
{
	cin >> n >> m;
	int cnt = 1;//��Ҫ������forѭ�����棬cnt��ֵҪһֱ������
	for (int i = 1; i <= n; i++)
	{
		int a, b, s, k = 1;//count����,kһ����ٸ�,��Ҫ��v w s����������������������
		cin >> a >> b >> s;
		while (k <= s)
		{
			s -= k;
			v[cnt] = a * k;
			w[cnt] = b * k;
			cnt++;
			k *= 2;
		}
		if (s)
		{
			v[cnt] = a * s;
			w[cnt] = b * s;
			cnt++;             //Ϊ��һ������׼��
		}
	}

	n = cnt - 1;                //01���� n���ܹ�������Ʒ��ע��nҪ��

	for (int i = 1; i <= n; i++)
		for (int j = m; j >= v[i]; j--)
			f[j] = max(f[j], f[j - v[i]] + w[i]);

	cout << f[m];

	return 0;
}
//7.24��дһ��   ע��v�����w�Ǽ�ֵ
//���ر����������Ż������Ӷȣ�n*v*log2s
#include<bits/stdc++.h>
using namespace std;

const int N = 11000, M = 2010;

int n, m;
int a[N], b[N];
int f[N][M];

int main()
{
	cin >> n >> m;
	int cnt = 1;
	for (int i = 1; i <= n; i++)
	{
		int v, w, s,k = 1;
		cin >> v >> w >> s;
		while (s >= k)
		{
			s -= k;
			a[cnt] = k * v;
			b[cnt] = k * w;
			cnt++;
			k *= 2;
		}
		if (s)
		{
			a[cnt] = s * v;
			b[cnt] = s * w;
			cnt++;
		}
	}
	n = cnt - 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (j >= a[i])
			{
				f[i][j] = max(f[i - 1][j], f[i - 1][j - a[i]] + b[i]);
			}
			else
			{
				f[i][j] = f[i - 1][j];
			}
		}
	}

	cout << f[n][m];

	return 0;
}
//7.24  ���ر���  �ڶ����Ż���ʽ   �õ��������Ż�     ʱ�临�Ӷȱȶ������Ż���С  ��bilibili��Ƶ��  ����ȫ���

#include<bits/stdc++.h>
using namespace std;

const int M = 20010;

int n, m;
int f[M], g[M], q[M];//         ֱ����һά����g��¼f����һ�㣬��ΪҪ�õ�f����һ�㣬�����ֵ��������Ż�Ҫ��С����ö��

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int v, w, s;
		cin >> v >> w >> s;
		memcpy(g, f, sizeof(f));
		for (int j = 0; j < v; j++)
		{
			int hh = 0, tt = -1;
			for (int k = j; k <= m; k += v)
			{
				if (hh <= tt && q[hh] < k - s * v)hh++;
				if (hh <= tt)f[k] = max(g[k], g[q[hh] + (k - q[hh]) / v * w);
				while (hh <= tt && g[k] >= g[q[tt]] + (k - q[tt]) / v * w)tt--;
				q[++tt] = k;
			}
		}
	}

	cout << f[m];

	return 0;
}





//**********************************************************************************************************
//���鱳������
//״̬��ʾ����ǰi����ѡ������ʣ��������j��״̬ת�Ʒ��̣�f[i][j] = ��i��һ��Ҳ��ѡ����i��ѡ��1��.....��i��ѡ���һ��
//f[i][j] = max(f[i-1][j],f[i-1][j-v[i][1]]+w[i][1],f[i-1][j-v[i][2]]+w[i][2],f[i-1][j-v[i][s[i]]]+w[i][s[i]])
#include<bits/stdc++.h>
using namespace std;

const int N = 110;

int n, V;
int s[N], v[N][N], w[N][N];
int f[N][N];

int main()
{
	cin >> n >> V;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		for (int j = 1; j <= s[i]; j++)
			cin >> v[i][j] >> w[i][j];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			for (int k = 0; k <= s[i]; k++)
			{
				if (j >= v[i][k])
					f[i][j] = max(f[i][j], f[i - 1][j - v[i][k]] + w[i][k]);
				else
					f[i][j] = f[i - 1][j];
			}
		}
	}

	cout << f[n][V];

	return 0;
}
//�ռ��Ż�
#include<bits/stdc++.h>
using namespace std;

const int N = 110;

int n, V;
int S[N], v[N][N], w[N][N];
int f[N];        //������ֻ��r-1���йأ�ɾ����һά��

int main()
{
	cin >> n >> V;
	for (int i = 1; i <= n; i++)
	{
		cin >> S[i];
		for (int j = 1; j <= S[i]; j++)
			cin >> v[i][j] >> w[i][j];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = V; j >= 1; j--)       //ע��ĵ�ʱ��ѼӼӸĳɼ���
		{
			for (int k = 0; k <= S[i]; k++)
				if (j >= v[i][k])          //j�����ܸĳɴ�v[i][k]��ʼ������ж�Ҫ����
					f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
		}
	}

	cout << f[V];

	return 0;
}