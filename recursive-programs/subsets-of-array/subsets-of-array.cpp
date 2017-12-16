#include <iostream>
#include <vector>

using namespace std;

void printAllSubsets(int arr[], vector <int> subset, int i, int n) {
    if(i == n) {
        vector<int>::iterator it;
        for(it=subset.begin(); it!=subset.end(); it++)
            cout<<*it<<" ";
        cout<<endl;
        return;
    }

    subset.push_back(arr[i]);
    printAllSubsets(arr, subset, i+1, n);
    subset.pop_back();
    printAllSubsets(arr, subset, i+1, n);
}

void printSubsets(int arr[], int i, int n) {
    vector <int> subset;
    printAllSubsets(arr, subset, i, n);
}

int main() {
	//code
	int num_test_cases;

	cin>>num_test_cases;
	while(num_test_cases > 0) {
	    //Code to solve problem
	    int n, arr[100];
	    cin>>n;
	    for(int i=0; i<n; i++)
	        cin>>arr[i];

	    printSubsets(arr,0, n);

	    num_test_cases--;
	}
	return 0;
}
