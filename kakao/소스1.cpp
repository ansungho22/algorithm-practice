//#include <string>
//#include <vector>
//#include <iostream>
//#include <cmath>
//using namespace std;
//string convertion(int num, int notation) {
//	string res = "";
//	int mok = num;
//	int nmg = 0;
//
//	while (mok >= notation) {
//		nmg = mok % notation;
//		mok /= notation;
//		if (notation > 10 && nmg >= 10) {
//			res = (char)(nmg + 55) + res;
//		}
//		else {
//			res = to_string(nmg) + res;
//		}
//	}
//	if (notation > 10 && mok >= 10) {
//		res = (char)(mok + 55) + res;
//	}
//	else {
//		res = to_string(mok) + res;
//	}
//	return res;
//}
//bool sosu(long num) {
//	if (num < 2) return false;
//	long a = (long)sqrt(num);
//	for (long i = 2; i <= a; i++) if (num % i == 0) return false;
//	return true;
//}
//int solution(int n, int k) {
//	int answer = 0;
//	string str = "";
//	string num = convertion(n, k);
//
//	for (auto c : num) {
//		if (c == '0') {
//			if (str != "")
//				if (sosu(stol(str))) answer++;
//			str = "";
//		}
//		if (c != '0')str += c;
//	}
//	if (str != "")if (sosu(stol(str))) answer++;
//
//	return answer;
//}
//int main() {
//	int n = 437674;
//	int k = 3;
//	cout << solution(n, k);
//
//}