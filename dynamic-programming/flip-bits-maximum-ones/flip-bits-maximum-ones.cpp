#include <iostream>

using namespace std;

// First approach O(n^2) time
int flipBits (int *arr, int n) {
    int num_of_ones = 0, max_diff = 0;

    for (int i=0; i<n; i++) {
        if (arr[i] == 1)
            num_of_ones++;

        int count1 =0, count0 = 0;

        for (int j=i; j<n; j++) {
            arr[j] == 0 ? count0++ : count1++;
            max_diff = max(max_diff, count0-count1);
        }
    }

    return max_diff+num_of_ones;
}

// Second approach O(n) time
int flipBitsOn (int *arr, int n) {
    int num_of_ones = 0;

    int curr_max = 0, global_max = 0;
    for (int i=0; i<n; i++) {
        if (arr[i] == 1)
            num_of_ones++;

        int val = arr[i] == 0 ? 1 : -1;

        curr_max = max(val, val+curr_max);
        global_max = max(global_max, curr_max);
    }
    global_max = max(0, global_max);

    return num_of_ones+global_max;
}

int main() {
	//code
	int numberOfTestCases;

	cin>>numberOfTestCases;
	while(numberOfTestCases > 0) {
	    //Code to solve problem
	    int n;
	    cin >> n;
	    int *arr = new int[n];
	    for(int i=0; i<n; i++)
	        cin >> arr[i];

	    // cout << flipBits (arr, n) << endl;
	    cout << flipBitsOn (arr, n) << endl;

	    free (arr);

	    numberOfTestCases--;
	}
	return 0;
}
