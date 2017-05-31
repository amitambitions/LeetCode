class Solution {
public:
    // While we iterate and inserting elements into the table, we also look back to check
    // if current element's complement already exists in the table. If it exists, we have
    // found a solution and return immediately.
    // Space complexity: O(n)
    // Run time complexity: O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> number_hash;
        vector<int> indexes;
        for (int i = 0; i < nums.size(); ++i) {
            int find_number = target - nums[i];
            if (number_hash.find(find_number) != number_hash.end()) {
                indexes.push_back(number_hash[find_number]);
                indexes.push_back(i);
                return indexes;
            }
        
            // number was not found, put it in the map for further reference.
            number_hash[nums[i]] = i;
        }
        return indexes;
    }
    
    // Brute force approach.
    // Space complexity: O(1)
    // Run time complexity: O(n^2)
    /*vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> number_hash;
        vector<int> indexes;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i+1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        // Return empty vector.
        return indexes;
    }*/
};