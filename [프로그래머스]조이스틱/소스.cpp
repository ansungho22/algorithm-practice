//¡∂¿ÃΩ∫∆Ω
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int cnt_alpha(char alph) {
    if (alph <= 'N')return alph - 'A';
    else return 'Z' - alph + 1;
}

int solution(string name) {
    int answer = 0;
    int size = name.size();
    int right_point=0, left_point=0, cur_point = 0;
    string ans(name.size(), 'A');
    while (ans != name) {
        answer += cnt_alpha(name[cur_point]);
        name[cur_point] = 'A';
        if (name == ans)break;
        for (int i = 1; i <= size/2; i++)
        {
            right_point = cur_point + i;
            left_point = cur_point - i;
            if (right_point >= size)right_point -= size;
            if (left_point < 0)left_point += size;
            if (name[right_point] != 'A') {
                answer += i;
                cur_point = right_point;
                break;
            }
            else if (name[left_point] != 'A') {
                answer += i;
                cur_point = left_point;
                break;
            }

        }
    }
    return answer;
}
int main() {
    string name = "JBCAAAAAAZA";
    vector<int> v;
    for (int i = 0; i < name.length(); i++)
    {
        int x = name[i] - 'A';
        v.push_back(x);
    }
    for(auto i : v)
    {
        cout << i << " ";
    }
}