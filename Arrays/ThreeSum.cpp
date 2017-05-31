// Leetcode question - https://leetcode.com/problems/3sum/#/description
// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
// Find all unique triplets in the array which gives the sum of zero.
// Note: The solution set must not contain duplicate triplets.
//
// For example, given array S = [-1, 0, 1, 2, -1, -4],
//
// A solution set is:
// [
//  [-1, 0, 1],
//  [-1, -1, 2]
// ]

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        
        int n = nums.size();
        for (int i =0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;
            int current = nums[i];
            while (left < right) {
                int sum = nums[left] + nums[right] + current;
                if (sum == 0) {
                    vector<int> temp({nums[i], nums[left], nums[right]});
                    result.push_back(temp);
                    ++left;
                    --right;
                } else if (sum < 0) {
                    ++left;
                } else {
                    --right;
                }
            }
        
        }
        return result;
    }
};