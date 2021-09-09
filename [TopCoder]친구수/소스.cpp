#include<iostream>
#include<stdlib.h>
#include <vector>
#include<algorithm>

using namespace std;

int highestScore(vector<string> s) {
	int ans = 0;
	int n = s[0].length();

	for (int i = 0; i < n; i++)
	{
		int cnt = 0;

		for (int j = 0; j < n; j++)
		{
			if (i == j)  continue;

			if (s[i][j] == 'Y') cnt++;
			else
			{
				for (int k = 0; k < n; k++)
				{
					if (s[j][k] == 'Y' && s[k][i] == 'Y')
					{
						cnt++;
						break;
					}
				}
			}
		}
		ans = max(ans, cnt);
	}
	return ans;
}

int main() {
	vector<string> s = { "NYY","YNY","YYN"};
	cout << highestScore(s);
}
//테스트용 