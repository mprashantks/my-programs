#include <iostream>

using namespace std;

int findSum(int num) {
    if(num <= 9)
        return num;

    return (num%10 + findSum(num/10));
}

int findReverse(int num, int rev) {
    if(num == 0)
        return rev;

    rev = rev*10 + num%10;
    return findReverse(num/10, rev);
}

int main() {
	//code
	int numberOfTestCases;

	cin>>numberOfTestCases;
	while(numberOfTestCases > 0) {
	    //Code to solve problem
	    int num;
	    cin >> num;

	    int sum_digits = findSum(num);
	    int rev = findReverse(sum_digits, 0);

	    sum_digits == rev ? cout<<"YES" : cout<<"NO";
	    cout << endl;

	    numberOfTestCases--;
	}
	return 0;
}
