//±¸¸§¿¡µà È²Á¦ÀÇ ¸ô¶ô
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int main() {
	int N, K;
	queue<int> q;
	cin >> N >> K;
	for (int i = 1; i <= N; i++){
		q.push(i);
	}
	while (q.size()>2) {
		q.pop();
		for (int i = 1; i < K; i++)
		{
			q.push(q.front());
			q.pop();
		}
	}
	N = q.front();
	K = q.back();
	N < K ? cout << N << " " << K : cout << K << " " << N;


}