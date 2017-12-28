#include <iostream>

using namespace std;

// Recursive approach
int maxProductRec (int n) {
    if (n==0 || n==1)
        return 0;

    int glo_pro = 0;

    for (int i=1; i<n; i++) {
        int pro = i*maxProductRec(n-i);

        glo_pro = max(max(pro, glo_pro), i*(n-i));
    }

    return glo_pro;
}


// Dynamic programming approach - Memoization
int maxProductDPMem (int n, int *DP_table) {
    if(DP_table[n]!=-1)
        return DP_table[n];

    if (n==0 || n==1)
        return 0;

    int glo_pro = 0;
    for (int i=1; i<=n; i++) {
        int pro = i*maxProductDPMem(n-i, DP_table);
        glo_pro = max(max(pro, glo_pro), i*(n-i));
    }

    DP_table[n] = glo_pro;

    return DP_table[n];
}

int maxProductDPMemInit (int n) {
    int *DP_table = new int[n+1];
    for(int i=0; i<=n; i++)
        DP_table[i] = -1;
    return maxProductDPMem(n, DP_table);
}


// Dynamic programming approach - Bottom up
int maxProductDPBu (int n) {
    int *DP_table = new int[n+1];
    DP_table[0] = DP_table[1] = 0;

    for(int i=1; i<=n; i++) {
        int glo_pro = 0;
        for(int j=2; j<=i/2; j++)
            glo_pro = max(max(j*(i-j), glo_pro), j*DP_table[i-j]);
        DP_table[i] = glo_pro;
    }

    return DP_table[n];
}


// Tricky Approach
long maxProductTr (int n) {
    if (n==1)
        return 0;
    if (n==2 || n==3)
        return n-1;

    long res = 1;
    while (n>4) {
        n -= 3;
        res *= 3;
    }

    return n*res;
}

int main() {
	//code
	int numberOfTestCases;

	cin>>numberOfTestCases;
	while(numberOfTestCases > 0) {
	    //Code to solve problem
	    int n;
	    cin >> n;

	    // cout << maxProductRec(n) << endl;
	    // cout << maxProductDPMemInit(n) << endl;
	    // cout << maxProductDPBu(n) << endl;
	    cout << maxProductTr(n) << endl;

	    numberOfTestCases--;
	}
	return 0;
}
