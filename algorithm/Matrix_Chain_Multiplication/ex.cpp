#include <iostream>
#include <algorithm>
using namespace std;
int** M;
int** P;
void minmult(int n,int* d)
{
	for (int diagonal = 1;  diagonal <= n-1; diagonal++)
	{
		for (int i = 1; i <= n - diagonal; i++)
		{
			int j = i + diagonal;
			for (int k = i; k <= j - 1; k++)
			{
				if (M[i][j] == 1)
				{
					M[i][j] = M[i][k] + M[k+1][j] + d[i - 1] * d[k] * d[j];
					P[i][j] = k;
				}
				else if (M[i][j] > M[i][k] + M[k+1][j] + d[i - 1] * d[k] * d[j])
				{
					M[i][j] = M[i][k] + M[k+1][j] + d[i - 1] * d[k] * d[j];
					P[i][j] = k;
				}
			}
			
		}
	}
}
void order(int i, int j)
{
	if (i == j)
		cout << "A" << i;
	else
	{
		int k = P[i][j];
		cout << "(";
		order(i, k);
		order(k + 1, j);
		cout << ")";
	}
}
int main() {
	int n = 0;
	int j = 0;
	int* d;
	cout << "행렬의 갯수를 입력해주세요: ";
	cin >> n;
	
	d = new int[n+1];
	
	cout << "첫번째 행렬의 행과 열을 입력해주세요:";
	cin >> d[0] >> d[1];
	
	for (int i = 2; i < n+1; i++)
	{
		cout << i << "번째 행렬의 열을 입력해주세요:";
		cin >> d[i];
	}
	
	M = new int* [n+1];
	P = new int* [n+1];
	for (size_t i = 0; i <= n+1; i++)
	{
		M[i] = new int[n];
		P[i] = new int[n];
	}
	
	for (int i = 0; i <= n+1; i++)
	{
		for (int j = 0; j <= n+1; j++)
		{
			M[i][i] = 0;
			P[i][i] = 0;
			if (i > j)
			{
				M[i][j] = 0;
				P[i][j] = 0;
			}
			else
			{
				M[i][j] = 1;
			}
		}
	}
	

	minmult(n,d);
	for (int i = 1; i <= n; i++)
	{
		cout << endl<<endl;
		for (int j = 1; j <= n; j++)
		{
			cout << M[i][j]<<"\t";
		}
	}
	cout << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << endl << endl;
		for (int j = 1; j <= n; j++)
		{
			cout << P[i][j] << "\t";
		}
	}
	cout << endl << endl;
	order(1, 5);
}