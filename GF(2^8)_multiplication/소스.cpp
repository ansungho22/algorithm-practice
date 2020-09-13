#include<iostream>
using namespace std;
const int N = 8;
void divi(int* fx, int* gx)  // 나눗셈
{
	int result[N] = { 0,0,0,0,0,0,0,0 };
	int maximum_numberfx = 0;  // f(x)에 대한 최고차항을 뜻함 
	int maximum_numbergx = 0; // g(x)에 대한 최고차항을 뜻함
	int q = 0; // 몫
	for (int i = 0; i < N; i++)
	{
		if (fx[i] == 1)
		{
			maximum_numberfx = i; //f(x) 최고차항 판별
			break;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (gx[i] == 1)
		{
			maximum_numbergx = i; //g(x) 최고차항 판별
			break;
		}
	}

	if (maximum_numberfx < maximum_numbergx) q = maximum_numberfx - maximum_numbergx; // f(x)g(x)의 최고차항을 비교해서 큰차항에서 작은차항의 차이를 구한다 배열의원리상 작은수의 배열일수록
	else if (maximum_numberfx > maximum_numbergx) q = maximum_numbergx - maximum_numberfx; // 큰 차항을 뜻하므로 뺀 후 절대값을 해준다
	else q = 0;
	q = abs(q);
	
	result[7 - q] = 1; //  각 함수의 최고차항의 차이가 몫이된다 
	
	for (int i = 0; i < N; i++)
	{
		cout << result[i];
	}
}
void mul(int* fx, int* gx) // 곱셈
{
	int mx[N+1] = {1,0,0,0,1,1,0,1,1}; // 기학다항식
	int result[N][N]; //[A][B] A에는 1을 곱햇을때 x를곱햇을떄 x^2을 곱햇을때를 뜻함 B에는 곱에대한 결과값 저장
	int temp[N] = { 0,0,0,0,0,0,0,0 }; // 마지막 덧셈의 저장소
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{

			if (i == 0)
			{
				result[i][j] = fx[j]; // f(x) * 00000001 값을 저장
			}
			else 
			{
				if (j == 7)
				{
					result[i][j] = 0; //왼쪽 쉬프트를 할때 오른족 끝은 0 으로 채운다  
				}
				else
				{
					result[i][j] = result[i - 1][j + 1]; // 공식에 의해서 전에 값에서 왼쪽으로 쉬프트해준다
				}
			}
		}
		if (result[i - 1][0] == 1) //  쉬프트 후 비트오버플로우가 일어났을때는 기항다항식의 최고차항을뺀 나머지를 더해주는과정
		{
			int c = i;
			for (int z = 0; z < N; z++) // 쉬프트 값 + 기항다항식에서 최고차항을뺀 다머지 항
			{
				if ((result[i][z] == 1 && mx[z + 1] == 0) || (result[i][z] == 0 && mx[z + 1] == 1))result[i][z] = 1;
				else result[i][z] = 0;
			}
		}

	}
	for (int i = 0; i < N; i++) // g(x)에 해당하는 항을 result에서 찾아서 더해서 temp에저장
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
void sub(int* fx, int* gx) // 뺄셈  (덧셈과 같은 원리 XOR을 해준다)
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
void add(int* fx, int* gx) // 덧셈
{
	int result[N]= { 0,0,0,0,0,0,0,0 };
	for (int i = 0; i < N; i++)
	{
		if ((fx[i] == 1 && gx[i] == 0) || (fx[i] == 0 && gx[i] == 1))result[i] = 1; // f(x) 와 g(x) 에 대해서 XOR를 한다
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