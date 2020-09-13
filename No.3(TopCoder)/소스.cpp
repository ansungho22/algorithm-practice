#include<iostream>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int main() {
	int numbers[] = { 1,3,2,1,1,3 };
	int ans = 1;
	sort(numbers,numbers+5);
	numbers[0] += 1;
	for (int i = 0; i < sizeof(numbers) / sizeof(int); i++) {
		ans *= numbers[i];
	}
	
	cout << ans;
}
