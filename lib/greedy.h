#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ans{0};
        for (int i = 0, min_ = INT_MAX; i < prices.size(); i++)
        {
            min_ = min(min_, prices[i]);
            ans = max(ans, prices[i] - min_);
        }
        return ans;
    }

    bool canJump(vector<int> &nums)
    {
        for (int n = nums.size(), i = 0, end = 0, maxPos = 0; i < n && end < n - 1;)
        {

            for (; i <= end; i++)
            {
                maxPos = max(maxPos, nums[i] + i);
            }
            if (end == maxPos && end < n - 1)
                return false;
            end = maxPos;
        }
        return true;
    }

    int jump(vector<int> &nums)
    {
        int count = 0;
        for (int n = nums.size(), i = 0, end = 0, maxPos = 0; i < n && end < n - 1;)
        {
            for (; i <= end; i++)
            {
                maxPos = max(maxPos, nums[i] + i);
            }
            end = maxPos;
            count++;
        }
        return count;
    }

    vector<int> partitionLabels(string s)
    {
        vector<int> ans;
        unordered_map<char, int> map;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            map[s[i]] = i;
        }

        for (int i = 0, start = 0,end=0; i < n; i++)
        {
            if (map[s[i]] != i)
                end=max(end,map[s[i]]);
            if(i==end)
            {
                ans.push_back(i-start+1);
                end++;
                start=end;
            }
        }
        return ans;
    }
};