#include<iostream>
#include<cstdlib>

using namespace std;

void myFunciton(int value)
{
	cout << "myFunciton����ִ����" << endl;
}

class TESTCLASS
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
public:
	int m_a;
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
	//1.1����ָ��
	void(*pMyFunc)(int) = myFunciton;//����һ������ָ�벢����ֵ
	pMyFunc(23);//ʹ�ú���ָ����ú���  �����һ���ɵ��ö���

	//1.2operator()
	TESTCLASS ts;
	ts.operator()(3);
	//�ȼ�������ĵ���
	ts(23);

	//1.3�ɱ�ת��Ϊ����ָ��������_�º���
	testclass02 tc2;
	tc2(40);//�ȵ���operator tfpoint,Ȼ����÷��صĺ���
	//�ȼ���
	tc2.operator testclass02::tfpoint()(40);

	//1.4���Ա����ָ��
	TESTCLASS tc03;
	void (TESTCLASS::*myfPoint)(int) = &TESTCLASS::myfunction02;//���Ա����ָ�붨���������ʼ��
	//��Ա����ָ�뱾�����е�ַ�ģ��������������
	(tc03.*myfPoint)(234);//���������*  ----Ҳ��һ���ɵ��ö���
	


	
	system("pause");
	return 0;
}
/*
* (1)�ɵ��ö���
*	������������()������������
*	1.1����ָ��
*	1.2����operator()��Ա�����������--������()������������
*		�º����Ķ��壺�º���funtor��������Ϊ�����ں����Ķ���(something that performs a function)
*		c++�зº�����ͨ������������()�����ʵ�ֵġ��º����ֱ���Ϊ��������function obeject��������ʹ�������ܵ��ࡣ
*	1.3�ɱ�ת��Ϊ����ָ��������_�º���_��������
*	1.4���Ա����ָ��
*�ܽ᣺
*	1.���пɵ��ö��󿴳�һ������
*	2.���Ƕ���ʹ��()��������������a�ǿɵ��ö�����ô���ǿ���ʹ��a(para,para...)����
*	
*/