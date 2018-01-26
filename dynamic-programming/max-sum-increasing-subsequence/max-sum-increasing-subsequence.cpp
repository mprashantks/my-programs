#include <iostream>

int maxSumIncSeqRec (int *arr, int arr_size, int *sum) {
  if (arr_size == 1)
    return arr[0];

  int max_seq_end = arr[arr_size-1];

  for (int i=1; i<arr_size; i++) {
    int seq_sum = maxSumIncSeqRec (arr, i, sum);

    if (arr[i-1]<arr[arr_size-1] && seq_sum+arr[arr_size-1]>max_seq_end)
      max_seq_end = seq_sum+arr[arr_size-1];
  }

  if (*sum < max_seq_end)
    *sum = max_seq_end;

  return max_seq_end;
}

int maxSumIncSeqRecInit (int *arr, int arr_size) {
  int sum = 1;
  maxSumIncSeqRec (arr, arr_size, &sum);
  return sum;
}

int maxSumIncSeqDP (int *arr, int arr_size) {
  int sum_table[arr_size];
  for(int i=0; i<arr_size; i++)
    sum_table[i] = arr[i];

  for (int i=1; i<arr_size; i++)
    for (int j=0; j<i; j++) {
      if (arr[j]<arr[i] && sum_table[j]+arr[i]>sum_table[i])
        sum_table[i] = sum_table[j]+arr[i];
    }

  int res = sum_table[0];
  for (int i=1; i<arr_size; i++)
    if (res < sum_table[i])
      res = sum_table[i];

  return res;
}


int main() {
  int arr[] = {1, 101, 2, 3, 100, 4, 5};
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  std::cout << maxSumIncSeqRecInit (arr, arr_size) << std::endl;
  // std::cout << maxSumIncSeqDP (arr, arr_size) << std::endl;
  return 0;
}
