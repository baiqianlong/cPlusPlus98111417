#include<iostream>
#include<cstdlib>

using namespace std;
class A
{
public:
	A()
	{
		cout << "ִ��A�Ĺ��캯��" << endl;
	}
	~A()
	{
		cout << "ִ��A����������" << endl;
	}
	int myFunction()
	{
		cout << "ָ��A��myFunction����" << endl;
		return 0;
	}
};

int main(void)
{
	A().myFunction();//����һ����ʱ���󣬵�����ʱ����ĺ���

	(const A()).myFunction();//ok,����resharp����ʾ����

	decltype(A().myFunction()) number01;//number01��������int����
	//û�й������ʱ����Ҳû���������ù�����
	/*
	 * ִ��A�Ĺ��캯��
		ָ��A��myFunction����
		ִ��A����������
		ִ��A�Ĺ��캯��
		ָ��A��myFunction����
		ִ��A����������
	 */
	system("pause");
	return 0;
}
/*
* (1)ʹ������()���������ʱ����������еĳ�Ա����
* (2)
* (3)
* (4)
* (5)
* (6)(7)
*/