//
// Created by 13410 on 2024/4/23.
//
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target){
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if(m.find(target-nums[i])!=m.end())
                return {m[target-nums[i]],i};
            m[nums[i]]=i;
            
        }
        return {};
    }
};