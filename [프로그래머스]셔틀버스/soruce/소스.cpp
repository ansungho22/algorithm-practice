#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int time_to_int(string n) {
	string hour = n.substr(0, 2);
	string minute = n.substr(3, 2);
	return stoi(hour) * 60 + stoi(minute);
}
string int_to_time(int n) {
	string time = "";

	int int_hour = n / 60;
	int int_minute = n % 60;

	string str_hour = "";
	string str_minute = "";

	if (int_hour == 0) str_hour = "00";
	else if (int_hour < 10) str_hour = '0' + to_string(int_hour);
	else str_hour = to_string(int_hour);

	if (int_minute == 0) str_minute = "00";
	else if (int_minute < 10) str_minute = '0' + to_string(int_minute);
	else str_minute = to_string(int_minute);

	return str_hour + ':' + str_minute;
}
vector<int> bus_timetable(int n, int t) {
	vector<int> timetable;
	int time = 540;
	for (int i = 0; i < n; i++)
	{
		timetable.push_back(time);
		time += t;
	}
	return timetable;
}
vector<int> crew_timetable(vector<string> timetable) {
	vector<int> crewtimetable;
	for (auto time : timetable) {
		crewtimetable.push_back(time_to_int(time));
	}
	sort(crewtimetable.begin(), crewtimetable.end());
	return crewtimetable;
}
string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";
	int Shuttle_Time = 540;
	vector<int> crewTimetable = crew_timetable(timetable);
	int index = 0;
	for (int i = 1; i <= n; i++, Shuttle_Time = Shuttle_Time + t)
	{
		int cnt = 0;
		for (int j = index; j < crewTimetable.size(); j++ )
		{
			if (crewTimetable[j] <= Shuttle_Time) {
				index++;
				cnt++;
				if (cnt == m)break;
			}
		}
		if (i == n) {
			if (cnt == m)return int_to_time(crewTimetable[index - 1] - 1);
			else return int_to_time(Shuttle_Time);
		}
	}
}
int main() {
	int n = 2;
	int t = 10;
	int m = 2;
	vector<string> timetable = { "09:10", "09:09", "08:00" };
	cout << solution(n, t, m, timetable);
}