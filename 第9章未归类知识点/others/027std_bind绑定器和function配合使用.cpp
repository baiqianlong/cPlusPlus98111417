#include<iostream>
#include<cstdlib>
#include <functional>

using namespace std;

class CT
{
public:
	void myFunction(int x, int y)//��ͨ��Ա����
	{
		cout << "x=" << x << endl;
		cout << "y=" << y << endl;
		m_a = x;
	}
	void operator()()
	{
		cout << "operator()����������" << endl;
	}
public:
	int m_a = 0;
	
};

void myCallBack(int cs,const std::function<void(int)>&f)
{
	f(cs);
}

void runFunc(int x)
{
	cout << "runFunc����ִ����" <<x<< endl;
}

int main(void)
{
	//(1)std::bind������function���ʹ��
	CT ct;
	std::function<void(int, int)> bf1 = std::bind(&CT::myFunction, &ct, std::placeholders::_1, std::placeholders::_2);
	bf1(10, 20);

	//(2)�ѳ�Ա������ַ������һ����
	std::function<int&()>bf2 = std::bind(&CT::m_a, &ct);//����ڶ�����������&���ã���������ο������캯��
	//��һ��������ct������һ����ʱ���󣬵ڶ�����std::bindҪ����һ��CT���Ͷ��󣬷��ص�CT���󿽱�����ʱ����std::bindִ����Ϻ���ʱ������ͷš�
	bf2() = 53;//ʵ���޸ĵ��ǳ�Ա������ֵ


	auto rt = std::bind(CT());//ִ�й��캯�����������죬��������
	/*
	 * CT()������ʱ���󣬵��ÿ������캯������һ����ʱ������Ϊstd::bind()�ķ��ض���
	 * bind���طº������Ͷ��󣬾��ǵ��ÿ������캯����������Ķ���
	 */

	auto bf4 = std::bind(runFunc, std::placeholders::_1);//����ʱ��ָ����һ������

	for (int i=0;i<10;i++)
	{
		myCallBack(i, bf4);//���õ�runFunc
		
	}
	
	system("pause");
	return 0;
}
/*
* (1)std::bind������function���ʹ��
* (2)�ѳ�Ա������ַ������һ���󶨣��󶨽������std::function<int&(void)>���棬˵���˾�����һ���ɵ��ö������ͱ��档
* (3)�ܽ᣺
*		bind˼�룬��ν���ӳٵ��ã����ɵ��ö����ʽͳһ��������������Ҫ��ʱ���ڵ��á�
*		������std::function��һ���ɵ��ö������ͳ�Ա���ܰ󶨣�std::bind��Ա��������Ա���������԰�
*	2019��12��11��12��22��
* 
* (4)
* (5)
* (6)(7)
*/