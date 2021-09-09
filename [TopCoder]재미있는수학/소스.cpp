#include<iostream>
#include<stdlib.h>
#include<vector>

using namespace std;

int main() {
	vector<int> ans;
	int base = 4;
	for (int i = 2; i < base; i++)
	{
		if (((base - 1) % i) == 0) ans.push_back(i);
	}
}