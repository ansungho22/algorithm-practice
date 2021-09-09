//³ª»ÛÀÌ¿ôÁý»ç¶÷µé topcoder
#include<iostream>
#include<vector>
using namespace std;
int maxDonations(vector<int> donations) {
	vector<int> dp1, dp2;
	dp1.resize(donations.size(),donations[0]);
	dp2.resize(donations.size(),donations[1]);
	dp2[0] = 0;
	for (int i = 2; i < donations.size() - 1; i++)
	{
		dp1[i] = max(donations[i] + dp1[i - 2], dp1[i - 1]);
	}
	for (int i = 2; i < donations.size() ; i++)
	{
		dp2[i] = max(donations[i] + dp2[i - 2], dp2[i - 1]);
	}
	return max(dp1[donations.size() - 2], dp2[donations.size() - 1]);
}
int main() {
	vector<int> v = { 1,2,3,4,5,1,2,3,4,5 };
	cout << maxDonations(v);
}