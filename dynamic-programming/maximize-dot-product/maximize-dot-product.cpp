#include <iostream>
#include <limits.h>
#include <string.h>
typedef long int l;

using namespace std;

l maxDotProduct (l DP[][1000], l *arr1, int N, l *arr2, int M) {
    if (N<M || N<0 || M<0)
        return 0;

    if (DP[N][M] != 0)
        return DP[N][M];

    DP[N][M] = max(arr1[N]*arr2[M]+maxDotProduct(DP, arr1, N-1, arr2, M-1), maxDotProduct(DP, arr1, N-1, arr2, M));
    return DP[N][M];
}

int main() {
	//code
	int numberOfTestCases;

	cin>>numberOfTestCases;
	while(numberOfTestCases > 0) {
	    //Code to solve problem
	    int N, M;
	    cin >> N >> M;
	    l *arr1 = new l[N];
	    l *arr2 = new l[M];
	    for (int i=0; i<N; i++)
	        cin >> arr1[i];
	    for (int i=0; i<M; i++)
	        cin >> arr2[i];

	    l DP[1000][1000];
	    memset(DP, 0, sizeof DP);

	    cout << maxDotProduct (DP, arr1, N-1, arr2, M-1) << endl;

	    numberOfTestCases--;
	}
	return 0;
}
