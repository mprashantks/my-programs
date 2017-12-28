#include <iostream>

using namespace std;

int knapsackRec (int *value, int *weight, int sum, int capacity, int n) {
    if (capacity == 0 || n == 0)
        return sum;

    if (weight[n] > capacity)
        return knapsackRec(value, weight, sum, capacity, n-1);
    else {
        int tmp1 = knapsackRec(value, weight, value[n]+sum, capacity-weight[n], n-1);
        int tmp2 = knapsackRec(value, weight, sum, capacity, n-1);
        return max(tmp1, tmp2);
    }
}


int knapsackDPMem (int *value, int *weight, int sum, int capacity, int n) {

}

int main() {
	//code
	int numberOfTestCases;

	cin>>numberOfTestCases;
	while(numberOfTestCases > 0) {
	    //Code to solve problem
	    int n, capacity;
	    cin >> n >> capacity;
	    int *value = new int[n];
	    int *weight = new int[n];
	    for (int i=0; i<n; i++)
	        cin >> value[i];
	    for (int i=0; i<n; i++)
	        cin >> weight[i];

	    cout << knapsackRec (value, weight, 0, capacity, n-1) << endl;

	    numberOfTestCases--;
	}
	return 0;
}
