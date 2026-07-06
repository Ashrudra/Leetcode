#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        // Step 1: Find the longest prefix where each element is exactly one more than the previous
        // This prefix is sequential starting from nums[0].
        int n = nums.size();
        int prefixSum = 0;  // Sum of the longest sequential prefix
        int prefixLength = 0; // Length of the longest sequential prefix
        
        // We assume the prefix starts from index 0 and goes as long as nums[i] == nums[i-1] + 1
        for (int i = 0; i < n; i++) {
            if (i == 0 || nums[i] == nums[i-1] + 1) {
                prefixSum += nums[i];
                prefixLength++;
            } else {
                // Break as soon as the sequence is broken
                break;
            }
        }
        
        // Step 2: We need to find the smallest integer x missing from nums such that
        // x >= prefixSum (sum of the longest sequential prefix)
        
        // To efficiently check which integers are present in nums, use a hash set
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        // Start checking from prefixSum upwards to find the smallest missing integer
        int x = prefixSum;
        while (true) {
            if (numSet.find(x) == numSet.end()) {
                // x is missing in nums and x >= prefixSum, so return x
                return x;
            }
            x++;
        }
    }
};
