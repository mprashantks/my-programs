#include <iostream>

using namespace std;

int maxSumRec (int *arr, int i, int size) {
    if (i == size-1)
        return arr[size-1];

    int glo_sum = 0;

    while (i<size) {
        int loc_sum = 0;
        loc_sum = arr[i]+maxSumRec(arr, i+2, size);

        if(loc_sum > glo_sum)
            glo_sum = loc_sum;

        i++;
    }
    return glo_sum;
}


int maxSumDP (int *arr, int size) {

}

int main() {
	//code
	int numberOfTestCases;

	cin>>numberOfTestCases;
	while(numberOfTestCases > 0) {
	    //Code to solve problem
	    int size;
	    cin >> size;
	    int *arr = new int[size];
	    for(int i=0; i<size; i++)
	        cin >> arr[i];

	    // cout << maxSumRec(arr, 0, size) << endl;
	    cout << maxSumDP(arr, size) << endl;
	    numberOfTestCases--;
	}
	return 0;
}
