// 구름레벨 1등과 2등
#include <iostream>
using namespace std;
int main() {
	string str;
	int intInput[100];
	int start = 0, end,x;
	cin >> str;
	cout << "Hello Goorm! Your input is " << str << endl;
	int size = str.size();
	for (int i = 0; i < size; i++) {
		intInput[i] = str[i] - '0';
	}
	
	for (int i = 0; i < size; i++)
	{
		if (i == size-1) {
			cout << "NO";
			return 0;
		}
		if (intInput[i] <= 2 && intInput[i]+ intInput[i+1]==3) {
			for (int j = size; j >=0; j--){
				if (i + 1 == j - 1) break;
				if (intInput[j] == intInput[i] && intInput[j] + intInput[j - 1] == 3) {
					cout << "YES";
					return 0;
				}
			}
		}
	}
}