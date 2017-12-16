#include <iostream>

using namespace std;

long recSeq(long num) {
    long sum = 0;
    int j = 1;

    for(int i=1; i<=num; i++) {
        long product = 1;
        int n_times = i;

        while(n_times != 0) {
            n_times -= 1;
            product *= j;
            j += 1;
        }
        sum += product;
    }

    return sum;
}

int main() {
	//code
	int numberOfTestCases;

	cin>>numberOfTestCases;
	while(numberOfTestCases > 0) {
	    //Code to solve problem
	    long num;
	    cin >> num;

	    cout << recSeq(num) << endl;

	    numberOfTestCases--;
	}
	return 0;
}
