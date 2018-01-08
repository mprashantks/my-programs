import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    public static int findMissingNum (int arr[], int N) {
        int sum = 0;
        for (int ele : arr)
            sum += ele;
        return (N*(N+1))/2 - sum;
    }

	public static void main (String[] args) {
		//code
		int num_testcases;
		Scanner sc = new Scanner(System.in);
		num_testcases = sc.nextInt();

        while (num_testcases != 0) {
            int N;
            N = sc.nextInt();
            int arr[] = new int[N-1];
            for (int i=0; i<N-1; i++)
                arr[i] = sc.nextInt();

            System.out.println(findMissingNum (arr, N));

            num_testcases --;
        }
	}
}
