#include <iostream>

using namespace std;

void floodFill(int m, int n, int arr[][100], int x, int y, int prevC, int newC) {
    if(x<0 || x>=m || y<0 || y>=n)
        return;
    if(arr[x][y] != prevC)
        return;
    if(prevC == newC)
        return;

    arr[x][y] = newC;

    floodFill(m, n, arr, x-1, y, prevC, newC);
    floodFill(m, n, arr, x+1, y, prevC, newC);
    floodFill(m, n, arr, x, y-1, prevC, newC);
    floodFill(m, n, arr, x, y+1, prevC, newC);
}

int main() {
	//code
	int numberOfTestCases;

	cin>>numberOfTestCases;
	while(numberOfTestCases > 0) {
	    //Code to solve problem
	    int m, n, x, y, k;
	    cin >> m >> n;
	    int arr[100][100];
	    for(int i=0; i<m; i++)
	        for(int j=0; j<n; j++)
	            cin >> arr[i][j];

	    cin >> x >> y >> k;

	    floodFill(m, n, arr, x, y, arr[x][y], k);

	    for(int i=0; i<m; i++)
	        for(int j=0; j<n; j++)
	            cout << arr[i][j] << " ";

	    cout << endl;

	    numberOfTestCases--;
	}
	return 0;
}
