

//C++��һ��ǿ�������ԣ������޷�������̬���ԣ�python javascript�������ӣ���дһ��ͨ�õ��߼������԰��������͵ı�������ȥ����
//���ͱ���ֲ������ȱ�㣬ͨ����ͨ���߼����Ϊģ�壬���������͵����ƣ��ṩ�˼̳л����������һ�ֳ�����ƣ�����������˴���Ŀ������ԡ�

//��ͨ����ģ�壺
/*#include<bits/stdc++.h>
using namespace std;
template <typename T>    // û�ֺ�
int Compare(const T a, const T b)
{
	if (a > b)
		return -1;
	else
		return 1;
}

int main()
{
	cout<<Compare<int>(1, 2);
	return 0;
}*/
//������ͨ�������Զ���Ϊģ�壬��ĳ�Ա����Ҳ���Զ���Ϊģ��:
/*#include<bits/stdc++.h>
using namespace std;

class liu {
public:
	template<typename T>
	void print(T t)
	{
		cout << t << endl;
	}
};

int main()
{
	liu l;
	l.print<int>(5);
	l.print<string>("abc");
	l.print<const char*>("abc");    //  char *  ����
	//ʵ���ƶ�:�ñ������Լ��ƶ���ʲô����:
	l.print("abc");
	l.print(2.0);

	return 0;
}*/

//  ���ж��  typename T1, typename T2, typename T3ʱ���ں�������дsum<long>��longָ�����ǵ�һ�����Ǵ�������ָ����
//sum_alternative<long,int,long> ���� T1��long��T2��int��T3��long
/*template<typename T1, typename T2, typename T3>
T1 sum(T2 v2, T3 v3) {
  return static_cast<T1>(v2 + v3);
}

auto ret = sum<long>(1L, 23); //ָ��T1, T2��T3���ɱ��������ƶ�

template<typename T1, typename T2, typename T3>
T3 sum_alternative(T1 v1, T2 v2) {
  return static_cast<T1>(v1 + v2);
}
auto ret = sum_alternative<long>(1L, 23); //error��ֻ�ܴ���������һָ��
auto ret = sum_alternative<long,int,long>(1L,23); //ok, ˭��������һ��T3��Ϊ�������͵��أ�
*/

//����ģ��Ϊinline�����Ч�ʣ�inline ����template�󣬷�������ǰ
//template<typename T> inline int Compare(const T a,const T b)

//  ��ģ�壺
#include<bits/stdc++.h>
using namespace std;
template<class Type> class liu {
public:
	bool empty()const//�Ѷ����const�ĳ�Ա������һ����ͼ�޸����ݳ�Ա��ֵ�����������������
	{
		;
	}
	bool lalala()const;
};

int main()
{
	liu<int> l;

}


template<typename T> T sum()
{

}