#include <string>
#include <vector>
#include <algorithm>
using namespace std;


vector<string> Stringsplit(string str) {
	vector<string> ReturnSplitString;
	string tmp = "";
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	for (int i = 0; i < str.length()-1; i++) {
		tmp = str.substr(i, 2);
		if (tmp[0] >= 'a' && tmp[0] <= 'z' && tmp[1] >= 'a' && tmp[1] <= 'z') {
			ReturnSplitString.push_back(tmp);
		}
	}
	return ReturnSplitString;
}

int Intersection(vector<string> s1, vector<string> s2) {
	int intersection = 0;
	if (s1.size() > s2.size()){
		for (int i = 0; i < s2.size(); i++){
			auto itr = find(s1.begin(), s1.end(), s2[i]);
			if (itr != s1.end()){
				intersection++;
				s1.erase(itr);
			}
		}
	}
	else{
		for (int i = 0; i < s1.size(); i++){
			auto itr = find(s2.begin(), s2.end(), s1[i]);
			if (itr != s2.end()){
				intersection++;
				s2.erase(itr);
			}
		}
	}
	return intersection;
}

int solution(string str1, string str2) {
	int IntIntersection = 0;
	int IntUnion = 0;
	vector<string> Splitstr1 = Stringsplit(str1);
	vector<string> Splitstr2 = Stringsplit(str2);
	if (Splitstr1.empty() && Splitstr2.empty()) {
		return 65536;
	}
	IntIntersection = Intersection(Splitstr1, Splitstr2);
	IntUnion = Splitstr1.size() + Splitstr2.size() - IntIntersection;
	if (IntUnion == 0) {
		return 65536;
	}
	double answer = (double)IntIntersection / (double)IntUnion * 65536;
	return answer;
}