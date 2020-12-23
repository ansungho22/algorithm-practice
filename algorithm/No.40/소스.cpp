// TopCoder 회사 조직과 급여
#include<iostream>
#include<vector>
#include <string>
using namespace std;
int check[51] = { 0, };
void dp(vector<string> relations) {
	int NumOfPeople = relations.size();
	for (int i = 0; i < NumOfPeople; i++){
		if (relations[i].find("Y") == string::npos) check[i] = 1;
	}
	for (int i = 0; i < NumOfPeople; i++)
	{
		if (check[i] == 0) {
			for (int i = 0; i < relations[i].length; i++)
			{
				
			}
		}
	}

}
int main() {
	vector<string> relations = { "NNYN","NNYN","NNNN","NYYN" };
	dp(relations);
}