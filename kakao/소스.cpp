//#include <string>
//#include <vector>
//#include <unordered_map>
//#include<sstream>
//#include<algorithm>
//#include <iostream>
//using namespace std;
//
//
//vector<int> solution(vector<string> id_list, vector<string> report, int k) {
//    vector<int> answer;
//    unordered_map<string, int>m1;
//    unordered_map<string, vector<string>>m2;
//    sort(report.begin(), report.end());
//    report.erase(unique(report.begin(), report.end()), report.end());
//    string temp1, temp2;
//    for (auto str : report) {
//        istringstream ss(str);
//        ss >> temp1 >> temp2;
//        m1[temp2]++;
//        m2[temp1].push_back(temp2);
//    }
//    for (auto name : id_list) {
//        int cnt = 0;
//        for (auto str : m2[name]) {
//            if (m1[str] >= k)cnt++;
//        }
//        answer.push_back(cnt);
//    }
//    
//    return answer;
//}
//
//int main() {
//    vector<string> id_list = { "muzi", "frodo", "apeach", "neo" };
//    vector<string> report = { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi","muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi","muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" };
//    int k = 2;
//    for (auto i : solution(id_list, report, k)) {
//        cout << i;
//    }
//}