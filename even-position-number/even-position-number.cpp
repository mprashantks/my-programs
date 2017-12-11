#include <iostream>
#include <math.h>

using namespace std;

int findPos(int num, int ans) {
    if(num == 1)
        return ans;

    findPos(num/2, ans*2);
}

int main() {
	//code
	int numberOfTestCases;

	cin>>numberOfTestCases;
	while(numberOfTestCases > 0) {
	    //Code to solve problem
	    int num;
	    cin >> num;

	    //cout << findPos(num, 1) << " ";
	    cout << pow(2, (int)(log(num)/log(2)));
	    cout << endl;

	    numberOfTestCases--;
	}
	return 0;
}
