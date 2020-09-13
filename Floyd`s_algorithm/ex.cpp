#include<iostream>
#include<stdlib.h>
#include <algorithm>
using namespace std;
int** cost, **relay_center;
string* list;
const int INF = 9999;

void floyd(int N,int** cost,int** relay_center) {
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= N; k++)
			{
				if (cost[j][i] + cost[i][k] < cost[j][k]) {
					cost[j][k] = cost[j][i] + cost[i][k];
					relay_center[j][k] = i;
				}
			}
		}
	}
}
int main() {
	int N = 0;
	string v[10] = { "v0","v1","v2" ,"v3" ,"v4" ,"v5" ,"v6" ,"v7" ,"v8","v9" };
	cout << "input node count : ";
	cin >> N;
	list = new string [N+1];
	cost = new int* [N+1];
	relay_center = new int* [N+1];
	// �ʱ�ȭ
	for (int i = 1; i <= N; i++)
	{
		cost[i] = new int[N];
		relay_center[i] = new int[N];
		list[i] = v[i];
	}
	cout << " input node to node cost (INF = 9999) :"<<endl;
	// �� �Է�
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			relay_center[i][j] = 0;
			if (i != j) {
				cout << list[i]<< "  ����" << list[j] << "�� :";
				cin >> cost[i][j];
				
			}
			else cost[i][j] = 0;
		}
	}
	
	floyd(N, cost,relay_center);
	cout << endl;
	// cost �� ���
	for (int i = 1; i <= N; i++) {
		cout << "\t" << list[i];
	}
	for (int i = 1; i <= N; i++)
	{

		cout << endl;
		for (int j = 1; j <= N; j++)
		{
			if (j == 1)
			{
				cout << list[i];
			}
			cout << "\t" << cost[i][j];
		}
	}
	// path ���
	cout << endl;
	for (int i = 1; i <= N; i++) {
		cout << "\t" << list[i];
	}
	for (int i = 1; i <= N; i++)
	{

		cout << endl;
		for (int j = 1; j <= N; j++)
		{
			if (j == 1)
			{
				cout << list[i];
			}
			cout << "\t" << relay_center[i][j];
		}
	}

}