#include <iostream>
//using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define delimiter "----------------------------------------------------------------"
#define tab "\t"

void hello()
{
	cout << "Hello" << endl;
}
int sum(int a, int b)
{
	return a + b;
}

void main()
{
	setlocale(LC_ALL, "");
	void (*p_hello)() = hello;				//void* - void pointer (��������� �� void, 
											//		  ����� ������� ����� ��������� ������ ����)
	//��� ������������� void pointer ����������� ����� ��������������� ��� � ������� ���.
	p_hello();
	int (*p_sum)(int, int) { sum };			// = sum, ��� {sum}
	//cout << p_sum(2, 3) << endl;
	cout << (*p_sum)(2, 3) << endl;
	cout << sum << endl;
}