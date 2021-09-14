//#include <string>
//#include <vector>
//#include<sstream>
//#include <unordered_map>
//#include <iostream>
//#include <cmath>
//#include <algorithm>
//#include <map>
//using namespace std;
//int cal(int basic_time, int basic_cost, int add_time, int add_cost, int time) {
//	if (time < basic_time) return basic_cost;
//	return basic_cost + (int)ceil((double)(time - basic_time) / (double)add_time) * add_cost;
//}
//vector<int> solution(vector<int> fees, vector<string> records) {
//	vector<int> answer;
//	string time, name, INorOUT;
//	int lasttime = 23 * 60 + 59;
//	unordered_map<string, int> m;
//	unordered_map<string, vector<int>> m2;
//	vector<string> v_name;
//	for (auto str : records) {
//		istringstream ss(str);
//		ss >> time >> name >> INorOUT;
//		v_name.push_back(name);
//		int hour = stoi(time.substr(0, 2)) * 60;
//		int minutes = stoi(time.substr(3, 2));
//		if (INorOUT == "IN") {
//			m[name] = hour + minutes;
//		}
//		if (INorOUT == "OUT") {
//			m2[name].push_back((hour + minutes) - m[name]);
//			m.erase(name);
//		}
//	}
//
//	for (auto i : m) {
//		m2[i.first].push_back(lasttime - i.second);
//	}
//	sort(v_name.begin(), v_name.end());
//	v_name.erase(unique(v_name.begin(), v_name.end()), v_name.end());
//	for (auto i : v_name) {
//		int all_time = 0;
//		for (auto time : m2[i]) {
//			all_time += time;
//		}
//		answer.push_back(cal(fees[0], fees[1], fees[2], fees[3], all_time));
//	}
//	return answer;
//}
//
//int main() {
//	vector<int> fees = { 180, 5000, 10, 600 };
//	vector<string> records = { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" };
//	for (auto i : solution(fees, records)) {
//		cout << i << endl;
//	}
//}
