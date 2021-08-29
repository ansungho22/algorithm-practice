//#include <string>
//#include <vector>
//#include<sstream>
//#include<iostream>
//#include <algorithm>
//using namespace std;
//
//vector<vector<string>> Split_str(vector<string> VectorString) {
//	vector<vector<string>> Return_list;
//	for (auto str : VectorString) {
//		istringstream strStream(str);
//		string stringBuffer;
//		vector<string> temp;
//		while (getline(strStream, stringBuffer, ' ')) {
//			if (stringBuffer == "and")continue;
//			temp.push_back(stringBuffer);
//		}
//		Return_list.push_back(temp);
//	}
//	return Return_list;
//}
//int Reduce_str(vector<string> info,vector<string> Target_list) {
//	int Return_cnt=0;
//	vector<string> temp;
//
//	for (auto str : info) {
//		Return_cnt = 0;
//		istringstream strStream(str);
//		string stringBuffer;
//		int index = 0;
//		while (getline(strStream, stringBuffer, ' ')) {
//			if (index == 4) { 
//				if (Target_list[index] == "-" ||stoi(Target_list[index]) <= stoi(stringBuffer)) {
//					Return_cnt++;
//				}
//			}
//			if (stringBuffer == Target_list[index] || Target_list[index] == "-") {
//				index++;
//				temp.push_back(stringBuffer);
//			}
//			else {
//				temp.clear();
//				break;
//			}
//		}
//	}
//	return Return_cnt;
//}
//vector<int> solution(vector<string> info, vector<string> query) {
//	vector<int> answer;
//	vector<vector<string>> split_query = Split_str(query);
//	vector<vector<string>> reduce_info;
//
//	for (auto Target_list : split_query) {
//		
//		answer.push_back(Reduce_str(info, Target_list));
//		
//	}
//	return answer;
//}
//int main()
//{
//	vector<string> info = { "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" };
//	vector<string> query = { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" };
//	for (auto i : solution(info, query)) {
//		cout << i;
//	}
//}
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include<iostream>
using namespace std;

const string ALL = "-";
unordered_map<string, vector<int>> map;

void insert(string* key, int mask, int point) {
	string s = "";
	for (int i = 0; i < 4; i++) {
		s += (mask & (1 << i)) ? ALL : key[i];
	}
	map[s].push_back(point);
}

vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	string key[4], tmp;
	int point;

	for (auto& inf : info) {
		istringstream iss(inf);
		iss >> key[0] >> key[1] >> key[2] >> key[3] >> point;
		for (int i = 0; i < 16; i++) insert(key, i, point);
	}

	for (auto& m : map) sort(m.second.begin(), m.second.end());

	for (auto& que : query) {
		istringstream iss(que);
		iss >> key[0] >> tmp >> key[1] >> tmp >> key[2] >> tmp >> key[3] >>
			point;
		string s = key[0] + key[1] + key[2] + key[3];
		vector<int>& v = map[s];
		answer.push_back(v.end() - lower_bound(v.begin(), v.end(), point));
	}

	return answer;
}
int main()
{
	vector<string> info = { "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" };
	vector<string> query = { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" };
	for (auto i : solution(info, query)) {
		cout << i;
	}
}