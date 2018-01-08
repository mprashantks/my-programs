import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    public static void posSum (int arr[], int sum) {
        int i = 0, j = 0, temp_sum = 0;
        while (i<arr.length) {
            temp_sum += arr[j];

            if (temp_sum == sum) {
                System.out.print((i+1)+" "+(j+1));
                return;
            }
            else if (temp_sum < sum) {
                if (j+1 >= arr.length)
                    break;
                j++;
            }
            else if (temp_sum > sum) {
                temp_sum -= (arr[i]+arr[j]);
                i++;
            }
        }
        System.out.print("-1");
    }

	public static void main (String[] args) {
		//code
		int num_testcases;
		Scanner sc = new Scanner(System.in);
		num_testcases = sc.nextInt();

        while (num_testcases != 0) {
            int N, sum;
            N = sc.nextInt();
            sum = sc.nextInt();
            int arr[] = new int[N];
            for (int i=0; i<N; i++)
                arr[i] = sc.nextInt();

            posSum (arr, sum);
            System.out.println();

            num_testcases --;
        }
	}
}
