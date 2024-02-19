#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int f(vector<int> &nums, int target, int index, vector<int> &dp)
    {
        if (index == 0)
            return 0;
        if (dp[index] != -1)
            return dp[index];
        int ans = INT_MIN;
        for (int i = index - 1; i >= 0; i--)
        {
            if (abs(nums[index] - nums[i]) <= target)
            {
                ans = max(1 + f(nums, target, i, dp), ans);
            }
        }
        return dp[index] = ans;
    }
    int maximumJumps(vector<int> &nums, int target)
    {

        vector<int> dp(nums.size(), 0);
        // int ans= f(nums, target, nums.size()-1, dp);
        for (int index = 1; index < nums.size(); index++)
        {
            int ans = INT_MIN;
            for (int i = index - 1; i >= 0; i--)
            {
                if (abs(nums[index] - nums[i]) <= target)
                {
                    ans = max(1 + dp[i], ans);
                }
            }
            dp[index] = ans;
        }
        int ans = dp[nums.size() - 1];
        if (ans < 0)
            return -1;
        return ans;
    }
};

int main()
{
    return 0;
}