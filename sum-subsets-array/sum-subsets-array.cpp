#include <iostream>
#include <algorithm>

using namespace std;

void subsetSum(int arr[], int i, int n, vector<int> &sum_subset, int sum=0) {
    if(i == n) {
        sum_subset.push_back(sum);
        return;
    }

    subsetSum(arr, i+1, n, sum_subset, sum);
    subsetSum(arr, i+1, n, sum_subset, sum+arr[i]);
}

int main() {
	//code
	int numberOfTestCases;

	cin>>numberOfTestCases;
	while(numberOfTestCases > 0) {
	    //Code to solve problem
	    int n, arr[100];
	    cin>>n;
	    for(int i=0; i<n; i++)
	        cin>>arr[i];

	    vector<int> sum_subset;
	    vector<int>::iterator it;

	    subsetSum(arr,0, n, sum_subset);
        sort(sum_subset.begin(), sum_subset.end());

	    for(it=sum_subset.begin(); it!=sum_subset.end(); it++)
	        cout << *it << " ";
	    cout << endl;

	    numberOfTestCases--;
	}
	return 0;
}
