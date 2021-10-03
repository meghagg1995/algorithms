/* Brute Force T:O(n*k) S:O(1) */
int findMaxSumSubArray(int k, const vector<int>& arr) {
    int maxSum = 0;
    for(int i=0;i<=arr.size()-k;i++) {
      int sum = 0;
      for(int j=i;j<i+k;j++) {
        sum += arr[j];
      }
      maxSum = max(maxSum, sum);
    }
    return maxSum;
}

/* Optimized T:O(n) S:O(1) */
int findMaxSumSubArray(int k, const vector<int>& arr) {
    int i = 0;
    int sum = 0;
    int maxSum = INT_MIN;
    for(int j=0;j<arr.size();j++) {
        /* Sum [i, j] */
        sum += arr[j];
        if(j - i + 1 == k) {
            maxSum = max(maxSum, sum);
            sum -= arr[i];
            i++;
        }
    }
    return maxSum;
}
