#include<iostream>
#include<cstdlib>
#include <functional>

using namespace std;

//��ͨ�����ɵ��ö���
void myFunciton(int value)
{
	cout << "myFunciton����ִ����" << endl;
}

class TC
{
public:
	void operator()(int value)
	{
		cout << "��������������()������ĺ���ִ����" << endl;
	}
	void myfunction02(int value)
	{
		cout << "testclass ���е�myfunction02����ִ����" << endl;
	}

	static int stcfunc(int t)
	{
		cout << "��tc�еľ�̬����ִ��" << endl;
		return t;
	}
public:
	int m_a=0;
};

//1.3�ɱ�ת��Ϊ����ָ��������_�º���_��������
class testclass02
{
public:
	using tfpoint = void(*)(int);
	static void myStaticFunction(int value)//��̬��Ա����ִ����
	{
		cout << "testclass02��̬��Ա����ִ����" << endl;
	}
	operator tfpoint()//����ת������
	{
		return myStaticFunction;//���ص���һ����̬����ָ������
	}
};
int main(void)
{
	//1.1����ͨ����
	std::function<void(int)> f1 = myFunciton;
	f1(123);
	
	//1.2�����еľ�̬��Ա����
	std::function<int(int)>f2 = TC::stcfunc;
	cout << f2(234) << endl;

	//1.3�󶨷º���
	TC tc03;
	std::function<void(int)>f3 = tc03;//���еĳ�Ա����Ҫ��ʼ��
	f3(23);


	testclass02 tc02;
	std::function<void(int)>f4 = tc02;
	f4(23);
	system("pause");
	return 0;
}
/*
* (1)function()�ɵ��ö����װ��
*����ܰѸ��ֿɵ��ö���ͳһһ�£�ʹ��ͬһ�ַ������ã�����
*std::function()�ɵ��ö����װ��
*c++11��������±�׼��std::function��һ����ģ�壬����װ���ֿɵ��ö���(����װ���Ա����ָ�룬��Ϊ��Ҫ��������)
*
*std::function��ģ����ص㣺����ͨ������ָ��ģ������������ܹ���ͳһ�ķ�ʽ����������
*	1.����ͨ����
*	1.2����ľ�̬��Ա����
*	1.3�󶨷º���
*
*
*/