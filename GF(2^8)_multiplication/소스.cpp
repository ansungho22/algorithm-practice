#include<iostream>
using namespace std;
const int N = 8;
void divi(int* fx, int* gx)  // ������
{
	int result[N] = { 0,0,0,0,0,0,0,0 };
	int maximum_numberfx = 0;  // f(x)�� ���� �ְ������� ���� 
	int maximum_numbergx = 0; // g(x)�� ���� �ְ������� ����
	int q = 0; // ��
	for (int i = 0; i < N; i++)
	{
		if (fx[i] == 1)
		{
			maximum_numberfx = i; //f(x) �ְ����� �Ǻ�
			break;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (gx[i] == 1)
		{
			maximum_numbergx = i; //g(x) �ְ����� �Ǻ�
			break;
		}
	}

	if (maximum_numberfx < maximum_numbergx) q = maximum_numberfx - maximum_numbergx; // f(x)g(x)�� �ְ������� ���ؼ� ū���׿��� ���������� ���̸� ���Ѵ� �迭�ǿ����� �������� �迭�ϼ���
	else if (maximum_numberfx > maximum_numbergx) q = maximum_numbergx - maximum_numberfx; // ū ������ ���ϹǷ� �� �� ���밪�� ���ش�
	else q = 0;
	q = abs(q);
	
	result[7 - q] = 1; //  �� �Լ��� �ְ������� ���̰� ���̵ȴ� 
	
	for (int i = 0; i < N; i++)
	{
		cout << result[i];
	}
}
void mul(int* fx, int* gx) // ����
{
	int mx[N+1] = {1,0,0,0,1,1,0,1,1}; // ���д��׽�
	int result[N][N]; //[A][B] A���� 1�� �������� x���������� x^2�� ���������� ���� B���� �������� ����� ����
	int temp[N] = { 0,0,0,0,0,0,0,0 }; // ������ ������ �����
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{

			if (i == 0)
			{
				result[i][j] = fx[j]; // f(x) * 00000001 ���� ����
			}
			else 
			{
				if (j == 7)
				{
					result[i][j] = 0; //���� ����Ʈ�� �Ҷ� ������ ���� 0 ���� ä���  
				}
				else
				{
					result[i][j] = result[i - 1][j + 1]; // ���Ŀ� ���ؼ� ���� ������ �������� ����Ʈ���ش�
				}
			}
		}
		if (result[i - 1][0] == 1) //  ����Ʈ �� ��Ʈ�����÷ο찡 �Ͼ������ ���״��׽��� �ְ��������� �������� �����ִ°���
		{
			int c = i;
			for (int z = 0; z < N; z++) // ����Ʈ �� + ���״��׽Ŀ��� �ְ��������� �ٸ��� ��
			{
				if ((result[i][z] == 1 && mx[z + 1] == 0) || (result[i][z] == 0 && mx[z + 1] == 1))result[i][z] = 1;
				else result[i][z] = 0;
			}
		}

	}
	for (int i = 0; i < N; i++) // g(x)�� �ش��ϴ� ���� result���� ã�Ƽ� ���ؼ� temp������
	{
		int a = 7 - i;
		if (gx[i] == 1)
		{
			for (int j = 0; j < N; j++)
			{
				if ((result[a][j] == 1 && temp[j] == 0) || (result[a][j] == 0 && temp[j] == 1))temp[j] = 1;
				else temp[j] = 0;
			}
			
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << temp[i];
	}
	
	
} 
void sub(int* fx, int* gx) // ����  (������ ���� ���� XOR�� ���ش�)
{
	int result[N] = { 0,0,0,0,0,0,0,0 };
	for (int i = 0; i < N; i++)
	{
		if ((fx[i] == 1 && gx[i] == 0) || (fx[i] == 0 && gx[i] == 1))result[i] = 1;
		else result[i] = 0;
	}
	for (int i = 0; i < N; i++)
	{
		cout << result[i];
	}
}
void add(int* fx, int* gx) // ����
{
	int result[N]= { 0,0,0,0,0,0,0,0 };
	for (int i = 0; i < N; i++)
	{
		if ((fx[i] == 1 && gx[i] == 0) || (fx[i] == 0 && gx[i] == 1))result[i] = 1; // f(x) �� g(x) �� ���ؼ� XOR�� �Ѵ�
		else result[i] = 0;
	}
	for (int i = 0; i < N; i++)
	{
		cout << result[i];
	}
}
int main() 
{
	//           x^7,x^6,x^5,x^4,x^3,x^2,x  ,1
	int fx[N] = { 0	,1	,0	,1	,0	,1	,1	,1 };
	int gx[N] = { 1	,0	,0	,0	,0	,0	,1	,1 };
	cout << "add :";
	add(fx, gx);
	cout << endl;
	cout << "sub :";
	sub(fx, gx);
	cout << endl;
	cout << "div :";
	divi(fx, gx);
	cout << endl;
	cout << "mul :";
	mul(fx, gx);
	
}