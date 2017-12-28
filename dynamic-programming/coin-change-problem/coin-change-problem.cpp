#include <iostream>

using namespace std;

int coinChangeRec (int *arr, int size, int cents) {
    if (cents == 0)
        return 1;

    if (cents < 0)
        return 0;

    if (size<=0 && cents>=1)
        return 0;

    return coinChangeRec(arr, size, cents-arr[size-1])+coinChangeRec(arr, size-1, cents);
}

int coinChangeDP (int *arr, int size, int cents) {
    int *DP_table = new int[cents+1];
    DP_table[0] = 1;

    for (int i=0; i<size; i++)
        for (int j=1; j<=cents; j++)
            if (j >= arr[i])
                DP_table[j] += DP_table[j-arr[i]];

    return DP_table[cents];
}

int main() {
	//code
	int numberOfTestCases;

	cin>>numberOfTestCases;
	while(numberOfTestCases > 0) {
	    //Code to solve problem
	    int size, cents;
	    cin >> size;
	    int *arr = new int[size];
	    for(int i=0; i<size; i++)
	        cin >> arr[i];
	    cin >> cents;

	    // cout << coinChangeRec (arr, size, cents) << endl;
	    cout << coinChangeDP (arr, size, cents) << endl;
	    numberOfTestCases--;
	}
	return 0;
}
