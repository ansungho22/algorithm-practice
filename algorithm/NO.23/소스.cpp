//NHN 2020신입채용 코테
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int arr[10][10];
int ans = 0;
int cnt;
void search(int x, int y) {
    if (arr[x][y] == 1) {
        cnt++;
        arr[x][y] = 0;
        search(x + 1, y);
        search(x, y + 1);
        search(x - 1, y);
        search(x , y-1);
    }
}

void dfs(int n, int x, int y) {
    vector<int> v;
    for (int i = 0; i < n; i++){
        for (int j = 0; j  < n; j ++){
            if (arr[i][j] == 1) {
                search(i, j);
                ans++;
                v.push_back(cnt);
                cnt = 0;
            }
        }
    }
    sort(v.begin(), v.end());
    cout << ans << endl;
    for(auto i:v)
    {
        cout << i<<" ";
    }
}
int main() {
    int n;
    string str;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < n; j++) {
            arr[i][j] = str[j] - '0';
        }
    }
    dfs(n, 0, 0);
    return 0;
}