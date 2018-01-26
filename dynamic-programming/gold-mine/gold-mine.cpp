#include <iostream>
#include <string.h>

using namespace std;

int maxValue (int arr[][20], int n, int m, int i, int j, int DP[][20]) {
    if (i>=n || j>=m || i<0 || j<0)
        return 0;

    if (DP[i][j] != 0)
        return DP[i][j];

    int t1 = arr[i][j]+maxValue(arr, n, m, i-1, j+1, DP);
    int t2 = arr[i][j]+maxValue(arr, n, m, i+1, j+1, DP);
    int t3 = arr[i][j]+maxValue(arr, n, m, i, j+1, DP);
    int res = max(max(t1, t2), t3);

    DP[i][j] = res;
    return res;
}

int maxValue (int arr[][20], int n, int m) {
    int max_val = 0;
    int DP[20][20];
    memset(DP, 0, sizeof DP);

    for (int i=0; i<n; i++) {
        int res = maxValue(arr, n, m, i, 0, DP);
        if (res > max_val)
            max_val = res;
    }

    return max_val;
}

int main() {
	//code
	int numberOfTestCases;

	cin>>numberOfTestCases;
	while(numberOfTestCases > 0) {
	    //Code to solve problem
	    int n, m;
	    cin >> n >> m;
	    int arr[20][20];
	    for (int i=0; i<n; i++)
	        for (int j=0; j<m; j++)
	            cin >> arr[i][j];

	    cout << maxValue(arr, n, m) << endl;

	    numberOfTestCases--;
	}
	return 0;
}
