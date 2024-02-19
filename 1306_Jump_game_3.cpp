#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        queue<pair<int, int>> q;
        vector<bool> vis(arr.size(), false);
        q.push({start, arr[start]});

        while (!q.empty())
        {
            int ind = q.front().first;
            int val = q.front().second;
            q.pop();
            if (val == 0)
                return true;
            vis[ind] = true;
            int ind1 = ind + arr[ind];
            int ind2 = ind - arr[ind];
            if (ind1 >= 0 and ind1 <= arr.size() - 1 and !vis[ind1])
                q.push({ind1, arr[ind1]});
            if (ind2 >= 0 and ind2 <= arr.size() - 1 and !vis[ind2])
                q.push({ind2, arr[ind2]});
        }
        return false;
    }
};

int main()
{
    return 0;
}