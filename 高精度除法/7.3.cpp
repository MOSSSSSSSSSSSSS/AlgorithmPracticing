

//�߾��ȳ����������λ��ʼ�㣬Ҳ�������������һ������ʼ��
//һ������£���Ŀ�Ӽ��˳���ϣ����Գ���Ҳ�õ��Ŵ洢�ķ�ʽ
//���Ҫ��123��4���1234,�Ϳ���123*10+4
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> div(vector<int>& A, int b, int& r)
{
	vector<int> C;
	r = 0;
	for (int i = A.size() - 1; i >= 0; i--)
	{
		r = r * 10 + A[i];
		C.push_back(r / b);
		r %= b;//����˳�ѭ��ʱ��r�������յ�����
	}
	reverse(C.begin(), C.end());//�������������Ҫ��C����ת������reverse��Ҫͷ�ļ�algorithm��C.begin(),C.end()
	while (C.size() > 1 && C.back() == 0)C.pop_back();//��Ϊ����120��11�����ȿ�1��11����0��������ǰ���и�û�õ�0����ת��ȥ������ٰ�����0���ӵ�

	return C;
}

int main()
{
	string a;
	int b,r;//r�������������ĺ���Ҫ�����̺�����
	vector<int> A, C;
	cin >> a >> b;
	for (int i = a.size() - 1; i >= 0; i--)A.push_back(a[i] - '0');

	C = div(A,b,r);
	for (int i = C.size() - 1; i >= 0; i--)printf("%d", C[i]);
	cout << endl << r;

	return 0;
}