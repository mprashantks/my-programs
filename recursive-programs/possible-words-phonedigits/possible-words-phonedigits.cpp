#include <iostream>
#include <string.h>

using namespace std;

const char digits_table[10][5] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void printWordsFun(int *arr, int len, int curr, char *result) {
    int i;

    if(curr == len) {
        cout << result << " ";
        return;
    }

    for(i=0; i<strlen(digits_table[arr[curr]]); i++) {
        result[curr] = digits_table[arr[curr]][i];
        printWordsFun(arr, len, curr+1, result);

        if(arr[curr]==0 || arr[curr]==1)
            return;
    }
}

void printWords(int *arr, int len) {
    char result[len+1];
    result[len] = '\0';
    printWordsFun(arr, len, 0, result);
}

int main() {
	//code
	int numberOfTestCases;

	cin>>numberOfTestCases;
	while(numberOfTestCases > 0) {
	    //Code to solve problem
	    int len;
	    cin >> len;
	    int * arr = new int[len];
	    for(int i=0; i<len; i++)
	        cin >> arr[i];

	    printWords(arr, len);
	    cout << endl;

	    numberOfTestCases--;
	}
	return 0;
}
