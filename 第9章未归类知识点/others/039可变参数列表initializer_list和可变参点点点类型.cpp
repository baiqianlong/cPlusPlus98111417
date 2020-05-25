#include<iostream>
#include<iostream>
#include<cstdlib>
#include<functional>
#include <vector>
#include <algorithm>
#include<initializer_list>
#include<stdarg.h>//...��ͷ�ļ�
using namespace std;

void printValue(initializer_list<int>temArr)
{
	for (auto beg=temArr.begin();beg!=temArr.end();beg++)
	{
		cout << *beg << endl;
	}
	cout << "temArr.size()="<<temArr.size() << endl;//�鿴�б��е�Ԫ�ظ�����
}


class CT
{
public:
	CT(const initializer_list<int>&temArray)
	{
		cout << "initializer_list�������캯���ĳ�ʼ���б�ĺ���ִ����" << endl;
	}
};

//ʡ�Ժ��β�(...)--������ɸ�double���ͱ�����ֵ
double sum01(int num,...)//�ɱ����...
{
	va_list valist01;//����һ��va_list���͵ı���
	double sum = 0;
	va_start(valist01, num);//ʹvalist01ָ����ʵ�Ĳ�����ȷ�����ڴ�ռ��λ��
	for(int i=0;i<num;i++)
	{
		//��������
		sum = sum + va_arg(valist01, int);//����2˵�����ص�����Ϊint
	}
	va_end(valist01);//�ͷ�valist01
	return sum;
	
}

//char*��ʡ�Ժ��β�...
void funcChar(const char*msg,...)//ͨ��msg�õ��ɱ��������
{
	va_list valist;//������i��va_list����
	int intmsg = atoi(msg);//��ȡ�ɱ��������
	va_start(valist, msg);//��
	int parmCount = 0;
	while (parmCount<intmsg)
	{
		char*p;//��������Ĳ��������ַ�����
		p = va_arg(valist, char*);
		printf("��%d���ַ���%s\n", parmCount, p);
		parmCount++;
	}
	va_end(valist);
	
}

int main(void)
{
	initializer_list<int>myArray;//���飬Ԫ��������int,���б�������
	initializer_list<int>myArray02 = { 1,2,3,4,4,5 };//int��������
	//ע��һ����ʼ����ϣ����ܸı䣬Ҳ����˵initializer_list�е�Ԫ����Զ�ǳ���ֵ�����ܱ��ı�

	//2.1begin() end()����,size()��ȡԪ�صĸ���
	printValue(myArray);//0
	printValue({ 1,2,3,4,4,5,56,6,6,67,7,7,2,7,7 });//����ֵ���У����������з���{}����Ϊһ�����崫��  15��Ԫ��
	//��ʵc++11��ʹ��{}�����ų�ʼ��{��ʼ���б�}��Ϊһ�ֱȽ�ͨ�õĳ�ʼ����ʽ�������ںܶ����͡�
	//
	//֧�ֵ�����������ʹ�÷���for�����б���
	for(auto&temItem:myArray02)//ʹ�����ò���ֵ����
	{
		cout << temItem << endl;
	}

	//2.2�����͸�ֵ
	initializer_list<string> myArray03 = { "aa","bbb","ccc" };
	initializer_list<string>myArray04(myArray03);//���ÿ�������
	initializer_list<string>myArray05;
	myArray05=myArray03;//���ÿ�������

	/*�ڴ��ַ��ȫ��ͬ
	 [ԭʼ��ͼ]={_First=0x0053fcb4 "aa" _Last=0x0053fd08 <��ȡ�ַ������ַ�ʱ����> }
	 [ԭʼ��ͼ]={_First=0x0053fcb4 "aa" _Last=0x0053fd08 <��ȡ�ַ������ַ�ʱ����> }
	 [ԭʼ��ͼ]={_First=0x0053fcb4 "aa" _Last=0x0053fd08 <��ȡ�ַ������ַ�ʱ����> }
	 */
	CT ct={ 12, 34, 34, 345, 54, 54, 5, 54, 5 };//��ʽ����ת��
	
	CT ct02{ 234,43,5,45,4,5,46,5 };//����=��������ʽ����ת��
	CT ct03 = CT({ 234,34,32,345,4 });


	//3ʡ�Ժ��β�(...)
	cout << sum01(4, 100, 200, 300, 400) << endl;//��һ������ָ���м�������

	printf("value=%d,value02=%d", 1, 2);
	/*f12���Կ�����
	 *
	 * _CRT_STDIO_INLINE int __CRTDECL printf(
    _In_z_ _Printf_format_string_ char const* const _Format,
    ...)
	 */

	funcChar("3","aaaa", "bbbb", "cccccc");
	system("pause");
	return 0;
}
/*
* (1)�ɱ�����б�
* �ܽ��ܷǹ̶����������ĺ������ǿɱ����������
* initializer_list��׼�����͡�ǰ�����������е�ʵ��������ͬ
* (2)initializer_list��ʼ���б�
* ʵ����������Ԥ֪���������в�����������ͬ�����ǿ���ʹ��initializer_list���͵��β������ܡ�
* initializer_list��c++�ṩ�������ͣ�Ҳ��һ����ģ�塣
* ����ĳ�����͵����飬�����ģ����ָ��������ģ�������������������汣������ݵ����͡�
*����ͷ�ļ�#include<initializer_list>
*
*	2.1begin() end()����,size()��ȡԪ�صĸ���
*	2.2�����͸�ֵ
*		�����͸�ֵһ��initializer_list���󣬲��´���б��е�Ԫ�ء�ԭ������Ϳ������߸�ֵ�����Ķ�������е�Ԫ���ڴ�ռ䡣
*
*	2.3��ʼ���б������캯������
* (3)ʡ�Ժ��β�(...)
* �����ʹ��ݸ�ʡ�Ժ��β�һ�������⣬һ����Դ���int ,char*�����͡�
* ����ʡ�Ժ���ʽ�Ŀɱ������������Ȼ����������ȷ�������Ǻ��������в����Ǵ洢���������Ե�ջ�ռ��еġ�
* ���Ҵ�...�Ŀɱ����������������Ҫ��һ����ͨ���������ǾͿ���ͨ�������ͨ������Ѱַ��
*
*�ܽ᣺1.������һ����Ч���βΣ�������ȫ��...
*2.  ...�β�ֻ�ܳ������β��б������һ��λ�ã�
*3.  ��һ��������������ͼ�飬...�еĲ�������������ͼ�顣
*4.  ...֮ǰ�Ķ��ſ���ʡ��void funcChar(const char*msg...)
*5.����ж����ͨ��������ôva_start(valist,msg),�ڶ������������...֮ǰ����һ��������
*6.�ɱ������int�����ַ������Ϳ��Ի����������������Զ��������Ϳ��ܲ�����������
*
*Ҫ���Լ�д��������Ҫ��...�ɱ�������ͣ��������Կ������ɡ�
*
* (4)shift+f11����ʱ���˳���ǰ����
* (5)
* (6)(7)
*/