//프로그래머스 키패드
#include <string>
#include <vector>

using namespace std;

typedef struct coord {
    int x;
    int y;
} Coord;

string solution(vector<int> numbers, string hand) {
    string answer = "";

    Coord left, right; // 왼손, 오른손 좌표 저장 
    left.y = 3; left.x = 0;
    right.y = 3; right.x = 2;

    for (int i = 0; i < numbers.size(); i++) {
        int num = numbers[i];

        if (num % 3 == 1) { // 왼손 사용: 1,4,7
            answer += "L";
            left.x = 0;
            if (num == 1) left.y = 0;
            else if (num == 4) left.y = 1;
            else left.y = 2;
        }
        else if (num % 3 == 0 && num != 0) { // 오른손 사용: 3,6,9
            answer += "R";
            right.x = 2;
            if (num == 3) right.y = 0;
            else if (num == 6) right.y = 1;
            else right.y = 2;
        }
        else { // 왼,오 사용: 2,5,8,0
            Coord tmp; tmp.x = 1;
            if (num == 2) tmp.y = 0;
            else if (num == 5) tmp.y = 1;
            else if (num == 8) tmp.y = 2;
            else tmp.y = 3;

            int leftDiff = abs(tmp.y - left.y) + abs(tmp.x - left.x);
            int rightDiff = abs(tmp.y - right.y) + abs(tmp.x - right.x);

            if (leftDiff < rightDiff) {
                answer += "L";
                left.y = tmp.y; left.x = tmp.x;
            }
            else if (leftDiff > rightDiff) {
                answer += "R";
                right.y = tmp.y; right.x = tmp.x;
            }
            else {
                if (hand == "left") {
                    answer += "L";
                    left.y = tmp.y; left.x = tmp.x;
                }
                else {
                    answer += "R";
                    right.y = tmp.y; right.x = tmp.x;
                }
            }
        }
    }
    return answer;
}