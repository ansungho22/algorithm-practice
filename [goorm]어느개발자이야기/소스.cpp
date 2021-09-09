//구름 어느개발자이야기
#include <iostream>
#include<math.h>
#include<string>
#include <typeinfo>
using namespace std;
int main() {
	string str;
	int ans = 1;
	int sum = 0;
	bool flag = true;
	cin >> str;
	while (1){
		sum = 0;
		for (int i = 0; i < str.size(); i++){
			sum += ((str[i] - '0') * pow(ans, str.size() - (i + 1)));
		}
		if (sqrt(sum) / 1 == (int)sqrt(sum)){
			for (int i = 0; i < str.size(); i++){
				if (ans > (str[i] - '0')){
					flag = true;
				}
				else{
					flag = false;
					break;
				}
			}
			if (flag == true)
			{
				cout << ans;
				return 0;
			}
		}
		ans++;
	}
	return 0;
}