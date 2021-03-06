#include <iostream>

using namespace std;

int reverse (int num, int rev) {
    // Using recursion
    if (num==0)
        return rev;

    rev = rev*10 + num%10;
    reverse(num/10, rev);

    // Using iteration
    // int rev=0;
    //
    // while (num!=0) {
    //     rev = rev*10 + num%10;
    //     num /= 10;
    // }
    // return rev;
}

int main() {
	//code
	int num_test_cases;

	cin >> num_test_cases;
	while (num_test_cases > 0) {
	    //Code to solve problem
	    int num;
	    cin >> num;

	    while (num%10 == 0)
	        num /= 10;

	    cout << reverse(num, 0) << endl;
	    num_test_cases--;
	}
	return 0;
}
