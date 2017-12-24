#include <iostream>

// Brute force using recursion
// Recursion tree for array of size 4
//            lIS(4)
//        /       |     \
//     lIS(3)   lIS(2)  lIS(1)
//     /   \      |
// lIS(2) lIS(1) lIS(1)

int lonIncSeqRec (int *arr, int arr_size, int *max) {
  if (arr_size == 1)
    return 1;

  int longest_seq_end = 1;

  for (int i=1; i<arr_size; i++) {
    int res = lonIncSeqRec (arr, i, max);

    if (arr[i-1]<arr[arr_size-1] && res+1>longest_seq_end)
      longest_seq_end = res+1;
  }

  if (*max < longest_seq_end)
    *max = longest_seq_end;

  return longest_seq_end;
}

int lonIncSeqRecInit (int *arr, int arr_size) {
  int max = 1;
  lonIncSeqRec (arr, arr_size, &max);
  return max;
}


// Dynamic programming approach
int lonIncSeqDP (int *arr, int arr_size) {
  int lon_inc_seq_table[arr_size], res = 0;

  for (int i=0; i<arr_size; i++)
    lon_inc_seq_table[i] = 1;

  for (int i=1; i<arr_size; i++)
    for (int j=0; j<i; j++)
      if (arr[j]<arr[i] && lon_inc_seq_table[j]+1>lon_inc_seq_table[i])
        lon_inc_seq_table[i] = lon_inc_seq_table[j]+1;

  for (int i=0; i<arr_size; i++)
    if (res < lon_inc_seq_table[i])
      res = lon_inc_seq_table[i];

  return res;
}

int main () {
  int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  // std::cout << lonIncSeqRecInit (arr, arr_size) << std::endl;
  std::cout << lonIncSeqDP (arr, arr_size) << std::endl;
  return 0;
}
