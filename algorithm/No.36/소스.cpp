//마법의 숫자
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> card =  { { 1,2,3,4,5,6,7,8 },
							  { 1,2,3,4,9,10,11,12 },
							  { 1,2,5,6,9,10,13,14 },
							  { 1,3,5,7,9,11,13,15 } };
vector<int> cnt(17);
class Number {
	char Check(vector<int> X, int number) {
		for (int x = 0; x < 8; x++)
		{
			if (X[x] == number)return 'Y';
		}
		return 'N';
	}
public:
	int theNumber(string answer) {
		for (int i = 1; i <= 16; i++)
		{
			if (Check(card[0], i) != answer[0])continue;
			if (Check(card[1], i) != answer[1])continue;
			if (Check(card[2], i) != answer[2])continue;
			if (Check(card[3], i) != answer[3])continue;
			return i;
		}
		return 0;
	}
};
int main() {
	string answer = "YYYY";
	Number num;
	cout << num.theNumber(answer);
}