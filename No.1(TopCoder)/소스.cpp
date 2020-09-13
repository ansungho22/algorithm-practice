#include<iostream>
#include<stdlib.h>

using namespace std;

int main() {
	int capacities[] = { 14,35,86,58,25,62 };
	int bottles[] = { 6,34,27,38,9,60 };
	int fromid[] = { 1,2,4,5,3,3,1,0 };
	int toid[] = { 0,1,2,4,2,5,3,1 };

	int total=0;
	for (int i = 0; i < sizeof(fromid)/sizeof(int); i++)
	{
		total = bottles[fromid[i]] + bottles[toid[i]];
		if (capacities[toid[i]] > total  ) {
			bottles[fromid[i]] = 0;
			bottles[toid[i]] = total;
		}
		else {
			bottles[fromid[i]] = total - capacities[toid[i]];
			bottles[toid[i]] = capacities[toid[i]];
		}
	}

	for (int i = 0; i < sizeof(bottles) / sizeof(int); i++)
	{
		cout << bottles[i] << "\t";
	}
}