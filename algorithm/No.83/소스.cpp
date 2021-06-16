// 로또의 최고 순위와 최저 순위
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int rank_num(int num) {
	switch (num)
	{
		case 6:
			return 1;
		case 5:
			return 2;
		case 4:
			return 3;
		case 3:
			return 4;
		case 2:
			return 5;
		default:
			return 6;
		break;
	}
}
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	vector<int> answer;
	int highest_num = 0, lowest_num = 0, zero_num = 0;
	sort(lottos.begin(), lottos.end());
	for (int i = 0; i < lottos.size(); i++)
	{
		if (lottos[i] == 0)zero_num++;
		else {
			for (int j = 0; j < win_nums.size(); j++)
			{
				if (lottos[i] == win_nums[j]) {
					highest_num++;
					break;
				}
			}
		}
	}
	answer.push_back(rank_num(highest_num+zero_num));
	answer.push_back(rank_num(highest_num));

	return answer;
}