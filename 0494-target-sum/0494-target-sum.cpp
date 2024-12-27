class Solution {
public:
    int findTargetSumWays(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> dp;
        dp[0] = 1;
        
        for (const auto& num : nums) {
            std::unordered_map<int, int> temp;
            for (const auto& pair : dp) {
                temp[pair.first + num] += pair.second;
                temp[pair.first - num] += pair.second;
            }
            dp = std::move(temp);
        }
        
        return dp[target];
    }
};
