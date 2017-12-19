#include <iostream>

using namespace std;

void largestNumber (int num_digits, int sum) {
    int *largest_num = new int[num_digits];
    if(sum == 0) {
        num_digits==1?cout<<0:cout<<-1;
        return;
    }
    if(sum > 9*num_digits) {
        cout << -1;
        return;
    }


    for(int i=0; i<num_digits; i++) {
        if(sum > 9) {
            largest_num[i] = 9;
            sum -= 9;
        } else {
            largest_num[i] = sum;
            sum = 0;
        }
    }

    for(int i=0; i<num_digits; i++)
        cout << largest_num[i];
}

int main() {
	//code
	int numberOfTestCases;

	cin>>numberOfTestCases;
	while(numberOfTestCases > 0) {
	    //Code to solve problem
	    int num_digits, sum;
	    cin >> num_digits >> sum;

	    largestNumber(num_digits, sum);
	    cout << endl;

	    numberOfTestCases--;
	}
	return 0;
}
