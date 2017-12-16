#include <iostream>

using namespace std;

int numOfPaths(int row, int col, int i, int j) {
    if(i == row-1)
        return 1;
    if(j == col-1)
        return 1;

    return numOfPaths(row, col, i+1, j) + numOfPaths(row, col, i, j+1);
}

int main() {
	//code
	int num_test_cases;

	cin >> num_test_cases;
	while(num_test_cases > 0) {
	    //Code to solve problem
	    int row, col;
	    cin >> row >> col;

	    cout << numOfPaths(row, col, 0, 0) << endl;

	    num_test_cases--;
	}
	return 0;
}
