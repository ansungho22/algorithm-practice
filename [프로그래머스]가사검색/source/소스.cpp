#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool comp(const string& a, const string& b) {
    if (a.length() < b.length())
        return true;
    else if (a.length() == b.length())
        if (a < b) return true;
    return false;
}
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    vector<string> rwords(words);
    for (int i = 0; i < rwords.size(); i++)
        reverse(rwords[i].begin(), rwords[i].end());

    sort(words.begin(), words.end(), comp);
    sort(rwords.begin(), rwords.end(), comp);
    for (string query : queries) {
        if (query[0] != '?') { // 접두사 
            string start(query);
            for (int i = 0; i < start.length(); ++i)
                if (start[i] == '?') // ?를 모두 a 로 바꾸기 
                    start[i] = 'a';
            auto start_ptr = lower_bound(words.begin(), words.end(), start, comp); // fraaa 하한선 위치. 비교 함수를 적용하여 같은 길이 내에서 하한선을 찾도록 한다
            string end(query);
            for (int i = 0; i < end.length(); ++i)
                if (end[i] == '?') // ?를 모두 z 로 바꾸기 
                    end[i] = 'z';
            auto end_ptr = upper_bound(words.begin(), words.end(), end, comp); // frzzz 상한선 위치. 비교 함수를 적용하여 같은 길이 내에서 상한선을 찾도록 한다
            answer.push_back(end_ptr - start_ptr);
        }
        else {  // 접미사
            reverse(query.begin(), query.end()); // 쿼리문도 뒤집기! 뒤집고 나서 접두사 구하듯이 구하면 된다.
            string start(query);
            for (int i = 0; i < start.length(); ++i)
                if (start[i] == '?')
                    start[i] = 'a';
            auto start_ptr = lower_bound(rwords.begin(), rwords.end(), start, comp);

            string end(query);
            for (int i = 0; i < end.length(); ++i)
                if (end[i] == '?')
                    end[i] = 'z';
            auto end_ptr = upper_bound(rwords.begin(), rwords.end(), end, comp);

            answer.push_back(end_ptr - start_ptr);
        }
    }

    return answer;
}