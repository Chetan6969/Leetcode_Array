int numberOfSubarrays(int* nums, int numsSize, int k) {
    int count = 0;
    int oddCount = 0;
    int prefix[numsSize + 1];
    memset(prefix, 0, sizeof(prefix));
    prefix[0] =
        1; // Initialize prefix[0] to count subarrays starting from index 0

    for (int i = 0; i < numsSize; ++i) {
        oddCount += nums[i] % 2;
        if (oddCount >= k) {
            count += prefix[oddCount - k];
        }
        prefix[oddCount]++;
    }

    return count;
}