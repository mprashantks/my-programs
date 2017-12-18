#include <iostream>
#include <math.h>

using namespace std;

void smallNum(int sum, int no_of_digits) {
    if(sum > 9*no_of_digits) {
        cout << -1 << endl;
        return;
    }

    if(sum == 0) {
        no_of_digits==1?cout<<0:cout<<-1;
        cout << endl;
        return;
    }

    int *arr = new int[no_of_digits];
    sum -= 1;

    for(int i=no_of_digits-1; i>0; i--) {
        if(sum > 9) {
            arr[i] = 9;
            sum -= 9;
        } else {
            arr[i] = sum;
            sum = 0;
        }
    }
    arr[0] = sum+1;

    for(int i=0; i<no_of_digits; i++)
        cout << arr[i];
    cout << endl;
}

int main() {
	//code
	int numberOfTestCases;

	cin>>numberOfTestCases;
	while(numberOfTestCases > 0) {
	    //Code to solve problem
	    int s, d;
	    cin >> s >> d;
	    smallNum(s, d);
	    numberOfTestCases--;
	}
	return 0;
}
