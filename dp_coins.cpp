#include <iostream>
#include <array>
#include <climits>

using namespace std;

void change_dp(int*, int, int);

int main() {
	int v0[] = {1,3,7,12};
	int a0 = 31;
	int s0 = sizeof(v0) / sizeof(int);

	int v1[] = {1,5,10,25,50};
	int a1 = 24;
	int s1 = sizeof(v1) / sizeof(int);

	int v2[] = {1,10,21,50};
	int a2 = 63;
	int s2 = sizeof(v2) / sizeof(int);

	int v3[] = {1,2,4,8,16};
	int a3 = 120;
	int s3 = sizeof(v3) / sizeof(int);


	change_dp(v0, s0, a0);

	return 0;
}

void change_dp(int V[], int size, int A) {
	int cases[A + 1];
	int result[A + 1];
	int C[size] = {};
	
	//Base case
	cases[0] = 0;

	//Initialize all elements in min as maximum int
	for(int i = 1; i <= A; i++) {
		cases[i] = INT_MAX;
		result[i] = -1;
	}

	//Compute minimum coins for V = 1...V
	for(int i = 1; i <= A; i++) {
		//Loop through denominations that are <= i
		for(int j = size - 1; j >= 0; j--) {
			if(V[j] <= i) {
				int res = cases[i - V[j]];
				
				if(res != INT_MAX && res + 1 < cases[i]) {
					cases[i] = res + 1;
					result[i] = j;
				}
			}
		}
	}

	int res_itr = A;

	//Remove next 2 comments to print coins used
//	cout << "The coins are: ";
	while(res_itr != 0) {
		int k = result[res_itr];
//		cout << V[k] << " ";
		C[k]++;
		res_itr = res_itr - V[k];
	}
	cout << endl;

	cout << "Min coins = " << cases[A] << endl;
	cout << "C = ";
	for(int i = 0; i < size; i++) {
		cout << C[i] << " ";
	}
	cout << endl;
}
