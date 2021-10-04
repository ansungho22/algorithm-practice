#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<long long, long long> Room;

long long Find(long long N)
{
    if (Room[N] == 0) return N;
    return Room[N] = Find(Room[N]);
}

vector<long long> solution(long long k, vector<long long> room_number)
{
    vector<long long> answer;
    for (auto i : room_number) {
        long long Num = room_number[i];
        
        if (Room[Num] == 0)
        {
            answer.push_back(Num);
            Room[Num] = Find(Num + 1);
        }
        
        else
        {
            long long Next_Num = Find(Num);
            answer.push_back(Next_Num);
            Room[Next_Num] = Find(Next_Num + 1);
        }
    }

    return answer;
}



int main() {
    long long k = 10;
    vector<long long> room_number = { 1,1,1,1,1,1 };

    for (auto i : solution(k, room_number)) {
        cout << i;
    }
}