#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        int q = 2;
        for (int i = 3, p = 1, tmp; i <= n; i++)
        {
            tmp = q;
            q = p + q;
            p = tmp;
        }
        return q;
    }

    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        if (n == 1)
            return cost[0];
        if (n == 2)
            return min(cost[0], cost[1]);
        int q = 0;
        for (int i = 2, p = 0, tmp; i <= n; i++)
        {
            tmp = q;
            q = min(cost[i - 1] + q, cost[i - 2] + p);
            p = tmp;
        }
        return q;
    }

    int combinationSum4(vector<int> &nums, int target)
    {
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[j] <= i && dp[i - nums[j]] < INT_MAX - dp[i])
                    dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};