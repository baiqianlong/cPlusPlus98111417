#include<iostream>
#include<cstdlib>
#include <functional>
using namespace std;

class CT
{
public:
	int i;
	int  j;
};


int testFunction()
{
	return 10;
}

const int&&myfunctionTest(void)
{
	return 0;
}
int main(void)
{
	//1.1decltype���Բ�����Ǹ�����
	const int i = 0;
	const int&reference01 = i;
	auto number01 = i;//number01=int ��ֵ��ʽ�ƶϣ��������Ժ�const���Զ��ᱻ����
	decltype(i) number02 = 23;//number02=const int���͡���i��ʲô���ͣ�number02����ʲô����
	//���decltype�Ǹ�������������е�const���Ի᷵�ء�
	decltype(reference01) number03 = number02;//const���Ժ��������Զ��ᱣ��   int const&����
	//������
	decltype(CT::i) number04;//number04=int
	CT temCT;
	decltype(temCT) temCT02;//temCT02=CT����
	decltype(temCT02.j)number05;//number05=int

	auto &&number06 = i;//��������  --auto =int,number06=int&
	decltype(number06) && number07 = i;//�����õ������۵����۵�������ֵ�� int &number07=i;
	
	//1.2decltype���Բ�����Ǹ����Ǹ����������ʽ�����ر��ʽ�����Ӧ����
	decltype(34)number08 = 5;//number08=5;

	int j = 0;
	int*p1 = &j;
	int&reference02 = j;
	decltype(reference02 + 1)number09 = 454;//j=int ()�������α��ʽ
	decltype(p1)p2=&j;//p2=int*����
	*p2 = 43;
	decltype(*p2) number10 = j;
	/*
	 *number10=int&����
	 **p2ָ��p2��ָ����ڴ�ռ䣬�����ܹ����ڴ�ռ丳ֵ�������Ǹ���ֵ
	 **p2�Ǹ����ʽ�����Ǹ�������������ʽ�Ľ������Ϊ��ֵ�����ߵ�ֵ����ôdecltype�󷵻صľ��Ǹ����á�
	 *ר�żǣ�
	 *decltype����Ǹ��Ǳ������ʽ�����ұ��ʽ�ܹ���Ϊ�Ⱥ���ߵ����ݣ����صľ���һ������int&�����á�
	 */
	//�ڱ�������������һ�����ţ���������ѱ�������һ�����ʽ
	decltype((i))reference03 = j;//���ս���Ǹ�����
	//���ۣ�decltype((����))�Ľ����Զ�Ǹ�����

	//1.3decltype���Բ�����Ǹ�����
	decltype(testFunction())temv = 14;//temv�Ǻ����ķ���ֵ���ͣ����ǲ����������ú���
	decltype(testFunction)temv2;//����()���ص���int(void),��һ���ɵ��ú�������

	function<decltype(testFunction)> func01 = testFunction;//����һ��function�����������ͣ�����һ���ɵ��ö���  int(void)
	cout << func01() << endl;//10

	decltype(myfunctionTest()) myreturn = 0;//const int&&���� ��������ֵ

	


	
	system("pause");
	return 0;
}
/*
* (1)decltype����;����������Ƶ�����
*	1 decltype���ڸ����ı��������߱��ʽ��decltype�ܹ�����������ֻ��߱��ʽ������
*		�ӱ��ʽ�������ƶϳ�Ҫ����ı������ͣ����Ҳ����ʼ������--ʹ��decltype
*		decltype˵��������Ҫ���ã����ز���������������
*
*		decltype���ص㣺
*			1.decltype���Զ������ƶϻᷢ���ڱ����ڼ�
*			2.decltype��������������ʽ��ֵ
*	1.1decltype���Բ�����Ǹ�����
*	1.2decltype���Բ�����Ǹ����Ǹ����������ʽ�����ر��ʽ�����Ӧ����
*	1.3decltype���Բ�����Ǹ�����--����ֵ�Ǻ�������ֵ����
* declare����
* (2)
* (3)
* (4)
* (5)
* (6)(7)
*/