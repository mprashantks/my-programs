#include <iostream>

using namespace std;

bool containsDigit(int num) {
    if(num == 0)
        return false;

    if(num%10 == 4)
        return true;

    containsDigit(num/10);
}

int countNumbers(int num) {
    int sum = 0;

    for(int i=1; i<=num; i++) {
        if(containsDigit(i))
            sum+=1;
    }
    return sum;
}

int main() {
	//code
	int numberOfTestCases;

	cin>>numberOfTestCases;
	while(numberOfTestCases > 0) {
	    //Code to solve problem
	    int num;
	    cin >> num;

	    cout << countNumbers(num) << endl;

	    numberOfTestCases--;
	}
	return 0;
}
