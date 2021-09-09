#include<algorithm>
#include<stdlib.h>
#include<iostream>
#include<queue>
using namespace std;


int main() {
	int N=0, K = 0;
	int seq=0;
	queue<int> josephus;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		josephus.push(i);
	}
	cout << "<";
	while(!josephus.empty())
	{
		for (int i = 0; i <K-1; i++)
		{
			josephus.push(josephus.front());
			josephus.pop();
		}
		cout << josephus.front()<<", ";
		josephus.pop();
	}
	cout << ">";

}