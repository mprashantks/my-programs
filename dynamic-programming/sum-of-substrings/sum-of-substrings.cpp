#include <iostream>
#include <string>

using namespace std;

int sumOfSubstrings(string num)
{
    int n = num.length();

    //  allocate memory equal to length of string
    int sumofdigit[n];

    //  initialize first value with first digit
    sumofdigit[0] = num[0]-'0';
    int res = sumofdigit[0];

    //  loop over all digits of string
    for (int i=1; i<n; i++)
    {
        int numi = num[i]-'0';

        // update each sumofdigit from previous value
        sumofdigit[i] = (i+1) * numi +
                        10 * sumofdigit[i-1];

        // add current value to the result
        res += sumofdigit[i];
    }

    return res;
}

int main() {
	//code
	int numberOfTestCases;

	cin>>numberOfTestCases;
	while(numberOfTestCases > 0) {
	    //Code to solve problem
	    string str;
	    cin >> str;

	    cout << sumOfSubstrings(str) << endl;

	    numberOfTestCases--;
	}
	return 0;
}
