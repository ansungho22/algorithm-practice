#include <iostream>
#include <algorithm>

using namespace std;
float** A;
int** R;

struct Node
{
	int key;
	Node* par;
	Node* left;
	Node* right;
	Node() : key(), par(NULL), left(NULL), right(NULL) {}

};
Node* tree(int i, int j)
{
	int k = R[i][j];
	if (k == 0) return NULL;
	else
	{
		Node* p = new Node();
		p->key = k;
		p->left = tree(i, k - 1);
		p->right = tree(k + 1, j);
		return p;
	}
}
float Sigma(int i, int j, float* p)
{
	float sum = 0;
	for (int a = i; a <= j; a++)
	{
		sum += p[a];
	}
	return sum;
}
void optsearchtree(int n, float* p)
{
	for (int diagonal = 1; diagonal <= n - 1; diagonal++)
	{
		for (int i = 1; i <= n - diagonal; i++)
		{
			int j = i + diagonal;
			for (int k = i; k <= j; k++)
			{
				if (A[i][j] == 1)
				{
					A[i][j] = A[i][k - 1] + A[k + 1][j];
					R[i][j] = k;
				}
				else if (A[i][j] > A[i][k-1] + A[k + 1][j])
				{
					A[i][j] = A[i][k - 1] + A[k + 1][j];
					R[i][j] = k;
				}
			}
			A[i][j] += Sigma(i, j, p);

		}
	}
}

int main() 
{
	int n = 0;
	int j = 0;
	float* p;
	cout << "key의 갯수 입력:  ";
	cin >> n;

	p = new float[n + 1];



	for (int i = 1; i < n + 1; i++)
	{
		cout << i << "번째 키를 찾을 확률:";
		cin >> p[i];
	}

	A = new float* [n + 1];
	R = new int* [n + 1];
	for (int i = 0; i <= n + 1; i++)
	{
		A[i] = new float[n];
		R[i] = new int[n];
	}

	for (int i = 0; i <= n + 1; i++)
	{
		for (int j = 0; j <= n + 1; j++)
		{
			A[0][j] = 0;
			R[0][j] = 0;
			A[i][i] = p[i];
			R[i][i] = i;
			if (i > j)
			{
				A[i][j] = 0;
				R[i][j] = 0;
			}
			else if (i < j)
			{
				A[i][j] = 1;
			}

		}
	}

	optsearchtree(n, p);
	for (int i = 0; i <= n; i++)
	{
		cout << endl << endl;
		for (int j = 0; j <= n; j++)
		{
			cout << A[i][j] << "\t";
		}
	}
	cout << endl;
	for (int i = 0; i <= n; i++)
	{
		cout << endl << endl;
		for (int j = 0; j <= n; j++)
		{
			cout << R[i][j] << "\t";
		}
	}
	cout << endl;
	Node* root = new Node();
	root = tree(1, n);
	cout << "이진트리의 루트값은 "<<root->key;
}
