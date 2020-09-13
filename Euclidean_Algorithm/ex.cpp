#include <iostream>

using namespace std;

int GCD(int a, int b) 
{
	if (a < b) {     // a 가 b보다 크기가 작다면 위치를 바꾸어서 GCD공식에 편하게 위치를바꾼다
		int temp = a;
		a = b;
		b = temp;
	}
	if (b == 0)     // GCD공식에 의하여  GCD(A,B) == GCD(B,A&%B) == GCD(A%B , 0) 
		return a;
	else
		GCD(b, a % b);
}
int main()
{
	int a = NULL;
	int b = NULL;
	cout << "숫자를 입력해주세요 : ";
	cin >> a;
	
	cout << "숫자를 입력해주세요 : ";
	cin >> b;

	int n =  GCD(a, b);
	cout << "최대공약수는 " << n << " 입니다" << endl;
	cout << "최소공배수는 " << (a / n) * (b / n) * n << " 입니다" << endl;
}