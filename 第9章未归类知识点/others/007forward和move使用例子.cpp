#include<iostream>
#include<cstdlib>

using namespace std;


void printInformation(int&tem)//��������ֵ���õ��β�
{
	cout << "�β�����Ϊ��ֵ���õĺ���" << endl;
}
void printInformation(int&&tem)//��������ֵ���õ��β�
{
	cout << "�β�����Ϊ��ֵ���õĺ���" << endl;
}

template<typename T>
void testTransmit(T&&t)//��������
{
	printInformation(t);//���t����ֵ��T=int t=int&&���ͣ�t��������ֵ	���t����ֵ��T=int&,t=int&���ͣ�t��������ֵ
	printInformation(std::forward<T>(t));
	printInformation(std::move(t));//move����ֵת��Ϊ��ֵ
	
}

int main(void)
{
	testTransmit(1);//������ֵ
	/*
	 *  �β�����Ϊ��ֵ���õĺ���
		�β�����Ϊ��ֵ���õĺ���
		�β�����Ϊ��ֵ���õĺ���
	 */

	int i = 123;
	testTransmit(i);//������ֵ
	/*

	�β�����Ϊ��ֵ���õĺ���
	�β�����Ϊ��ֵ���õĺ���
	�β�����Ϊ��ֵ���õĺ���
	 */
	system("pause");
	return 0;
}
/*
 * (1)std::forward()С����
 * (2)
 * (3)
 * (4)
 * (5)
 * (6)(7)
 */