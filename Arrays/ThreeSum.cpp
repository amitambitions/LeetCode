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
// 
// Currently failing for: [0,0,0] - passes
// Then failed for [] - passed
// TODO - Still runtime ins 116ms, need to reduce it.
class Solution {
public:
        vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        
        int n = nums.size();
        // NOTE - Method can be optimised further by iterating i until a[i]<0,
        // because all positive can't make sum as zero.
        // for (int i =0; i < n - 2 && a[i] < 0; ++i) {
        // Since we need the sum of three elements, max we need to go till n -2.
        for (int i =0; i < n - 2; ++i) {
            // Solution 1 -  - see we need to remove duplicates, so the common observation
            // is that lets us say we have sorted numbers as -1,-1,0,1,2 and we start with
            // the first -1, so nums[i] = -1 and if we get a triplet then it means that
            // there exist two numbers AFTER i, whose sum is same as nums[i], for e.g. let
            // us say the numbers are -1,-1,2 so this becomes our triplet now since -1 is
            // duplicate we know for sure that this triplet is not coming again because for
            // this triplet to come we need one more -1, so we can safely avoid it.
            //
            // Also, let us take -1, -1, 0, 1, this will repeat [-1,0,1] as we have two
            // duplicates there.but realize that 0,1 counters both -1, so why to repeat them?
            //
            // NOTE - it is imp to check nums[i] == nums[i-1] rather than nums[i] == nums[i+1]
            // because the later one will remove pairs like [-1,-1,2]
            //if (nums[i] == nums[i+1])
            if (i > 0 && nums[i] == nums[i - 1])
			    continue ;
            int left = i + 1;
            int right = n - 1;
            int current = nums[i];
            while (left < right) {
                int sum = nums[left] + nums[right] + current;
                if (sum == 0) {
                    vector<int> temp({nums[i], nums[left], nums[right]});
                    result.push_back(temp);
                    while(left<n-1 && nums[left]==nums[left+1]) left++; 
                    while(right>0 && nums[right]==nums[right-1]) right--;
                    ++left;
                    --right;
                } else if (sum < 0) {
                    ++left;
                } else {
                    --right;
                }
            }
        
        }
        // Solution 1 - one very easy solution is to just fill the result set first, and 
        // then think like which data structure makes sure that there are no duplicates?
        // Well that is a "set", so use that to filter out all the duplicates and then
        // convert that back to a vector.
        // pros - easy to do
        // cons - though the complexity remains same in terms of O, but effectively we have
        // added many more cycles now, which should be avoided. Set internally is a red black
        // tree so all those unnecessary computations are added now.
        // set<vector<int>> final(result.begin(), result.end());
        // vector<vector<int>> res(final.begin(), final.end());
        // return res;
        //
        // Solution 3 - rather than using set, we can simply sort the vector again, then
        // iterate over it and filter out the duplicates. Something like:
        // 
        // int len = 1;
        // for (int i = 1; i < ret.size(); ++i)
        //  if (ret[len-1] != ret[i])
        //      ret[len++] = ret[i];
        // return vector<vector<int> >(ret.begin(), ret.begin()+len);
        return result;
    }
};
