#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        for (int i = 0, j = 0, n = nums.size();; i++)
        {
            for (; j < n && nums[j] == 0; j++)
                ;
            if (j < n)
            {
                swap(nums[i], nums[j]);
                j++;
            }
            else
                return;
        }
    }

    int maxArea(vector<int> &height)
    {
        int ans = 0;
        for (int n = height.size(), i = 0, j = n - 1; i < j;)
        {
            ans = max(ans, (j - i) * min(height[i], height[j]));
            if (height[i] > height[j])
                j--;
            else
                i++;
        }
        return ans;
    }

    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int n = nums.size(), i = 0, sum; i < n - 2 && nums[i] <= 0;)
        {
            for (int j = i + 1, k = n - 1; j < k;)
            {
                sum = nums[i] + nums[j] + nums[k];
                if (sum == 0)
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    for (j++; j < k && nums[j] == nums[j - 1]; j++)
                        ;
                    for (k--; j < k && nums[k] == nums[k + 1]; k--)
                        ;
                }
                else if (sum < 0)
                    for (j++; j < k && nums[j] == nums[j - 1]; j++)
                        ;
                else
                    for (k--; j < k && nums[k] == nums[k + 1]; k--)
                        ;
            }
            for (i++; i < n - 2 && nums[i] == nums[i - 1]; i++)
                ;
        }
        return ans;
    }

    int trap(vector<int> &height)
    {
        int ans = 0;
        for (int n = height.size(), i = 0, j = n - 1, leftMax = 0, rightMax = 0; i < j;)
        {
            if (height[i] < height[j])
            {

                leftMax = max(height[i], leftMax);
                ans += leftMax-height[i];
                i++;
            }
            else
            {
                rightMax = max(height[j], rightMax);
                ans += rightMax-height[j];
                j--;
            }
        }
        return ans;
    }
};