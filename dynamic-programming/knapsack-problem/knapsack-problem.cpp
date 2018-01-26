#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

// Recursion approach
int knapsackRec (int *value, int *weight, int capacity, int n) {
    if (capacity == -1 || n == -1)
        return 0;

    if (weight[n] > capacity)
        return knapsackRec(value, weight, capacity, n-1);
    else {
        int tmp1 = value[n]+knapsackRec(value, weight, capacity-weight[n], n-1);
        int tmp2 = knapsackRec(value, weight, capacity, n-1);
        return max(tmp1, tmp2);
    }
}


// Dynamic programming - Memoization
int res = 0;
int knapsackDPMem (int *value, int *weight, int DP_table[100][100], int capacity, int n) {
    if (capacity == -1 || n == -1)
        return 0;

    if (DP_table[n][capacity] != -1)
        return DP_table[n][capacity];

    if (weight[n] > capacity)
        res = knapsackDPMem(value, weight, DP_table, capacity, n-1);
    else {
        int tmp1 = value[n]+knapsackDPMem(value, weight, DP_table, capacity-weight[n], n-1);
        int tmp2 = knapsackDPMem(value, weight, DP_table, capacity, n-1);
        res = max(tmp1, tmp2);
    }

    DP_table[n][capacity] = res;
    return res;
}

int knapsackDPMemInit (int *value, int *weight, int capacity, int n) {
    int DP_table[100][100];
    for (int i=0; i<n; i++)
        for (int j=0; j<=capacity; j++)
            DP_table[i][j] = -1;

    return knapsackDPMem (value, weight, DP_table, capacity, n-1);
}



// Dynamic programming - Bottom up
int knapsackDPBU (int *value, int *weight, int capacity, int n) {
    int DP_table[n+1][capacity+1];

    for (int i=0; i<=n; i++)
        for (int j=0; j<=capacity; j++) {
            if (i==0 || j==0)
                DP_table[i][j] = 0;
            else if (weight[i-1] <= j)
                DP_table[i][j] = max(value[i-1] + DP_table[i-1][j-weight[i-1]],  DP_table[i-1][j]);
            else
                DP_table[i][j] = DP_table[i-1][j];
        }

    return DP_table[n][capacity];
}


int main() {
	//code
	int numberOfTestCases;

	cin>>numberOfTestCases;
	while(numberOfTestCases > 0) {
	    //Code to solve problem
	    int n, capacity;
	    cin >> n >> capacity;
	    int *value = new int[n];
	    int *weight = new int[n];
	    for (int i=0; i<n; i++)
	        cin >> value[i];
	    for (int i=0; i<n; i++)
	        cin >> weight[i];

	    // cout << knapsackRec (value, weight, capacity, n-1) << endl;
	    cout << knapsackDPMemInit (value, weight, capacity, n) << endl;

	    // cout << knapsackDPBU (value, weight, capacity, n) << endl;


	    numberOfTestCases--;
	}
	return 0;
}
