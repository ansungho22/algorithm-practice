#include <iostream>

using namespace std;

int GCD(int a, int b) 
{
	if (a < b) {     // a �� b���� ũ�Ⱑ �۴ٸ� ��ġ�� �ٲپ GCD���Ŀ� ���ϰ� ��ġ���ٲ۴�
		int temp = a;
		a = b;
		b = temp;
	}
	if (b == 0)     // GCD���Ŀ� ���Ͽ�  GCD(A,B) == GCD(B,A&%B) == GCD(A%B , 0) 
		return a;
	else
		GCD(b, a % b);
}
int main()
{
	int a = NULL;
	int b = NULL;
	cout << "���ڸ� �Է����ּ��� : ";
	cin >> a;
	
	cout << "���ڸ� �Է����ּ��� : ";
	cin >> b;

	int n =  GCD(a, b);
	cout << "�ִ������� " << n << " �Դϴ�" << endl;
	cout << "�ּҰ������ " << (a / n) * (b / n) * n << " �Դϴ�" << endl;
}