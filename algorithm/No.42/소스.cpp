//프로그래머스 도둑질
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> money) {
	vector <int> one;
	vector <int> two;
	int msize = money.size();
	one.resize(msize, money[0]);
	two.resize(msize, money[1]);
	two[0] = 0;
	
	for (int i = 2; i <= msize - 2; i++)
		one[i] = max(one[i - 2] + money[i], one[i - 1]);

	for (int i = 2; i <= msize - 1; i++)
		two[i] = max(two[i - 2] + money[i], two[i - 1]);


	return max(one[msize - 2], two[msize - 1]);
}
int main() {
	vector<int> money = { 2,3,4,5,6,7,8,9 };
	cout << solution(money);
}