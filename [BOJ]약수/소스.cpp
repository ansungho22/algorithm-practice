//탑코더 악수
#include<iostream>
#include<vector>
using namespace std;
void handsShaking(int n) { 
	vector<int> v(n/2+1); 
	v[0] = 1;
	for (int i = 1; i <= n/2; i++) 
	{
		v[i] = 0;
		for (int j = 0; j < i; j++)
		{
			v[i] += v[j] * v[i - j - 1];
		}
	}
	cout << v.back();
}
int main() {
	handsShaking(8);
}