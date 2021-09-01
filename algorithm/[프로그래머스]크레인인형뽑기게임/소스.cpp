// 프로그래머스 크레인 인형뽑기 게임(카카오)
#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int size = moves.size();
    vector<int> box;
    for (int crane : moves) {
        for (int i = 0; i < board.size(); i++) {
            if (board[i][crane-1] == 0)continue;
            if ( box.empty() == 0 && box.back() == board[i][crane-1]) {
                answer += 2;
                box.pop_back();
                board[i][crane-1] = 0;
                break;;
            }
            box.push_back(board[i][crane-1]);
            board[i][crane-1] = 0;
            break;
        }

    }
    return answer;
}

