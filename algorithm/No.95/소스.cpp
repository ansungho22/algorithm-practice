#include <string>
#include <vector>
#include<sstream>
#include<iostream>
#include <algorithm>
using namespace std;

bool compare(vector<string> a, vector<string>b) {
	return stoi(a[4]) < stoi(b[4]);
}
int compare_str(vector<string> TargetStr, vector<vector<string>> CompareList, int order) {
	vector<vector<string>> temp;
	if (order == 5)return CompareList.size();
	if (TargetStr[order] == "-") return compare_str(TargetStr, CompareList, order + 1);
	for (auto CompareStr : CompareList) {
		if (order == 4) {
			if (stoi(TargetStr[order]) <= stoi(CompareStr[order])) temp.push_back(CompareStr);
			continue;
		}
		if (CompareStr[order] == TargetStr[order]) temp.push_back(CompareStr);
	}
	return compare_str(TargetStr, temp, order + 1);
}
vector<vector<string>> Binary(vector<vector<string>> split_info, int start, int end, int key) {

	int mid = (start + end) / 2;
	if (start < 0 || end > split_info.size() - 1)return split_info;
	if (stoi(split_info[mid][4]) == key) {
		if (stoi(split_info[mid][4]) == stoi(split_info[mid - 1][4])) {
			return Binary(split_info, start, mid - 1, key);
		}
		else {
			vector<vector<string>> return_info;
			for (int i = mid; i < split_info.size(); i++)
			{
				return_info.push_back(split_info[i]);
			}
			return return_info;
		}
	}
	else if (stoi(split_info[mid][4]) > key) {
		return Binary(split_info, start, mid - 1, key);

	}
	else {
		return Binary(split_info, mid + 1, end, key);
	}
}
vector<vector<string>> Split_str(vector<string> VectorString) {
	vector<vector<string>> Return_list;
	for (auto str : VectorString) {
		istringstream strStream(str);
		string stringBuffer;
		vector<string> temp;
		while (getline(strStream, stringBuffer, ' ')) {
			if (stringBuffer == "and")continue;
			temp.push_back(stringBuffer);
		}
		Return_list.push_back(temp);
	}
	return Return_list;
}
vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	vector<vector<string>> split_info = Split_str(info);
	vector<vector<string>> split_query = Split_str(query);
	vector<vector<string>> reduce_info;
	sort(split_info.begin(), split_info.end(), compare);

	for (auto Target_list : split_query) {
		if(Target_list[4]!="-" && (split_query.begin()[4] != split_query.end()[4]))reduce_info = Binary(split_info, 0, split_info.size(), stoi(Target_list[4]));
		answer.push_back(compare_str(Target_list, reduce_info, 0));
	}
	return answer;
}

