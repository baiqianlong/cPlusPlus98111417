#include<iostream>
#include<cstdlib>
#include <functional>

using namespace std;

class CT
{
public:
	void myFunction(int x,int y)//��ͨ��Ա����
	{
		cout << "x=" << x << endl;
		cout << "y=" << y << endl;
		m_a = x;
	}
public:
	int m_a = 0;
};

int main(void)
{
	CT ct;
	auto bf1 = std::bind(&CT::myFunction, ct,std::placeholders::_1, std::placeholders::_2);
	bf1(1, 2);
	/*
	 * bind��ʹ�õڶ�������ct�ᵼ�µ���CT�Ŀ������캯��������һ��CT�Ŀ������캯������һ����ʱ������Ϊstd::bind()��
	 * ����ֵ���º������ͣ���������myFunction�����޸ĵ��������ʱ�����m_a��ֵ������Ӱ��ct���ֵ�ֵ��
	 * ����취��ctʹ�����ã��Ͳ���������ʱ���󣬻��޸�����ct��ֵ
	 * 
	 */
	auto bf2 = std::bind(&CT::myFunction, &ct, std::placeholders::_1, std::placeholders::_2);
	bf2(1, 2);

	system("pause");
	return 0;
}
/*
* (1)std::bind����_�󶨳�Ա����_�ڶ��������������
* 
* std::bind(���󶨵ĺ�������/����ָ��/��Ա����ָ�룬�󶨲���ֵ1��������ֵ2��������....)
* �ܽ᣺
*	1.���ɵ��ö���ɲ�������һ�𣬹���һ���º���������ֱ�ӵ���
*	2.��������ж������������ֻ��һ���֣����������ڵ���ʱ��ָ��
* (2)
* (3)
* (4)
* (5)
* (6)(7)
*/