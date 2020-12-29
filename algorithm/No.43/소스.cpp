#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
// 테스트통과 효율성 x
int* solution(int prices[], size_t prices_len) {
	int* answer = (int*)malloc(sizeof(int) * prices_len);
	bool check[100000] = { false, };
	for (int i = 0; i < prices_len; i++)
	{
		answer[i] = 0;
		check[i] = true;
		for (int j = 0; j < i; j++)
		{
			if (check[j] == true ) {
				answer[j]++;
			}
			if (prices[j] > prices[i]) check[j] = false;
		}
	}
	return answer;
}

int main() {
	int prices[] = {1, 2, 3, 2, 3};
	size_t prices_len = sizeof(prices) / sizeof(prices[0]);
	int* ans = solution(prices, prices_len);
}