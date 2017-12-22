#include <iostream>
#include <limits.h>

using namespace std;

int minNumberOfCoinsRecursive (int *coins, int num_coins, int value) {
    if(value == 0)
        return 0;

    int res = INT_MAX;

    for(int i=0; i<num_coins; i++) {
        if(coins[i] <= value) {
            int sub_value = minNumberOfCoinsRecursive(coins, num_coins, value-coins[i]);
            if(sub_value!=INT_MAX && sub_value+1<res)
                res = sub_value+1;
        }
    }

    return res;
}

int minNumberOfCoinsDP (int *coins, int num_coins, int value) {
    int *DP_table = new int[value+1];
    DP_table[0] = 0;

    for(int i=1; i<=value; i++)
        DP_table[i] = INT_MAX;

    for(int i=1; i<=value; i++) {
        for(int j=0; j<num_coins; j++) {
            if(coins[j] <= i) {
                int sub_value = DP_table[i-coins[j]];
                if(sub_value!=INT_MAX && sub_value+1<DP_table[i])
                    DP_table[i] = sub_value+1;
            }
        }
    }

    if(DP_table[value] == INT_MAX)
        return -1;
    return DP_table[value];
}

int main() {
	//code
	int numberOfTestCases;

	cin>>numberOfTestCases;
	while(numberOfTestCases > 0) {
	    //Code to solve problem
	    int value, num_coins;
	    cin >> value >> num_coins;
	    int *coins = new int[num_coins];
	    for(int i=0; i<num_coins; i++)
	        cin >> coins[i];

	    //cout << minNumberOfCoinsRecursive (coins, num_coins, value) << endl;
        cout << minNumberOfCoinsDP (coins, num_coins, value) << endl;

	    numberOfTestCases--;
	}
	return 0;
}
