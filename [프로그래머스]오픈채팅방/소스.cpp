#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	map<string, string> MapIdAndName;
	vector<pair<string, string>> ActionAndId;
	for (string log : record) {
		string temp;
		istringstream strBuffer(log);
		vector<string> strVec;
		while (getline(strBuffer, temp, ' ')) {
			strVec.push_back(temp);
		}
		if (strVec[0] == "Change") {
			MapIdAndName[strVec[1]] = strVec[2];
		}
		else if (strVec[0] == "Enter") {
			if (MapIdAndName.find(strVec[1]) == MapIdAndName.end()) {
				MapIdAndName.insert(make_pair(strVec[1], strVec[2]));
			}
			else {
				MapIdAndName[strVec[1]] = strVec[2];
			}
			ActionAndId.push_back(make_pair(strVec[0], strVec[1]));
		}
		else if (strVec[0] == "Leave") {
			ActionAndId.push_back(make_pair(strVec[0], strVec[1]));
		}

	}
	for (auto i : ActionAndId) {
		if (i.first == "Enter") {
			answer.push_back(MapIdAndName[i.second] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
		}
		else if (i.first == "Leave") {
			answer.push_back(MapIdAndName[i.second] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
		}
	}
	return answer;
}
int main() {
	vector<string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };
	vector<string> answer = solution(record);
	for (auto i : answer) {
		cout << i << endl;
	}
}