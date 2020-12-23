// TopCoder 회사 조직과 급여
#include<iostream>
#include<vector>
#include <string>
using namespace std;
int check[51] = { 0, };
int dp(vector<string> relations, int sqe) {
	int ans = 0;
	if (check[sqe] == 0) {
		string str = relations[sqe];
		for (int i = 0; i < str.length(); i++){
			if (str[i] == 'Y') {
				ans += dp(relations, i);
			}
		}
		if (ans == 0)ans = 1;
		check[sqe] = ans;
	}
	return check[sqe];
}
int solution(vector<string> relations) {
	int ans = 0;
	for (int i = 0; i < relations.size(); i++){
		ans += dp(relations, i);
	}
	return ans;
}
int main() {
	vector<string> relations = { "NNYN","NNYN","NNNN","NYYN" };
	cout << solution(relations);
}