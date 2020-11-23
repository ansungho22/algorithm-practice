#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include <iostream>
#include <algorithm>
using namespace std;
float one(int* arr,int size) {
	int sum = 0;
	for (int i = 0; i < size; i++){
		sum += arr[i];
	}
	return round(sum / size);
}
int two(int* arr, int size) {
	return arr[size / 2];
}
int three(int* arr,int size) {
	int cnt = 1;
	int temp = arr[0];
	int ans = 0;
	int pos = 0;
	for (int i = 1; i < size; i++){
		if (temp == arr[i]) cnt++;
		else {
			temp = arr[i];
			if (ans < cnt) {
				pos = i - 1;
				ans = cnt;
			}
			cnt = 1;
		}
	}
	if (size == 1) return arr[0];
	return arr[pos];
}
int four(int* arr,int size) {
	return (arr[size - 1] - arr[0]);
}
void switching(int *arr,int i,int j) {
	int temp = 0;
	temp = arr[i] ;
	arr[i] = arr[j];
	arr[j] = temp;
} 
int main() {
	int input = 0;
	int size = 0;
	int temp = 0;
	cin >> size;
	int *arr = new int[size];
	for (int i = 0; i < size; i++){
		cin >> input;
		arr[i] = input;
	}
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++)
		{
			if (arr[i] < arr[j]) {
				switching(arr, i, j);
			}
		}
	}
	cout << one(arr, size) << endl;
	cout << two(arr, size) << endl;
	cout << three(arr, size) << endl;
	cout << four(arr, size) << endl;
	
}
