import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    public static int equPoint (int arr[]) {
        int sum = 0;
        for (int ele: arr)
            sum += ele;

        int temp_sum = 0;
        for (int i=0; i<arr.length; i++) {
            if (temp_sum != sum-arr[i]) {
                sum -= arr[i];
                temp_sum += arr[i];
            } else
                return i+1;
        }
        return -1;
    }

	public static void main (String[] args) {
		//code
		int num_testcases;
		Scanner sc = new Scanner(System.in);
		num_testcases = sc.nextInt();

        while (num_testcases != 0) {
            int N;
            N = sc.nextInt();
            int arr[] = new int[N];
            for (int i=0; i<N; i++)
                arr[i] = sc.nextInt();

            System.out.println(equPoint (arr));

            num_testcases --;
        }
	}
}
