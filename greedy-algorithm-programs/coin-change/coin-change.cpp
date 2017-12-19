#include <iostream>

using namespace std;

const int denominations[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
const int len = 9;

void minimumCoins (int amount) {
    int i = len-1, remain;
    while(denominations[i] > amount)
        i--;
    while(amount >= 0) {
        remain = amount - denominations[i];
        if(remain < 0) {
            i--;
        } else if(remain == 0) {
            cout << denominations[i];
            break;
        } else {
            amount = remain;
            cout << denominations[i] << " ";
        }
    }
    cout << endl;
}

int main() {
	//code
	int numberOfTestCases;

	cin>>numberOfTestCases;
	while(numberOfTestCases > 0) {
	    //Code to solve problem
	    int amount;
	    cin >> amount;

	    minimumCoins(amount);

	    numberOfTestCases--;
	}
	return 0;
}
